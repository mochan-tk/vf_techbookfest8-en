# Get the BMI measurement result over the phone from Amazon Connect
When you answer your height and weight, the BMI is measured based on those values. The measurement results are sent via the Amazon Connect service.
I made a phone call to my mobile phone. I'm impressed when you actually receive a call.

## How it works
Answer height and weight to Alexa built with Voiceflow. Based on that value, calculate BMI on AWS Lambda.
The result of the calculation will be shown on the phone via Amazon Connect.

![Architecture](images/chapxx-gaomar/s000.png)

## Preparation
We are going to make various preparations. All you need is:

* Issuing phone number
* Create contact flow
* Create AWS Lambda function
* API Gateway settings
* Voiceflow settings

Then we will prepare them in order.

### Issue Amazon Connect Phone Number

#### Create resources
Go to AWS and log in with your AWS account.

[https://aws.amazon.com/jp/](https://aws.amazon.com/jp/)@<br>{}

When the console screen opens, enter [Amazon Connect] from the service search and search. Click on the `Amazon Connect` that appeared.

![AmazonConnect](images/chapxx-gaomar/g101.png)

Click the Start Now button.

![Click to start now](images/chapxx-gaomar/g102.png)

Check if it is in the Tokyo region. If not, select "Asia Pacific (Tokyo)" from the top right.

![Select Asia Pacific (Tokyo)](images/chapxx-gaomar/g103.png)

Decide the name to be used this time for the access URL. Give it a name like [vf-techbookfest- {your name}] that won't hurt anyone.

![Determine resource name](images/chapxx-gaomar/g104.png)

Select "Skip this" since you can create an administrator for Step 2 later, and then click the [Next Step] button.

![Skip this and click the next step](images/chapxx-gaomar/g105.png)

Leave the telephony option in step 3 as it is and click the Next Step button.

![Click the next step](images/chapxx-gaomar/g106.png)

Click the [Next Step] button for the data storage in Step 4 as it is.

![Click the next step](images/chapxx-gaomar/g107.png)

Make a final check in step 5 and if there are no problems, click the [Create Instance] button.

![Click Create Instance](images/chapxx-gaomar/g108.png)

It takes about 1-2 minutes to create.

![Wait for 1-2 minutes](images/chapxx-gaomar/g109.png)

If successful, click the Start Now button.

![Click to start now](images/chapxx-gaomar/g110.png)

#### Get phone number
Get a dedicated Amazon Connect phone number.
The screen for Amazon Connect will be displayed in another tab, so click the [Start Now] button displayed there.

If it is not in Japanese, select "Japanese" from the upper right.

![Start now](images/chapxx-gaomar/g111.png)

To get the phone number, select Japan +81 as the country.

![Select +81](images/chapxx-gaomar/g112.png)

There are two types: Please choose the one you like.

![Phone number type list](images/chapxx-gaomar/h100.png)

![Select phone number type](images/chapxx-gaomar/g113.png)

Finally, select your favorite number and click the [Next] button.

![Click Next](images/chapxx-gaomar/g114.png)

Click the [Continue] button. Your phone number is now issued.

![Click Continue](images/chapxx-gaomar/g115.png)

#### Confirm issued phone number
Check the obtained phone number.
Click the routing phone number from the left menu.

![Click the routing phone number](images/chapxx-gaomar/g116.png)

The obtained phone number is displayed. If you want to increase another number, you can add it by pressing the "Add phone number" button on the right. I'll use this phone number later, so make a note of it.

![Make note of phone number](images/chapxx-gaomar/g117.png)

### Create a contact flow
Create a flow when you receive a call on Amazon Connect. You can easily create it by simply arranging it on the GUI screen.

#### Create a contact flow
Click "Contact Flow" from the menu on the left.

![Click the inquiry flow](images/chapxx-gaomar/s100.png)

Click Create Contact Flow.

![Click to create contact flow](images/chapxx-gaomar/s101.png)

Enter the name Voiceflow-AmazonConnect.

![Input Voiceflow-AmazonConnect](images/chapxx-gaomar/s102.png)

Drag and drop the "Audio settings" block in the settings category and click on the dropped block.

![Drag and drop audio settings](images/chapxx-gaomar/s103.png)

Please select your favorite language in "Japanese".

![Select Takumi or Mizuki](images/chapxx-gaomar/s104.png)

Connect the entry point and the audio setting block.

![Connect blocks](images/chapxx-gaomar/s105.png)

Drag and drop "Set query attribute" in the setting category.

![Drag and drop the setting of the query attribute](images/chapxx-gaomar/s106.png)

Set the attributes. Select "Use attributes".

![Attribute setting list](images/chapxx-gaomar/h101.png)

![Set the attribute](images/chapxx-gaomar/s107.png)

Connect the blocks.

![Connect blocks](images/chapxx-gaomar/s108.png)

Drag and drop "Play prompt" in the operation category.

![Drag and drop playback of prompt](images/chapxx-gaomar/s109.png)

Set the attributes. Select "Text-to-speech or chat text".

![Attribute setting](images/chapxx-gaomar/h102.png)

![Set the attributes](images/chapxx-gaomar/s110.png)

Connect the blocks.

![Connect blocks](images/chapxx-gaomar/s111.png)

Drag and drop "Loop" in the branch category.
Specify the number of loops as you like.

![Set the loop](images/chapxx-gaomar/s112.png)

Connect the blocks.

![Connect blocks](images/chapxx-gaomar/s113.png)

Connect loop and prompt playback.

![Connect blocks](images/chapxx-gaomar/s114.png)

Drag and drop “Disconnect / Hang up” in the End / Transfer category.

![Drag and drop cutting / hangup](images/chapxx-gaomar/s115.png)

Connect all the parts that have not been connected yet to "Disconnect / Hang up".

![Connect blocks](images/chapxx-gaomar/s116.png)

Click the ① [Save] and ② “Publish” buttons in the upper right in order.

![Save → Click the publish button](images/chapxx-gaomar/s117.png)

#### Write down your ID
Under the contact flow name, expand the item labeled "Show additional flow information". When expanded, the ARN information is displayed. Make a note of the `instance` ID and` constact-flow` ID respectively.

![Write down your ID](images/chapxx-gaomar/s118.png)

### Create a Lambda function
We will implement processing to calculate the height and weight data sent from Voiceflow side and notify Amazon Connect of the result.

#### Create Lambda function
Search for `Lambda` from the service and click on the one that comes up.

![Search Lambda](images/chapxx-gaomar/s120.png)

Create a new function from Lambda. Click the Create Function button.

![Click to create function](images/chapxx-gaomar/s130.png)

Enter the function as follows and click the [Create Function] button.

![Function setting items](images/chapxx-gaomar/h103.png)

![Function settings](images/chapxx-gaomar/s131.png)

#### Add Amazon Connect permissions
Click Show Voiceflow-AmazonConnect-Role Role.

![Click to view role](images/chapxx-gaomar/s132.png)

Click Add Inline Policy.

![Click to add inline policy](images/chapxx-gaomar/s133.png)

Expand the service and search for "Connect" in the search window. Click [Connect] that appears.

![Search Connect](images/chapxx-gaomar/s134.png)

Expand the "Write" part of the action's access level and check the `StartOutboundVoiceContact` in it.

![Check the StartOutboundVoiceContact](images/chapxx-gaomar/s135.png)

Select all resources and click the Check Policy button in the lower right.

![Click Check Policy](images/chapxx-gaomar/s136.png)

Enter a policy name. `Voiceflow-AmazonConnect-Policy`. Click the Create Policy button in the lower right.

![Enter policy name](images/chapxx-gaomar/s137.png)

#### Write the program
Open index.js. Delete all existing sources and copy and paste the following program.
Since the request comes from Voiceflow, get the target value from body.

```javascript
const Util = require ('./ util.js');

exports.handler = async (event) => {

    // get height and weight values
    const height = event.queryStringParameters.height;
    const weight = event.queryStringParameters.weight;
    
    const bmiVal = (parseFloat (weight) / (parseFloat (height) / 100 * parseFloat (height) / 100)). toFixed (1);
    const message = `Your BMI is $ {bmiVal}. `;
    
    const response = {
        statusCode: 200,
        body: "We will announce the results by phone",
    };

    // Amazon Connect submission
    await Util.callMessageAction (message);

    return response;
};
```

Create a new file.

![Create new file](images/chapxx-gaomar/s150.png)

Copy and paste the code below.

```javascript
'use strict';
const AWS = require ('aws-sdk');
var connect = new AWS.Connect ();

// Calling process
module.exports.callMessageAction = async function callMessageAction (message) {
    return new Promise (((resolve, reject) => {

        // Set the content to be spoken in Attributes
        var params = {
            Attributes: {"message": message},
            InstanceId: process.env.INSTANCEID,
            ContactFlowId: process.env.CONTACTFLOWID,
            DestinationPhoneNumber: process.env.PHONENUMBER,
            SourcePhoneNumber: process.env.SOURCEPHONENUMBER
        };

        // to call
        connect.startOutboundVoiceContact (params, function (err, data) {
            if (err) {
                console.log (err);
                reject ();
            } else {
                resolve (data);
            }
        });
    }));
};
```

When saving, change the file name to `util.js`.

![Change the file name to util.js](images/chapxx-gaomar/s151.png)

#### Set environment variables
Set the environment variables to link with Amazon Connect.

![Environment variable](images/chapxx-gaomar/h104.png)

![Set environment variables](images/chapxx-gaomar/s152.png)

#### Configure API Gateway
Issue a URL to access from Voiceflow.
Click Add Trigger.

![Set API Gateway](images/chapxx-gaomar/s153.png)

Specify the following for the trigger setting. Finally, click the [Add] button.

![Trigger setting item](images/chapxx-gaomar/h105.png)

![Trigger settings](images/chapxx-gaomar/s154.png)

Make a note of the API endpoint URL.

![Make note of API URL](images/chapxx-gaomar/s155.png)

Click the save button in the upper right.

![Click Save](images/chapxx-gaomar/s156.png)

## Set up Voiceflow
From here, make settings in Voicecelflow. Access Voiceflow and log in. @<br>{}

[https://www.voiceflow.com/](https://www.voiceflow.com/)

### Create a project
Create a Voiceflow project. This can also be easily created on the GUI screen.

#### Create new project
After logging in, click the New Project button.

![Click New Project](images/chapxx-gaomar/s200.png)

Enter a project name. In this case, it is `VoiceflowBMI`. Uncheck English and check Japanese (JP). Finally, click the [Create Project] button.

![Set up the project](images/chapxx-gaomar/s201.png)

Drag and drop the `Speak` block and enter the words you want Alexa to speak. First, I want to ask the user's height, so enter "Measure BMI. Please answer height in centimeters."

```
Measure BMI. Please answer your height in centimeters.
```

![Register words to get your height answered](images/chapxx-gaomar/s202.png)

Connect the blocks with lines.
![Connect with a line](images/chapxx-gaomar/s203.png)

I want to store the height and weight values in variables, respectively, so register the variable names. Register `height`,` weight` and `res` respectively.

![Add a variable](images/chapxx-gaomar/s204.png)

Drag and drop the `Capture` block in the Logic category. Connect it to the `Speak` block with a line, and select` FourDigitNumber` because you want to get the Input Type. For the Capture Input to, I want to store it in the created variable `{height}`, so select the variable name `height` to be stored from the pull-down menu.

![Put height value into variable height](images/chapxx-gaomar/s205.png)

Drag and drop the `Speak` block and connect it with a line. Next, I want to ask for my weight, so type "Please give your weight in kilograms."

```
Then please give your weight in kilograms.
```

![Register words to get your weight answered](images/chapxx-gaomar/s206.png)

Drag and drop the `Capture` block in the Logic category. Select `FourDigitNumber` as well as height. For Capture Input to, I want to store it in the created variable `{weight}`, so select the variable name `weight` to be stored from the pull-down menu.

![Put weight value into variable weight](images/chapxx-gaomar/s207.png)

Drag and drop the `Integrations` block in the Advanced category. Connect the line with `Capture` and click` Custom API`.

![Click Custom API](images/chapxx-gaomar/s2071.png)

 Paste the URL issued by API Gateway into the Request URL. The method always selects `POST`. Click the Params tag to set the parameters to pass.

Set the height and weight parameters in the Entry Parameter key part. Set `height` and` weight` to Key and Value respectively. Since the result from the API is stored, enter `response` in the Enter Object path part of Transform info Variables and select the variable name` res`.

![Parameter setting for Key and Value](images/chapxx-gaomar/s208.png)

Drag and drop the `Speak` block and connect the top of the Integrations block with a line. Enter the variable name `{res}` to have the contents of the variable `res` spoke.

![Res is uttered when API is successful](images/chapxx-gaomar/s209.png)

Enter the text when an error occurs on the API Gateway or Lambda side.

```
An error has occurred.
```

![Enter the text at the time of error](images/chapxx-gaomar/s210.png)

Drag and drop the Advanced category `Exit` block to end the skill.
Connect the upper and lower blocks.

![Set end block](images/chapxx-gaomar/s211.png)

#### Operation check
Now that you have a flow, deploy it to Alexa. Click the `Upload to Alexa` button at the top right of the screen. If you haven't linked to Amazon yet, press the `Connect Amazon` button.

![Click Upload to Alexa](images/chapxx-gaomar/s212.png)

Click the `Amazon Console` link when the upload is complete.

![Click Amazon Console](images/chapxx-gaomar/s213.png)

The alexa developer console screen will be displayed. Enter "Open voiceflowbmi". Enter your height and weight and you will receive a call on your mobile phone.

![BMI measurement result comes over the phone](images/chapxx-gaomar/s214.png)

With Voiceflow, the integration of Amazon Connect was implemented very quickly. Let's try various cooperations and "go" together.


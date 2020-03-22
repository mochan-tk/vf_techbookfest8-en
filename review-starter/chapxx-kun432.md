# Let's work with Google Spreadsheets

With Voiceflow's Google Spreadsheet integration feature, you can use it as a simple database with the same ease of use as your usual Excel, which will dramatically broaden your skill development. Let's make the most of it and take your skills to the next level.

## Randomly call data in a spreadsheet

First, let's learn the basics of how to use Voiceflow's Google Spreadsheet integration while also doing some random data retrieval from the sheet. As a sample, let's create a skill that randomly teaches you the recommended recipes and their ingredients that you have in your Google spreadsheet.

### Create a spreadsheet and create a basic part of the skill

First, log in to Google Spreadsheets with your Google account and create a spreadsheet like the one below.

![](images/chapxx-kun432/s009.png)

- The name of the spreadsheet should be "My Recipe Data" and the name of the sheet (bottom tab) should be "Recipe List".
- Enter ```recipe_name``` in A1 and ```recipe_content``` in B1. The first line is always the heading line. Please note that it is not possible to specify in Japanese.
- After the second row, enter the name of the recipe in column A and the ingredients in column B.

Next, create a project like the following on the Voiceflow side and place the blocks.

![](images/chapxx-kun432/s069.png)

- The name of the project will be "My Home Recipes". Please select only "Japanese (ja-JP)" as the language.
- Once the project is created, place one Speak block and line it up with the Home block Start.
- The Speak block should be set as follows.

//list[][]{
Welcome to my home recipe skills. In this skill, I'll randomly give you a recommended recipe. Today's recommendation is <audio src="soundbank://soundlibrary/ui/gameshow/amzn\_ui\_sfx_gameshow\_intro\_01"/>
//}

By the way, the last part of the ```<audio src=~``` is to play the sound effects using the Alexa Skills Kit sound library.

//note[Alexa Skills Kit sound library]{
@<href>{https://developer.amazon.com/ja-JP/docs/alexa/custom-skills/ask-soundlibrary.html}
//}

//embed[latex]{
\clearpage
//}

### "Integration blocks" that work with Google spreadsheets

Use the "Integration block" to work with Google Spreadsheets. From Advanced in the Blocks menu on the left, drag and drop the Integration block to the right of the Speak block and connect it with a line.

![](images/chapxx-kun432/s002.png)

In the Integration block settings that appear on the right, click on "Google Sheets" (Google spreadsheets are called Google Sheets in English).

![](images/chapxx-kun432/s002-2.png)

//embed[latex]{
\clearpage
//}

First, select what you want to do with the data in the spreadsheet: Retrieve Data/Create Data (add one row of data to the spreadsheet), Update Data (update one row of data in the spreadsheet), or Delete Data (delete data in the spreadsheet). This time, I want to retrieve the recipe name and ingredient name data from the Google spreadsheet, so I click on "Retrieve Data".

![](images/chapxx-kun432/s003-2.png)

Next, tie it to your Google account to access your Google spreadsheet. Click on "+Add User".

![](images/chapxx-kun432/s004.png)

//embed[latex]{
\clearpage
//}

If this is your first time, you will see the login screen of your Gooogle account as shown below. Click on "Login with Google".

![](images/chapxx-kun432/s005.png)

The Google account selection screen will appear and you will select the account where you created the Google spreadsheet. You may be prompted to enter your account password. In this case, please log in with your Google account and password. Then "allow" access to the Google spreadsheet from Voiceflow.

![](images/chapxx-kun432/s006-3.png)

//embed[latex]{
\clearpage
//}

If you see the following, your Google account has been connected to your Google account. Click on the "Using Sheet" to proceed.

![](images/chapxx-kun432/s008.png)

In the "Using Sheet", select the spreadsheet to be accessed from Voiceflow. Select a spreadsheet name in Spreadsheet and a sheet name (tab name at the bottom) in Sheet from the list, respectively. In the case of the first spreadsheet you created this time, select "My Recipe Data" in the "Spreadsheet" and "Recipe List" in the "Sheet". (If you can't see the sheet name, scroll down a bit.)

![](images/chapxx-kun432/s011.png)

//embed[latex]{
\clearpage
//}

Once the spreadsheet has been selected, "With Settings" will appear. If it's random, select "Row Number" from the list in "Column" on the left, and click "Next" without entering anything in "Value to Match" on the right.

![](images/chapxx-kun432/s035.png)

The "Mapping Output" part is also set up later, so click "Next" as it is.

![](images/chapxx-kun432/s036.png)

//embed[latex]{
\clearpage
//}

Test Integration allows you to actually test the connection to a Google spreadsheet. Click on "Test Integration".

![](images/chapxx-kun432/s037.png)

Under "Test Integration", if you see the recipe name and ingredients listed in the spreadsheet, you've succeeded. Click "Test Integration" several times to make sure that the results change randomly.

![](images/chapxx-kun432/s014.png)

### Using variables to use spreadsheet data within a skill

I've been able to work with Google Spreadsheets, but I can't use that data from within the skill yet. You need to use "variables" in order to use the data retrieved from the spreadsheet in your skills. First, let's create a variable.

You can create a variable from the "Variables menu". Click on the bottom icon from among the three vertical icons on the leftmost side of the screen to switch the menu. Enter the name of the variable in the input form immediately below "Create Variable" and press ENTER key to create the variable. First, type ```varName``` and press ENTER.

![](images/chapxx-kun432/s016-2.png)

If you see ```varName``` at the end of ```sessions```, etc., just below the input field, then the variable has been successfully created. Similarly, create a variable called ```varContent```.

![](images/chapxx-kun432/s039.png)

//embed[latex]{
\clearpage
//}

It is OK if two variables have been created as follows. Click on the top icon of the three leftmost icons to go back to the "Blocks menu".

![](images/chapxx-kun432/s110.png)

Next, we tie the data retrieved from the Google spreadsheet to the variables. This will allow you to call the data that is in the variable (say "value") in other blocks, click on the Integration Block to bring up the configuration screen, then click on Mapping Output.

![](images/chapxx-kun432/s051.png)

//embed[latex]{
\clearpage
//}

Mapping Output" is used to link variables and acquired data. Click on "+Add Mapping".

![](images/chapxx-kun432/s050.png)

Click on "+Add Mapping" and you will be able to select "Column" and "Variable" respectively. Specify the column name of the data retrieved from the spreadsheet in "Column" and the variable name to which it is attached in "Variable". This ties the data in the spreadsheet to the variables.

![](images/chapxx-kun432/s053.png)

//embed[latex]{
\clearpage
//}

Now let's do the tying. Select ```recipe_name``` for "Column" and ```varName``` for "Variable".

![](images/chapxx-kun432/s024-2.png)

Now, the data in the ```recipe_name``` column of the spreadsheet is now in the variable ```varName```. Similarly, you can also attach a ```recipe_content``` column to the variable ```varContent```. Click on "+Add Mapping" to add your settings in the same way.

If the two are connected and look like this, you're good to go. Click on "Next" to return to the canvas.

![](images/chapxx-kun432/s058.png)

Now, let's take the data from the spreadsheet and use it in our skills, by placing a Speak block next to the Integration block and connecting it to the one that doesn't say "fail" in the Integration block.

![](images/chapxx-kun432/s060.png)

The Speak block is set up as follows.

```
{varName}. The material is {varContent}.
```

Now let's upload it to the Alexa developer console and test it out. Once you've run the skill a few times and are sure that you're getting the data in your Google spreadsheet and that the data changes randomly, you're good to go.

![](images/chapxx-kun432/s062.png)

//embed[latex]{
\clearpage
//}

### Prepare for integration block failure

Google Spreadsheet integration is very convenient, but there is a possibility that the spreadsheet may not be accessible or data may not be retrieved due to communication problems or setting errors. Let's make sure that you handle the error properly.

Place the Speak block next to the Integration block and connect it to the "fail" in the Integration block.

![](images/chapxx-kun432/s066.png)

The Speak block is set up as follows.

```
Sorry, there was an error. Please come back to us after a while.
```

Now, this Speak block will be executed when an error occurs during Google Spreadsheet integration.

## Get the data of the spreadsheet with conditions.

Now, let's do a search by specifying conditions. Ask your users which recipes they would like to know, then take their utterances and search the spreadsheet for them. @<br>{}

### Receive speech from users who are search criteria

We'll need to accept the user's speech, so we'll change the flow a bit. First, let's modify the contents of the first Speak block.

![](images/chapxx-kun432/s071.png)

```
Welcome to my home recipe skills. With this skill, you can ask for the name of the ingredients when you say the name of the recipe. For example, say, "I want to know the recipe for hamburgers.
```

Between the first Speak block and the Integration block, add a Choice block and a Speak block and connect them as follows

![](images/chapxx-kun432/s072.png)

//embed[latex]{
\clearpage
//}

Let's create an Intent/Sampled Speech/Slot by clicking on the Choice block and creating an Intent. In the "Name new intent or selecting existing intent" field, type ```ask_recipe_intent``` and click "Create". This will be the name of the intent.

![](images/chapxx-kun432/s073.png)

You'll see a new section called Utterances. Here you can register a sample utterance. In the "What might the user say to invoke this intent?" field, type `want to know the recipe for ```slot_recipe_name```. Don't forget to put a space between ```slot_recipe_name``` and ```want to know the recipe```.

![](images/chapxx-kun432/s111.png)

//embed[latex]{
\clearpage
//}

Next, select the part of ```slot_recipe_name``` with the cursor and click "Create" because it will be displayed as follows.

![](images/chapxx-kun432/s112.png)

The slot creation screen appears. Select ```slot_recipe_name``` for the slot name, choose Food for the slot type and your favorite color for the slot color. Finally, click on "Create Slot". The slot has now been created.

![](images/chapxx-kun432/s113.png)

//embed[latex]{
\clearpage
//}

If you go back to the Choice block setting screen, the sample utterance ```slot_recipe_name``` has changed to the color you specified. In this way, we will create a sample utterance that includes the slot. Don't forget to register it as a sample utterance by clicking on the ENTER key at the end.

![](images/chapxx-kun432/s114.png)

If the sample speech is displayed under the input field, the sample speech has been registered. I will continue to add variations on the sample utterances. Type ```tell me the recipe for slot_recipe_name```.

![](images/chapxx-kun432/s115.png)

//embed[latex]{
\clearpage
//}

As in the first, select ```slot_recipe_name``` with the cursor. You only need to select it from the list because it is already registered.

![](images/chapxx-kun432/s116.png)

It is also possible to select a slot by entering ```{``` at the time of sample utterance input and continue inputting afterwards. Register a few sample utterances in the way you like.

![](images/chapxx-kun432/s117.png)


```
Example of sample utterances: 

I want to know the material for {slot_recipe_name}
Tell me the material for {slot_recipe_name}.
Recipe for {slot_recipe_name}
Material for {slot_recipe_name}
{slot_recipe_name}
```

//embed[latex]{
\clearpage
//}

If the final result looks like this, it's OK.

![](images/chapxx-kun432/s118.png)

The Speak block above is used to listen again when you receive speech that doesn't match the intent you set in the Choice block.

![](images/chapxx-kun432/s081.png)

Enter the following.

```
I'm sorry, I didn't catch it well. For example, say, "I want to know the recipe for hamburgers.
```

//embed[latex]{
\clearpage
//}

### Get data from a spreadsheet with a condition

You are now ready to receive the utterances of users who are search criteria. Now, let's try to search the spreadsheet based on that utterance: click on the Integration block and click on "With Settings".

![](images/chapxx-kun432/s080.png)

For random, I selected "Row Number" on the left and left "Value to Match" empty on the right. You can do this as follows, with ```recipe_name``` on the left and ```{slot_recipe_name}``` on the right. Now you can search the "recipe\_name" column by specifying the variable ```slot_recipe_name```. Click "Next".

![](images/chapxx-kun432/s082.png)

//embed[latex]{
\clearpage
//}

Keep "Mapping Output" and click "Next" to go to "Test Integration" and then click "Test Integration".

![](images/chapxx-kun432/s083.png)

A different screen came up than in the random case. Try typing "curry rice" into the ```slot_user_recipe``` and clicking on "Run".

![](images/chapxx-kun432/s085.png)

//embed[latex]{
\clearpage
//}

The data of the curry rice is properly retrieved. As you can see, if you use a variable as a search condition in "With Settings", you can specify the value of the variable and test it yourself. Search by other recipe names and make sure you get data that meets your criteria.

![](images/chapxx-kun432/s086.png)

It's working correctly on the Alexa developer console side as well.

![](images/chapxx-kun432/s087.png)

//embed[latex]{
\clearpage
//}

### What to do when there are no search results

Continuing from the previous test, this time try a recipe name that is not registered in the recipe data.

![](images/chapxx-kun432/s089.png)

```undefined``` means ```nothing is defined```. I tried to search for a recipe name that wasn't in the recipe data, so that's natural, but it's not a good idea for Alexa to give me an answer like this. Let's fix that a bit.

Remove the Integration block and the Speak block (the non-fail one) and place the If block in the Logic menu of the Block menu.

![](images/chapxx-kun432/s090.png)

//embed[latex]{
\clearpage
//}

An If block is a block that specifies a condition and splits the process flow according to the result. Here, the Integration block will branch out if the data can be retrieved from the recipe name, and if it cannot.

![](images/chapxx-kun432/s091.png)

Now it's time to set the conditions. If you simply think about it, because the variable ```varName``` or variable ```varContent``` that contains the data obtained from the spreadsheet is ```undefined```, I think it is good if you compare using equals. However, this ```undefined``` is a bit special programmatically, and it doesn't work well even if you set it as follows.

![](images/chapxx-kun432/s092.png)

//embed[latex]{
\clearpage
//}

So we're going to twist it a bit so that we don't judge whether it's ```undefined``` or not, but whether the search results are correct or not. First of all, the top "Select Variable" selects ```slot_user_recipe```.

![](images/chapxx-kun432/s098.png)

Next, the "Value" at the bottom can only be entered directly in the initial state, so you can't select a variable. From there, click on the right-most "</>" icon. Then click "Variable" when the menu appears.

![](images/chapxx-kun432/s094.png)

//embed[latex]{
\clearpage
//}

Then, the bottom side will also change to "Select Variable".

![](images/chapxx-kun432/s096.png)

In other words, it checks that "the name of the recipe that the user spoke (```slot_user_recipe```) = the name of the recipe retrieved from the spreadsheet (```varName```), and the search result was retrieved. If the condition is met, the flow will go to "1", and if not, the flow will go to "else".

![](images/chapxx-kun432/s097.png)

//embed[latex]{
\clearpage
//}

Now, let's talk about each result to Alexa with a Speak block. The original Speak block should be connected to "1" in the If block. I also changed the content of my speech slightly.

![](images/chapxx-kun432/s100.png)

Add another Speak block and connect it to the If block from "else" and configure it as follows.

![](images/chapxx-kun432/s101.png)

//embed[latex]{
\clearpage
//}

Finally, you can test it in the Alexa developer console, and if you're able to speak up if it doesn't get results properly, you're done. Thank you for your hard work.

![](images/chapxx-kun432/s102.png)

//note[about the decision to undefine]{
Voiceflow's If block has a description method called "Advanced Expression", which allows you to use programmatic writing to determine the undefind. If you are used to programming, this may be easier to understand. See also the official documentation. @<br>{}

Advanced expression (IF and SET blocks) - Voiceflow Docs @<br>{}
@<href>{https://docs.voiceflow.com/voiceflow-documentation/logic-in-voiceflow/advanced-expression-if-and-set-blocks} 
//}

//embed[latex]{
\clearpage
//}

## Notes on using Google Spreadsheets

It is convenient and easy to work with Google Spreadsheet, but there are also weaknesses.

- It is a personal impression, but access to Google spreadsheets, I feel that the response is a little slow compared to access to general APIs, etc. Please note that accessing the spreadsheet multiple times in a skill may compromise the user's sense of tempo and rhythm when using the skill.
- Also, high frequency access to Google spreadsheets may result in restricted access from Google. It's fine if the skill is used in general, but please note that if the skill becomes popular, it may be subject to this restriction.
- If you have a lot of data in a Google spreadsheet (e.g. a lot of rows and columns, a lot of characters in a cell, etc.), the response may be slow or the data may not be retrievable. It depends on the combination of rows, columns, data in cells, etc., so it's hard to say a general rule of thumb, but it's recommended to keep it under 1000 rows at most.
- When searching in a Google spreadsheet, you can only specify a single column to search for. Please note that it is not possible to perform complex search conditions such as those performed in general databases.

If the above limitations are met, or if Google spreadsheets are functionally bogged down, we recommend using a full-fledged database such as Airtable or Firebase.

- Airtable (@<href>{https://airtable.com/})
- Firebase (@<href>{https://firebase.google.com/})

## Finally.

If you use a Google spreadsheet to read out the data, you can feel the atmosphere of a database at once. Of course, it is possible to register, update and delete the data in a spreadsheet. The details are summarized in the following site In addition to Google Spreadsheet integration, we also provide many other Voiceflow tips, so please take a look at them. @<br>{}

- Voiceflow Summer Holiday Advent Calendar@<br>{}
@<href>{https://qiita.com/kun432/items/666ae13f097004ea7935}

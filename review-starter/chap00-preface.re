= Preface

//blankline
//blankline

本書を手に取っていただき、ありがとうございます。@<br>{}
本書は、ノンコーディングで音声アプリケーションを作成できるサービス「Voiceflow」についてわかりやすく解説した本です。@<br>{}
AIやクラウドコンピューティングの進化により、音声アプリケーションは飛躍的に使いやすくなり身近なモノになりつつあります。
また、これからはあらゆる物が音声UIを備えると考えられ、音声UXの担う役割はますます重要になるでしょう。@<br>{}
この本には、Voiceflowを使った音声アプリケーションの作成手法や勘所などのエッセンスをはじめ、Voiceflowというツール自体の活用用途、家電操作、ゲームブック、外部クラウドサービスとの連携などの音声アプリケーションの可能性が詰まっており、まさに虎の巻といえるものになっています。@<br>{}
この本においては、エンジニアの方に読んでいただくのはもちろん光栄ですが、コーディングをしない全ての職業・職種の方、小中学生を含めた学生の方にも読んでいただき、音声UIの世界に一歩踏み入れるきっかけになれば幸いです。@<br>{}@<br>{}


===== Targets

 * People who are interested in Voice UI（老若男女、あらゆる職業・職種を問いません）
 * People who are interested in Voiceflow

===== Disclaimer @<br>{}

- The views and opinions expressed in this book are those of the authors and do not represent those of any entities such as agency, organizations, employee and company.
- Althogh the authors have made good faith efforts to ensure that the information and instructions contained in this book are accurate at press time, the authors disclaim all responsibility for any errors or omissions, or for the results obtained from the use of or reliance on this book. Use of the information and instructions contained in this book is completely at your own risk.
- If any code samples or other technology this work contains or describes is subject to open source licenses or the intellectual property rights of others, it is your responsibility to ensure that your use thereof complies with such licenses and/or rights.
- 
本書に記載されている情報は、２０２０年1月執筆時点のものです。サービスのバージョン、URLなどの仕様や情報は変動することがありますのでご了承ください。

//embed[latex]{
\clearpage
//}

=== Voiceflowチームより寄稿
Before we started Voiceflow, we were Alexa Skill creators working on an Alexa skill called Fable. The premise was a series of interactive children's stories with real voice actors, and a "choose your own adventure" format that would give the reader the ability to use their voice and control the narrative. At that time, we had all left school to work on the concept together. We felt voice technology was going to change the world and couldn't wait to be a part of the revolution. Working on Fable, we would stay up for days straight writing interactive children stories that would be played on Alexa. Every week we would write a new story, create the audio, print physical storybooks for the families to read alongside Alexa, then box-up the stories and devices and deliver them on our bikes every Friday afternoon.  

//numberlessimage[chap00-preface/voiceflow_01][The Fable team packaging up boxes of stories to be delivered][scale=0.5]

Fable became a popular Alexa skill in Canada. However, Alexa often misheard the families and heard "Bible" instead of "Fable". So, we changed the name of the skill to "Storyflow" which was named after our role model of a company, Webflow. We worked incredibly hard for 5 months, without any pay, to build an amazing stories platform on Alexa. Below is a flowchart we made for one of our interactive stories that would later serve as the inspiration for Voiceflow's flowchart design system.  

//numberlessimage[chap00-preface/voiceflow_02][Flowchart used to model out an interactive story on Storyflow]

Storyflow was becoming very popular and being used by over 5,000 families across the United States, Canada, and United Kingdom. It was so successful in fact that we were able to raise $500,000 of investment to start a real company around the concept. Our goal became to build the "YouTube of voice entertainment" - a place where anyone could create and share stories on Alexa.   

//numberlessimage[chap00-preface/voiceflow_03][The original Voiceflow office - a small rented dormitory room]

To achieve this vision, we needed to make it easier to create Alexa content. Writing code was too difficult, took too long, and existing visual building tools were not good enough. So, we decided to build our own tool to make it easier to create Alexa content that could then be shared on our entertainment platform, Storyflow.   

//numberlessimage[chap00-preface/voiceflow_04][The Voiceflow team showing off the first version of "Storyflow"]

The Storyflow "creator" platform was rudimentary, but worked well. It helped us build Storyflow stories at a very fast pace. Soon, we were starting to generate our first income from Alexa.

//numberlessimage[chap00-preface/voiceflow_05][Storyflow's first ever successful income]

We then opened Storyflow to other interactive story creators to add their content to the platform. We made Storyflow easy to use so that children's story writers, whom might not be technically savvy, could still use Storyflow to publish their stories. Within months, over 3,000 people were using Storyflow to create their own Alexa content. However, it wasn't just interactive stories - people were creating all kinds of amazing apps on Storyflow. It was then we realized that we had a much larger mission - to help everyone create amazing conversational experiences, regardless of their technical abilities.

//numberlessimage[chap00-preface/voiceflow_06][The Storyflow Alexa Skill, built on the Storyflow creator platform]

We changed our name to Voiceflow to reflect this new mission and focus. Since then, it's been 2 years of hard work, every day and night. In January 2020, Voiceflow supports over 23,000 creators across 30+ countries. In 2019, Voiceflow powered over 60,000,000 conversations across both Alexa and Google Assistant, and hosts 6,000+ voice apps. Further, the Voiceflow Community Group on Facebook now has over 5,500 active members and is growing rapidly every day.@<br>{}
We view Community as a core part of Voiceflow's product, not just an external service. Knowing that there are thousands of other creators just like you to learn, share, and socialize with is part of the Voiceflow product experience. This is why Communities like Voiceflow Japan and others are so important - they are a core part of Voiceflow. 

//numberlessimage[chap00-preface/voiceflow_07][Voiceflow India Meetup]

As Voiceflow grows, so will the product and role of community. Through 2020 we plan to make Voiceflow more international by adding additional language support, adding new channels like Siri and Bixby to create for, and further integrating the Voiceflow Community into the platform itself with the expansion of workspace and collaboration features.@<br>{}
None of this could be possible without the hard work of thousands of Voiceflow users, customers, and teammates who support the platform every day. Together, we'll build a platform that allows anyone to create conversational interfaces across every platform, not just voice platforms. To all of our early users, customers, partners, and supporters - thank you. We have so much more to accomplish together.

//numberlessimage[chap00-preface/voiceflow_08][Voiceflow team, December 2019][scale=0.9]

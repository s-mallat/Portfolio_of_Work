<h1>PCOMP | Final Project</h1>
<hr>

<h1>Project Concept</h1>

<p>To better explain the inspiration behind my project, I'd like to tell a short story about my journey with anxiety and panic attacks. For years I was overcome with bouts of panic attacks in silence and I remember desperately wishing back then for some way to make them instantly stop or to just go away. Back then, I would resort to my endless list of bookmarked web pages full of writings / breathing techniques / distraction exercises to make it go away.Mental health issues are still heavily stigmatized in many parts of the world and as such, many people out there are still afraid to seek help due to fear of being labelled "crazy" or "weak minded." After all, if there's nothing physically wrong with you, then you must be imagining things!
  <br><br>
Yes! A doctor said that to me once.
  <br><br>
Therefore, I wanted to create a device that helps people who find themselves often trapped in their own negative thoughts becoming spectators of the outer world while they remain bystanders stuck inside an invisible bubble. In other words, this device measures the user's stress levels and attempts to ground them (make the user focus on outside stimuli as a way to distract the them) and help them overcome high levels of agitation and stress.</p>
<br><hr><br>

<h1>Project Objectives</h1>

| Conceptual Objectives  | Technical Objectives |
| ------------- | ------------- |
| To create a device that helps alleviate high stress levels / agitation and panic attacks  | To design and create a device that integrates several inputs & outputs to reach a better understanding of Arduino, sensors, motors and so on  |
| To reduce the fear factor associated with panic attacks which plays a huge part in triggering them to begin with. This is done by showing people that panic attacks aren't really that scary once one learns how to control them using specific exercises | To develop a stronger familiarity with schematic drawings and how to move from a circuit diagram to physically building it and putting together  |
|  To normalize seeking mental health advice & having devices or games catered towards helping people overcome them in a similar fashion to how we have many devices that help with alleviate physical health conditions  | To create a complex interaction between different inputs and output put togethr through wiring and coding  |
| To shift the mental image of fear and distress that is associated with negative emotions. In other words, create a more colourful image using colourful LEDs and cool gadgets  | To transform a soldered circuit into an actual usable device by creating an appropiate housing for it and showing how the user can interact with the device  |

<br><hr><br>

<h1>Challenges</h1>

1. One of the biggest challenges I had in this project was moving from the regular Arduino Leonardo to the Arduino Nano. I remember freaking out when my circuit didn't work as I initially transferred it to the Nano board. I especially had an issue with the motor as it would not work at all with the Nano even though I had all my inputs and outputs powered using 3.3V on Leonardo just to make sure that they would work later on. The solution to this problem was to create a relay circuit and use a MOSFET transistor and a 9V battery to power the motor separately form the rest of the components in my circuit.

2. Another challenging aspect was soldering the circuit on a strip board. Since my project is a wearable device, I had to design my soldered circuit on a paper  before attempting to solder it. My circuit is a two level circuit with the Arduino, MPR, battery attached to one strip board and the motor, LEDs attached to another strip board which is placed on top. Then I had to add the GSR to the side vertically and extend the GSR electrodes outside the circuit so I can attach them elsewhere. The easiest way to create this circuit was to take a  picture of a strip board, print it and draw on it what I wanted to do. Then having multiple Grounds and Power rows so that the wires wouldn't be too condensed in one area on the strip board.

3. Last but not least, I think every part of this project has been challenging but extremely fun at the same time. As someone who started this semester with no prior knowledge of Arduino and C++ coding, I thoroughly enjoyed the process of creating this project. I've learned so many new things from soldering properly, to using a hot air gun, to becoming much more familiar with making circuits and using sensors and motors.  Somehow, it feels like I can create any device at this point!

<br><hr><br>

<h1>Future Possibilities</h1>

When I was putting the circuit together, I kept thinking about how cool it would be if at some point this device can go from a being bracelet to a full 
body immersive experience. I'm just imagining a device that can be worn around the body & once the user is stressed or agitated it would cover them with LED light patterns that respond to the GSR values being recorded. In a way, the user would become a walking art piece and that will most definitely distract the user from their worries as they will be too focused on looking at the device in the mirror and recording the patterns it creates.
<br>
To further elaborate on this point, it would also be fun to connect the device to a screen via bluetooth. This screen creates or plots colorful patterns using the GSR values. I'm thinking along the lines of something extremely colorful and fun to look at. For example, designs that are similar to GLSL fragment shaders.
Another direction I can think of is adding different distraction exercises to the device. For now, the  device uses LEDs as a slow breathing exercise for the user and the vibration motor to create a shock stimuli. However, I can easily invision this device with a sound element to it along with simple games. For example, creating a game where the user is required to touch different areas around their body to turn off the LEDs (similar to Whac-A-Mole arcade game but involving touch only)! This can easily be done using a capacitive touch library or even the MPR121 which is already being used in this project to control the vibration motor.

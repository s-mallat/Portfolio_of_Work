<h1> Lab 00 | Leds in Serial and Parallel </h1>
<hr>
<h4>1. How many leds can you hook up with a 220k resistor in serial before running out of voltage?</h4> 
<p>You can hook up two red LEDs in a series to a 220 Ohm resistor and they will both work. Adding more red LEDs will result in losing voltage through out the circuit and the LEDs will get dimmer and some of them will not work at all. Moreover, the number of LEDs used is also relevant to the color of the LEDs. In other words, red LEDs hold a forward voltage of approximately 1.8V, however, other LEDs have higher forward voltage and might require a different resistor value to light up. </p>

<h4>2. How many leds can you hook up with a 220k resistor in parallel before running out of voltage? </h4>
<p> Ideally, it's better to have a resistor for every LED placed in a circuit. The good thing about parallel circuits in general is that Voltage is the same through out. Therefore, the LEDs will not run out of voltage no matter how many of them are placed within a parallel circuit. </p>

<br>
<br>

<h1> Lab 01 | Serial Data </h1>
<hr>

<img width="726" alt="Screenshot 2021-10-12 at 8 09 42 pm" src="https://user-images.githubusercontent.com/92052904/137014939-d0b00364-ba73-4496-92d7-d52535fd5f7f.png">

<img width="843" alt="Screenshot 2021-10-12 at 8 10 11 pm" src="https://user-images.githubusercontent.com/92052904/137014949-ced1c388-39df-4dd7-affe-0d180361ec34.png">


<br>
<br>

<hr>
<h1> Lab 02 | Potentiometers (Knobs) </h1>
<hr>

![Powerful Vihelmo-Bigery](https://user-images.githubusercontent.com/92052904/136826382-80fab1ee-c22f-40f3-85ec-589eaec8c53a.png)


https://user-images.githubusercontent.com/92052904/136827864-d56af673-7ad6-4a88-9804-5aa165649830.mp4



<br>
<br>

<hr>
<h1> Lab 03 | Light Dependent Resistors </h1>
<hr>


![Surprising Kasi](https://user-images.githubusercontent.com/92052904/136822725-6d1202cd-d8fe-4956-a33d-1e6ea5caf0aa.png)
<p>^Figure 1.0. Tinercad circuit</p>



https://user-images.githubusercontent.com/92052904/136823225-4166c362-e230-41c7-aabb-7211e39a9d9a.mp4


<br>
<br>

<hr>
<h1> Lab 04 | Playing with Common Sensors </h1>
<hr>

<br>
<br>

<hr>
<h1> Lab 05 | Device from Scratch </h1>
<hr>
<p>For this lab, I chose the Ultrasonic sensor to create a device which helps me at home. In my accommodations, I have a large table placed directly in front of the sink area in the kitchen space. This table is not a part of the original room design and was left behind by the previous tenant and I somehow have a love/hate relationship with it. It's convenient because I don't have anywhere else to eat and at the same time, it blocks my path and I have to move it back and forth multiple times every single day. So, my idea for this device is to attach an ultrasonic sensor to one end of the table and as I move towards it, the sensor will detect the distance and the table will move away from the sink so I can use it. Later, when I move away from the sensor, the table will move back to it's original position. </p>

<p>Steps to create the device:</p>
<ol>
  <li>1. Use MDF boards to create the platform that the table will stand on.</li>
  <li>2. Attach wheels to each end of the board and connect them through wires. The wires will be connected to a servo motor which will allow the wheels to move when programmed into an arduino sketch.</li>
  <li>3. Set up the Ultrasonic sensor by connecting it to the Arduino and then attach it to the leg of the table.</li>
  <li>4. Connect the ultrasonic sensor and the servo objects through an if/else function.</li>
  <li>5. Any distance below 15 cm will allow the table wheels to move backwards away from the sink area and vice versa.</li>
  <li>6. Note: I'm not actually sure if this device is physically possible to create with a 5V power source.</li>
</ol>

![Untitled_Artwork 64](https://user-images.githubusercontent.com/92052904/137034233-1ffc47d3-2274-4466-beb7-e9eaef70f288.jpg)
<p>^ Sketch of the space. The yellow area shows a board with wheels for the table attached to the sensor on the upper leg of the table.</p>

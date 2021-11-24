<h1>Week 09 | Final Project Progress</h1>


https://user-images.githubusercontent.com/92052904/143033102-f8613893-3970-4784-8350-c74c55fb5860.mp4

<h2>Full Circuit on Arduino Nano 33 BLE Sense</h2>
<h4>The next step was to switch from the regular Arduino Leonardo board to the Arduino Nano board. This step wasvery challenging as many of the inputs and outputs stopped working since the Nano board produces less current than the Leonardo. However, in the end it worked and this isa video of how the entire circuit works. The next step would be to solder the circuit and start putting things together.</h4>

https://user-images.githubusercontent.com/92052904/143242705-8fb186e8-526c-45b2-8dad-d114166effa9.mp4

<h2>Relay Circuit & Power Supply</h2>
<h4>This video shows the way the circuit is powered. Since the Arduino Nano isn't strong enough to power the motorI used a 9V battery and connected it as relay using a MOSFET transistor. This way the 9V battery wouldn't damage the Arduino board and other elements that only work with 5V or 3.3V in this case. Therefore, the arduino itself along with the LEDs and MPR121 are powered through 3.3V power source and only the motor is powered through a separate 9V batter.</h4>

https://user-images.githubusercontent.com/92052904/143243859-4f877fef-ea5b-4612-8103-51109d41ab86.mp4



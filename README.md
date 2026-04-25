# ArduinoUno_BettingGame_1
This was my first project using a microcontroller, i took two days to build. The goal was the learn the basics of using the arduino like wiring, input &amp; output, components and coding. 

My project uses a joystick as input and a lcd and some leds as output.

Components:
- Arduino Uno
- Lcd display
- Joystick
- Leds

How it works:
The joystick sends a analog signal to the Arduino if greater then certain number then the betting amount goes op or down depending on the direction.
If the joystick is pressed it sends a signal to the Arduino who makes the Leds animated and then a random number is chosen and switches on a specific Led, that number is your winning/losing amount.
Then the Arduino calculates the number with the bet amount and adds that numerical value to totalmoney and then you go back to the start screen.

Images/Demo/Videos:

What i learned:
- Reading analog input
- Using Lcd
- Led control
- Basic wiring and circuit design

Challenges:
- Having not enough Gpio pins
- Wiring was a mess

Future improvements:
- better wiring (soldering & better planning)
- Unnecessary pin usage

Future plans:
- Custom PCB or protoboard

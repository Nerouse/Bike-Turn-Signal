# **Bike Turn Signal**

I would like to introduce my project, the bike turn signal. I have created a system that can
show riders behind you what direction you are trying to go. This system also includes a bright
led headlight and a bell system. Biking in the city at night can be dangerous and if you commute
with a bike it is important to stay safe when traveling. This system I created was designed to
keep riders safe by allowing other people to see where you are going. The turn signal allows cars
and other bike riders to see if you are turning or braking.

## **Project Description**

The main control of this design is the [Joystick](https://www.adafruit.com/product/512
). When the joystick is pressed down, it will
toggle the [led headlights](https://www.digikey.com/en/products/detail/cree-inc/XMLBWT-00-0000-000LT40E6/3770883?utm_adgroup=LED%20Lighting%20-%20White&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Optoelectronics&utm_term=&utm_content=LED%20Lighting%20-%20White&gclid=Cj0KCQiA2uH-BRCCARIsAEeef3kv4UThlnkv1I_XcKduJw-aB7YkIX0q2Ycm--xTO5zN7jF3h8I-M84aAmpgEALw_wcB). When the joystick is tilted forward, a bell will play; In this case “Take
on me” by A-Ha will play from a [peizo buzzer](https://www.adafruit.com/product/160
). When the joystick is tilted backwards, the [led panel](https://www.adafruit.com/product/3134
) will blink
repeatedly indicating that you are slowing down or stopping. And the left/right tilt will indicate
the direction you are turning. When you hold the stick to the left/right direction. A wave will
appear on the led Matrix going the direction that was inputted.This whole system is powered by [8-AA](https://www.digikey.com/en/product-highlight/m/mpd/covered-8-aa-battery-pack
) Batteries.
## ** Circuit Design**
![Circuit](/circuit)
## **Design Process**
When I first started working on the project, I had to test every part to make sure it was
working separately before I could put everything together. When I tested the joystick, I decided
to reference another project online so that I was able to use the Joystick controller. I stuck the
Vcc into the +5 Volt pin and the ground into the ground pin. I placed the x axis on the analog pin
A0 and Y axis on analog pin A1. I placed the select button on the digital output pin 2. The
reference code had a serial output setup so it was easy to see where my x and y values were.
Using this I determined that if X <= 0 and Y <= 0 then the joystick position is at neutral; X <= 0,
y = 512 joystick is tilted forward; x = 512, y < 0 joystick is tilted right; x = -512, y < 0 joystick
is tilted left; x < 0, y = -512 joystick is tilted down; SW_state = 0 means the select button has
been pressed. After this was figured out, all I had to do was to set up 5 if statements for the
following cases.
<br><br>
Working with the LED matrix was scary at first because there were so many pins that
were available but after reading and researching, I found out that you only need to use 4 pins.
The board has a matrix driver chip installed (IS31FL3731) and that is what takes care of the
multiplexing. The 15 x 7 Charlieplex Led Matrix only requires 3 Volts so I was able to plug it
directly into the 3.3 Volt pin. The only difference between 3.3 volt and 3 volt were the brightness
but it didn't affect the brightness that much so I ignored it. All LED control is done over 12C
using the IS31FL3731 library so this only uses the SDA and SCL pins to display the patterns.
Since I also used a library for the LED matrix, there were some preloaded examples already
provided. I really liked the wave pattern so I decided to display that state when the joystick was
neutral. After that I wanted to show the direction that joystick was pointing. My original plan
was to display an arrow to indicate the direction but I had some difficulty creating the arrow so I
decided to use a scanning wave motion instead. I created this by lighting random LEDS until I
knew which led pin correlated with the position and I created the wave effect. I used a for loop
and the function ledmatrix.drawPixel() to choose which led to light up. After this was done, I
wanted to show if the user was braking so I decided to show this with flashes when the down tilt
was selected.
<br><br>
When I was working with the buzzer, I came across some problems. When I was
purchasing speakers, I was afraid that the speakers that I was looking at was not going to produce
a loud enough sound. When I decided to go with the piezo buzzer, I bought 2 to make sure that
they were going to be loud. After working with the buzzers, I found out that a PN2222 transistor
was able to amplify the sound but not as much as I needed. After searching for more solutions, I
came across the ToneAC library which allowed me to amplify the sound using alternating
currents. When you use the normal tone library, you are only using 50% of the duty cycle
making it sound like you are only supplying 2.5 volts to the speaker. By using the PWM pins 9
and 10 we are able to make the sound twice as loud making it sound like we are directly
supplying 5 volts to the speaker. I needed to figure out what sound I wanted my bell to be. I
decided on the song “Take on me” by A-Ha to be my bell sound. I did this by referencing
someone else code. They had already made a version of Take on me on the normal Tone library.
I rewrote the code so that it would run with ToneAC. Another problem I ran into was the
Pitches.h file. The reference code did not provide a pitches.h file so I had to search for one. The
Pitches.h file was just a mapping of notes to a value so that we can access that note easily.
Working with the White LED was simple. Because this was a high power LED, that
might have needed a heatsink, I soldered two wires onto the LED and covered the back with
epoxy so that the wires were secure. The LED was already very bright with just the supplied 5
volts so I did not need to connect it to another power supply.
<br><br>
After everything was coded and working, it was time to put everything together. Because
of COVID-19, I had to relocate and I did not have a lot of material to work with building the
housing for the system. I decided to use a plastic candy container to hold the LED matrix and a
square tupperware to hold the joystick, arduino, speaker and light. I repurposed an old bike
phone mount to hold the housing for the arduino. The LED matrix is connected to the arduino
with a long wire that runs along the top tube of the bike. Because I ran out of material, I couldn’t
find a proper housing for the battery but if I did have the material, I would have placed it in a
plastic box and secured it under the top tube of the bike.
When I look back and compare what I had originally planned, there were not many
deviations I have made; The changes I have made were mostly minor. I originally planned to
have the buzzer play with the select button but because of how the joystick was mounted, I
thought users would have an easier time using the forward tilt to sound a bell rather than using
the select button. Another deviation I had was the bell system. When I first purchased the piezo
buzzer, the volume was too low; To solve this I decided to get two buzzers. But even plugging in
2 buzzers wasn’t loud enough so I found the ToneAC library which allowed me to connect the
buzzer to 2 digital output pins and it made the buzzer significantly louder. The main deviations I
had were mostly the design; Because of COVID, I was not able to make my project look nicer. I
used plastic containers to hold my components in but they are a bit bulky. If I had more material
and time I would have cut the plastic to the correct size making the project look better. When I
was working with cutting the plastic to size, the containers kept on cracking and I wasn’t able to
get a water tight container.
<br><br>
Some improvements that could have been done mostly apply to the design aspect of the
project. If I were to rebuild this project, I would have had a smaller box to house the joystick,
buzzer, and light. I would place the arduino with the power supply in another container and
secure it between the top and bottom tubes of the bike. I also would have liked to make a smaller
housing for the LED matrix and if I added a light diffuser, the LED matrix would be easier to
look at. Currently, this system is not waterproof or water resistant but with a few additions it
could be water resistant.
<br><br>

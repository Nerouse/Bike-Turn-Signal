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
## **Circuit Design**
![Circuit](/BikeTurnSignal.png)
## **Design Process**
[Design Process](/DesignProcess.md)
## **Parts List & Sources**
[ARUDINO UNO](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_4?dchild=1&keywords=arduino+uno&qid=1608048137&sr=8-4)
<br>
[WHITE LED](https://www.digikey.com/en/products/detail/cree-inc/XMLBWT-00-0000-000LT40E6/3770883?utm_adgroup=LED%20Lighting%20-%20White&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Optoelectronics&utm_term=&utm_content=LED%20Lighting%20-%20White&gclid=Cj0KCQiA2uH-BRCCARIsAEeef3kv4UThlnkv1I_XcKduJw-aB7YkIX0q2Ycm--xTO5zN7jF3h8I-M84aAmpgEALw_wcB)
<br>
[JOYSTICK](https://www.adafruit.com/product/512)
<br>
[15x7 CHARLIEPLEX LED MATRIX DISPLAY](https://www.adafruit.com/product/3134)
<br>
[PIEZO BUZZER - PS1240](https://www.adafruit.com/product/160)
<br>
[8-AA BATTERY HOLDER](https://www.digikey.com/en/product-highlight/m/mpd/covered-8-aa-battery-pack)
<br>
<br>
[Take On Me Source Code](https://create.arduino.cc/projecthub/GeneralSpud/passive-buzzer-song-take-on-me-by-a-ha-0f04a8)
<br>
[Pitches.h Source Code](https://gist.github.com/mikeputnam/2820675)
<br>
[Joystick Source Code](https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0)
<br>







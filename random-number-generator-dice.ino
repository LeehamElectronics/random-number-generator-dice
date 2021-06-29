/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                     PLEASE READ THE FOLLOWING!                                    *
 * This open source software was written by Liam Price 2019 and is FREE to use...                    *
 * The purpose of this software is to compile and run on an Arduino based IoT device, like an ESP32  *
 *                                                                                                   *
 * This is used to control an electronic 3D printed die that I built for my VET Integrated           *
 * Technologies class in Year 11 2019. It is very simple, all you do is tap on the die and it will   *
 * detect the vibrations and display a random number with LED's. I am planning on using a Espressif  *
 * WiFi chip with WifiManager to create an easy way to modify the die through your phone. This is    *
 * basically cheating because you can turn it into a 'weighted' die and use it for your advantage    *
 * because I am a good person.                                                                       *
 * https://github.com/random-number-generator-dice                                                   *
 *                                                                                                   *
 * If you'd like to support my open source work, buy me a coffee:                                    *
 * https://www.paypal.com/paypalme/liamproice/                                                       *
 *                                                                                                   *
 * And if you need help, feel free to email me at liamisprice@gmail.com                              *
 * Thanks!                                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

 /*
 ██╗░░░░░███████╗███████╗██╗░░██╗░█████╗░███╗░░░███╗██╗░██████╗      ░██████╗░█████╗░███████╗████████╗░██╗░░░░░░░██╗░█████╗░██████╗░███████╗
 ██║░░░░░██╔════╝██╔════╝██║░░██║██╔══██╗████╗░████║╚█║██╔════╝      ██╔════╝██╔══██╗██╔════╝╚══██╔══╝░██║░░██╗░░██║██╔══██╗██╔══██╗██╔════╝
 ██║░░░░░█████╗░░█████╗░░███████║███████║██╔████╔██║░╚╝╚█████╗░      ╚█████╗░██║░░██║█████╗░░░░░██║░░░░╚██╗████╗██╔╝███████║██████╔╝█████╗░░
 ██║░░░░░██╔══╝░░██╔══╝░░██╔══██║██╔══██║██║╚██╔╝██║░░░░╚═══██╗      ░╚═══██╗██║░░██║██╔══╝░░░░░██║░░░░░████╔═████║░██╔══██║██╔══██╗██╔══╝░░
 ███████╗███████╗███████╗██║░░██║██║░░██║██║░╚═╝░██║░░░██████╔╝      ██████╔╝╚█████╔╝██║░░░░░░░░██║░░░░░╚██╔╝░╚██╔╝░██║░░██║██║░░██║███████╗
 ╚══════╝╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░░╚═════╝░     ╚═════╝░░╚════╝░╚═╝░░░░░░░░╚═╝░░░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝
 */

/* 
* This program will run on arduino nano and will detect a bump from a sound sensor which will trigger a random
* rumber event and display a number by turning digital inputs on and powering LED in an array to represent a dice.
 */
//setup constants
int pinLeds1 = 8;
int pinLeds2 = 9;
int pinLeds3 = 7;
int pinLed4 = 10;
int microphone = A0; //input for microphone (roll detector)
long ran;
int time = 2000;

void setup()
{
    Serial.begin(9600); //serial input for diognostic
    //setup inputs and outputs
    Serial.println("system up and running"); // 
    randomSeed(analogRead(0)); //for random number generator 
    pinMode(microphone, INPUT); //for bump detector (aka sound sensor)
    pinMode(pinLeds1, OUTPUT); //display 1 LED
    pinMode(pinLeds2, OUTPUT); // display 2 LED's
    pinMode(pinLeds3, OUTPUT); //display 2 LED's
    pinMode(pinLed4, OUTPUT); //display 2 LED's

    /*
    Example of display output: (the numbers on the example represent the pinLed1 / pinLed2 / pinLed3 / pinLed4)

    1         2

    3    4    3

    2         1

    */
}

void loop()
{
    if (digitalRead(microphone)) {
        Serial.println("microphone sound detected"); // so I can keep track
        void rollAnimation();
        ran = random(1, 7);
        if (ran == 1) {
            Serial.println("Rolled a 1");
            digitalWrite(pinLed4, HIGH);
            delay(time);
        }
        if (ran == 2) {
            Serial.println("Rolled a 2");
            digitalWrite(pinLeds2, HIGH);
            delay(time);
        }
        if (ran == 3) {
            Serial.println("Rolled a 3");
            digitalWrite(pinLeds2, HIGH);
            digitalWrite(pinLed4, HIGH);
            delay(time);
        }
        if (ran == 4) {
            Serial.println("Rolled a 4");
            digitalWrite(pinLeds1, HIGH);
            digitalWrite(pinLeds2, HIGH);
            delay(time);
        }
        if (ran == 5) {
            Serial.println("Rolled a 5");
            digitalWrite(pinLeds1, HIGH);
            digitalWrite(pinLeds2, HIGH);
            digitalWrite(pinLed4, HIGH);
            delay(time);
        }
        if (ran == 6) {
            Serial.println("Rolled a 6");
            digitalWrite(pinLeds1, HIGH);
            digitalWrite(pinLeds2, HIGH);
            digitalWrite(pinLeds3, HIGH);
            delay(time);
        }
    }
    Serial.println("finished roll go back to 0");
    digitalWrite(pinLeds1, LOW);
    digitalWrite(pinLeds2, LOW);
    digitalWrite(pinLeds3, LOW);
    digitalWrite(pinLed4, LOW);
}


void rollAnimation()
{
    Serial.println("running roll animation");
    digitalWrite(pinLeds1, HIGH);
    delay(100);
    digitalWrite(pinLeds1, LOW);
    digitalWrite(pinLeds2, HIGH);
    delay(100);
    digitalWrite(pinLeds2, LOW);
    digitalWrite(pinLeds3, HIGH);
    delay(100);
    digitalWrite(pinLeds3, LOW);
    digitalWrite(pinLed4, HIGH);
    delay(100);
    digitalWrite(pinLed4, LOW);
    Serial.println("finished roll animation");
}


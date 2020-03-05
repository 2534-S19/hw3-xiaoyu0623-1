/*
 * GPIO.c
 *
 *  Created on: 3/2/2020
 *      Author: Xiaoyu Hou
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

//Define the buttons for launch pad
#define LAUNCHPAD_S1 BIT1
#define LAUNCHPAD_S2 BIT4

//Define the buttons for booster pack
#define BOOSTERPACK_S1 BIT1
#define BOOSTERPACK_S2 BIT5

//Define the LEDs for launch pad
#define LAUNCHPAD_LED1 BIT0
#define LAUNCHPAD_RED BIT0
#define LAUNCHPAD_GREEN BIT1
#define LAUNCHPAD_BLUE BIT2

//Define the LED for booster pack
#define BOOSTERPACK_RED BIT6
#define BOOSTERPACK_GRN BIT4
#define BOOSTERPACK_BLU BIT6


// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR = P1DIR & ~LAUNCHPAD_S1;
    P1REN = P1REN | LAUNCHPAD_S1;
    P1OUT = P1OUT | LAUNCHPAD_S1;

    // Launchpad S2
    P1DIR = P1DIR & ~LAUNCHPAD_S2;
    P1REN = P1REN | LAUNCHPAD_S2;
    P1OUT = P1OUT | LAUNCHPAD_S2;

    // Boosterpack S1
    P5DIR = P5DIR & ~BOOSTERPACK_S1;
    P5REN = P5REN | BOOSTERPACK_S1;
    P5OUT = P5OUT | BOOSTERPACK_S1;

    // Boosterpack S2
    P3DIR = P3DIR & ~BOOSTERPACK_S2;
    P3REN = P3REN | BOOSTERPACK_S2;
    P3OUT = P3OUT | BOOSTERPACK_S2;

    // Launchpad LED1
    P1DIR = P1DIR | LAUNCHPAD_LED1;

    // Launchpad LED2 Red
    P2DIR = P2DIR | LAUNCHPAD_RED;

    // Launchpad LED2 Green
    P2DIR = P2DIR | LAUNCHPAD_GREEN;

    // Launchpad LED2 Blue
    P2DIR = P2DIR | LAUNCHPAD_BLUE;

    // Boosterpack LED Red
    P2DIR = P2DIR | BOOSTERPACK_RED;

    // Boosterpack LED Green
    P2DIR = P2DIR | BOOSTERPACK_GRN;

    // Boosterpack LED Blue
    P5DIR = P5DIR | BOOSTERPACK_BLU;

    // Turn off all LEDs at the start.
    P1OUT= P1OUT & ~LAUNCHPAD_LED1;
    P2OUT = P2OUT & ~LAUNCHPAD_RED;
    P2OUT = P2OUT & ~LAUNCHPAD_GREEN;
    P2OUT = P2OUT & ~LAUNCHPAD_BLUE;
    P2OUT = P2OUT & ~BOOSTERPACK_RED;
    P2OUT = P2OUT & ~BOOSTERPACK_GRN;
    P5OUT = P5OUT & ~BOOSTERPACK_BLU;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_S1) == LAUNCHPAD_S1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_S1) == LAUNCHPAD_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTERPACK_S1) == BOOSTERPACK_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTERPACK_S2) == BOOSTERPACK_S2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LAUNCHPAD_LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT= P1OUT & ~LAUNCHPAD_LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LAUNCHPAD_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LAUNCHPAD_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LAUNCHPAD_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LAUNCHPAD_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LAUNCHPAD_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LAUNCHPAD_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BOOSTERPACK_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BOOSTERPACK_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BOOSTERPACK_GRN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BOOSTERPACK_GRN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BOOSTERPACK_BLU;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BOOSTERPACK_BLU;
}

void turnOff_all()
{
    P1OUT= P1OUT & ~LAUNCHPAD_LED1;
    P2OUT = P2OUT & ~LAUNCHPAD_RED;
    P2OUT = P2OUT & ~LAUNCHPAD_GREEN;
    P2OUT = P2OUT & ~LAUNCHPAD_BLUE;
    P2OUT = P2OUT & ~BOOSTERPACK_RED;
    P2OUT = P2OUT & ~BOOSTERPACK_GRN;
    P5OUT = P5OUT & ~BOOSTERPACK_BLU;
}

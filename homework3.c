#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

#define PRESSED 0
typedef enum {UP,DOWN} debounce_state;
int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;
    unsigned char history;
    bool pushbutton;
    // TODO: Declare the variables that main uses to interact with your state machine.


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0 = count0 + 1;
        }
        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
            history = checkStatus_BoosterpackS1();
        }
        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        pushbutton = fsmBoosterpackButtonS1(history);

        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(pushbutton == true)
        {
            count1 = count1 +1;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    int check_count = count % 7;
    if(check_count == 0)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Red();
    }
    else if(check_count == 1)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Green();
    }
    else if(check_count == 2)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
    }
    else if(check_count == 3)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Blue();
    }
    else if(check_count == 4)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Blue();
    }
    else if(check_count == 5)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
    }
    else if(check_count == 6)
    {
        turnOff_all();
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    int check_count = count % 8;
        if(check_count == 0)
        {
            turnOff_all();
        }
        else if(check_count == 1)
        {
            turnOff_all();
            turnOn_BoosterpackLEDRed();
        }
        else if(check_count == 2)
        {
            turnOff_all();
            turnOn_BoosterpackLEDGreen();
        }
        else if(check_count == 3)
        {
            turnOff_all();
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
        }
        else if(check_count == 4)
        {
            turnOff_all();
            turnOn_BoosterpackLEDBlue();
        }
        else if(check_count == 5)
        {
            turnOff_all();
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDBlue();
        }
        else if(check_count == 6)
        {
            turnOff_all();
            turnOn_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDGreen();
        }
        else if(check_count == 7)
        {
            turnOff_all();
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDGreen();
        }

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;
    static debounce_state current_state = UP;

    switch (current_state)
    {
    case UP:
        if(buttonhistory == 1)
        {
            current_state = DOWN;
            pressed = true;
        }
        break;
    case DOWN:
        if(buttonhistory != 1)
        {
            current_state = UP;
            pressed = false;
        }
        break;
    }
    return pressed;
}



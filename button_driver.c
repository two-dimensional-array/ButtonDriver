#include "button_driver.h"

void ButtonHandlerReset(button_hanler_t* pHandler)
{
    pHandler->state = false;
    pHandler->counter = BUTTON_DRIVER_COUNTER_MIN_VAL;
    pHandler->event = NULL;
}

void ButtonHandler(button_hanler_t* pHandlers, size_t buttonCount)
{
    for (size_t i = 0; i < buttonCount; i++)
    {
        if (pHandlers[i].event == NULL)
        {
            continue;
        }

        if (BUTTON_DRIVER_HW_READ(&pHandlers[i].hw))
        {
            if (pHandlers[i].counter < BUTTON_DRIVER_COUNTER_MAX_VAL)
            {
                ++pHandlers[i].counter;
            }
        }
        else
        {
            if (pHandlers[i].counter > BUTTON_DRIVER_COUNTER_MIN_VAL)
            {
                --pHandlers[i].counter;
            }
        }

        if (pHandlers[i].counter > BUTTON_DRIVER_COUNTER_PRESSED_VAL)
        {
            if (pHandlers[i].state == false)
            {
                pHandlers[i].state = true;
                pHandlers[i].event(pHandlers[i].state);
            }
        }
        else if (pHandlers[i].counter < BUTTON_DRIVER_COUNTER_RELEASED_VAL)
        {
            if (pHandlers[i].state == true)
            {
                pHandlers[i].state = false;
                pHandlers[i].event(pHandlers[i].state);
            }
        }
    }
}

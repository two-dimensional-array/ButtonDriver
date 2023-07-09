#include <gpio.hpp>
#include "button_driver.h"
#include "button_driver_config.h"

void ButtonHandlerReset(button_hanler_t* pHandler)
{
    pHandler->state = false;
    pHandler->counter = BUTTON_DRIVER_COUNTER_MIN_VAL;
#ifndef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
    pHandler->event = NULL;
#endif
}

void ButtonHandler(button_hanler_t* pHandlers, size_t buttonCount)
{
    for (size_t i = 0; i < buttonCount; i++)
    {
#ifndef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
        if (pHandlers[i].event == NULL)
        {
            continue;
        }
#endif
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
#ifndef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
                pHandlers[i].event(pHandlers[i].state);
#else
                ButtonEventHanler(i, pHandlers[i].state);
#endif
            }
        }
        else if (pHandlers[i].counter < BUTTON_DRIVER_COUNTER_RELEASED_VAL)
        {
            if (pHandlers[i].state == true)
            {
            	pHandlers[i].state = false;
#ifndef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
                pHandlers[i].event(pHandlers[i].state);
#else
                ButtonEventHanler(i, pHandlers[i].state);
#endif
            }
        }
    }
}

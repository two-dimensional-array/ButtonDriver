#ifndef __BUTTON_DRIVER_H__
#define __BUTTON_DRIVER_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "button_driver_config.h"

typedef BUTTON_DRIVER_HW_TYPE button_hw_t;
typedef bool button_state_t;
typedef BUTTON_DRIVER_COUNTER_TYPE button_counter_t;
typedef void (*button_event_t)(bool);

struct SButtonHandler
{
    button_hw_t hw;
    button_state_t state;
    button_counter_t counter;
    button_event_t event;
};

typedef struct SButtonHandler button_hanler_t;

#ifndef BUTTON_DRIVER_HW_READ
bool ButtonRead(button_hw_t* pButtonHW); // need write definition
#define BUTTON_DRIVER_HW_READ(pHW) (ButtonRead(pHW))
#endif

void ButtonHandlerReset(button_hanler_t* pHandler);
void ButtonHandler(button_hanler_t* pHandlers, size_t buttonCount);

#endif // __BUTTON_DRIVER_H__

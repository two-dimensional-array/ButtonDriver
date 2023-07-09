#ifndef __BUTTON_DRIVER_H__
#define __BUTTON_DRIVER_H__

#ifdef __cplusplus
extern "C" {
#endif

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
#ifndef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
    button_event_t event;
#endif
};

typedef struct SButtonHandler button_hanler_t;

#ifndef BUTTON_DRIVER_HW_READ
bool ButtonRead(button_hw_t* pButtonHW); // need write definition
#define BUTTON_DRIVER_HW_READ(pHW) (ButtonRead(pHW))
#endif

#ifdef BUTTON_DRIVER_USE_CUSTOM_EVENT_HANDLER
void ButtonEventHanler(size_t idx, bool state); // need write definition
#endif

void ButtonHandlerReset(button_hanler_t* pHandler);
void ButtonHandler(button_hanler_t* pHandlers, size_t buttonCount);

#ifdef __cplusplus
}
#endif // extern "C"

#endif // __BUTTON_DRIVER_H__

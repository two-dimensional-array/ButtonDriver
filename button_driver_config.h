#ifndef __BUTTON_DRIVER_CONFIG_H__
#define __BUTTON_DRIVER_CONFIG_H__

// place for include button hw header
// example #include <gpio.h>

// place for include button counter type header
#include <stdint.h>

#define BUTTON_DRIVER_HW_TYPE SGPIO
//example #define BUTTON_DRIVER_HW_READ(pHW) (GPIORead(pHW)) // bool BUTTON_DRIVER_HW_READ(BUTTON_DRIVER_HW_TYPE* pHW)

#define BUTTON_DRIVER_COUNTER_TYPE         uint32_t
#define BUTTON_DRIVER_COUNTER_MAX_VAL      100
#define BUTTON_DRIVER_COUNTER_MIN_VAL      10
#define BUTTON_DRIVER_COUNTER_PRESSED_VAL  90
#define BUTTON_DRIVER_COUNTER_RELEASED_VAL 20

#endif // __BUTTON_DRIVER_CONFIG_H__

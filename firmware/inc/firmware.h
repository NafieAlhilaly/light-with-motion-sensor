#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/vector.h>
#include <libopencm3/stm32/rcc.h>

// States
#define DETECTING 0
#define LIGHT_ON 1
#define LIGHT_OFF 2


#define SENSOR_PIN_ID GPIO0
#define MOTION_SENSOR_PIN_ID GPIO9
#define RELAY_PIN GPIO7



void change_state(uint8_t new_state);
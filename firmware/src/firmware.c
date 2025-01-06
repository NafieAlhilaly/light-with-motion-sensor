#include "firmware.h"

int main(void)
{
  rcc_clock_setup_pll(&rcc_hsi16_configs[RCC_CLOCK_VRANGE1_80MHZ]);
  rcc_periph_clock_enable(RCC_GPIOA);
  gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, RELAY_PIN);
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, SENSOR_PIN_ID);
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, MOTION_SENSOR_PIN_ID);
  gpio_clear(GPIOA, RELAY_PIN);

  while (1)
  {
    if (gpio_get(GPIOA, MOTION_SENSOR_PIN_ID) > 0)
    {
      gpio_clear(GPIOA, RELAY_PIN);
    }
    else
    {
      gpio_set(GPIOA, RELAY_PIN);
    }
  }
  return 0;
}
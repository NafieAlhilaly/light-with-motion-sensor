#include "firmware.h"

static volatile uint64_t ticks = 0;
static volatile state = 0;

void sys_tick_handler(void)
{
  ticks++;
}

static void systick_setup(void)
{
  systick_set_frequency(SYSTICK_FREQ, CPU_FREQ);
  systick_counter_enable();
  systick_interrupt_enable();
}

uint64_t get_ticks(void)
{
  return ticks;
}

void delay_ms(uint64_t milleseconds)
{
  uint64_t end_time = get_ticks() + milleseconds;
  while (get_ticks() < end_time)
    ;
}

void light_on()
{
  gpio_clear(GPIOA, RELAY_PIN);
}

void light_off()
{
  gpio_set(GPIOA, RELAY_PIN);
}

void clock_setup()
{
  rcc_clock_setup_pll(&rcc_hsi16_configs[RCC_CLOCK_VRANGE1_80MHZ]);
  rcc_periph_clock_enable(RCC_GPIOA);
}
void gpio_setup()
{
  gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, RELAY_PIN);
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, SENSOR_PIN_ID);
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, MOTION_SENSOR_PIN_ID);
}

void change_state(uint8_t new_state)
{
  state = new_state;
}
int main(void)
{
  clock_setup();
  gpio_setup();
  light_off();
  systick_setup();
  while (1)
  {
    switch (state)
    {
    case LIGHT_ON:
      light_on();
      delay_ms(5000);
      change_state(2);
      break;
    case LIGHT_OFF:
      light_off();
      delay_ms(2000);
      change_state(0);
      break;
    case DETECTING:
      while (gpio_get(GPIOA, MOTION_SENSOR_PIN_ID) == 0)
        ;
      change_state(1);
      break;
    }
  }
  return 0;
}
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

constexpr uint16_t LEDS{GPIO9|GPIO13};
void setup_LEDS () {
    rcc_periph_clock_enable(RCC_GPIOE);

gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO8 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO9 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO12 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO13 )
}
void setup_timer () {
    rcc_periph_clock_enable(RCC_TIM6);
    timer_set_prescaler(TIM6, 32000-1);
timer_set_period(TIM6,1000-1 );
timer_enable_counter(TIM6);

}
void blink_LEDS () {
if (timer_get_counter(TIM6)<500)
gpio_set(GPIOE,LEDS);
else
gpio_clear(GPIOE,LEDS);
    
}

int main () {
rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
setup_LEDS();
setup_timer();
blink_LEDS();
    while (true) { 

// gpio_set(GPIOE, GPIO9 | GPIO13 );
// for(volatile uint32_t i=0;i<500'000; ++i);
// gpio_clear(GPIOE,GPIO9 | GPIO13 );
// gpio_set(GPIOE, GPIO8|GPIO12 );
// for(volatile uint32_t i=0;i<500'000; ++i);
// gpio_clear(GPIOE,GPIO8 |GPIO12 );
  
   }
}

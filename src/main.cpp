#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>



constexpr uint16_t LEDS{GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13};
int main () {
    // nastroika taktovoi podsistemi

    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

    // nastroika na SID
    rcc_periph_clock_enable(RCC_GPIOE);
    
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9);
    // nastroika timera

    rcc_periph_clock_enable(RCC_TIM6);

    timer_set_prescaler(TIM6, 32000 - 1);

    timer_set_period(TIM6, 1000 - 1);

    timer_enable_counter(TIM6);

    while (true) {

       if (timer_get_counter(TIM6) < 500)
          gpio_set(GPIOE, LEDS);
       else
          gpio_clear(GPIOE, LEDS);
      
    //     gpio_toggle(GPIOE, GPIO9);
    //    for (volatile uint32_t i = 0; i < 500000; ++i);
    //    gpio_toggle(GPIOE, GPIO10);
    //    for (volatile uint32_t i = 0; i < 500000; ++i);
    //    gpio_toggle(GPIOE, GPIO11);
    //    for (volatile uint32_t i = 0; i < 500000; ++i);
    //    gpio_toggle(GPIOE, GPIO12);
    //    for (volatile uint32_t i = 0; i < 500000; ++i);
    //    gpio_toggle(GPIOE, GPIO13);
    //    for (volatile uint32_t i = 0; i < 500000; ++i);

    }
}
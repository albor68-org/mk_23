#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main () {
rcc_periph_clock_enable(RCC_GPIOE);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO8);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO9);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO10);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO11);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO12);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO13);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO14);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,GPIO15);

    while (true) {


       gpio_toggle(GPIOE, GPIO8);
       for(volatile uint32_t i=0;i<100'000;++i);
       gpio_toggle(GPIOE, GPIO9);
       for(volatile uint32_t i=0;i<150'000;++i);
       gpio_toggle(GPIOE, GPIO10);
       for(volatile uint32_t i=0;i<200'000;++i);
       gpio_toggle(GPIOE, GPIO11);
       for(volatile uint32_t i=0;i<250'000;++i);
       gpio_toggle(GPIOE, GPIO12);
       for(volatile uint32_t i=0;i<300'000;++i);
       gpio_toggle(GPIOE, GPIO13);
       for(volatile uint32_t i=0;i<350'000;++i);
       gpio_toggle(GPIOE, GPIO14);
       for(volatile uint32_t i=0;i<400'000;++i);
       gpio_toggle(GPIOE, GPIO15);
       for(volatile uint32_t i=0;i<450'000;++i);

    }
}
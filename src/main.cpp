#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main () {

    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO12);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO13);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10 | GPIO14);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11 | GPIO15);

    while (true) {

        gpio_toggle(GPIOE, GPIO8 | GPIO12);
        for(volatile uint32_t i = 0; i < 200'000; i++);
        gpio_toggle(GPIOE, GPIO9 | GPIO13);
        for(volatile uint32_t i = 0; i < 200'000; i++);
        gpio_toggle(GPIOE, GPIO10 | GPIO14);
        for(volatile uint32_t i = 0; i < 200'000; i++);
        gpio_toggle(GPIOE, GPIO11 | GPIO15);
        for(volatile uint32_t i = 0; i < 200'000; i++);

    }
}
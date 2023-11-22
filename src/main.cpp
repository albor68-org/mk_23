#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main () {
    rcc_clock_setup_pll(
        &rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]
    );

    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);

    while (true) {
        gpio_toggle(GPIOE, GPIO8 | GPIO12);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO9 | GPIO13);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO10 | GPIO14);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO11 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);

        gpio_toggle(GPIOE, GPIO11 | GPIO15);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO10 | GPIO14);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO9 | GPIO13);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO12);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);

        gpio_toggle(GPIOE, GPIO8);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO9);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO10);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO11);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO12);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO13);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO14);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);

        gpio_toggle(GPIOE, GPIO15);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO14);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO13);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO12);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO11);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO10);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO9);
        for(volatile uint32_t i = 0; i < 50'000*8; i++);
        gpio_toggle(GPIOE, GPIO8);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);

        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 300'000*8; i++);
        gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for(volatile uint32_t i = 0; i < 1000'000*8; i++);
    }
}
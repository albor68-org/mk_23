#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

constexpr uint16_t LEDS{GPIO9 | GPIO13};

int main () {
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10 | GPIO14);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11 | GPIO15);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12 | GPIO8);

    while (true) {
        gpio_toggle(GPIOE, LEDS);
        for (volatile uint32_t i=0; i < 100'000; i++);
        gpio_toggle(GPIOE, GPIO10 | GPIO14);
        for (volatile uint32_t i=0; i < 100'000; i++);
        gpio_toggle(GPIOE, GPIO11 | GPIO15);
        for (volatile uint32_t i=0; i < 100'000; i++);
        gpio_toggle(GPIOE, GPIO12 | GPIO8);
        for (volatile uint32_t i=0; i < 100'000; i++);
    }
}
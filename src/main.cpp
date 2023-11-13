#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

constexpr uint16_t LEDS{GPIO9 | GPIO13};

int main () {

    rcc_periph_clock_enable(RCC_GPIOE);

    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,
                    GPIO_PUPD_NONE, LEDS);

    while (true) {

        gpio_toggle(GPIOE, LEDS);
        for (volatile uint32_t i = 0; i < 500'000; ++i);
    
    }
}

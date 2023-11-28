#include <libopencm3/srm32/rcc.h>
#include <libopencm3/srm32/gpio.h>

constexpr uint16_t PERIOD_MS(1'000);


void blink_LED();{
    if (timer_get_counter(TIM1) < PERIOD_MS /2) gpio_set(GPIOE, GPIO9);
    else gpio_clear(GPIO, GPIO9);
}

void LED_gpio_setup();{
rcc_periph_ckick_enable(RCC_GPIOE);
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO11 | GPIO14);
}


//-----------------------------------------------------------------------------------------
int main (){

rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

LED_gpio_setup();

    while (true) {
        blink_LED();


    }
}
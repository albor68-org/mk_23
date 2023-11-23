#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

constexpr uint16_t LEDS{GPIO10 | GPIO14};

constexpr uint16_t PERIOD_MS{1000};

void setup_LEDS () {
    //Настройка для сид
   rcc_periph_clock_enable(RCC_GPIOE);
   gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
}

void setup_timer () {
    //"Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    //Настройка делителя
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6) / PERIOD_MS - 1);
    //Указание предела счета
    timer_set_period(TIM6, PERIOD_MS - 1);
    //Запуск таймера
    timer_enable_counter(TIM6);
}

void blink_LEDS () {
        if (timer_get_counter(TIM6) < PERIOD_MS / 2)
            gpio_set(GPIOE, LEDS);
        else
            gpio_clear(GPIOE, LEDS);
}

int main () {
    //Настройка тактовой подсистемы
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

    setup_LEDS();
    setup_timer();

    while (true) {
        blink_LEDS(); 
    }
}
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
constexpr uint16_t LEDS{GPIO9 | GPIO12 | GPIO11 | GPIO10 | GPIO13 | GPIO14 | GPIO15 | GPIO8};
constexpr uint16_t PERIOD_MS{1000};
void setup_LEDS() {
    //Настройка линий для сид
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11 | GPIO15);
}
void setup_timer() {
//Настройка таймера
    //"Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    //Настройка делителя
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6) - 1);
    //Указание предела счета
    timer_set_period(TIM6, 1000 - 1);
    timer_enable_irq(TIM6, TIM_DIER_UIE);
    nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
    //Запуск
    timer_enable_counter(TIM6);
}
void setup_blink() {
if (timer_get_counter(TIM6) < 500)
            gpio_set(GPIOE, GPIO9 | GPIO11 | GPIO13 | GPIO15);
        else gpio_clear(GPIOE, LEDS);
                // gpio_toggle(GPIOE, GPIO9);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO13);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO10);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO14);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO11);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO15);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO12);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO8);
        // for(volatile uint32_t i = 0; i<900000; i++);
        // gpio_toggle(GPIOE, GPIO13);
        // for(volatile uint32_t i = 0; i<900000; i++);

        // gpio_toggle(GPIOE, GPIO14);
        // for(volatile uint32_t i = 0; i<900000; i++);

        // gpio_toggle(GPIOE, GPIO15);
        // for(volatile uint32_t i = 0; i<900000; i++);

        // gpio_toggle(GPIOE, GPIO8);
        // for(volatile uint32_t i = 0; i<900000; i++);
}
int main() {
    //НАстройка тактовой подсистемы
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
    setup_LEDS();
    setup_timer();
    while (true) {

        setup_blink();

    }
}
void tim6_dac_isr(){
    timer_clear_flag(TIM6, TIM_SR_UIF);
    gpio_toggle(GPIOE, GPIO11 | GPIO15);
}
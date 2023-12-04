#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/cm3/nvic.h>

constexpr uint16_t LEDS{GPIO9 | GPIO13};
constexpr uint16_t PERIOD_MS{1000};

void setup_LEDS() {
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11|GPIO15);
}

void setup_timer() {
    rcc_periph_clock_enable(RCC_TIM6);
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6)/PERIOD_MS - 1);
    timer_set_period(TIM6, PERIOD_MS - 1);
    timer_enable_irq(TIM6, TIM_DIER_UIE);
    nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
    timer_enable_counter(TIM6);
}

void blink_LEDS() {
if (timer_get_counter(TIM6) < PERIOD_MS/2)
            gpio_set(GPIOE, LEDS);
        else 
            gpio_clear(GPIOE, LEDS);
}

void setup_timer_1() {
    rcc_periph_clock_enable(RCC_TIM1);
    timer_set_prescaler(TIM1, rcc_get_timer_clk_freq(TIM1)/PERIOD_MS - 1);
    timer_set_period(TIM1, PERIOD_MS - 1);
    timer_set_oc_value(TIM1, TIM_OC1, PERIOD_MS/3);
    timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_RWM1);
    timer_enable_oc_output(TIM1, TIM_OC1);
    timer_enable_break_main_output(TIM1);
    timer_enable_counter(TIM1);
}

int main () {
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
    setup_LEDS();
    setup_timer();
    //Для того, чтобы СИДом управлял таймер, необходимо настроить таймер и линию порта
    setup_timer_1();
    setup_timer_port();
    while (true) {
        blink_LEDS();  
    }
}

void tim6_dac_isr () {
    timer_clear_flag(TIM6, TIM_SR_UIF);
    gpio_toggle(GPIOE, GPIO11|GPIO15);

}
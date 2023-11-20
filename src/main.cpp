#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

constexpr uint16_t LEDS{GPIO9 | GPIO13};

int main () {
//настройка тактовой подсистемы
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]); //pll умножитель
//Настройка линий для СИД
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    // gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10 | GPIO14);
//Настройка таймера
//Разморозка таймера
    rcc_periph_clock_enable(RCC_TIM6);
//Настройка делителя
    timer_set_prescaler(TIM6, 32000 - 1);
//Указание предела счёта
    timer_set_period(TIM6, 1000 - 1);
//Запуск таймера
    timer_enable_counter(TIM6);

    while (true) {

    if (timer_get_counter(TIM6) < 500)
       gpio_set(GPIOE, LEDS);
    else
       gpio_clear(GPIOE, LEDS);
 
      // gpio_toggle(GPIOE, GPIO10 | GPIO14);
      //for(volatile uint32_t i=0; i< 500'000; i++); 
      
    }
}
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

int main () {


    //Настройка тактовой подсистемы 
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);//умножитель частоты
    
    //Настройка линий для СИДиодов
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO12);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO13);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10 | GPIO14);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11 | GPIO15);

    //Настройка таймера
    //1) "Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    //2) Настройка делителя
    timer_set_prescaler(TIM6, 32'000 - 1);
    //3) Указание предела счёта
    timer_set_period(TIM6, 1000 - 1);
    //4) Запуск таймера
    timer_enable_counter(TIM6);

    while (true) {

        if(timer_get_counter(TIM6) < 500){
            //gpio_set(GPIOE, GPIO8 | GPIO12);
            //gpio_set(GPIOE, GPIO9 | GPIO13);
            //gpio_set(GPIOE, GPIO10 | GPIO14);
            gpio_set(GPIOE, GPIO11 | GPIO15);
        }
        else{
            //gpio_clear(GPIOE, GPIO8 | GPIO12);
            //gpio_clear(GPIOE, GPIO9 | GPIO13);
            //gpio_clear(GPIOE, GPIO10 | GPIO14);
            gpio_clear(GPIOE, GPIO11 | GPIO15);
        }

    }
}
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
int main () {

    // Настройка тактовой подсистемы
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

     // Настройка порта ввода-вывода
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  GPIO8 |GPIO9 |GPIO10 |GPIO11 |GPIO12 |GPIO13 | GPIO14 |GPIO15);
    
    while(true) {
    //Переключение светодиода
      gpio_toggle(GPIOE, GPIO8 |GPIO9 |GPIO10 |GPIO11 |GPIO12 |GPIO13 | GPIO14 |GPIO15);
      for (volatile uint32_t i = 0; i < 500'000; ++i);  
    }
}
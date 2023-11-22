#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

constexpr uint16_t LEDS{GPIO9|GPIO13};
int main () {
    //Настройка тактовой подсистемы 
rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
//Настройка линий для  СИД
rcc_periph_clock_enable(RCC_GPIOE);

gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO8 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO9 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO12 );
gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,GPIO_PUPD_NONE, GPIO13 );

//Настройка таймера
//"Разморозка" таймера
rcc_periph_clock_enable(RCC_TIM6);

//Настройка дилителя
timer_set_prescaler(TIM6, 32000-1);

//Настройка предела счета
timer_set_period(TIM6,1000-1 );

//Запуск таймера
timer_enable_counter(TIM6);

    while (true) { 
if (timer_get_counter(TIM6)<500)
gpio_set(GPIOE,LEDS);
else
gpio_clear(GPIOE,LEDS);
/*gpio_set(GPIOE, GPIO9 | GPIO13 );
for(volatile uint32_t i=0;i<500'000; ++i);
gpio_clear(GPIOE,GPIO9 | GPIO13 );
gpio_set(GPIOE, GPIO8|GPIO12 );
for(volatile uint32_t i=0;i<500'000; ++i);
gpio_clear(GPIOE,GPIO8 |GPIO12 );
  */ 
   }
}

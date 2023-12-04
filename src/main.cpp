#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>


#include <libopencm3/cm3/nvic.h> //заголовок для перерывааний находиться в другой папке 

constexpr uint16_t PERIOD_MS{1000};

void blink_LED() 
{
if(timer_get_counter(TIM1) < PERIOD_MS / 2)   
  {
    gpio_set(GPIOE, GPIO9);  
  } 


else 
  {
  gpio_clear(GPIOE, GPIO9);
  } 

}


void LED_gpio_setup()
{
  rcc_periph_clock_enable( RCC_GPIOE);
  gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO11  | GPIO14 );

  gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO14 );

  gpio_set_af(GPIOE, GPIO_AF2, GPIO14);

}

void timer_setup()
{
  rcc_periph_clock_enable( RCC_TIM1);
  timer_set_prescaler (TIM1, rcc_get_timer_clk_freq(TIM1) / PERIOD_MS -1  );
  timer_set_period(TIM1, PERIOD_MS-1);

//для разрешения беспокойства процессора 
  timer_enable_irq(TIM1, TIM_DIER_UIE);
  nvic_enable_irq (NVIC_TIM1_UP_TIM16_IRQ ); 

  timer_enable_counter(TIM1);
}




int main()
{ //  насттройка порта ввода-вывода 
  //Для разгоник ЦП нужно порабоать с rcc_clock_setup_pll
  rcc_clock_setup_pll( &rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

    rcc_periph_clock_enable( RCC_GPIOE);
  gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10);
  gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);




LED_gpio_setup();
timer_setup();

  while (true )
 {
  blink_LED();








// СТАРЫЙ ОЛГАРИТМ       //  переключение светодиона
// gpio_toggle(GPIOE, GPIO10);
//   for(volatile uint32_t i = 0; i < 1'000'000; ++i);
// gpio_toggle(GPIOE, GPIO12);
  
  }

}



void tim1_up_tim16_isr(void)  //обработчик  
{

timer_clear_flag(TIM1, TIM_SR_UIF); // снимаем заброс или выключаем будильник.  TIM_SR_UIF- для обнуленяи
//полезная работа те переключение сетодиода  
gpio_toggle(GPIOE, GPIO11) ;
}





// hsi - hight speed internal когда появляется кварц 
// uint32_t---жёсткое приивание разрядности для МК
// cmake --install build --- для загрузки на плату прокта 
// cmake --build build --- сборка прокта на проверку ошибок 
//  cmake -B build --- настройка . Редко при удалении папки , добавление файлов в покт или редоктирование CMakeList.txt)
//  cmake --install build
//  git pull upstream  main
//  sudo apt install nscd
//  git pull origin main
//  sudo apt upgrade 
//  sudo apt update
//  cat /etc/group | grep plug
//   sudo usermod -a -G plugdev stud133   
//   sudo openocd -f board/stm32f3discovery

//09.11.2023//volatile - позволяет  программе выполнять функцию ,которую она хочет игнорировать. Для того чтобы начать рабоать с платой нцжно 
//    1.Ничего не надо писать просто подключаем плату  ( sudo  openocd -f board/stm32f3discovery.cfg,  в случае если плата ушла в ожидании то нужно нажать )

//    2. написать программу сохранить и сначала вцыполонить cmake --build build, а потом ,  cmake --install build


// 29.11.2023 изменение алгоритма мигания 
//для разрешения сигнла из вне 
// для многих каналов используеться канал захвата сравнение 
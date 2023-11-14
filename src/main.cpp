#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main()
{ //  насттройка порта ввода-вывода 
  //Для разгоник ЦП нужно порабоать с rcc_clock_setup_pll
 rcc_clock_setup_pll( &rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

  rcc_periph_clock_enable( RCC_GPIOE);
 gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10);
 gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);

    while (true )
    {

      //  переключение светодиона
gpio_toggle(GPIOE, GPIO10);
  for(volatile uint32_t i = 0; i < 1'000'000; ++i);
gpio_toggle(GPIOE, GPIO12);
  

  
  
    }

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

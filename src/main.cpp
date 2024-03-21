#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <ring_buff/buff.hpp>
#include <libopencm3/cm3/nvic.h>

uint8_t c{'a'};
Ring_buffer buf;

void setup (){
    // Интерфейс U(S)ART с внешним миром
rcc_periph_clock_enable(RCC_GPIOA);                           // Разморозка порта ввода/вывода
rcc_periph_clock_enable(RCC_GPIOE);  

gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO9 | GPIO10);  // Режим альтернативной функции
gpio_set_af(GPIOA,GPIO_AF7, GPIO9 | GPIO10);                           // Альтернативная функция (выбор по номеру) PA9 --- Tx, PA10 --- Rx.

gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO11);

rcc_periph_clock_enable(RCC_USART1);                      // Разморозка ПУ


usart_set_baudrate(USART1, 19200);                       // Скорость передачи
usart_set_databits(USART1, 8);                            // Размер посылки
usart_set_stopbits(USART1, USART_STOPBITS_1);             // Количество стоп-битов
usart_set_parity(USART1, USART_PARITY_NONE);              // Контроль четности

usart_set_mode(USART1, USART_MODE_TX_RX);                 // Режим работы ПУ
usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);   // Управление процессом передачи сообщений

usart_enable_rx_interrupt(USART1);
nvic_enable_irq(NVIC_USART1_EXTI25_IRQ);

usart_enable(USART1);                                     // Включение ПУ

}

void loop(){
    if (!buf.empty()){c=buf.get();}
usart_send_blocking (USART1 , c);
for (volatile uint32_t i = 0; i<2000000; i++);
gpio_toggle(GPIOE, GPIO9);
}
int main (){
    setup();

    gpio_set(GPIOE, GPIO15);

   while(true){
    loop();

   } 
}

 void usart1_exti25_isr(void){

    USART_RQR(USART1) &= ~(USART_RQR_RXFRQ);

    if (buf.not_full()){
        buf.put(static_cast<uint8_t>(usart_recv(USART1)));
    }

    gpio_toggle(GPIOE, GPIO11);
    //очистить флаг запроса прерывания
    //сохранить принятый символ в переменную (глобальную надо определить!)
    //переключить светодиод
 }

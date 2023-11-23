#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

constexpr uint16_t LEDS8_12{GPIO8 | GPIO12};
constexpr uint16_t LEDS9_13{GPIO9 | GPIO13};
constexpr uint16_t LEDS10_14{GPIO10 | GPIO14};
constexpr uint16_t LEDS11_15{GPIO11 | GPIO15};

constexpr uint16_t PERIOD_MS{1000};
constexpr uint16_t LOCK_FREQ{1000};


void setup_LEDS(){
    //Настройка линий для СИДиодов
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO12);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO13);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10 | GPIO14);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11 | GPIO15);
}

void setup_timer(){
    //1) "Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    //2) Настройка делителя
    //половина 64МГц (мы ускоряли систему)
    //Мы спросили у системы какая у неё частота
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6) / LOCK_FREQ - 1);
    //3) Указание предела счёта
    timer_set_period(TIM6, PERIOD_MS - 1);
    //Запрос прерывания
    timer_enable_irq(TIM6, TIM_DIER_UIE);
    nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
    //4) Запуск таймера
    timer_enable_counter(TIM6);
}

void blink_LEDS(){
    if(timer_get_counter(TIM6) < (PERIOD_MS / 2)){
            gpio_set(GPIOE, LEDS8_12);
            //gpio_set(GPIOE, LEDS9_13);
            //gpio_set(GPIOE, LEDS10_14);
            //gpio_set(GPIOE, LEDS11_15);
        }
        else{
            gpio_clear(GPIOE, LEDS8_12);
            //gpio_clear(GPIOE, LEDS9_13);
            //gpio_clear(GPIOE, LEDS10_14);
            //gpio_clear(GPIOE, LEDS11_15);
        }
}

int main () {

    //Настройка тактовой подсистемы 
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);//умножитель частоты
    
    setup_LEDS();
    setup_timer();

    while (true) {
        blink_LEDS();
    }
}


//Обработка прерывания
void tim6_dac_isr(){
    timer_clear_flag(TIM6, TIM_SR_UIF);
    gpio_toggle(GPIOE, LEDS11_15);
}
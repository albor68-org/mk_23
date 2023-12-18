#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/cm3/nvic.h>

constexpr uint16_t LEDS{GPIO12 | GPIO15};

constexpr uint16_t CNT_FREQ_HZ{1000};
constexpr uint16_t PERIOD_MS{40};


void setup_LEDS () 
{
    // Настройка линии для СИД (свето излучающие диоды)
    rcc_periph_clock_enable(RCC_GPIOE);

    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
   // gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9);
}

void setup_timer () 
{
    // Настройка таймера
    // "Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    // Настройка делителя
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6) / CNT_FREQ_HZ - 1);
    // Указание предела счета
    timer_set_period(TIM6, PERIOD_MS - 1);


    // Устанавливаем будильник
    timer_enable_irq(TIM6, TIM_DIER_UIE);
    // Просим разрешение у секретаря передать сигнал ЦПУ (nvic)
    nvic_enable_irq(NVIC_TIM6_DAC_IRQ);


    // Запуск таймера
    timer_enable_counter(TIM6);
}

void setup_timer_1 () 
{
    // Настройка таймера
    // "Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM1);
    // Настройка делителя
    timer_set_prescaler(TIM1, rcc_get_timer_clk_freq(TIM1) / CNT_FREQ_HZ - 1);
    // Указание предела счета
    timer_set_period(TIM1, PERIOD_MS - 1);
    
    timer_set_oc_value(TIM1, TIM_OC1, PERIOD_MS / 3);
    timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);

    timer_enable_oc_output(TIM1, TIM_OC1);

    timer_enable_break_main_output(TIM1);

    // Запуск таймера
    timer_enable_counter(TIM1);
}

void setup_timer_port()
{
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO9);
    gpio_set_af(GPIOE, GPIO_AF2, GPIO9);
}


void blink_LEDS () 
{
    if (timer_get_counter(TIM6) < PERIOD_MS / 2)
            gpio_set(GPIOE, LEDS);
        else
            gpio_clear(GPIOE, LEDS);

       // gpio_toggle(GPIOE, GPIO13);
       // for (volatile uint32_t i = 0; i < 250'000; i++);

       // gpio_toggle(GPIOE, GPIO9);
       // for (volatile uint32_t i = 0; i < 125'000; i++);
}

int main () 
{
    // Настройка тактовой подсистемы
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);

    setup_LEDS();

    setup_timer();

    // Для того, чтобы СИДом управлял таймер, необходимо настроить таймер и линию порта
    setup_timer_1();
    setup_timer_port();

    while (true) 
    {
        blink_LEDS();
    }
}

void tim6_dac_isr()
{
    //Выключение сигнала будильника
    timer_clear_flag(TIM6, TIM_SR_UIF);
    //Включение 2-х светодиодов
     gpio_toggle(GPIOE, GPIO13);

     static uint8_t rep{0};
     rep++;
     rep %= 4;
     if (rep == 0) {
             static uint8_t rep2{0};
            rep2++;
            rep2 %= 5;

            timer_set_oc_value(TIM1, TIM_OC1, PERIOD_MS / (rep2+1));
     }
}


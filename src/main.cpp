#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/cm3/nvic.h>

constexpr uint16_t LEDS{GPIO12 | GPIO15};
constexpr uint16_t PERIOD_MS{1000};

void setup_LEDS () 
{
    // Настройка линии для СИД (свето излучающие диоды)
    rcc_periph_clock_enable(RCC_GPIOE);

    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDS);
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9 | GPIO13);
   // gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO9);
}

void setup_timer () 
{
    // Настройка таймера
    // "Разморозка" таймера
    rcc_periph_clock_enable(RCC_TIM6);
    // Настройка делителя
    timer_set_prescaler(TIM6, rcc_get_timer_clk_freq(TIM6) / PERIOD_MS - 1);
    // Указание предела счета
    timer_set_period(TIM6, PERIOD_MS - 1);


    //Устанавливаем будильник
    timer_enable_irq(TIM6, TIM_DIER_UIE);
    // Просим разрешение у секретаря передать сигнал ЦПУ (nvic)
    nvic_enable_irq(NVIC_TIM6_DAC_IRQ);


    // Запуск таймера
    timer_enable_counter(TIM6);
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

    while (true) 
    {
        blink_LEDS();
    }
}

void tim6_dac_isr()
{
    //Выключение сигнала будильника
    timer_clear_flag(TIM6, TIM_SR_UIF);
    //Включение 2 светодиодов
     gpio_toggle(GPIOE, GPIO9 | GPIO13);
}
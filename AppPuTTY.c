#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

/// @brief Função que liga um led
/// @param key Valor da tecla que correposnde ao seu respectivo LED
void turn_on_led(uint key)
{   
    // valores das keys devem ser trocas nesse bloco conforme a necessidade
    if (key == 10) gpio_put(LED_GREEN, 1);
    if (key == 11) gpio_put(LED_BLUE, 1);
    if (key == 12) gpio_put(LED_RED, 1);

}

/// Função para ligar todos os LEDs luz branca
void turn_on_all_leds_white() {
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
}

/// Função para desligar todos os LEDs
void turn_off_all_leds() {
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

/// Função para ligar o buzzer por 2 segundos
void turn_on_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}
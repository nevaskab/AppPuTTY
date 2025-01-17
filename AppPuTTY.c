#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21


/// @brief Função que liga um led
/// @param key Valor da tecla que correposnde ao seu respectivo LED
void turn_on_led(uint key)
{   
    // valores das keys devem ser trocas nesse bloco conforme a necessidade
    if (key == 10) gpio_put(LED_GREEN, 1);
    if (key == 11) gpio_put(LED_BLUE, 1);
    if (key == 12) gpio_put(LED_RED, 1);
}
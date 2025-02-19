#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

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

/// Função para desligar todos os LEDs
void turn_off_all_leds() {
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

/// @brief Função que liga um led
/// @param key Valor da tecla que corresponde ao seu respectivo LED
void turn_on_led(uint key)
{   
    turn_off_all_leds();
    if (key == 11) gpio_put(LED_GREEN, 1);
    if (key == 12) gpio_put(LED_BLUE, 1);
    if (key == 13) gpio_put(LED_RED, 1);
}


/// Função para ligar todos os LEDs luz branca
void turn_on_all_leds_white() {
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
}

/// Função para ligar o buzzer por 2 segundos
void turn_on_buzzer() {
    int duracao_ms = 2000;
        while (duracao_ms > 0) {
            gpio_put(BUZZER, 1);
            sleep_ms(2);
            duracao_ms --;
            gpio_put(BUZZER, 0);
            sleep_ms(3);
            duracao_ms -=3;
        }
}

/// @brief Função que realiza o reboot do dispositivo em modo BOOTSEL
void do_bootsel() 
{
    printf("Reiniciando...");
    sleep_ms(1);
    rom_reset_usb_boot_extra(-1, 0, false);
}

int main() { 
    stdio_init_all();
    init_gpio();

    printf("Aguardando comandos...\n");

    while (true) {
 
        if (getchar_timeout_us(0) != PICO_ERROR_TIMEOUT) {
            char comando = getchar();

            switch (comando) {
                case '1':
                    printf("Ligando LED verde...\n");
                    turn_on_led(11);
                    break;
                case '2':
                    printf("Ligando LED azul...\n");
                    turn_on_led(12);
                    break;
                case '3':
                    printf("Ligando LED vermelho...\n");
                    turn_on_led(13);
                    break;
                case '4':
                    printf("Ligando todos os LEDs...\n");
                    turn_on_all_leds_white();
                    break;
                case '5':
                    printf("Desligando os LEDs...\n");
                    turn_off_all_leds();
                    break;
                case '6':
                    printf("Acionando buzzer...\n");
                    turn_on_buzzer();
                    break;
                case '7':
                    do_bootsel();
                    break;
                default:
                    printf("Entrada invalida.\n");
                    break;
            }
        }
    }

    return 0;
}

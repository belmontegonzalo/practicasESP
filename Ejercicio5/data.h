#ifndef DATA_H
#define DATA_H

#include <Arduino.h>

enum LedCommand {
    LED_1, // Enciende el LED rojo
    LED_2, // Enciende el LED verde
    LED_3, // Enciende el LED azul
    LED_BLINK // Parpadean los 3 LEDs
};

// Devuelve un comando LED aleatorio
LedCommand randomCommand();

#endif 
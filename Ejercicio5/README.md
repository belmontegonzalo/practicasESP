# Ejercicio 5 – LED RGB con Color Aleatorio y Parpadeo

Este ejercicio utiliza tres LEDs, encendiendose cada uno aleatoriamente o parpadeando los tres colectivamente de manera aleatoria

## Objetivo

- Controlar todos los LEDs
- Usar `random()` para seleccionar los LEDs aleatorios
- Crear un efecto visual de parpadeo (blink) entre todos los leds

## Requisitos

- Microcontrolador ESP32  
- 3 LEDs (cátodo común)  
- 3 resistencias de 220Ω  
- Protoboard y cables  

## Instrucciones

1. Conectar los pines del LED RGB al ESP32 con resistencias
2. Subir el código al ESP32
3. Observar cómo los LEDs enciende un color al azar y parpadea

## Funcionamiento

- El ESP32 configura los pines para rojo, verde y azul
- Se selecciona aleatoriamente un color usando `random()`
- Ese color se enciende y apaga con intervalos para crear un efecto de parpadeo

![Ejercicio 5](https://github.com/belmontegonzalo/practicasESP/blob/main/media/Ejercicio5.gif)
# Ejercicio 6 – Torre de Control con Pistas de Aterrizaje

Este ejercicio simula una torre de control que gestiona el aterrizaje de 5 aviones en 2 pistas utilizando FreeRTOS. Se emplean tareas, colas y semáforos para coordinar el acceso concurrente a las pistas.

## Objetivo

- Simular el comportamiento de una torre de control aeronáutica.
- Gestionar múltiples aviones con tareas independientes.
- Usar una cola (`QueueHandle_t`) para recibir solicitudes de aterrizaje.
- Controlar el acceso a las pistas mediante semáforos (`SemaphoreHandle_t`).
- Garantizar que solo un avión utilice una pista a la vez.

## Requisitos

- Microcontrolador ESP32  
- Entorno de desarrollo Arduino IDE o PlatformIO  
- Cable USB para programación  
- Monitor serie (Serial Monitor)

## Instrucciones

1. Cargar el código en el ESP32.
2. Abrir el monitor serie a 115200 baudios.
3. Observar cómo los aviones solicitan aterrizaje y la torre los dirige ordenadamente a una pista disponible.

## Funcionamiento

- Se crean **5 tareas**, una por cada avión.
- Cada avión espera un tiempo aleatorio y luego solicita aterrizaje enviando su número por la cola.
- La **torre de control** (otra tarea) escucha la cola y, al recibir un número, intenta asignarle una pista libre.
- Se utilizan dos **semáforos mutex** para representar el estado de cada pista.
- El avión aterriza en una pista si el semáforo correspondiente está disponible, y después de 4 segundos (simulando el aterrizaje), libera la pista.


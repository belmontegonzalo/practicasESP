# Ejercicio 3 – Semáforos Sincronizados y Doble Núcleo

Este ejercicio sincroniza dos semáforos y aprovecha los dos núcleos del ESP32 para ejecutar tareas en paralelo

## Objetivo

- Ejecutar tareas en paralelo en el ESP32 utilizando ambos núcleos
- Simular dos semáforos que trabajan de forma coordinada

## Requisitos

- Microcontrolador ESP32
- 6 LEDs (2 de cada color: rojo, amarillo y verde)
- Resistencias de 220Ω
- Protoboard y cables
- Entorno de desarrollo: Arduino IDE o PlatformIO

## Instrucciones

1. Conectar los LEDs al ESP32 según el esquema proporcionado
2. Subir el código al ESP32
3. Observar la sincronización de los dos semáforos

## Funcionamiento

- El núcleo 0 maneja el semáforo A
- El núcleo 1 maneja el semáforo B
- Las tareas están sincronizadas para que cuando uno esté en rojo, el otro esté en verde, y viceversa

![Ejercicio 3](https://github.com/belmontegonzalo/practicasESP/blob/main/media/esp32img.png)


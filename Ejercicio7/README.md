# Ejercicio – Comunicación MQTT entre Dispositivos con ESP32

Este ejercicio permite enviar y recibir mensajes entre usuarios usando el protocolo MQTT mediante un ESP32. Se conecta a un broker público y se interactúa a través del monitor serie.

## Objetivo

- Conectarse a una red WiFi.
- Conectarse a un broker MQTT.
- Suscribirse a un tópico específico.
- Enviar y recibir mensajes a través del monitor serie.
- Implementar una lógica básica de selección de receptor y envío de mensajes.

## Requisitos

- Microcontrolador ESP32  
- Acceso a una red WiFi  
- Broker MQTT público (`broker.hivemq.com`)  
- Arduino IDE o PlatformIO  
- Monitor serie (baudrate 115200)

## Instrucciones

1. Asegurarse de tener instalada la librería `PubSubClient`.
2. Conectar el ESP32 a la red WiFi especificada en el código.
3. Subir el código al ESP32.
4. Abrir el monitor serie a 115200 baudios.
5. Escribir en el monitor serie `Receptor:usuario` para indicar a quién se desea escribir.
6. Luego, escribir el mensaje que se desea enviar a ese usuario.
7. Observar cómo se reciben mensajes en tiempo real desde otros dispositivos conectados al mismo tópico.

## Funcionamiento

- El ESP32 se conecta a una red WiFi y al broker `broker.hivemq.com` por el puerto 1883.
- Se suscribe al tópico `huergo/sistemas-embebidos/belmonte`.
- Cuando se recibe un mensaje, se imprime carácter por carácter usando un **callback**.
- Cuando se escribe `Receptor:nombre`, el sistema se prepara para enviarle mensajes a ese usuario.
- Cualquier mensaje escrito luego será enviado al tópico `huergo/sistemas-embebidos/nombre`.
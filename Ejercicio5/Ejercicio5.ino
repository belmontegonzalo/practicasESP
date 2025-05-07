#include "data.h"

#define LED_RED 26       
#define LED_GREEN 33    
#define LED_BLUE 35  

QueueHandle_t myQueue; 

// Controla la secuencia del semáforo 1 usando el semáforo para sincronizar
void productor(void *parameter) {
  while (1) {
    string accion = LedCommand();

    if (xQueueSend(myQueue, &idrandom, portMAX_DELAY) == pdPASS)

    }

  }
}

// Controla la secuencia del semáforo 2 de forma sincronizada con semáforo1
void consumidor(void *parameter) {
  while (1) {
    if (accion != 'LED_BLINK') {
      digitalWrite(accion, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));
      digitalWrite(accion, LOW);
    }
    else {
      for (int i = 0; i < 4; i++) {
        pinMode(LED_RED, HIGH);
        pinMode(LED_GREEN, HIGH);
        pinMode(LED_BLUE, HIGH);
        vTaskDelay(pdMS_TO_TICKS(300));
        pinMode(LED_RED, LOW);
        pinMode(LED_GREEN, LOW);
        pinMode(LED_BLUE, LOW);
      }

  }
}

void setup() {
  Serial.begin(115200);  // Inicializa comunicación serie
  delay(100);            // Espera a que Serial esté listo

  myQueue = xQueueCreate(20, sizeof(int));

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  xTaskCreatePinnedToCore(
    productor,     // Función que ejecuta la tarea
    "Task_Core2",  // Nombre de la tarea
    4096,          // Tamaño del stack en palabras
    NULL,          // Parámetro que se le pasa a la tarea
    1,             // Prioridad de la tarea
    NULL,          // Handle (opcional, no lo usamos aquí)
    0              // Core donde queremos que corra la tarea (0 o 1)
  );

  xTaskCreatePinnedToCore(
    consumidor,     // Función que ejecuta la tarea
    "Task_Core2",  // Nombre de la tarea
    4096,          // Tamaño del stack en palabras
    NULL,          // Parámetro que se le pasa a la tarea
    2,             // Prioridad de la tarea
    NULL,          // Handle (opcional, no lo usamos aquí)
    1              // Core donde queremos que corra la tarea (0 o 1)
  );
}

void loop() {
}
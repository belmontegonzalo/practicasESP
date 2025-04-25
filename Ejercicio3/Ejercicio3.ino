
#define verde 14
#define amarillo 12
#define rojo 13

#define verde2 4
#define amarillo2 2
#define rojo2 15


SemaphoreHandle_t semaforo;


void tarea(void *parameter) {
  int core = xPortGetCoreID();  // Obtenemos el ID del core actual

  Serial.print("HOLA LUZKO, ME ESTOY CORRIENDO EN EL CORE ");
  Serial.println(core);

  while (1) {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void semaforo1(void *parameter) {
  while (1) {
    if (xSemaphoreTake(semaforo, portMAX_DELAY) == pdTRUE) {
      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(amarillo, LOW);

      digitalWrite(verde, HIGH);
      vTaskDelay(pdMS_TO_TICKS(4000));

      digitalWrite(verde, LOW);
      digitalWrite(amarillo, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, HIGH);
      xSemaphoreGive(semaforo);
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  }
}

void semaforo2(void *parameter) {
  while (1) {
    if (xSemaphoreTake(semaforo, portMAX_DELAY) == pdTRUE) {
      digitalWrite(rojo2, LOW);
      digitalWrite(amarillo2, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(amarillo2, LOW);

      digitalWrite(verde2, HIGH);
      vTaskDelay(pdMS_TO_TICKS(4000));

      digitalWrite(verde2, LOW);
      digitalWrite(amarillo2, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(amarillo2, LOW);
      digitalWrite(rojo2, HIGH);

      xSemaphoreGive(semaforo);
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  }
}



void setup() {
  Serial.begin(115200);  // Inicializamos el puerto serie
  delay(100);            // Esperamos un poco para que el Serial esté listo

  semaforo = xSemaphoreCreateMutex();

  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(rojo2, OUTPUT);

  digitalWrite(rojo, HIGH);
  digitalWrite(rojo2, HIGH);
  delay(100);
  /*
  xTaskCreatePinnedToCore(
    tarea,         // Función que ejecuta la tarea
    "Task_Core1",  // Nombre de la tarea
    4096,          // Tamaño del stack en palabras
    NULL,          // Parámetro que se le pasa a la tarea
    1,             // Prioridad de la tarea
    NULL,          // Handle (opcional, no lo usamos aquí)
    1              // Core donde queremos que corra la tarea (0 o 1)
  );
  */
  xTaskCreatePinnedToCore(
    semaforo1,     // Función que ejecuta la tarea
    "Task_Core2",  // Nombre de la tarea
    4096,          // Tamaño del stack en palabras
    NULL,          // Parámetro que se le pasa a la tarea
    1,             // Prioridad de la tarea
    NULL,          // Handle (opcional, no lo usamos aquí)
    0              // Core donde queremos que corra la tarea (0 o 1)
  );

  xTaskCreatePinnedToCore(
    semaforo2,     // Función que ejecuta la tarea
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

#define verde 14       // LED verde del semáforo 1
#define amarillo 12    // LED amarillo del semáforo 1
#define rojo 13        // LED rojo del semáforo 1

#define verde2 4       // LED verde del semáforo 2
#define amarillo2 2    // LED amarillo del semáforo 2
#define rojo2 15       // LED rojo del semáforo 2

SemaphoreHandle_t semaforo;  // Semáforo (mutex) para sincronizar las tareas

// Tarea auxiliar que imprime el core en el que se está ejecutando
void tarea(void *parameter) {
  int core = xPortGetCoreID();
  Serial.print("Hola profe, estoy en el core ");
  Serial.println(core);

  while (1) {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

// Controla la secuencia del semáforo 1 usando el semáforo para sincronizar
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

// Controla la secuencia del semáforo 2 de forma sincronizada con semáforo1
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
  Serial.begin(115200);  // Inicializa comunicación serie
  delay(100);            // Espera a que Serial esté listo

  semaforo = xSemaphoreCreateMutex();  // Crea el mutex

  // Configura pines como salidas
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(rojo2, OUTPUT);

  digitalWrite(rojo, HIGH);   // Inicia semáforo 1 en rojo
  digitalWrite(rojo2, HIGH);  // Inicia semáforo 2 en rojo
  delay(100);
  
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

#define verde 14       // LED verde del semáforo
#define amarillo 12    // LED amarillo del semáforo
#define rojo 13        // LED rojo del semáforo

// Tarea que simula la secuencia de un semáforo
void semaforo(void *parameter) {
  while (1) {
      digitalWrite(verde, LOW);
      digitalWrite(rojo, HIGH);
      vTaskDelay(pdMS_TO_TICKS(4000));

      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, HIGH);
      vTaskDelay(pdMS_TO_TICKS(1000));

      digitalWrite(amarillo, LOW);
      digitalWrite(verde, HIGH);
      vTaskDelay(pdMS_TO_TICKS(4000));
  }
}

void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serie
  delay(100);            // Espera a que el puerto serie esté listo

  // Configura los pines como salidas
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);

  digitalWrite(rojo, HIGH);  // Comienza con luz roja encendida
  delay(100);

  // Crea una tarea que se ejecuta en el core 0
  xTaskCreatePinnedToCore(
    semaforo,     // Función que ejecuta la tarea
    "Task_Core2",  // Nombre de la tarea
    4096,          // Tamaño del stack en palabras
    NULL,          // Parámetro que se le pasa a la tarea
    1,             // Prioridad de la tarea
    NULL,          // Handle (opcional, no lo usamos aquí)
    0              // Core donde queremos que corra la tarea (0 o 1)
  );
}

void loop() {
}

SemaphoreHandle_t pista1;
SemaphoreHandle_t pista2;

QueueHandle_t myQueue;

void TorCon(void *parameter) {
  Serial.println("Torre de control iniciada.");
  int Avion;
  Serial.println("Esperando datos...");

  while(1) {
    if (xQueueReceive(myQueue, &Avion, portMAX_DELAY) == pdPASS) {
      if (xSemaphoreTake(pista1, portMAX_DELAY) == pdTRUE){
        if (Avion == 1) {
          Serial.println("Avion 1 aterrizando en pista 1...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 1 aterrizado en pista 1. Pista despejada.");
        }
        if (Avion == 2) {
          Serial.println("Avion 2 aterrizando en pista 1...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 2 aterrizado en pista 1. Pista despejada.");
        }
        if (Avion == 3) {
          Serial.println("Avion 3 aterrizando en pista 1...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 3 aterrizado en pista 1. Pista despejada.");
        }
        if (Avion == 4) {
          Serial.println("Avion 4 aterrizando en pista 1...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 4 aterrizado en pista 1. Pista despejada.");
        }
        if (Avion == 5) {
          Serial.println("Avion 5 aterrizando en pista 1...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 5 aterrizado en pista 1. Pista despejada.");
        }
        xSemaphoreGive(pista1);
      }
    }
      
    if (xQueueReceive(myQueue, &Avion, portMAX_DELAY) == pdPASS) {
      if (xSemaphoreTake(pista2, portMAX_DELAY) == pdTRUE){
        if (Avion == 1) {
          Serial.println("Avion 1 aterrizando en pista 2...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 1 aterrizado en pista 2. Pista despejada.");
        }
        if (Avion == 2) {
          Serial.println("Avion 2 aterrizando en pista 2...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 2 aterrizado en pista 2. Pista despejada.");
        }
        if (Avion == 3) {
          Serial.println("Avion 3 aterrizando en pista 2...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 3 aterrizado en pista 2. Pista despejada.");
        }
        if (Avion == 4) {
          Serial.println("Avion 4 aterrizando en pista 2...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 4 aterrizado en pista 2. Pista despejada.");
        }
        if (Avion == 5) {
          Serial.println("Avion 5 aterrizando en pista 2...");
          vTaskDelay(pdMS_TO_TICKS(4000));
          Serial.println("Avion 5 aterrizado en pista 2. Pista despejada.");
        }

        xSemaphoreGive(pista2);
      }
    }
  }
}

void Avion1(void *parameter) {
  while(1) {
    vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
    int Avion = 1;
    xQueueSend(myQueue, &Avion, portMAX_DELAY);
    
    Serial.println("Avion 1 pide aterrizaje.");
  }
}

void Avion2(void *parameter) {
  while(1) {
    vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
    int Avion = 2;
    xQueueSend(myQueue, &Avion, portMAX_DELAY);

    Serial.println("Avion 2 pide aterrizaje.");
  }
}

void Avion3(void *parameter) {
  while(1) {
    vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
    int Avion = 3;
    xQueueSend(myQueue, &Avion, portMAX_DELAY);

    Serial.println("Avion 3 pide aterrizaje.");
  }
}

void Avion4(void *parameter) {
  while(1) {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int Avion = 4;
  xQueueSend(myQueue, &Avion, portMAX_DELAY);

  Serial.println("Avion 4 pide aterrizaje.");
  }
}

void Avion5(void *parameter) {
  while(1) {
    vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
    int Avion = 5;
    xQueueSend(myQueue, &Avion, portMAX_DELAY);

    Serial.println("Avion 5 pide aterrizaje.");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  myQueue = xQueueCreate(30, sizeof(int));

  pista1 = xSemaphoreCreateMutex();
  pista2 = xSemaphoreCreateMutex();
  xSemaphoreGive(pista1);
  xSemaphoreGive(pista2);

  xTaskCreatePinnedToCore(
    Avion1,
    "Avion1",
    4096,
    NULL,
    1,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    Avion2,
    "Avion2",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    Avion3,
    "Avion3",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    Avion4,
    "Avion4",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    Avion5,
    "Avion5",
    4096,
    NULL,
    1,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    TorCon,
    "Torre de control",
    4096,
    NULL,
    1,
    NULL,
    1
  );
}

void loop() {

}
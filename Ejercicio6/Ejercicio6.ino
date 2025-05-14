
SemaphoreHandle_t pista1;
SemaphoreHandle_t pista2;

SemaphoreHandle_t myAvion1;
SemaphoreHandle_t myAvion2;
SemaphoreHandle_t myAvion3;
SemaphoreHandle_t myAvion4;
SemaphoreHandle_t myAvion5;

QueueHandle_t myQueue;

void TorCon() {
  if (xQueueReceive(myQueue, &aviones, portMAX_DELAY) == pdPASS) {
    if (xSemaphoreTake(mySemaphore, portMAX_DELAY) == pdTRUE){
      if (aviones == 1) {

      }
      if (aviones == 2) {

      }
      if (aviones == 3) {

      }
      if (aviones == 4) {

      }
      if (aviones == 5) {

      }
    }
  }
}

void Avion1() {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int avion1 = 1;

  xQueueSend(myQueue, &avion1, portMAX_DELAY);
}

void Avion2() {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int avion2 = 2;

  xQueueSend(myQueue, &avion2, portMAX_DELAY);
}

void Avion3() {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int avion3 = 3;

  xQueueSend(myQueue, &avion3, portMAX_DELAY);
}

void Avion4() {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int avion4 = 4;

  xQueueSend(myQueue, &avion4, portMAX_DELAY);
}

void Avion5() {
  vTaskDelay(pdMS_TO_TICKS(random(5000,10000)));
  int avion5 = 5;

  xQueueSend(myQueue, &avion5, portMAX_DELAY);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  myQueue = xQueueCreate(30, sizeof(int));

  pista1 = xSemaphoreCreateMutex();
  pista2 = xSemaphoreCreateMutex();
  xSemaphoreGive(pista1);
  xSemaphoreGive(pista2);

  xSemaphoreGive(myAvion1);
  xSemaphoreGive(myAvion2);
  xSemaphoreGive(myAvion3);
  xSemaphoreGive(myAvion4);
  xSemaphoreGive(myAvion5);

  xTaskCreatePinnedToCore(
    avion1,
    "Avion1",
    4096,
    NULL,
    1,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    avion2,
    "Avion2",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    avion3,
    "Avion3",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    avion4,
    "Avion4",
    4096,
    NULL,
    1,
    NULL,
    0
  );

    xTaskCreatePinnedToCore(
    avion5,
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

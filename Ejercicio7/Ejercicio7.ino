#include <WiFi.h>
#include <PubSubClient.h>
WiFiClient espClient;
PubSubClient client(espClient);


// Callback (una función con una firma particular) que respondera ante un nuevo mensaje recibido
void callback(char* topic, byte* payload, unsigned int length) {
  for (int i = 0; i < length; i++) {
    char letra = (char)payload[i];

    Serial.print(letra);
  }

  Serial.println();
  Serial.println("-------------------------------------------");
}


void setup() {
  Serial.begin(115200);

  // Conectarse a una red por nombre + contraseña
  WiFi.begin("iPhone de Morci","morcilover123");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando WiFi...");
  }

  Serial.println("WiFi conectado con exito!");

  client.setCallback(callback);
  client.setServer("broker.hivemq.com", 1883);
  client.connect("belmonte"); // devuelve un booleano indicando si se conecto correctamente

  if (!client.connected()) {
    Serial.println("MQTT no conectado, reintentando...");
    client.connect("belmonte");
  } else {
    Serial.println("MQTT conectado.");
  }

  client.subscribe("huergo/sistemas-embebidos/belmonte"); // seguir patron del topico a escuchar
  Serial.println("-------------------------------------------");
}

String usuario_a_escribir; // Fila 57

void loop() {
  if (Serial.available()) {
    bool xd = 0;
    String msg = Serial.readStringUntil('\n');

    if (msg.startsWith("Receptor:")) {
      xd = 1;
      usuario_a_escribir = msg.substring(9);
      Serial.println("Ya puede mandar el mensaje para mandarle mensaje a " + usuario_a_escribir);
    }

    if (xd == 0) {
      String msg_entero = "Belmonte: " + msg;
      String receptor = "huergo/sistemas-embebidos/" + usuario_a_escribir;
      Serial.println(receptor);
      client.publish(receptor.c_str(), msg_entero.c_str()); // convertir el mensaje mediante .c_str()
    }
  }

  client.loop();
}
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "XXX-yyy-zzz.firebaseio.com"
#define FIREBASE_AUTH ""
#define WIFI_SSID "dinhnt-iot" 
#define WIFI_PASSWORD "dinhnt-iot1280"

#define LED1 0
int stateBtn;

int setValB;
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  stateBtn = Firebase.getInt("gesture");
  Serial.println(stateBtn);
  if (stateBtn == 0) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW );
  }
  delay(100);
}

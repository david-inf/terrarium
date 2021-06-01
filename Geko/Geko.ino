#include "secret.h"

#include "home.h"
#include "changes.h"
#include "internal_conditions.h"
#include "summary.h"

#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>

WebServer server(80);

#include <FirebaseESP32.h>

// DHT setup
#include <DHT.h> //temprature
#include <DHT_U.h> //humidity
#define DHT_PIN 2
#define DHT_TYPE DHT11   // DHT 11

DHT dht11(DHT_PIN, DHT_TYPE);

/* DICHIARAZIONE DEI PIN COME CONST INT o #define

   USATE NOMI SCRITTI IN MAIUSCOLO PER LE VARIABILI COSTANTI
   COME AD ESEMPIO I PIN E VARIE SOGLIE DI VALORI CRITICI

*/

//---------------------------------

// PINs definitions
const int RED_LED_PIN = 18;     // RED    =>  190ohm
const int GREEN_LED_PIN = 19;   // GREEN  =>  180ohm
const int BLUE_LED_PIN = 20;    // BLUE   =>  120ohm
const int PHOTORES_PIN = 34;

// Thresholds for temperature and humidity values
const float LOW_TEMPERATURE_THRESHOLD_DAY = 23.0;
const float HIGH_TEMPERATURE_THRESHOLD_DAY = 29.0;

const float LOW_TEMPERATURE_THRESHOLD_NIGHT = 18.0;
const float HIGH_TEMPERATURE_THRESHOLD_NIGHT = 25.0;

const float LOW_HUMIDITY_THRESHOLD = 30.0;
const float HIGH_HUMIDITY_THRESHOLD = 50.0;

// Thresholds for light
const int LIGHT_THRESHOLD = 341; //1/3 valore totale (1024)

// Threshold for check
const long CHECK_PERIOD = 60000;

//---------------------------------

// Variables definition
float temperature_value = 0.0;
float humidity_value = 0.0;
float light_value = 0.0;

int temp_led = 0;
int hum_led = 0;
int brigh_led = 0;

String color_led_temp = "";

int sun_moon = 0;  // per decidere se giorno o notte

int hour = timestamp.substring(10, 12).toInt();

/* DICHIARATE EVENTUALI VARIABILI DI CONFIGURAZIONE FUORI DAL SETUP */
//////////////////////////////////////////////////////////////
// Timestamp configuration
int timezone = 2;
int dst = 0;

//---------------------------------

/* IMPLEMENTATE LE FUNZIONI DI HANDLE PRIMA DEL SETUP */

// Webserver handle functions
void handle_home() {
  Serial.println("GET /home");
  server.send(200, "text/html", home_html_page());
}

void handle_internal() {
  Serial.println("GET /internal_conditions");
  server.send(200, "text/html", internal_html_page(String(temperature_value), String(humidity_value),
              String(int((1 - light_value / 1024) * 100)), temp_led, hum_led, brigh_led));
}

/*String status_red = "spenta";
  String status_green = "spenta";
  String status_blue = "spenta";
  bool light_over_thr = false;*/

void handle_changes() {
  Serial.println("GET /changes"); // sistemare
  server.send(200, "text/html", changes_html_page());
}

long last_control = millis();
//String status_green = "spenta";

void handle_summary() {
  Serial.println("GET /summary");
  server.send( 200, "text/html", summary_html_page( String(temperature_value), String(humidity_value),
               String(int((1 - light_value / 1024) * 100)), sun_moon, color_led_temp,
               String(LOW_TEMPERATURE_THRESHOLD_DAY ), String(HIGH_TEMPERATURE_THRESHOLD_DAY ),
               String(LOW_TEMPERATURE_THRESHOLD_NIGHT ), String(HIGH_TEMPERATURE_THRESHOLD_NIGHT),
               String(LOW_HUMIDITY_THRESHOLD), String(HIGH_HUMIDITY_THRESHOLD), String(LIGHT_THRESHOLD) ) );
}

void handle_not_found() {
  server.send(404, "text/plain", "404: Page not found !");
}

/*
	CERCATE DI STRUTTURARE A BLOCCHI SIA IL SETUP CHE IL LOOP
	COMMENTANDO BREVEMENTE IL COMPORTAMENTO DEL BLOCCO
*/

void setup(void) {
  // Serial port setup
  Serial.flush(); Serial.begin(115200); Serial.flush();
  delay(100); Serial.flush();

  // PINs setup
  pinMode(RED_LED_PIN, OUTPUT); digitalWrite(RED_LED_PIN, LOW);
  pinMode(GREEN_LED_PIN, OUTPUT); digitalWrite(GREEN_LED_PIN, LOW);
  pinMode(BLUE_LED_PIN, OUTPUT); digitalWrite(BLUE_LED_PIN, LOW);

  pinMode(DHT_PIN, INPUT);

  //---------------------------------

  // Wi-Fi connection setup
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("");
  Serial.print("Connecting to "); Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");  Serial.println(WIFI_SSID);
  Serial.print("IP address: ");   Serial.println(WiFi.localIP());

  // Server setup DAVID
  server.on("/", handle_home);
  server.on("/internal_conditions.html", handle_internal);
  server.on("/changes.html", handle_changes);
  server.on("/summary.html", handle_summary);
  server.onNotFound(handle_not_found); //When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();
  Serial.print("HTTP server started at ");  Serial.println(WiFi.localIP());

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // Firebase updating data
  FirebaseJson json_data;
  json_data.set("Board", "ESP-32");
  json_data.set("IP", WiFi.localIP());
  if (Firebase.updateNode(firebase_data_obj, "/", json_data)) {
    Serial.println("Correct updating data!");
  } else {
    Serial.println(firebase_data_obj.errorReason());
  }

  //---------------------------------

  // Configuring timestamp function
  configTime(timezone * 3600, dst * 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Timestamp available!\n");

  //DHT11 init
  dht11.begin();
}
/*************************** End setup *******************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

/*
	DICHIARATE PRIMA DEL LOOP EVENTUALI VARIABILI GLOBALI CHE SERVIRANNO PER I VALORI DEI SENSORI
	O ALTRO
*/

String timestamp = "";
int count_timestamp_todrop = 0;

//int led_green_state = 0;

/*********************************************************************/
/*********************************************************************/

void loop(void) {
  //Handle client requests
  server.handleClient();

  //---------------------------------
  /* CHANGES */
  float new_max_hum = float(server.args("max_hum"));  // va convertito  
  float new_min_hum = float(server.args("min_hum"));  // va convertito  
  Serial.println(new_max_hum); // controllare il valore
  Serial.println(new_min_hum);
  if (new_max_hum != HIGH_HUMIDITY_THRESHOLD) {
    HIGH_HUMIDITY_THRESHOLD = new_max_hum;
  }

  //---------------------------------

  /***************************************************************************************/
  /* This block below, execute only every S seconds, without delay(S*1000); function!   */
  /*************************************************************************************/

  timestamp = get_timestamp();
  if (count_timestamp_todrop <= 5) {
    count_timestamp_todrop ++; //first timestamp are incorrect !!!
  }

  if (timestamp != "" && count_timestamp_todrop > 5) {
    delay(5000);
    // Get sensors measurements
    Serial.print("Timestamp: "); Serial.println(get_timestamp());

    // Read temperature as Celsius (the default)
    temperature_value = dht11.readTemperature();
    humidity_value = dht11.readHumidity();
    Serial.print("DHT11 -> Temperature value: "); Serial.print(temperature_value); Serial.println("°C");
    Serial.print("DHT11 -> Humidity  value: "); Serial.print(humidity_value);  Serial.println("%");

    if (hour <= 8 && hour >= 20) {
      night_function();
      Serial.println("NIGHT");
      sun_moon = 2;
    } else {
      day_function();
      Serial.println("DAY");
      sun_moon = 1;
    }

    // HUMIDITY
    if (humidity_value >= LOW_HUMIDITY_THRESHOLD && humidity_value <= HIGH_HUMIDITY_THRESHOLD) {
      Serial.println("ACCETTABILE");  //immagine se va bene o sfora
      hum_led = 1;
    }
    else {
      Serial.println("NON ACCETTABILE");
      hum_led = 2;
    }

    // Light sensor management
    light_value = analogRead(PHOTORES_PIN);
    Serial.print("Photoresistor -> Light value: ");
    Serial.println(light_value);
    if  (light_value > LIGHT_THRESHOLD) {
      Serial.println("GREEN_LED");
      brigh_led = 1;
      //MESSAGGIO HTML
      /*digitalWrite(BLUE_LED_PIN, HIGH);
        digitalWrite(RED_LED_PIN, LOW);
        light_over_thr = false;
        status_blu = "accesa";
        status_red = "spenta";*/
    } else {
      Serial.println("RED LED");
      brigh_led = 2;
      //MESSAGGIO HTML
      /*digitalWrite(BLUE_LED_PIN, LOW);
        digitalWrite(RED_LED_PIN, HIGH);
        light_over_thr = true;
        status_blu = "spenta";
        status_red = "accesa";*/
    }

    //Firebase updating data
    FirebaseJson json_data;
    json_data.set("Timestamp", timestamp);
    json_data.set("DHT11/Temperature/temperature_value", temperature_value);
    json_data.set("DHT11/Temperature/Day/HIGH_TEMPERATURE_THRESHOLD_DAY", HIGH_TEMPERATURE_THRESHOLD_DAY);
    json_data.set("DHT11/Temperature/Day/LOW_TEMPERATURE_THRESHOLD_DAY", LOW_TEMPERATURE_THRESHOLD_DAY);
    json_data.set("DHT11/Temperature/Night/HIGH_TEMPERATURE_THRESHOLD_NIGHT", HIGH_TEMPERATURE_THRESHOLD_NIGHT);
    json_data.set("DHT11/Temperature/Night/LOW_TEMPERATURE_THRESHOLD_NIGHT", LOW_TEMPERATURE_THRESHOLD_NIGHT);
    json_data.set("DHT11/Temperature/temp_led", temp_led);

    json_data.set("DHT11/Humidity/humidity_value", humidity_value);
    json_data.set("DHT11/Humidity/HIGH_HUMIDITY_THRESHOLD", HIGH_HUMIDITY_THRESHOLD);
    json_data.set("DHT11/Humidity/LOW_HUMIDITY_THRESHOLD", LOW_HUMIDITY_THRESHOLD);

    json_data.set("Brightness/light_value", light_value);
    json_data.set("Brightness/LIGHT_THRESHOLD", LIGHT_THRESHOLD);

    if (Firebase.updateNode(firebase_data_obj, "/", json_data)) {
      Serial.println("Correct updating data!");
    } else {
      Serial.println(firebase_data_obj.errorReason());
    }
  }

}
/*************************** End loop ********************************/
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

// Utils functions

// DAY THRESHOLD
void day_function() {
  if (temperature_value > HIGH_TEMPERATURE_THRESHOLD_DAY) {
    Serial.println("RED LED");
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    temp_led = 1;
  }
  else if (temperature_value >= LOW_TEMPERATURE_THRESHOLD_DAY && temperature_value <= HIGH_TEMPERATURE_THRESHOLD_DAY) {
    Serial.println("GREEN LED");
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    temp_led = 2;
  }
  else {
    Serial.println("BLUE LED");
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    temp_led = 3;
  }
}

// NIGHT THRESHOLD
void night_function() {
  if (temperature_value > HIGH_TEMPERATURE_THRESHOLD_NIGHT) {
    Serial.println("RED LED");
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    temp_led = 1;
    color_led_temp = "RED";
  }
  else if (temperature_value >= LOW_TEMPERATURE_THRESHOLD_NIGHT && temperature_value <= HIGH_TEMPERATURE_THRESHOLD_NIGHT) {
    Serial.println("GREEN LED");
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    temp_led = 2;
    color_led_temp = "GREEN";
  }
  else {
    Serial.println("BLUE LED");
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    temp_led = 3;
    color_led_temp = "BLUE";
  }
}

String get_timestamp() {
  String timestamp = "";
  time_t now = time(nullptr);
  timestamp = String(ctime(&now));
  timestamp.remove(24);

  if (timestamp.endsWith("1970")) {
    return "";
  } else {
    return timestamp;
  }
}

//Led fisico solo temperatura
//Led ciascuno per Temperatura, Umidità, Luminosità

//Led sotto Internal Conditions, sotto i vari riquadri
//Giorno e notte in Summary, e Teca

#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <FS.h>

const char* ssid = "tedata";
const char* password = "blank5019";

#define FIREBASE_HOST "ota-test1.firebaseio.com"             // the project name address from firebase id
#define FIREBASE_AUTH "Uqw7UoTw9v1ZZUPr16vAdTKdy6MCwVehXKiHIsor"       // the secret key generated from firebase

String FIRMWARE_URL = "" ;
String Fingerprint = "" ;

void setup() {
    Serial.begin(9600);
     SPIFFS.begin();
    //Serial.print("Connecting to "); Serial.print(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
   }
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH) ;
   
    Serial.println(" ");
   FIRMWARE_URL=Firebase.getString("url");
   Serial.println(FIRMWARE_URL);
   Fingerprint=Firebase.getString("Fingerprint");
    Serial.println(Fingerprint);
   Download_Firmware();
}

void loop() {

  

}


void Download_Firmware() {
  HTTPClient http;
  const char* filename = "/samplefile.hex";
  SPIFFS.format();
  File f = SPIFFS.open(filename, "w");
  if(f)
  {
    http.begin(FIRMWARE_URL ,Fingerprint);
    int httpCode = http.GET();
    if (httpCode <= 0)
    {
        Serial.printf("HTTP failed, error: %s\n", 
        http.errorToString(httpCode).c_str());
    return;
    }
    if (httpCode == HTTP_CODE_OK) 
    {
        Serial.println("d check");
        http.writeToStream(&f);
    }
    Serial.printf("Content-Length: %d\n", (http.getSize()));
    Serial.printf("file-size: %d\n", (f.size()));
    f.close();
    http.end();
   }
   f = SPIFFS.open(filename, "r");
   if (!f) 
   {
     Serial.println("file open failed");
      return;
   }
   else
   {
       Serial.println("Reading Data from File:");
       //Data from file
       for(int i=0;i<(f.size()/40);i++) //Read upto complete file size
       {
          for(int j=0;j<80;j++)
          {
            Serial.print(f.read(),HEX);
          }
          Serial.println(f.read(),HEX);
       }
       f.close();  //Close file
       Serial.println("File Closed");
   }
   Serial.println();
   Serial.println("Done"); 
}

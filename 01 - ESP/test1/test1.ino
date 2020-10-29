#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <FS.h>
#include <SoftwareSerial.h>

/* States */
#define  WAIT_NEW_UPADTE   0
#define  NEW_UPDATE_DWN    1
#define  NEW_UPDATE     2

/* Pins */
#define RESET_PIN 5 


SoftwareSerial S( 14 , 12);  // rx- tx

const char* ssid = "tedata";
const char* password = "blank5019";
const char* filename = "/samplefile.hex";
char new_flag ;
int state  = WAIT_NEW_UPADTE ; 
File f ;

#define FIREBASE_HOST "ota-test1.firebaseio.com"             // the project name address from firebase id
#define FIREBASE_AUTH "Uqw7UoTw9v1ZZUPr16vAdTKdy6MCwVehXKiHIsor"       // the secret key generated from firebase

String FIRMWARE_URL = "" ;
String Fingerprint = "" ;

void setup()
{
  /* Intitialize Serial Communication */
  Serial.begin(9600);
  S.begin(9600);

  /* Configure pin as output to reset rhe stm  */
  pinMode (RESET_PIN , OUTPUT);
  digitalWrite (RESET_PIN , HIGH);
     
  SPIFFS.begin();
  
  /* Connect to Wifi */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /* Connect to Firebase */
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH) ;
  Serial.println(" "); 
}

void loop() { 
  switch (state){
    /************* Check for new Update ***************/
    case WAIT_NEW_UPADTE :
      new_flag = Firebase.getInt("NewUpdate");
      if (new_flag == 1){
        Serial.println (new_flag);
        state = NEW_UPDATE_DWN ;
        }  
      break ;


    /************* Send the update ***************/
    case NEW_UPDATE : 
      /* Reset ECU before sending the new update */
      digitalWrite (RESET_PIN , LOW);
      delay(100);
      digitalWrite (RESET_PIN , HIGH);  
      delay(1000); 
      /* Send new file and clear flag */    
      send_file();
      state = WAIT_NEW_UPADTE ;
      Firebase.setInt("NewUpdate" , 0);
      break ;
      
    /************* Download the new update ***************/
    case NEW_UPDATE_DWN : 
      FIRMWARE_URL=Firebase.getString("url");
      Serial.println(FIRMWARE_URL);
      Fingerprint=Firebase.getString("Fingerprint");
      Serial.println(Fingerprint);
      int download_check = 1 ;
      while (download_check){
        download_check = Download_Firmware();
        }
      state = NEW_UPDATE ;
      break ;

    }
}


int Download_Firmware() {
  int error_code = 0 ;
  HTTPClient http;
  SPIFFS.format();
  f = SPIFFS.open(filename, "w");
  if(f)
  {
    http.begin(FIRMWARE_URL ,Fingerprint);
    int httpCode = http.GET();
    if (httpCode <= 0)
    {
        Serial.printf("HTTP failed, error: %s\n", 
        http.errorToString(httpCode).c_str());
        error_code = 1 ;
    return error_code ;
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
   return error_code ;
}

void send_file(void){
   char x = 0 ;
   char y = 0 ;
   Serial.print("here");
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
       for(int i=0;i<f.size();i++) //Read upto complete file size
       {
         x = f.read();
         if (x == '\r')
         {
          x = f.read();
          S.write(x);
          Serial.println ("f");
          while ( S.available() == 0);
          y = S.read();
          Serial.println (y);
         }
         else {
        S.write(x);
          }
       }
       f.close();  //Close file
       Serial.println("File Closed");
   }
  }


  

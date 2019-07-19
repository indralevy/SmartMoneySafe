#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include "Gsender.h"
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 
#include <SoftwareSerial.h>
#pragma region Globals
uint8_t connection_state = 0;                    // Connected to WIFI or not
//uint16_t reconnect_interval = 10000;             // If not connected wait time to try again
#pragma endregion Globals
//int s;
//String s;
char s;
String subject;
Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
WiFiServer server(80);
String header;
WiFiClient espClient;
int dataduit;

 
void setup()
{
    Serial.begin(115200);
    while(!Serial){
      
    }
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("Smart Money Safe");
//    Serial.println("Connected.");
//    Serial.println("");
//    Serial.println("WiFi Connected.");
//    Serial.print("IP address: ");
//    Serial.println(WiFi.localIP());
//    Serial.println("");
//    Serial.println("WiFi Connected.");
//    Serial.print("IP address: ");
//    Serial.println(WiFi.localIP());
//    Serial.println("Sensor Active");
    connection_state = WiFi.localIP();
    
    if(!connection_state)  // if not connected to WIFI
        Serial.println("GAK");
 //   Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
    subject = "SELAMAT DATANG DI SMART MONEY SAVE";
    if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Semua data uang yang masuk akan masuk ke email ini")) {
    
// Serial.println("Message send.");
    }
    else {
//        Serial.print("Error sending message: ");
        Serial.println(gsender->getError());
    }
}

void loop(){
  if (Serial.available())
    {
//       s = Serial.readString();
//       Serial.print(s.toInt());
          s = Serial.read();
          kirim();
    }
WiFiClient client = server.available();
if (client) {                             
//    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        //Serial.write(c);                    
        header += c;
        if (c == '\n') {                    
            if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            // Web Page Heading
            client.println("<body><h1>Smart Money Safe Link</h1>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
 }

}

void kirim(){
    if (s == 'A'){
    Serial.println("10K");
    subject = "UANG Rp. 10.000 TELAH MASUK";
    if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 10.000 Telah Masuk")) {
    Serial.println("Message send.");
    }
  }
  
else if(s == 'B'){
  Serial.println("5K");
   subject = "UANG Rp. 5.000 TELAH MASUK";
   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 5.000 Telah Masuk")) {
   Serial.println("Message send.");
   }
  }

else if(s == 'C'){
  Serial.println("2K");
   subject = "UANG Rp. 2.000 TELAH MASUK";
   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 2.000 Telah Masuk")) {
   Serial.println("Message send.");
   }
  }

else if(s == 'D'){
  Serial.println("1K");
   subject = "UANG Rp. 1.000 TELAH MASUK";
   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 1.000 Telah Masuk")) {
   Serial.println("Message send.");
   }
  }

else if(s == 'E'){
  Serial.println("50K");
   subject = "UANG Rp. 50.000 TELAH MASUK";
   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 50.000 Telah Masuk")) {
   Serial.println("Message send.");
    }
  }
  
else if(s == 'F'){
  Serial.println("100K");
  subject = "UANG Rp. 100.000 TELAH MASUK";
  if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 100.000 Telah Masuk")) {
  Serial.println("Message send.");
  }
 }

else if(s == 'G'){
  Serial.println("20K");
  subject = "UANG Rp. 20.000 TELAH MASUK";
  if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang Rp. 20.000 Telah Masuk")) {
  Serial.println("Message send.");
  }
 }

else{
 
}

}


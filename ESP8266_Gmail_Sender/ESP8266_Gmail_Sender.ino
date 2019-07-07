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
String s;
String subject;
//Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
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
    Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
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
       s = Serial.read();
       Serial.write(Serial.read());
       //kirim();
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
    if (s == "R20G25B16"){
    Serial.println("10K");
    subject = "UANG 10000 TELAH MASUK";
    Gsender *gsender = Gsender::Instance();
    if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 10000 Telah Masuk")) {
    Serial.println("Message send.");
    }
  delay(5000);
  }
  
//  if(s == '2'){
//  Serial.println("5K");
//   subject = "UANG 5000 TELAH MASUK";
//   Gsender *gsender = Gsender::Instance();
//   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 5000 Telah Masuk")) {
//   Serial.println("Message send.");
//   }
//  delay(5000);
//  }

//  if(s == '3'){
//  Serial.println("2K");
//   subject = "UANG 2000 TELAH MASUK";
//   Gsender *gsender = Gsender::Instance();
//   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 2000 Telah Masuk")) {
//   Serial.println("Message send.");
//   }
//  delay(5000);
 // }

//  if(s == '4'){
//  Serial.println("1K");
//   subject = "UANG 1000 TELAH MASUK";
//   Gsender *gsender = Gsender::Instance();
//   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 1000 Telah Masuk")) {
//   Serial.println("Message send.");
//   }
//  delay(5000);
//  }
//
//  if(s == '5'){
//  Serial.println("50K");
//   subject = "UANG 50000 TELAH MASUK";
//   Gsender *gsender = Gsender::Instance();
//   if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 50000 Telah Masuk")) {
//   Serial.println("Message send.");
//    }
//  delay(5000);
//  }
//  
//  if(s == '6'){
//  Serial.println("100K");
//  subject = "UANG 100000 TELAH MASUK";
//  if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 100000 Telah Masuk")) {
//  Serial.println("Message send.");
//  }
// delay(5000);
//
// }
//
//if(s == '7'){
//  Serial.println("20K");
//  subject = "UANG 20000 TELAH MASUK";
//  if(gsender->Subject(subject)->Send("indrajitalepro@gmail.com", "Uang 20000 Telah Masuk")) {
//  Serial.println("Message send.");
//  }
// delay(5000);
//
// }
}

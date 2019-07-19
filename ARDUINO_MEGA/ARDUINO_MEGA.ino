#include<SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display 

int s0 = 4;
int s1 = 5;
int s2 = 6;
int s3 = 7;
int out=8;
int enB = 9;
int in3 = 10;//high
int in4 = 11;//low
int button=12;
int led = 13;
int red = 0;
int green = 0;
int blue = 0;
int total = 0;
int jml = 0;
String str;

//int dataduit=0; 
void setup() {
   Serial.begin(115200);
   Serial1.begin(115200);
   lcd.init();
   lcd.setCursor(1,0);
   lcd.print("SMART MONEY");
   lcd.setCursor(1,1);
  lcd.print("SAFE Mark-I");
  lcd.clear();
  delay(5000);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(button, HIGH);
}

void loop()
{
  lcd.setCursor(1,0);
  lcd.print(total);
  //while(digitalRead(button)) 
  color();
  Serial.print("R Intensity:");
  Serial.print(red, DEC);
  Serial.print(" G Intensity: ");
  Serial.print(green, DEC);
  Serial.print(" B Intensity : ");
  Serial.print(blue, DEC);
//  str =String('R')+String(red)+String('G')+String(green)+String('B')+String(blue);
//  Serial1.println(str);
  Serial.println();
  
//  if (red < 55 && red > 32 && green < 66 && green > 47 && blue < 38 && blue > 25) 
     //if(digitalRead(button)==LOW) 
     if (red == 27 && green == 35 && blue == 22) 
     {
    digitalWrite(led, HIGH);
    jml=10;
    total=jml+total;
    Serial1.println('A');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("SEPULUH RIBU");
    Serial.println(" - (10 Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
  }
  
    else if (red == 21 && green == 30 && blue == 28)
  {
    digitalWrite(led, HIGH);
    jml=5;
    total=jml+total;
    Serial1.println('B');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("LIMA RIBU");
    Serial.println(" - (lima Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
    }


  else if (red == 27 && green == 30 && blue == 24)
  {
    digitalWrite(led, HIGH);
    jml=2;
    total=jml+total;
    Serial1.println('C');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("DUA RIBU");
    Serial.println(" - (Dua Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
    }

else if (red == 24 && green == 30 && blue == 26)
  {
    digitalWrite(led, HIGH);
    jml=1;
    total=jml+total;
    Serial1.println('D');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("SERIBU");
    Serial.println(" - (Se Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
    }

else if (red == 30 && green == 28 && blue == 19)
  {
    digitalWrite(led, HIGH);
    jml=50;
    total=jml+total;
    Serial1.println('E');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("LIMA PULUH RIBU");
    Serial.println(" - (LIMA PULUH RIBU)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
    }

else if (red == 17 && green == 28 && blue == 21)
  {
    digitalWrite(led, HIGH);
    jml=100;
    total=jml+total;
    Serial1.println('F');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("Srts Ribu");
    Serial.println(" - (Srts Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000); 
    }
    
else if (red == 28 && green == 29 && blue == 25)
  {
    digitalWrite(led, HIGH);
    jml=20;
    total=jml+total;
    Serial1.println('G');
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(total);
    lcd.setCursor(1,1);
    lcd.print("Dua Puluh Ribu");
    Serial.println(" - (Dua Puluh Ribu)");
    Serial.println(total);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);
    delay(5000);
    }

  else {
    Serial.println("COBA LAGI");
  }
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(led, LOW);   
  delay(500);
}


void color()
{
digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
//count OUT, pRed, RED
red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s3, HIGH);
//count OUT, pBLUE, BLUE
blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s2, HIGH);
//count OUT, pGreen, GREEN
green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}




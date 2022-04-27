#include <Ethernet.h>
#include <SPI.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,200);

#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BOTTONE 2
int xx = 0, yy = 0;
IPAddress server(192,168,1,103);//il mio
EthernetClient client;

void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_BOTTONE, INPUT_PULLUP);
  
  Ethernet.begin(mac, ip);
}

void loop() {
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);
  int bottone = !digitalRead(JOYSTICK_BOTTONE);
  
   if(x > 600){
    xx = 1;

  }else if(x < 400){
    xx = -1;
   
  }else if(y > 600){
    yy = -1;
    
  }else if(y < 400){
    yy = 1;
  }

  Serial.print("X: " + String(xx));
  Serial.print("\tY: " + String(yy));
  Serial.println("P: " + String(bottone));
  
  
  
  if(client.connect(server,8000)){
    if(xx==1 || xx==-1 || yy==1 || yy==-1){
    client.print("GET /test/write_data.php?");
    Serial.print("GET /test/write_data.php?");
    client.print("valuex=");
    Serial.print("valuex=");
    client.print(digitalRead(JOYSTICK_X));
    Serial.print(digitalRead(JOYSTICK_X));
    client.print("&valuey=");
    Serial.print("&valuey=");
    client.print(digitalRead(JOYSTICK_Y));
    Serial.print(digitalRead(JOYSTICK_Y));
    client.print("&valuep=");
    Serial.print("&valuep=");
    client.print(bottone);
    Serial.print(bottone);

    client.println(" HTTP/1.1");
    client.println("Host: 192.168.1.103");

    client.println("Connection: close");
    client.println();
    client.println();
    //client.stop();
    }else{
      Serial.println("--> non funziona\n");
    }
  }else {
    Serial.println("--> connection failed\n");
  }
    delay(400);
}

#include <Ethernet.h>
#include <SPI.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,200);

#define JOYSTICK_X 4
#define JOYSTICK_Y 5
#define JOYSTICK_BOTTONE 2
//int xx = 0, yy = 0;
IPAddress server(192,168,1,103);//il mio
EthernetClient client;

void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_BOTTONE, INPUT_PULLUP);

  Ethernet.begin(mac, ip);
}

void loop() {
  int x = !digitalRead(JOYSTICK_X);
  int y = !digitalRead(JOYSTICK_Y);
  int bottone = !digitalRead(JOYSTICK_BOTTONE);
  
  /*  if(x > 600){
    //contatorex++;
    xx = 1;
    Serial.println(xx);
    //Serial.println("destra: " + String(contatorex));
  }else if(x < 400){
    //contatorex--;
    xx = -1;
    Serial.println(xx);
    //Serial.println("sinistra: " + String(contatorex));
  }else if(y > 600){
    //contatorey--;
    yy = -1;
    Serial.println(yy);
    //Serial.println("basso: " + String(contatorey));
    
  }else if(y < 400){
    //contatorey++;
    yy = 1;
    Serial.println(yy);
    //Serial.println("alto: " + String(contatorey));
  }
*/
  Serial.print("X: " + String(x));
  Serial.print("\tY: " + String(y));
  Serial.println("P: " + String(bottone));
  if(client.connect(server,8000) && (x==1 || x==-1 || y==1 || y==-1 || bottone==1)){
    client.print("GET /test/write_data.php?");
    Serial.print("GET /test/write_data.php?");
    client.print("valuex=");
    Serial.print("valuex=");
    client.print(x);
    Serial.print(x);
    client.print("&valuey=");
    Serial.print("&valuey=");
    client.print(y);
    Serial.print(y);
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
  }else {
    Serial.println("--> connection failed\n");
  }
    delay(400);
}

#define MOTOR  9
int recieveByte = 0;
String bufferStr = "";
String okStr = "OK";

void setup() {
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bufferStr = "";
  while (Serial.available() > 0) {
    recieveByte = Serial.read();
    if (recieveByte == (int)'\n') break;
    bufferStr.concat((char)recieveByte);
  }

  // 受け取ったデータがあるなら送りかえしてスイッチ操作
  if (bufferStr.length() > 0) {
    Serial.print("I received: "); 
    Serial.println(bufferStr);
    if (okStr.compareTo(bufferStr) == 0) {
      for ( int val = 160; val > -1; val -= 20 ) {
    analogWrite(MOTOR, val );
    delay(1000);}
      
    } else {
      analogWrite(MOTOR, LOW);
    }
  }

  delay(1000);
}

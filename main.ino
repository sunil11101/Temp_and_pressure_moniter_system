#include<SoftwareSerial.h>


SoftwareSerial serial(6,7);

void setup() {

  Serial.begin(115200);
  serial.begin(115200);

  Serial.println("Initializing Wifi...");
  while(!command_test())
   AT_send("AT");
  while(!command_test())
   AT_send("AT+CWMODE=2"); 
  while(!command_test())
   AT_send("AT+CWSAP=\"Master_Temp\",\"87651234\",1,4");
   

   Serial.println("Wifi is Attached....");

}

/****For Sending a AT command to wifi module *****/
void AT_send(String  command)
{
  while(!serial.available())
  {
  command+="\r\n";
  int len=command.length()+1;
  char ar[len]; 
  command.toCharArray(ar,len); 
  serial.write(ar);
  delay(20);
  }
}

/*** For testing command return value *****/
bool command_test()
{
  while(serial.available())
  {
    if(serial.read()=='O');
     if(serial.read()=='K')
      return true;
  }
  return false;
}

void loop() {

  if(Serial.available())
  serial.write(Serial.read());
  if(serial.available())
  Serial.write(serial.read());
  // put your main code here, to run repeatedly:

}

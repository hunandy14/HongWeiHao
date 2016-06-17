/**********************************************************
Name : 
Date : 2016/06/17
By   : CharlotteHonG
Final: 2016/06/17
**********************************************************/
#define Usb_Uart 9600
#define Led 13
#include "fun.h"

void setup() {
    Serial.begin(Usb_Uart);
    Serial.println("Welcom Arduino!");
    pinMode(Led, OUTPUT);

    Demo a(1);
    Serial.println(a.get());
}
void loop() {
    
}
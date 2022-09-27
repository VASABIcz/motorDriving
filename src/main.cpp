#include "Arduino.h"
#include "statefull/Driverbts7960state.h"

int RPWM=17;
int LPWM=19;
// timer 0
int L_EN=23;
int R_EN=32;

Driverbts7960state motor = Driverbts7960state(LPWM, RPWM, L_EN, R_EN);

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("setup begin");

    motor.spinRight(20);
    delay(3000);
}

/*
void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("setup begin");
    // put your setup code here, to run once:

    pinMode(RPWM,OUTPUT);
    pinMode(LPWM,OUTPUT);
    pinMode(L_EN,OUTPUT);
    pinMode(R_EN,OUTPUT);

    pinMode(DRIVER_POWER, OUTPUT);

    digitalWrite(RPWM,LOW);
    digitalWrite(LPWM,LOW);
    digitalWrite(L_EN,LOW);
    digitalWrite(R_EN,LOW);

    digitalWrite(DRIVER_POWER, HIGH);

    Serial.println("setup done");
    delay(1000);
    Serial.println("EN High");
    digitalWrite(R_EN,HIGH);
    digitalWrite(L_EN,HIGH);
    delay(500);
    analogWrite(RPWM, 20);
}
 */

void loop() {
    motor.inverse();
    delay(2000);
    /*
    // put your main code here, to run repeatedly:
    Serial.println("EN High");
    digitalWrite(R_EN,HIGH);
    digitalWrite(L_EN,HIGH);
    delay(1000);
    for(int i=0;i<256;i++){
        analogWrite(RPWM,i);
//  analogWrite(LPWM,255-i);
        delay(100);
    }
    delay(500);
    for(int i=255;i>0;i--){
        analogWrite(RPWM,i);
// analogWrite(LPWM,255-i);
        delay(100);
    }
    delay(500);
    Serial.println("EN LOW");
    digitalWrite(R_EN,HIGH);
    digitalWrite(L_EN,HIGH);
    delay(1000);
    for(int i=0;i<256;i++){
        analogWrite(LPWM,i);
        delay(100);
    }
    delay(500);
    for(int i=255;i>0;i--){
        analogWrite(LPWM,i);
        delay(100);
    }
    delay(500);
     */
}

// THIS IS SOMEWHAT WORKING PART
/*
 #include "Arduino.h"

int RPWM=17;
int LPWM=19;
// timer 0
int L_EN=23;
int R_EN=32;

int DRIVER_POWER = 22;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("setup begin");
    // put your setup code here, to run once:

    pinMode(RPWM,OUTPUT);
    pinMode(LPWM,OUTPUT);
    pinMode(L_EN,OUTPUT);
    pinMode(R_EN,OUTPUT);

    pinMode(DRIVER_POWER, OUTPUT);

    digitalWrite(RPWM,LOW);
    digitalWrite(LPWM,LOW);
    digitalWrite(L_EN,LOW);
    digitalWrite(R_EN,LOW);

    digitalWrite(DRIVER_POWER, HIGH);

    Serial.println("setup done");
    delay(1000);
}



void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("EN High");
    digitalWrite(R_EN,HIGH);
    digitalWrite(L_EN,HIGH);
    delay(1000);
    for(int i=0;i<256;i++){
        analogWrite(LPWM,i);
//  analogWrite(LPWM,255-i);
        delay(100);
    }
    delay(500);
    for(int i=255;i>0;i--){
        analogWrite(LPWM,i);
// analogWrite(LPWM,255-i);
        delay(100);
    }
    delay(500);
    Serial.println("EN LOW");
    digitalWrite(R_EN,LOW);
    digitalWrite(L_EN,LOW);
    delay(1000);
    for(int i=0;i<256;i++){
        analogWrite(RPWM,i);
        delay(100);
    }
    delay(500);
    for(int i=255;i>0;i--){
        analogWrite(RPWM,i);
        delay(100);
    }
    delay(500);
}

 */
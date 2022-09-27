//
// Created by vasabi on 9/27/22.
//
#include "DriverBTS7960.h"
#include "Arduino.h"

void Driverbts7960::begin(int lpwm, int rpwm, int r_en, int l_en) {
    pinMode(rpwm,OUTPUT);
    pinMode(lpwm,OUTPUT);
    pinMode(l_en,OUTPUT);
    pinMode(r_en,OUTPUT);

    digitalWrite(rpwm,LOW);
    digitalWrite(lpwm,LOW);
    digitalWrite(l_en,LOW);
    digitalWrite(r_en,LOW);
}

void Driverbts7960::spin(unsigned char speed, bool right) const {
    digitalWrite(r_en,HIGH);
    digitalWrite(l_en,HIGH);

    // TODO better solution
    // assert(speed <= 255 && speed >= 0);
    if (right) {
        analogWrite(lpwm, 0);
        analogWrite(rpwm, speed);
    }
    else {
        analogWrite(rpwm, 0);
        analogWrite(lpwm, speed);
    }
}

void Driverbts7960::spinLeft(unsigned char speed) const {
    spin(speed, false);
}

void Driverbts7960::spinRight(unsigned char speed) const {
    spin(speed, true);
}
//
// Created by vasabi on 9/27/22.
//

#ifndef MOTORDRIVING_DRIVERBTS7960_H
#define MOTORDRIVING_DRIVERBTS7960_H

#include "Arduino.h"

class Driverbts7960 {
private:
    int lpwm, rpwm, r_en, l_en;
public:
    explicit Driverbts7960(int lpwm, int rpwm, int l_en, int r_en) {
        this->lpwm = lpwm;
        this->rpwm = rpwm;
        this->l_en = l_en;
        this->r_en = r_en;

        pinMode(rpwm,OUTPUT);
        pinMode(lpwm,OUTPUT);
        pinMode(l_en,OUTPUT);
        pinMode(r_en,OUTPUT);

        digitalWrite(rpwm,LOW);
        digitalWrite(lpwm,LOW);
        digitalWrite(l_en,LOW);
        digitalWrite(r_en,LOW);
    }

    /// this function will set output mode for all the pins
    /// and set to low
    static void begin(int lpwm, int rpwm, int r_en, int l_en);

    /// this function will write tor rpwm if right is true else lpwm
    /// speed is unsigned byte from 0-255
    void spin(unsigned char speed, bool right = true) const;

    void spinRight(unsigned char speed) const;

    void spinLeft(unsigned char speed) const;
};
#endif //MOTORDRIVING_DRIVERBTS7960_H

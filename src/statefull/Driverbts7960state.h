//
// Created by vasabi on 9/27/22.
//

#ifndef MOTORDRIVING_DRIVERBTS7960state_H
#define MOTORDRIVING_DRIVERBTS7960state_H

#include "Arduino.h"

class Driverbts7960state {
private:
    int lpwm, rpwm, r_en, l_en;
    unsigned char speed = 0;
    bool isRight = true;
public:
    // create new instance and setup pins
    explicit Driverbts7960state(int lpwm, int rpwm, int l_en, int r_en) {
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

    /// this function will write tor rpwm if right is true else lpwm
    /// speed is unsigned byte from 0-255
    void spin(unsigned char speed, bool right = true);

    void spinRight(unsigned char speed);

    void spinLeft(unsigned char speed);

    void spinSlower(unsigned char speed);

    void spinFaster(unsigned char speed);

    void inverse();

    bool isSpinningRight() const;

    unsigned char getSpeed() const;

    void setSpeed(unsigned char );
};
#endif //MOTORDRIVING_DRIVERBTS7960state_H

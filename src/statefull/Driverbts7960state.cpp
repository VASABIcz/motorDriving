//
// Created by vasabi on 9/27/22.
//
#include "Driverbts7960state.h"
#include "Arduino.h"

void Driverbts7960state::spin(unsigned char speed, bool right) {
    this->isRight = right;

    setSpeed(speed);

    // FIXME i dont know why but cant be called just once in constructor
    digitalWrite(r_en,HIGH);
    digitalWrite(l_en,HIGH);

    if (right) {
        // set reverse rotation to 0
        analogWrite(lpwm, 0);
        analogWrite(rpwm, this->speed);
    }
    else {
        analogWrite(rpwm, 0);
        analogWrite(lpwm, this->speed);
    }
}

void Driverbts7960state::spinLeft(unsigned char speed) {
    spin(speed, false);
}

void Driverbts7960state::spinRight(unsigned char speed) {
    spin(speed, true);
}

void Driverbts7960state::inverse() {
    spin(this->speed, !this->isRight);
}

unsigned char Driverbts7960state::getSpeed() const {
    return this->speed;
}

bool Driverbts7960state::isSpinningRight() const {
    return this->isRight;
}

void Driverbts7960state::setSpeed(unsigned char speed) {
    this->speed = speed;
    // this should not be needed because unsigned char has 0 -> 255 possible values that's just right amount for driver
    // but it could help prevent overflows and underflows not sure
    if (this->speed > 255) this->speed = 255;
    else if (this->speed < 0) this->speed = 0;
}

void Driverbts7960state::spinFaster(unsigned char speed) {
    setSpeed(this->speed+speed);
    spin(this->speed, this->isRight);
}

void Driverbts7960state::spinSlower(unsigned char speed) {
    setSpeed(this->speed-speed);
    spin(this->speed, this->isRight);
}

#include <wiringPi.h>
#include "Sonar.h"
#include <iostream>


// Constructeur
Sonar::Sonar(int trigger, int echo) {

    this->Trigger = trigger;
    this->Echo = echo;

}

// Destructeur
Sonar::~Sonar() {

}

void Sonar::Init(int trigger, int echo) {

    this->Trigger = trigger;
    this->Echo = echo;
    pinMode(Trigger, OUTPUT);
    pinMode(Echo, INPUT);
    digitalWrite(Trigger, LOW);
    delay(500);
}

double Sonar::Distance() {

    delay(10);

    // Envoie une Impulsion
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);

    // D�but Chrono / Attente remise a zero Echo
    while (digitalRead(Echo) == 0);
    Debut = micros();

    // Fin Chrono / R�c�ption Impulsion
    while (digitalRead(Echo) == 1);
    Fin = micros();

    // Calcule temps d'�mission
    Temps = Fin - Debut;

    // Appele la m�thode Calcule qui permet de calculer la distance en fonction du temps
    Calcule();
}

double Sonar::Calcule() {

    distance = 100 * ((Temps / 1000000.0) * 340.29) / 2;
    std::cout << "distance : " << distance << std::endl;
    return distance;

}

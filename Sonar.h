#pragma once
class Sonar
{

private:

	int Trigger; // Broche Trigger
	int Echo; // Broche Echo
	double distance; // Distance
	volatile long Debut; // Variable Debut Chrono
	volatile long Fin; // Variable Fin Chrono
	long Temps; // Variable Temps d'émission

public:
	void Init(int trigger, int echo); // Initialise le Capteur
	double Distance(); // Calcule le temps d'émission
	double Calcule(); // Calcule la distance en fonction du temps d'émission

	Sonar(int trigger = 23, int echo = 24); // Constructeur
	~Sonar(); // Destructeur
};


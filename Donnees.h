#pragma once
#include "Sonar.h"
#include "Gps.h"
class Donnees
{

private:

	Sonar Sonar1;
	Gps GPS;
	double Profondeur;
	string Longitude;
	string Latitude;
	gps_data donneGps;

public:

	Donnees();
	~Donnees();

	void Initialisation(int trigger, int echo);
	void Acquisition(void);
	double GetProfondeur(void);
	string GetLongitude(void);
	string GetLatitude(void);


};


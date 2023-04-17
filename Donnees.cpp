#include "Donnees.h"
#include "Sonar.h"
#include <iostream>

Donnees::Donnees()
{
	//Sonar* Sonar1;
	//Sonar1 = new Sonar;

}

Donnees::~Donnees()
{
}

void Donnees::Initialisation(int trigger = 23, int echo = 24)
{
	Sonar1.Init(trigger, echo);
}

void Donnees::Acquisition(void)
{

	Profondeur = Sonar1.Distance();
	//std::cout << "Profondeur : " << Profondeur << std::endl;
	donneGps = GPS.AcquisitionGps();
	//cout << "latitude : " << donneGps.latitude << " longitude : " << donneGps.longitude;
}

double Donnees::GetProfondeur(void)
{
	cout << "return profondeur : " << Profondeur << endl;
	return Profondeur;
}

string Donnees::GetLongitude(void)
{
	cout << "return longitude : " << donneGps.longitude << endl;
	return donneGps.longitude;
}

string Donnees::GetLatitude(void)
{
	cout << "return latitude : " << donneGps.latitude << endl;
	return donneGps.latitude;
}

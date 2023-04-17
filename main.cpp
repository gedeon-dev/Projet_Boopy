#include <wiringPi.h>
#include <iostream>
#include "Donnees.h"
#include "Fichier.h"
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Broche LED - La broche WiringPi 0 est BCM_GPIO 17.
// nous devons utiliser la numérotation BCM au moment de l'initialisation à l'aide de wiringPiSetupSys
// si vous choisissez un autre numéro de broche, utilisez la numérotation BCM, et
// mettez à jour la commande Pages de propriétés - Événements de build - Événement postbuild distant
// qui utilise l'exportation gpio pour la configuration de wiringPiSetupSys
#define	trigger 23
#define	echo 24

void* tache1(void*);
void* tache2(void*);

int main(void)
{
	wiringPiSetupGpio();

//	Donnees Capteurs;
//	Fichier fichier1 = Fichier(1, 2, 3);

//	Capteurs.Initialisation(trigger, echo);
	 

	/*
	while (true)
	{
		delay(500);
		Capteurs.Acquisition();
		cout << "test" << endl;
		Profondeur = Capteurs.GetProfondeur();
		fichier1.enregistre_Fichier(0, 0, Profondeur);

	}
	*/

	pthread_t thread1, thread2;
	cout << "debut" << endl;
	pthread_create(&thread1, NULL, tache1, NULL);
	pthread_create(&thread2, NULL, tache2, NULL);
	cout << "fin" << endl;
	while (true)
	{
	}
	// return 0;
}

void* tache1(void*) // Mesure la profondeur / Géolocalise les données / les dates / Puis les enregistre au format CSV / Toutes les 2 Secondes
{
	Donnees Capteurs;
	Fichier fichier1 = Fichier("a", "a", 3);
	Capteurs.Initialisation(trigger, echo);
	//double Profondeur;
	double ProfondeurThread1;
	string LongitudeThread1;
	string LatitudeThread1;
	while (true)
	{
		delay(2000);
		Capteurs.Acquisition();
		//cout << "test" << endl;
		ProfondeurThread1 = Capteurs.GetProfondeur();
		LongitudeThread1 = Capteurs.GetLongitude();
		LatitudeThread1 = Capteurs.GetLatitude();
		fichier1.enregistre_Fichier(LongitudeThread1, LatitudeThread1, ProfondeurThread1);
	}
}

void* tache2(void*) // Envoie la position de la bouée toutes les 10 secondes a l'IHM
{
	Donnees Capteurs;
	string LongitudeThread2;
	string LatitudeThread2;

	while (true)
	{
		delay(10000);
		LongitudeThread2 = Capteurs.GetLongitude();
		LatitudeThread2 = Capteurs.GetLatitude();
	}
}

#include "Fichier.h"

Fichier::Fichier(string longitude, string latitude, float profondeur)
{
}

void Fichier::enregistre_Fichier(string longitude =0, string latitude=0, double profondeur=0)
{
	//manipulation de la date et de l'heure

	time_t timestampActuel; // r�cup�re  timestampactuel
	time(&timestampActuel); // initialise la methode time avec le timestampActuel
	tm* dateHeure = localtime(&timestampActuel); //strut tm de la librairie ctime
	heure = "" + to_string(dateHeure->tm_hour) + "h:" + to_string(dateHeure->tm_min) + "mn";
	date = "" + to_string(dateHeure->tm_mday) + "-" + to_string(1 + dateHeure->tm_mon) + "-" + to_string(1900 + dateHeure->tm_year);


	//traitement du fichier

	ofstream file("batymetrique.csv", ios::app); // on ouvre le flux en mode ajout
	file.seekp(0, ios::end); // on se place en fin de fichier
	int taille = file.tellp(); // on recup�re la taille
	file << date << "  ;  " << heure << "  ;  " << profondeur << "  ;  " << latitude << "  ;  " << longitude << endl;
	cout << date << ";" << heure << "  ;  " << profondeur << "  ;  " << latitude << "  ;  " << longitude << endl;
	/*
	if (taille != 0) {
		file << date << ";" << heure << ";" << "40" << ";" << "22343" << ";" << "5545" << endl;
		file << date << ";" << heure << ";" << "50" << ";" << "22353" << ";" << "5555" << endl;
		file << date << ";" << heure << ";" << "60" << ";" << "22363" << ";" << "5565" << endl;
	}
	else {
		file << "date" << ";" << "heure" << ";" << "profondeur" << ";" << "latitude" << ";" << "longitude" << endl;
		file << date << ";" << heure << ";" << "20" << ";" << "22323" << ";" << "5525" << endl;
		file << date << ";" << heure << ";" << "30" << ";" << "22333" << ";" << "5535" << endl;
		file << date << ";" << heure << ";" << "40" << ";" << "22343" << ";" << "5545" << endl;
		file << date << ";" << heure << ";" << "50" << ";" << "22353" << ";" << "5555" << endl;
		file << date << ";" << heure << ";" << "60" << ";" << "22363" << ";" << "5565" << endl;
	}
	*/
}

Fichier::~Fichier()
{
}

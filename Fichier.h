#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
class Fichier
{
private:
	double profondeur = {};
	string longitude = {};
	string latitude = {};
	string heure = "";
	string date = "";

public:
	Fichier(string longitude, string latitude, float profondeur);
	void enregistre_Fichier(string longitude, string latitude, double profondeur);
	~Fichier();
};


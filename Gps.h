#pragma once
#include "wiringPi.h"
#include <string>
#include <vector>
#include <iostream>
#include <wiringSerial.h>
using namespace std;
struct gps_data {
	string latitude;
	string longitude;
};
class Gps
{
private:
	gps_data donneeGPS;
	int fd;
	char c;
	string line = "";
	vector <string> trameLine;
public:
	Gps();
	~Gps();
	gps_data AcquisitionGps();

	//cette methode n'est pas utilisée!!
	gps_data EnregistrementGps();
};


#include "Gps.h"

Gps::Gps()
{
	wiringPiSetupGpio();
	fd = serialOpen("/dev/serial0", 9600);
}

Gps::~Gps()
{
}

gps_data Gps::AcquisitionGps()
{
	while (fd != -1) {
		c = serialGetchar(fd);
		line = line + c;
		if (c == '\n') {
			trameLine.push_back(line);
			for (size_t i = 0; i < trameLine.size(); i++) {
				string trameDebut = trameLine[i].substr(0, 6);
				if (trameDebut == "$GPGGA") {
					//cout << trameLine[i];
					donneeGPS.latitude = trameLine[i].substr(18, 9);
					donneeGPS.longitude = trameLine[i].substr(30, 10);
					return donneeGPS;
				}
			}
			line = "";
		}
	}
}


// Cette methode n'est pas utilis�!!
gps_data Gps::EnregistrementGps()
{
	for (size_t i = 0; i < trameLine.size(); i++) {
		//cout << trameLine.size() << endl;
		donneeGPS.latitude = "";
		donneeGPS.longitude = "";
		string trameDebut = trameLine[i].substr(0, 6);
		cout << trameLine[i] << endl;
		if (trameDebut == "$GPGGA") {
			cout << trameLine[i];
			donneeGPS.latitude = trameLine[i].substr(18, 9);
			donneeGPS.longitude = trameLine[i].substr(30, 10);
			//cout << donneeGPS.latitude << endl;
			//cout << donneeGPS.longitude << endl;
			return donneeGPS;
		}
	}
	return donneeGPS;
}

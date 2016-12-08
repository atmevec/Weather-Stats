/*Author: Alexander Mevec
Description: This program will allow a user to enter as many months
of weather statistics as they would like then displays the months
and the max/min values out of all the months for rain, snow, and sun.
*/

#include "WeatherStats.h"

//************************************************************
// WeatherStats constructor. Populates the object with the default
// invalid values.
//************************************************************

WeatherStats::WeatherStats()
{
	SetRain(-1);
	SetSnow(-1);
	SetRain(-1);
}

//************************************************************
// WeatherStats constructor. Populates the object with the values
// of the rainTotal, snowTotal, and sunnyDays.
//************************************************************

WeatherStats::WeatherStats(double rainTotal, double snowTotal, int sunnyDays)
{
	SetRain(rainTotal);
	SetSnow(snowTotal);
	SetSun(sunnyDays);
}

//************************************************************
// GetRain returns the value of rainTotal as a double.
//************************************************************

double WeatherStats::GetRain()
{
	return rainTotal;
}

//************************************************************
// GetSnow returns the value of snowTotal as a double.
//************************************************************

double WeatherStats::GetSnow()
{
	return snowTotal;
}

//************************************************************
// GetSun returns the value of sunnyDays as an integer.
//************************************************************

int WeatherStats::GetSun()
{
	return sunnyDays;
}

//************************************************************
// SetRain sets the value of rainTotal to the function argument.
//************************************************************

void WeatherStats::SetRain(double rainTotal)
{
	this->rainTotal = rainTotal;
}

//************************************************************
// SetSnow sets the value of snowTotal to the function argument.
//************************************************************

void WeatherStats::SetSnow(double snowTotal)
{
	this->snowTotal = snowTotal;
}

//************************************************************
// SetSun sets the value of sunTotal to the function argument.
//************************************************************

void WeatherStats::SetSun(int sunnyDays)
{
	this->sunnyDays = sunnyDays;
}

//************************************************************
// Overloaded output operator to allow the object to be displayed
// in the correct format.
//************************************************************

ostream &operator<<(ostream &strm, WeatherStats & obj)
{
	strm << "Total rain: " << obj.rainTotal << " inches" << endl
		 << "Total snow: " << obj.snowTotal << " inches" << endl
		 << "Total sun: " << obj.sunnyDays << " days" << endl;
	return strm;
}
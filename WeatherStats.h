/*Author: Alexander Mevec
Description: This program will allow a user to enter as many months
of weather statistics as they would like then displays the months
and the max/min values out of all the months for rain, snow, and sun.
*/

#pragma once
#include <iostream>

using namespace std;

class WeatherStats
{
	public:
		WeatherStats();
		WeatherStats(double rainTotal, double snowTotal, int sunnyDays);
		double GetRain();
		double GetSnow();
		int GetSun();
		void SetRain(double rainTotal);
		void SetSnow(double snowTotal);
		void SetSun(int sunnyDays);
		friend ostream &operator<<(ostream &strm, WeatherStats &obj);

	private:
		double rainTotal;
		double snowTotal;
		int sunnyDays;
};


/*Author: Alexander Mevec
Description: This program will allow a user to enter as many months
of weather statistics as they would like then displays the months
and the max/min values out of all the months for rain, snow, and sun.
*/

#include <string>
#include "LinkedList.h"
#include "WeatherStats.h"

void WeatherHighLow(LinkedList<WeatherStats>* list, int size)
{
	/*
	Initial Algorithm :
	1.Initialize data
	2.Set starting point
	3.FOR all following List Nodes
		4.Get stats
		5.Check maxes and mins
	END FOR
	6.Display the maxes and mins

	Refined Algorithm :
	1.Initialize data
	2.Set starting point
	3.FOR all following List Nodes
		4.Get stats
		5.Check maxes and mins
		IF current > stored
			Set max
		ELSE IF current < stored
			Set min
		END IF
		IF current > stored
			Set max
		ELSE IF current < stored
			Set min
		END IF
		IF current > stored
			Set max
		ELSE IF current < stored
			Set min
		END IF
	END FOR
	6.Display the maxes and mins
	*/

	//Initialize data
	double maxRain, minRain, maxSnow, minSnow;
	int maxSun, minSun;
	WeatherStats temp;
	
	//Set starting point
	temp = list->GetNode(0);
	maxRain = temp.GetRain();
	minRain = maxRain;
	maxSnow = temp.GetSnow();
	minSnow = maxSnow;
	maxSun = temp.GetSun();
	minSun = maxSun;

	//For all following List Nodes
	for (int i = 1; i < size; i++)
	{

		//Get stats
		WeatherStats current;
		current.SetRain(list->GetNode(i).GetRain());
		current.SetSnow(list->GetNode(i).GetSnow());
		current.SetSun(list->GetNode(i).GetSun());

			
		//If current > stored
		if (current.GetRain() > maxRain)

			//Set max
			maxRain = current.GetRain();

		//Else if current < stored
		else if (current.GetRain() < minRain)

			//Set min
			minRain = current.GetRain();

		//If current > stored
		if (current.GetSnow() > maxSnow)

			//Set max
			maxSnow = current.GetSnow();

		//Else if current < stored
		else if (current.GetSnow() < minSnow)

			//Set min
			minSnow = current.GetSnow();

		//If current > stored
		if (current.GetSun() > maxSun)

			//Set max
			maxSun = current.GetSun();

		//Else if current < stored
		else if (current.GetSun() < minSun)

			//Set min
			minSun = current.GetSun();
	}

	//Display the maxes and mins
	cout << "Max rain: " << maxRain << " inches" << endl
		 << "Min rain: " << minRain << " inches" << endl << endl
		 << "Max snow: " << maxSnow << " inches" << endl
		 << "Min snow: " << minSnow << " inches" << endl << endl
		 << "Max sun: " << maxSun << " days" << endl
		 << "Min sun: " << minSun << " days" << endl << endl;
}

int main()
{
	/*
	Initial Algorithm :
	1.Initialize data
	2.Request number of months
	3.FOR all months
		4.Get the variables
		5.Set the variables
		6.Append new object
	END FOR
	7.Display the list
	8.Show highs/lows
	9.EOP

	Refined Algorithm :
	1.Initialize data
	2.Request number of months
	3.FOR all months
		4.Get the variables
		5.Set the variables
		6.Append new object
	END FOR
	7.Display the list
	8.Show highs/lows
	9.EOP
	*/

	//Initialize data
	LinkedList<WeatherStats> list;
	int numMonths;

	//Request number of months
	cout << "Enter a number of months: ";
	cin >> numMonths;
	cout << endl;

	//For all months
	for (int i = 0; i < numMonths; i++)
	{
		WeatherStats temp;
		double tempRain, tempSnow;
		int tempSun;

		//Get the variables
		cout << "Enter the total inches of rain for month " << i + 1 <<
			": ";
		cin >> tempRain;
		cout << "Enter the total inches of snow for month " << i + 1 <<
			": ";
		cin >> tempSnow;
		cout << "Enter the total days of sun for month " << i + 1 <<
			"   : ";
		cin >> tempSun;
		cout << endl;

		//Set the new variables
		temp.SetRain(tempRain);
		temp.SetSnow(tempSnow);
		temp.SetSun(tempSun);

		//Append new object
		list.AppendNode(temp);
	}

	//Display the list
	cout << "The months you entered:" << endl;
	list.DisplayList();

	//Show highs/lows
	cout << "Record numbers for these months:" << endl;
	WeatherHighLow(&list, numMonths);

	//EOP
	return 0;
}
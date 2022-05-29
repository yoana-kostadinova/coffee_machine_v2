#include "cup_of_coffee_v2.h"
#include "coffee_machine_v2.h"
#include <iostream>


cup_of_coffee_v2::cup_of_coffee_v2()
{
	content = 0;

}

bool cup_of_coffee_v2::menu()
{
	int choose;
	std::cout << "\n*****************************************************************\n";
	std::cout << "\nNow you can either drink your coffee,\nor throw away your cup and make a new one\n";
	std::cout << "Have in mind that a sip of coffee is 25 ml,\na small coffee is 50 ml\n a normal coffee is 100 ml\n  and a long coffee is 150ml\n";
	do
	{
		std::cout << "\nTo drink coffee, press 1\n";
		std::cout << "To check how much coffee is there in the cup, press 2\n";
		std::cout << "To throw away your cup, press 3\n";
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			do 
			{ 
				drink(); 
				return false;
			} while (drink() == true);

				if(drink()== false)
				{
					return true; 
				}
			
			break;
		case 2:
			check();
			return false;
			break;
		case 3:
			return true;

		default:
			std::cout << "Invalid choice";
			return false;
		}
	} while (choose != 3);
}
void cup_of_coffee_v2::fill(int a)
{
	content = a;
}
void cup_of_coffee_v2::check()
{
	std::cout << "\n*****************************************************************\n";
	std::cout << "The cup is filled with "<<content;
	std::cout << " mls of coffee";
}
bool cup_of_coffee_v2::drink()
{
	if (content < sip)
	{
		std::cout << "\n*****************************************************************\n";
		std::cout << "\nCongratulations!You've drinked your coffee!\n";
		return false;
	}
	else 
	{
		content -= sip;
		std::cout << "\n*****************************************************************\n";
		std::cout << "\nYou've had one sip of coffee!\n";
		return true;
	}

}


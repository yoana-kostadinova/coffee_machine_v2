#include "coffee_machine_v2.h"
#include "user_interface_v2.h"

coffee_machine_v2::coffee_machine_v2()
{
	number_of_cups = 0;
	mls_of_water = 0;
	grams_of_coffee = 0;
	grams_of_sugar = 0;	
	
}

void coffee_machine_v2::autofill() 
{
	number_of_cups = 2;
	mls_of_water = 300;
	grams_of_coffee = 100;
	grams_of_sugar = 100;
}
void coffee_machine_v2::fill(int b, int a)
{
	switch (b)
	{
	case 1:		
		number_of_cups += a;
		break;

	case 2:		
		mls_of_water += a;
		break;

	case 3:		
		grams_of_coffee += a;
		break;

	case 4:		
		grams_of_sugar += a;
		break;			
	}

}

void coffee_machine_v2::sugar(int a)
{
	switch (a)
	{
	case 1:
		grams_of_sugar -= 10;
		break;

	case 0:
		break;
	}
}

std::auto_ptr<cup_of_coffee_v2> coffee_machine_v2::make_coffee(int b)
{	

	std::auto_ptr<cup_of_coffee_v2> cup;



	switch (b)
	{
	case 1:		
		number_of_cups--;
		mls_of_water -= 50;
		grams_of_coffee -= 10;
		cup = std::auto_ptr<cup_of_coffee_v2>(new cup_of_coffee_v2());

		if (cup.get() != nullptr)
			cup->fill(50); 
		// ��� (*cup).fill;
		break;

	case 2:	
		number_of_cups--;
		mls_of_water -= 100;
		grams_of_coffee -= 20;	
			
		cup = std::auto_ptr<cup_of_coffee_v2>(new cup_of_coffee_v2());

//		cup = (std::auto_ptr<cup_of_coffee_v2>)(new cup_of_coffee_v2());
//		cup = static_cast<std::auto_ptr<cup_of_coffee_v2> > (new cup_of_coffee_v2());

//		cup = some_type(some_val);
//		cup = (some_type)some_val;


		if (cup.get() != nullptr)
		{
			cup->fill(100);
//			cup.get()->fill(100);
		}
		break;

	case 3:			
		number_of_cups--;
		mls_of_water -= 150;
		grams_of_coffee -= 20;	
			
		cup = std::auto_ptr<cup_of_coffee_v2>(new cup_of_coffee_v2());
		if (cup.get() != nullptr)
			cup->fill(150);
		break;

	default:
		// cup = nullptr;
		break;
	}

	if (cup.get() != nullptr)
	{
		while (cup->menu() == false)
		{

		}
	}
	//
	return cup;
}


int foo()
{
	int a = 5;

	return a;
}

//int coffee_machine_v2::type_coffee(int a)
//{
	//return a;
//}

/*void coffee_machine_v2::fill_cup(cup_of_coffee_v2& cup)
{
	cup.fill(mls_of_water);
}*/

bool coffee_machine_v2::is_it_filled()
{
	if (number_of_cups < 1 || grams_of_coffee < 50 || mls_of_water < 150 || grams_of_sugar < 10)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool coffee_machine_v2::low_quantity1()
{
	if (number_of_cups < 2)
	{
		return true;
	}

	else { return false; }
}
bool coffee_machine_v2::low_quantity2()
{
	if (mls_of_water > 150 && mls_of_water < 250)
	{
	return true;
	}
	else { return false; }
}
bool coffee_machine_v2::low_quantity3()
{
	if (grams_of_coffee > 30 && grams_of_coffee < 100)
	{
	return true;
	}
	else { return false; }
}
bool coffee_machine_v2::low_quantity4()
{
	if (coffee_machine_v2::grams_of_sugar > 30 && coffee_machine_v2::grams_of_sugar < 100)
	{
	return true;
	}
	else { return false; }
}


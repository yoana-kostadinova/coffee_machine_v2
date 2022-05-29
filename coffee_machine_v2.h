#pragma once
#include "cup_of_coffee_v2.h"
#include <memory>

//typedef  std::auto_ptr<cup_of_coffee_v2> cup_auto_ptr;

class coffee_machine_v2
{
public:

	unsigned int number_of_cups;
	unsigned int mls_of_water;
	unsigned int grams_of_coffee;
	unsigned int grams_of_sugar;
	//static int (*p)(int);
	//p = &type_coffee;

	coffee_machine_v2();
	void autofill();
	void fill(int b, int a);
	void sugar(int a);
	bool is_it_filled();
	std::auto_ptr<cup_of_coffee_v2> make_coffee(int b);
	//static int type_coffee(int a);
	//void fill_cup(cup_of_coffee_v2& cup);
	bool low_quantity1();
	bool low_quantity2();
	bool low_quantity3();
	bool low_quantity4();
	
};


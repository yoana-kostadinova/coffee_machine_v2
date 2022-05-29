#pragma once
#include "coffee_machine_v2.h"

/*class io_device
{
public:
	virtual void show(const char* txt) = 0;
	virtual int get() = 0;
};


class std_io_dev : public io_device
{
	void show(const char* txt) override
	{
		std::cout << txt;
	}

	int get() override
	{
		int res;

		std::cin >> res;
		return res;
	}
};
*/

class user_interface_v2
{
public:

	void menu(coffee_machine_v2& machine, cup_of_coffee_v2& cup);
	void menu_coffee(coffee_machine_v2& machine);
	void menu_machine(coffee_machine_v2& machine);
	void warning(coffee_machine_v2& machine);
	static void ascii_art(int a);
	static void error1();
	static void error2();





	/*coffee_machine_v2 & machine;

	//--------
	user_interface_v2(coffee_machine_v2& amachine) : machine(amachine)
	{

	}*/
};






#include "user_interface_v2.h"
#include "coffee_machine_v2.h"
#include <iostream>


class coffee_machine_v2;
class cup_of_coffee_v2;


void user_interface_v2::menu(coffee_machine_v2& machine, cup_of_coffee_v2& cup)
{
	int button;
	std::cout << " Welcome to the second version of the coffee machine\n";
	std::cout << "      ______________________\n";
	std::cout << "     (___________          |\n";
	std::cout << "      [XXXXX]   |  ______  |\n";
	std::cout << "                |  coffee  |\n";
	std::cout << " ___|@@@@@@@@@@||  ------  |\n";
	std::cout << "( C |@@@@@@@@@@||  short   |\n";
	std::cout << " `-- |@@@@@@@@| |  normal  |\n";
	std::cout << "      |@@@@@@|  |   long   |\n";
	std::cout << "    __ |@@@@|___|          |\n";
	std::cout << "   (____________|__________|\n";
	std::cout << "   |_______________________|\n";

	do {
		std::cout << "\nChoose what do you want to do:\n";
		std::cout << "To make coffee, press 1\n";
		std::cout << "To fill the coffee machine, press 2\n";	
		std::cout << "To automatically fill the machine with everything needed, press 3\n";
		std::cout << "To end the program, press 0\n";
		std::cin >> button;

		switch (button)
		{
		case 1:
			menu_coffee(machine);
			break;

		case 2:
			menu_machine(machine);
			break;

		case 3:
			machine.autofill();
			break;
		}

	} while (button != 0);
}

void user_interface_v2::menu_coffee(coffee_machine_v2& machine)
//void user_interface_v2::menu_coffee(coffee_machine_v2& machine, io_device& io)
{
	int button;
	unsigned int add;
	std::auto_ptr<cup_of_coffee_v2> cup;

	std::cout<< "-----------------------------------\n";
	//io.show("-----------------------------------\n");
	std::cout << "For small coffee, press 1\n";
	std::cout << "For normal coffee, press 2\n";
	std::cout << "For long coffee, press 3\n";
	std::cout << "-----------------------------------\n";
	std::cin >> button;
	std::cout << "-----------------------------------\n";
	std::cout <<"Do you want sugar? (1/0)\n";
	std::cout << "-----------------------------------\n";
	std::cin >> add;
	//add = io.get();

	machine.sugar(add);
	switch (button)
	{
	case 1:
		if (machine.is_it_filled()==true)
		{	
			ascii_art(1);
			warning(machine);
			cup = machine.make_coffee(button);	
		}

		else
		{
			error2();
		}

		break;

	case 2:
		if (machine.is_it_filled() == true)
		{
			ascii_art(2);
			warning(machine);
			cup = machine.make_coffee(button);
		}

		else
		{
			error2();
		}
		break;

	case 3:
		if (machine.is_it_filled() == true)
		{
			ascii_art(3);
			warning(machine);
			cup = machine.make_coffee(button);			
		}

		else
		{
			error2();
		}
		break;

	default:
		error1();

	}
	

}

void user_interface_v2::menu_machine(coffee_machine_v2& machine)
{	
	int button;
	unsigned int add;

	do
	{
		std::cout << "To fill the machine with cups, press 1\n";
		std::cout << "To fill the machine with water, press 2\n";
		std::cout << "To fill the machine with coffee, press 3\n";
		std::cout << "To fill the machine with sugar, press 4\n";
		std::cout << "To stop filling the machine, press 0\n";
		std::cin >> button;

		switch (button)
		{
		case 1:
			std::cout << "How many cups do you want to fill?\n";
			std::cin >> add;
			machine.fill(button, add);
			break;
		case 2:
			std::cout << "How many mililiters of water do you want to fill?\n";
			std::cin >> add;
			machine.fill(button, add);
			break;
		case 3:
			std::cout << "How many grams of coffee do you want to fill?\n";
			std::cin >> add;
			machine.fill(button, add);
			break;
		case 4:
			std::cout << "How many grams of sugar do you want to fill?\n";
			std::cin >> add;
			machine.fill(button, add);
			break;

		case 0:
			break;

		default:
			error1();
		}
	}while (button != 0);

}

void user_interface_v2::warning(coffee_machine_v2& machine)
{
	if (machine.low_quantity1() == true)
	{
		std::cout<<"Warning!\nYou have only 1 cup left!\n";
	}
	if (machine.low_quantity2() == true)
	{
		std::cout << "Warning!\nYou don't have much water left!\n";
	}
	if (machine.low_quantity3() == true)
	{
		std::cout << "Warning!\nYou don't have much coffee beans left!\n";
	}
	if (machine.low_quantity4() == true)
	{
		std::cout << "Warning!\nYou don't have much sugar left!\n";
	}
}

void user_interface_v2::ascii_art(int a)
{
	std::cout<< ("Here is your coffee: \n");

	switch (a)
	{
	case 1:
		std::cout << "\n  ((((\n";
		std::cout << "  ))))\n";
		std::cout << " :----:\n";
		std::cout << "C|====|\n";
		std::cout << " `----' \n";
		break;
	case 2:
		std::cout << "\n    ((((\n";
		std::cout << "   ((((\n";
		std::cout << "    ))))\n";
		std::cout << " _ .---.\n";
		std::cout << "( |`---'|\n";
		std::cout << " -|     |\n";
		std::cout << "   .___.\n";
		break;
	case 3:
		std::cout << "\n      )  )\n";
		std::cout << "    ( ( ( ( \n";
		std::cout << "    ) ) ) ) )\n";
		std::cout << "    _________\n";
		std::cout << " .-'---------|\n";
		std::cout << "( C|         |\n";
		std::cout << " '-|         |\n";
		std::cout << "   '_________'\n";
		std::cout << "    '-------'\n";
		break;
	}
}

void user_interface_v2::error1()
{
	std::cout << "\nError.You've picked a number that's not on the menu.\n";
}

void user_interface_v2::error2()
{
	std::cout << "\nNot enough ingridients to make coffee. Please refill the machine.\n";
}

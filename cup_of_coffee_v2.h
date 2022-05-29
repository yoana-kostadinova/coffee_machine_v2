#pragma once

class cup_of_coffee_v2
{
private:
	const int sip = 25;	
	int content;

public:
	cup_of_coffee_v2();
	void fill(int a);
	bool menu();
	void check();
	bool drink();
};


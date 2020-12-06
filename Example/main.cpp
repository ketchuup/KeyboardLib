#include "Keyboard.h"
#include <iostream>

int main()
{
	initialize();
	setPressMode();

	int key;
	bool run = true;

	while (run)
	{
		key = getPressedKey();

		if (key == static_cast <int> ('q'))
		{
			run = false;
		}
		else
		{
			std::cout << ":3" << std::endl;
		}
	}

	setInputMode();

	std::cout << "Bye!" << std::endl;

	return 0;
}

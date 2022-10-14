#include <conio.h> 
#include "Utility.h"

#include <iostream>

namespace Utility
{
	// ------------------------------------------------------------------------------------------------------------------

	// Get a whole line typed by the user
	std::string GetCin()
	{
		std::cout << "-> ";
		std::string userCin;
		std::getline(std::cin, userCin);
		std::cout << std::endl;

		return userCin;
	}

	// ------------------------------------------------------------------------------------------------------------------

	std::string GetNumberTyped()
	{
		std::cout << "-> ";

		std::string numberTyped;

		// --------------------------------------------------------------------------------------------------------------

		do
		{
			char key = _getch();

			if (key >= '0' && key <= '9')
			{
				numberTyped += key;
				std::cout << key;
			}

			// If the key pressed is "delete".
			if (key == 8)
			{
				// If the attribute's value is not empty.
				if (!numberTyped.empty())
				{
					// Delete the last character and put the cursor back from 1 character in the console.
					numberTyped.pop_back();
					std::cout << "\b \b";
				}
			}

			// Prevents the user from entering the value 0.
			if (key == 13 && numberTyped != "0")
			{
				if (numberTyped.empty())
				{
					// The attribute's value is empty, so ask again to enter a number of hp
					std::cout << std::endl << "No value entered. Please enter a valid one" << std::endl;
					std::cout << "-> ";
				}

				else
				{
					break;
				}
			}

		} while (true);

		// --------------------------------------------------------------------------------------------------------------

		return numberTyped;
	}

	// ------------------------------------------------------------------------------------------------------------------
}
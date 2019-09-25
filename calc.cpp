/*
Author: Kristy Lau
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Project 1D

This program acts as a better calculator that can evaluate
multiple arithmetic expressions.
*/

#include <iostream>
using namespace std;

int main()
{
	int s;
	char character;
	int sum = 0;
	bool initial = true;
	bool add = false;
	bool subtract = false;

	//Double = is the comparator, single = is to set,

	//While the reading operation is a success
	//Reads file in pattern of integer then character
	while (cin >> s >> character)
	{
		//If the integer is squared
		if(character == '^')
		{
			s = s * s;
			if(initial == true)
			{
				sum += s;
				initial = false;
			}	

			//If initial is false
			else
			{
				if(add == true)
				{
					sum += s;
					add = false;
				}

				if(subtract == true)
				{
					sum -= s;
					subtract = false;
				}
			}

			//Reads character in next sequence after s
			cin >> character;
			if(character == '+')
			{
				add = true;
			}

			else if(character == '-')
			{
				subtract = true;
			}

			else if(character == ';')
			{
				cout << sum << endl;
				sum = 0;
				initial = true;
			}
		}

		//If plus character succeeds another character
		else if(character == '+')
		{
			if(initial == true)
			{
				sum += s;
				initial = false;
			}

			else
			{
				if(add == true)
				{
					sum += s;
					add = false;
				}

				if(subtract == true)
				{
					sum -= s;
					subtract = false;
				}
			}

			add = true;
		}

		//If minus character succeeds another character
		else if(character == '-')
		{
			if(initial == true)
			{
				sum = s;
				initial = false;
			}

			else
			{
				if(add == true)
				{
					sum += s;
					add = false;
				}

				if(subtract == true)
				{
					sum -= s;
					subtract = false;
				}
			}

			subtract = true;	
		}

		//If ; character succeeds another character
		else if(character == ';')
		{

			if(initial == true) 
			{
				sum = s;
				initial = false;
			}

			else
			{
				if(add == true)
				{
					sum += s;
					add = false;
				}

				if(subtract == true)
				{
					sum -= s;
					subtract = false;
				}
			}

			//Prints out the sum at the end of the sequence, resets to 0,
			//and reads integer of next sequence
			cout << sum << endl;
			sum = 0;
			initial = true;
		}
	}

	return 0;
}

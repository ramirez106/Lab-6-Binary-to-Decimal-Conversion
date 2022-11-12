/*
Carlos Ramirez
C++ Fall 2022
Due: November 11
Lab 6 Binary to Decimal Conversion
Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings
*/

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
void header();

string inputfile = "BinaryIn.dat";

int main()
{
	header();
	ifstream infile;
	infile.open(inputfile);
	char input;
	int decimalnum = 0, charcount = 0;
	bool firstchar = false, baddigit = false;
	infile.get(input);
	while (infile)
	{
		while (input != '\n' && infile)
		{
			if (input == '1' || firstchar && (input == '1' || input == '0'))
			{
				if (!firstchar)
					cout << "\t    ";
				charcount++;
				firstchar = true;
				cout << input;
				decimalnum *= 2;
				if (input == '1')
				{
					decimalnum++;
				}
			}
			else if (input != ' ' || (input == ' ' && firstchar))
			{
				for (int i = 0; i < charcount; i++)
					cout << "\b";
				cout << "bad digit on input \n";
				baddigit = true;
				infile.ignore(256, '\n');
				break;
			}
			infile.get(input);
		}
		if (baddigit == false)
		{
			for (int i = 0; i < (48 - charcount); i++)
				cout << " ";
			cout << decimalnum << endl;
		}
		firstchar = false;
		baddigit = false;
		infile.get(input);
		decimalnum = 0;
		charcount = 0;
	}
	return 0;
}
void header()
{
	cout << "\tBinary Number";
	cout << "\t\t\t\tDecimal Equivalent\n";
}
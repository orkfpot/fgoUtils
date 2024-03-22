#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

#define READ 1
#define WAIT 0

int writeOut(std::ifstream &fp, int startPos, int length)
{
	int posDiff=(startPos-length);
	char string[posDiff];
	fp.seekg(startPos);
	fp.read(string, posDiff);
	std::cout << string << '\n';
	return 0;
}


// god bless tellg(), seekg() and read()
// I am not turning this into a class to make it a nice recursive method 
int parseServants(std::ifstream &fp, int x = 0)
{
	char b;
	int pos = 0;
	int y = x; //	x and y are variables used to track indentation
	int charState = WAIT;

	while(fp.get(b))
	{
		switch(b)
		{
		case '"':

			if(charState==READ)
			{
				charState=WAIT;
				int pos=fp.tellg();
				break;
			}

			charState=0;
			writeOut(fp, pos, (int)fp.tellg()-1);
			pos = (int)fp.tellg()+1;
			break;

		default:
			break;
		}
	}
	return 0;
}


int main()
{
	std::ifstream fp("servants.json");
	std::cin.clear();
	fflush(stdin);
	if(!fp.is_open())
	{
		std::cout << "failed to open file" << '\n';
		return -1;
	}

	parseServants(fp);
//	writeOut(fp, 200, 200);
	std::cout << fp.tellg();

	return 0;
}

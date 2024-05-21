#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

#define READ 1
#define WAIT 0

int writeOut(std::ifstream &fp, int startPos, int endPos)
{
	endPos--;
	int posDiff=(endPos-startPos);
	char* string;
	string  = (char*) malloc(posDiff*sizeof(char));
	fp.seekg(startPos);
	fp.read(string, posDiff);
	std::cout.clear();
	std::cout << string << '\n';
//	std::cout << "startPos" << startPos << std::endl << "endPos"<< endPos << std::endl << "posDiff" << posDiff << std::endl << std::endl;
	free(string);
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

			if(charState==WAIT)
			{
				charState=READ;
				pos=fp.tellg();
				break;
			}

			charState=WAIT;
			writeOut(fp, pos, (int)fp.tellg());
			pos = (int)fp.tellg();
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
//	writeOut(fp, 3, 5);
	std::cout << fp.tellg();

	return 0;
}

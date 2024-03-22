#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define READ
#define WAIT

int writeOut(std::ifstream &fp, int pos1, int pos2)
{
	int posDiff=(pos2-pos1);
	char string[posDiff];
	fp.seekg(pos1);
	fp.read(string, posDiff);
	std::cout << string << '\n';
	return 1;
}


// god bless tellg(), seekg() and read()
int parseServants(std::ifstream &fp, int x = 0)
{
	char b;
	int pos = 0;
	int y = x; //	x and y are variables used to track indentation
	int charState;
//	skipWrite goes to before the while loop but it continues fp.get(b); at the position that it left of at because C++ is cool like that.
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
			else
			{
				charState=0;
				writeOut(fp, pos, (int)fp.tellg()-1);
			}
		default:
			break;
		}
	}
	return 1;
}
	/*
skipWrite:
while(fp.get(b))
	{
	
	switch(b)
	{
	case '{':
		y++;
		x=y-1;
		break;
	case '}':
		y--;
		x=y;
		break;
	case '"':
		if(charState==READ_VAR_NAME)
		{
			charState=WAIT_FOR_VAR_VAL;
			goto write;
		}
		else
		{
			charState=READ_VAR_NAME;
		pos = fp.tellg();
		}
		break;
	case ':':
		charState=READ_VAR_VAL;
		pos = fp.tellg();
		break;
	case ',':

		charState=WAIT_FOR_VAL_NAME;
		goto write;
		break;


	default:
//		std::cout << b;
		break;
	}

	goto skipWrite;

write:
	pos2 = fp.tellg();
	posDiff=(pos2-pos);
	char string[posDiff]; // I do need to free this don't I? after all I create a new one every iteration of the loop and this loop. or does it go out of scope every loop
		// I think it goes out of scope
	fp.seekg(pos);
	fp.read(string, posDiff);
	fp.seekg(pos2++);
	pos = fp.tellg();
	for(int i = 0; i < y; i++)
		std::cout << "	";
	std::cout << string << '\n';

	}
	*/


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

	return 0;
}

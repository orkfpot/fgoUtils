#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define WAIT_FOR_VAL_NAME 0
#define READ_VAR_NAME 1
#define WAIT_FOR_VAR_VAL 2
#define READ_VAR_VAL 3

// god bless tellg(), seekg() and read()
int parseServants(std::ifstream &fp, int x = 0)
{
	char b;
	unsigned long int pos, pos2;
	int y = x;
	int charState;
	int posDiff;

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
	fp.seekg(pos);
	fp.read(string, posDiff);
	fp.seekg(pos2);
	std::cout << string << '\n';

	}
	return 0;
}

int main()
{
	std::ifstream fp("servants.json");
	std::string searchSubject;
	char b;

	if(!fp.is_open())
	{
		std::cout << "failed to open file" << '\n';
		return -1;
	}

	parseServants(fp);

	return 0;
}

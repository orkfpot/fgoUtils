#include <iostream>
#include <fstream>
#include <string>

#define WAIT_FOR_VAL_NAME 0
#define READ_VAR_NAME 1
#define WAIT_FOR_VAR_VAL 2
#define READ_VAR_VAL 3

// god bless tellg(), seekg() and read()
int parseServants(std::ifstream &fp, int x = 0, int y = 0)
{
	char b;
	int charState;
	unsigned long int pos, pos2;
	int posDiff;
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
					char string[posDiff];
					fp.seekg(pos);
					fp.read(string, posDiff);
					fp.seekg(pos2);
					pos=fp.tellg();
					charState=WAIT_FOR_VAR_VAL;
				}
				else
				{
					pos2 = fp.tellg();
					posDiff=(pos2-pos);
					char string[posDiff];
					fp.seekg(pos);
					fp.read(string, posDiff);
					fp.seekg(pos2);
					charState=READ_VAR_NAME;
				}
				break;
			case ':':
				charState=READ_VAR_VAL;
				break;
			case ',':
				charState=WAIT_FOR_VAL_NAME;
				std::cout << '\n';
				break;


			default:
				std::cout << b;
				break;
		}
		
		/*
		switch(charState)
		{
			case READ_VAR_NAME:
				fp.seekg(pos);
				fp.read(string, posDiff);
				fp.seekg(pos2);
				break;
			case READ_VAR_VAL:
				fp.seekg(pos);
				fp.read(string, posDiff);
				fp.seekg(pos);
				break;
			default:
				break;
		}
		*/
	}
	return 0;
}

/*
std::string parseServants(&fp)
{

// this is gonna have to become a loop and a recursive function

/*
 * read file as done here until reach :
 * when encountered : call self?
 *
 * is that really all?
 *

// gonna rewrite this a second time
mainLoop:
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
				charState=WAIT_FOR_VAR_VAL;
			else
				charState=READ_VAR_NAME;
			break;
		case ':':
			charState=READ_VAR_VAL;
			break;
		case ',':
			charState=WAIT_FOR_VAL_NAME;
			std::cout << '\n';
			break;


		default:
			std::cout << b;
			goto skipWrite;
	}

write:
	switch(charState)
	{
		case READ_VAR_NAME:
			std::cout << b;
			break;
		case READ_VAR_VAL:
			std::cout << b;
		default:
			break;
	}
	
skipWrite:
	if(fp.get(b))
		goto mainLoop;
}
*/
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


/* irrelevant code as I am changing it to a character by character reading of file
	while(getline(fp,line))
	{


		if(line.find(searchSubject) != std::string::npos)
			goto saveInfo;
		if(line.find("{") != std::string::npos)
			x++;
		if(line.find("}") != std::string::npos)
		{
			x--;
		}
	}
	std::cout << "servant not found" << '\n';
	return -1;
saveInfo:
	this->name = searchSubject;
	while(getline(fp,line))
	{
		std::cout << line << '\n';


		if(line.find("{") != std::string::npos)
			x++;
		if(line.find("}") != std::string::npos)
		{
			x--;
			if(x==0)
				break;
		}
	}
	std::cout << name << '\n';
*/

	return 0;
}

#include <iostream>
#include <fstream>
#include <string>


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
	int x=0, y=0;



	if(!fp.get(b))
		std::cout << "NULL file pointer\n";
	
mainLoop:
	if(b=='{')
	{
		y++;
		x=y-1;
		goto indent;
	}
	if(b=='}')
	{
		y--;
		x=y;
		goto indent;
	}
	std::cout << b;
	goto skipIndent;
indent:

	std::cout << '\n';
	for(int i = 0; i < x; i++)
		std::cout << "    ";
	std::cout << b << '\n';
	for(int i = 0; i < y; i++)
		std::cout << "    ";
skipIndent:
	if(fp.get(b))
		goto mainLoop;

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

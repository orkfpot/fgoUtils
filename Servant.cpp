#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"


int Servant::init(std::ifstream &fp, std::string searchSubject)
{
	std::string line;
	if(!fp.is_open())
	{
		std::cout << "failed to open file" << std::endl;
		return -1;
	}
	int x=0;

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
	std::cout << "servant not found" << std::endl;
//I want to call a destructor in the constructor if servant is not found.	~this;

//probably best to call a destructor based on the return value
	return -1;

saveInfo:
	this->name = searchSubject;
	while(getline(fp,line))
	{
		std::cout << line << std::endl;


		if(line.find("{") != std::string::npos)
			x++;
		if(line.find("}") != std::string::npos)
		{
			x--;
			if(x==0)
				break;
		}
	}
	std::cout << name << std::endl;

	return 0;
}

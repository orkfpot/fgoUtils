#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fp;
    fp.open("servants.json");
	std::string line;
	if(!fp.is_open())
	{
		std::cout << "failed to open file" << '\n';
		return -1;
	}
	int x=0;

	while(getline(fp,line))
	{  


		if(line.find("battleName") != std::string::npos && line.find("        ") == std::string::npos)
        {
            x++;
            line.erase (0, 19);
	    line.erase (line.end()-2, 2);
            std::cout << line << '\n';
        }
    }
}

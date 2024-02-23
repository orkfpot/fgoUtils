#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>





/*
class CraftEssence()
{
};

class CommandCode()
{
};
*/

int parseServants(std::ifstream &fp)
{

    std::string line;
    if(!fp.is_open())
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    
    int x=0;
    
//    if(line.find("name") == std::string::npos)
//        goto loop;
    
    while(getline(fp,line))
    {
        
        std::cout << line << std::endl;
        if(line.find("{") != std::string::npos)
        {
            x++;
            std::cout << x << std::endl;
            if(x==100)
                break;
        }
    }

            
    return 0;
}


int main()
{
    std::ifstream servants;
    servants.open("servants.json");
    
    if(parseServants(servants)==-1)
    {
        std::cout << "parseServant failed";
        return -1;
    }


    return 0;
}

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"


//prints out one servant info right now
//unless I forgot to update the comment

//pretty sure this function has now been raplaced by Servant.init();
int parseServants(std::ifstream &fp)
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
        
        std::cout << line << std::endl;

        if(line.find("{") != std::string::npos)
        {
            x++;
        }
        if(line.find("}") !=std::string::npos)
        {
            x--;
            if(x==0)
                break;
        }

    }
            
    return 0;
}


int main()
{
    std::ifstream servants;
    servants.open("servants.json");
    if(!servants.is_open())
    {
        std::cout << "error opening file servants.json" << std::endl;
        return -1;
    }

// a constructor can't return a value therefore this is not valid c++, I hoped that if the servant was not found it would run that but tragedy has struck    
    // might make the function separate from the constructor
//    if(parseServants(servants)==-1)
//    if(!Servant altria(servants, "Altria Pendragon")) 
    Servant gilgamesh;
    gilgamesh.init(servants, "Gilgamesh");
//    {
//        std::cout << "parseServant failed";
//        return -1;
//    }


    return 0;
}

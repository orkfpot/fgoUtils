#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"


int main()
{
    std::ifstream servants;
    servants.open("servants.json");
    if(!servants.is_open())
    {
        std::cout << "error opening file servants.json" << '\n';
        return -1;
    }

// a constructor can't return a value therefore this is not valid c++, I hoped that if the servant was not found it would run that but tragedy has struck    
    // might make the function separate from the constructor
//    if(parseServants(servants)==-1)
//    if(!Servant altria(servants, "Altria Pendragon")) 
    Servant gilgamesh;
    if(gilgamesh.init(servants, "Gilgamesh")==-1)
    {
        std::cout << "parseServant failed";
        return -1;
    }


    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"


/*

	initial implementation of the Servant class, now in Servant.h, might remove it later

struct extraAssets
{
	std::string asc1;
	std::string asc2;
	std::string asc3;
	std::string asc4;
};


struct levellingMaterials
{
	std::string item1 = "";
	std::string item2 = "";
	std::string item3 = "";
	std::string item4 = "";
	std::string item5 = "";
	int qp = 0;
};



struct reqMaterials
{
	levellingMaterials skill1;
	levellingMaterials skill2;
	levellingMaterials skill3;
	levellingMaterials skill4;
	levellingMaterials skill5;
	levellingMaterials skill6;
	levellingMaterials skill7;
	levellingMaterials skill8;
	levellingMaterials skill9;
	levellingMaterials ascension1;
	levellingMaterials ascension2;
	levellingMaterials ascension3;
	levellingMaterials ascension4;
};


struct cardsHitCount
{
	int buster, arts, quick, extra;
};


class Servant{
private:
	std::string traits[50];
	std::string appendSkills[3];
	std::string passiveSkills[3];
	std::string skills[3];
	std::string name;
	std::string gender;
	std::string attribute;
	char cards[5];
	int rarity;
	int classID;
	int starAbsorb;
	int starGen;
	int ikChance;
	int atkGrowth[120];
	int hpGrowth[120];
	int xpGrowth[120];
	int bondGrowth[15];
	cardsHitCount hitCounts;
	extraAssets assets;
	reqMaterials materials;
public:
	int init(std::ifstream &fp, std::string searchSubject);
};
*/


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

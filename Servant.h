#ifndef SERVANT
#define SERVANT

#include <iostream>
#include <fstream>
#include <string>
#include "Servant.h"

struct extraAssets
{
	std::string ascension[4];
	std::string sprites[3];
};


struct levellingMaterials
{
	std::string items[5] = {"","","","",""};
	int qp = 0;
};



struct reqMaterials
{
	levellingMaterials skills[9];
	levellingMaterials ascensions[4];
};

// hit count based on card type
// need to add distribution
struct cardHits
{
	int buster, arts, quick, extra, np;
	int busterDistr[10];
	int artsDistr[10];
	int quickDistr[10];
	int extraDistr[10];
	int npDistr[10];
};


// assumes 3 effects for each skill
// leave empty for no effect??
struct skills
{
	std::string name, effect[3], description;
	int effect[3][10];
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
	//returns 0 if successful
	//returns -1 if failed
	int init(std::ifstream &fp, std::string searchSubject);
};

#endif // ! SERVANT


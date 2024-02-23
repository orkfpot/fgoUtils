#include <string>


struct extraAssets
{
	std::string asc1;
	std::string asc2;
	std::string asc3;
	std::string asc4;
};

struct materials
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

struct levellingMaterials
{
	std::string item1 = "";
	std::string item2 = "";
	std::string item3 = "";
	std::string item4 = "";
	std::string item5 = "";
	int qp = 0;
};


class Servant()
{
private:
	std::string[50] traits;
	std::string[3] appendSkills;
	std::string[3] passiveSkills;
	std::string[3] skills;
	std::string name;
	std::string gender;
	char[5] cards;
	int rarity;
	int classID;
	int starAbsorb;
	int starGen;
	int ikChance;
	int[120] atkGrowth;
	int[120] hpGrowth;
	int[120] xpGrowth;
	int[15] bondGrowth;
	int[4] hitCounts;
	int[3] cards;
	extraAssets assets;
	materials materials;
}

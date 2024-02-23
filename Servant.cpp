#include <string>


struct extraAssets
{};

struct traits
{};

struct materials
{};


class Servant()
{
	private
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
		extraAssets assets;
		traits traits;
}

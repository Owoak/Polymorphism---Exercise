#include "DesertEagle.h"
#include "CheckForAmmo.h"
using namespace std;

#define dataReport cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor"<< endl

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo) :Pistol(damagePerRound, clipSize, remainingAmmo) {}
bool DesertEagle::fire(PlayerVitalData& enemyPlayerData) {
	if (!checkForAmmo(this->_currClipBullets, this)) {
		return false;
	}
	enemyPlayerData.armor -= this->_damagePerRound / 4;
	if (enemyPlayerData.armor < 0) {
		enemyPlayerData.health += enemyPlayerData.armor;
		enemyPlayerData.armor = 0;
	}
	enemyPlayerData.health -= (this->_damagePerRound / 4) * 3;

	dataReport;

	return enemyPlayerData.health <= 0;
}

#undef dataReport
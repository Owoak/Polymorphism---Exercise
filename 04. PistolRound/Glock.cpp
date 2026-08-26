#include "Glock.h"
#include <iostream>
#include "Defines.h"
#include "CheckForAmmo.h"
using namespace std;

#define dataReport cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << endl

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo) :Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool Glock::fire(PlayerVitalData& enemyPlayerData) {
	for (int shotsFired = 0; shotsFired < InternalDefines::ROUNDS_PER_FIRE and enemyPlayerData.health > 0; shotsFired++) {
		if (!checkForAmmo(this->_currClipBullets, this)) {
			break;
		}
		enemyPlayerData.armor -= this->_damagePerRound / 2;
		if (enemyPlayerData.armor < 0) {
			enemyPlayerData.health += enemyPlayerData.armor;
			enemyPlayerData.armor = 0;
		}
		enemyPlayerData.health -= this->_damagePerRound / 2;
		dataReport;
	}
	return enemyPlayerData.health <= 0;
}

#undef dataReport
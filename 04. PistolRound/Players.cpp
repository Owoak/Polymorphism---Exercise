#include "Player.h"
#include "Defines.h"
#include "Pistol.h"
#include "Glock.h"
#include "DesertEagle.h"

using namespace std;

void Player::buyPistol(const PistolType pistolType, const int damagePerRound, const int clipSize, const int remainingAmmo) {
	if (pistolType == PistolType::GLOCK) {
		this->_pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
	}
	else if (pistolType == PistolType::DESERT_EAGLE) {
		this->_pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
	}
}
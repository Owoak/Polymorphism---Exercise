#include"CheckForAmmo.h"

bool checkForAmmo(int& currClipBullets, Pistol* gun) {
	if (currClipBullets == 0) {
		gun->reload();
		return false;
	}
	else {
		currClipBullets--;
		return true;
	}
}
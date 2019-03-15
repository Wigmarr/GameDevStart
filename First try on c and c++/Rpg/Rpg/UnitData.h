#pragma once

//Include
#include "UnitType.h"
#include "weaponType.h"

struct UnitData
{
	UnitType type;
	int row;
	int column;
	int health;
	WeaponType weapon;
};


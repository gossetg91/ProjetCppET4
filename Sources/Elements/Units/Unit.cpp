#include "Unit.h"

int Unit::getUnitPrice()
{
    return 0;
}

void Unit::move() {

	ptile->setEmpty();

	Tile* newTile;

	if (relatedTeam->isRight()) {
		newTile = ptile->getPrec();
	}
	else newTile = ptile->getNext();

	ptile = newTile;
	ptile->emplace(this);

	hasMoved = true;
}

bool Unit::checkMove() {

	if (relatedTeam->isRight() && ptile->getPrec() != nullptr) {
		if (ptile->getPrec()->isEmpty()) return true;
	}
	else if (ptile->getNext() != nullptr) {
		if (ptile->getNext()->isEmpty()) return true;
	}
	return false;
}
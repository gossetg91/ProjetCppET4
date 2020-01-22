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
		if (ptile->getPrec()->isAnyBase()) return false; //pas le droit d'être dans la case de la base
		if (ptile->getPrec()->isEmpty()) return true;
	}
	else if (ptile->getNext() != nullptr) {
		if (ptile->getNext()->isAnyBase()) return false; //pas le droit d'être dans la case de la base
		if (ptile->getNext()->isEmpty()) return true;
	}
	return false;
}

Tile* Unit::checkAttack() {

	Tile* curElem = ptile;

	for (int i = 0; i < minRange; i++) {
		//on initialise la case de range
		if (relatedTeam->isRight() && ptile->getPrec() != nullptr) curElem = curElem->getPrec();
		else if (ptile->getNext() != nullptr) curElem = curElem->getNext();
		else curElem = nullptr;
	}

	for (int i = minRange; i <= maxRange; i++) {

		if (curElem != nullptr) {

			if ((!curElem->isEmpty())) {
				if (curElem->getElement()->getRelatedTeam() == getRelatedTeam()); //elle est des notres
				else return curElem;
			}
			else if (curElem->isAnyBase()) { //si il y a une base (ne sera jamais de même team)
				return curElem;
			}

			//on incrémente la case visée
			if (relatedTeam->isRight()) curElem = curElem->getPrec();
			else curElem = curElem->getNext();
		}
	}

	return nullptr;
}


#include "entinity.h"

Entinity::Entinity(char character, pair<int, int> startCoords, Field *fld, int speed) : character(character), fld(fld), speed(speed)
{
    setCoords(startCoords.first, startCoords.second);
}

void Entinity::moveCoords(char mov)
{
    int newIndexesX = coords.first, newIndexesY = coords.second;
    switch (mov)
    {
    case 'w':
    {
        newIndexesY = (newIndexesY + speed);
        newIndexesY = newIndexesY == fld->getBarier() ? newIndexesY - 1 : newIndexesY;
        break;
    }
    case 's':
    {
        newIndexesY = (newIndexesY - speed);
        newIndexesY = newIndexesY < 0 ? fld->getBarier() - 1 : newIndexesY;
        break;
    }
    case 'd':
    {
        newIndexesX = (newIndexesX + speed) % (fld->getWide());
        break;
    }
    case 'a':
    {
        newIndexesX = (newIndexesX - speed);
        newIndexesX = newIndexesX < 0 ? fld->getWide() - 1 : newIndexesX;
        break;
    }

    default:
        return;
    }
    setCoords(newIndexesX, newIndexesY);
}

void Entinity::setCoords(int newIndexesX, int newIndexesY)
{
    (*fld)(coords.first, coords.second) = fld->getBlock();
    (*fld)(newIndexesX, newIndexesY) = this->character;
    coords = {newIndexesX, newIndexesY};
}

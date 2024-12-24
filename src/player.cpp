#include "entinity.h"

void Player::moveCoords(char mov)
{
    int newIndexesX = coords.first, newIndexesY = coords.second;
    switch (mov)
    {
    case 'w':
    {
        newIndexesY = (newIndexesY + speed);// % fld->getHeight();
        newIndexesY = newIndexesY == fld->getHeight() ? 1: newIndexesY;
        break;
    }
    case 's':
    {
        newIndexesY = (newIndexesY - speed);
        newIndexesY = newIndexesY < 0 ? fld->getHeight() - 1 : newIndexesY;
        if( newIndexesY == 0) newIndexesY = fld->getHeight() - 1;
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

void Player::gameOver()
{
    cout << "\nscore: " << this->score << '\n';
    exit(1);
}


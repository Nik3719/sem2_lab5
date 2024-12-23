#include "entinity.h"

void Bullet::moveCoords(char mv)
{
    int newIndexesX = coords.first, newIndexesY = coords.second;
    newIndexesY = (newIndexesY + 1);
    setCoords(newIndexesX, newIndexesY);
}

// void Bullet::setCoords(int newIndexesX, int newIndexesY)
// {
//     if (newIndexesY -1== fld->getBarier())
//     {
//         char block = fld->getBlockBarrier();

//         fld->operator()(coords.first, coords.second) = block;
//         life = 0;
//         return;
//     }
//     Entinity::setCoords(newIndexesX, newIndexesY);
// }
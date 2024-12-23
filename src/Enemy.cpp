#include "entinity.h"

void Enemy::move(int &life)
{
    if (this->coords.first == fld->getWide() - 1)
    {
        direction = 'a';
        moveCoords('s');
    }
    else if (this->coords.first == 0)
    {
        direction = 'd';
        moveCoords('s');
    }
    moveCoords(direction);

    if (isPlayer() || isBulllet())
    {
        life--;
    }
}

bool Enemy::isPlayer()
{
    if ((*fld)(coords.first, coords.second) == '1')
    {
        return true;
    }
    return false;
}

pair<int, int> Enemy::purposeCoords()
{
    // Получаем текущие координаты врага
    std::pair<int, int> currentCoords = this->coords;

    // Пример логики для изменения координат
    // В зависимости от текущего положения и направления движения врага
    std::pair<int, int> newCoords = currentCoords;

    if (currentCoords.first == fld->getWide() - 1)
    {
        // Враг находится на правом краю поля
        newCoords.first -= 1;  // Двигается влево
        newCoords.second += 1; // Двигается вниз
    }
    else if (currentCoords.first == 0)
    {
        // Враг находится на левом краю поля
        newCoords.first += 1;  // Двигается вправо
        newCoords.second += 1; // Двигается вниз
    }
    else
    {
        // Враг продолжает двигаться в текущем направлении
        switch (this->direction)
        {
        case 'w': // Вверх
            if (currentCoords.second > 0)
                newCoords.second -= 1;
            break;
        case 's': // Вниз
            if (currentCoords.second < fld->getHeight() - 1)
                newCoords.second += 1;
            break;
        case 'a': // Влево
            if (currentCoords.first > 0)
                newCoords.first -= 1;
            break;
        case 'd': // Вправо
            if (currentCoords.first < fld->getWide() - 1)
                newCoords.first += 1;
            break;
        default:
            break;
        }
    }
    return newCoords;
}
// // void Enemy::setCoords(int newIndexesX, int newIndexesY)
// {
//     if ()
// }

void Enemy::dead()
{
    (*fld)(coords.first, coords.second) = fld->getBlock();
}

int Enemy::getLife()
{
    return life;
}

bool Enemy::isBulllet()
{
    if ((*fld)(coords.first, coords.second) == '+')
    {
        return true;
    }
    return false;
}
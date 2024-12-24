#pragma once
#include <utility>
#include <cmath>
#include "field.h"

class Entinity
{
protected:
    char character;
    pair<int, int> coords;
    Field *fld;
    int speed;

public:
    Entinity(char character, pair<int, int> startCoords, Field *fld, int speed);
    virtual void moveCoords(char mov);
    virtual void setCoords(int newIndexesX, int newIndexesY);
    virtual ~Entinity() {}
    pair<int, int> getCoords() { return {coords.first, coords.second}; }
};

class Enemy : public Entinity
{
private:
    int life = 1;
    char direction = 'd';

public:
    Enemy(char character, std::pair<int, int> startCoords, Field *fld, int speed)
        : Entinity(character, startCoords, fld, speed) {}
    void move(int &life);
    bool isPlayer();
    void dead();
    int getLife();
    bool isBulllet();
    pair<int, int> purposeCoords();
    // void setCoords(int newIndexesX, int newIndexesY) override;
};

class Bullet : public Entinity
{

private:
    int id;
    int life = 1;

public:
    Bullet(char character, pair<int, int> startCoords, Field *fld, int speed, int id)
        : Entinity(character, startCoords, fld, speed) { this->id = id; }
    void moveCoords(char mov) override;
    int getLife() { return life; }
    // void setCoords(int newIndexesX, int newIndexesY) override;
};

class Player : public Entinity
{
private:
    int score = 0;
    int life = 3;
    // vector<Bullet*> bullets;

public:
    int idBullets = 0;
    Player(char character, pair<int, int> startCoords, Field *fld, int speed)
        : Entinity(character, startCoords, fld, speed) {}
    void moveCoords(char mov) override;
    // bool isEnemy(int newIndexesX, int newIndexesY);
    //  void shot();
    void gameOver();
    // void bullethHandler();
};
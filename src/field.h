#pragma once
#include <vector>
#include <iostream>



using namespace std;

class Field
{
private:
    vector<vector<char>> field;
    int wide;
    int height;
    int barier;
    char block = '\'';
    char blockBarrier = '-';

public:
    Field(int wide, int height);
    
    void printField();
    void printGap();

    char &operator()(int heihgt, int wide);

    int getBarier() { return this->barier; }
    char getBlockBarrier() { return this->blockBarrier; }
    int getHeight() { return this->height; }
    int getWide() { return this->wide; }
    char getBlock() { return this->block; }

    //bool isEnemy(int newIndexesX, int newIndexesY);

};

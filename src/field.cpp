#include "field.h"

Field::Field(int wide, int height) : wide(wide), height(height)
{
    int barier = height * 0.4;
    this->barier = barier;
    char sym = block;
    field.resize(height);
    for (size_t i = 0; i < height; i++)
    {
        field[i].resize(wide);
        for (size_t j = 0; j < wide; j++)
        {
            field[i][j] = sym;
        }
    }
}

void Field::printField()
{
    for (int i = height-1; i >=0; i--)
    {
        for (size_t j = 0; j < wide; j++)
        {
            cout << field[i][j] << ' ';
        }
        cout << "\n";
    }
}

void Field::printGap()
{
    for (size_t i = 0; i < 100; i++)
    {
        cout << '\n';
    }
}

char &Field::operator()(int heightIndex, int widthIndex)
{
    if (heightIndex >= 0 && heightIndex < height && widthIndex >= 0 && widthIndex < wide)
    {
        return field[widthIndex][heightIndex];
    }
    throw std::out_of_range("Index out of bounds!");
}




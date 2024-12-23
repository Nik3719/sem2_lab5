#include <iostream>
#include <unistd.h>
#include <thread>
#include "entinity.h"
#include "field.h"
#include "Tools.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    setTerminalMode(true);


    Field fl(30,30);
    Player player('1', std::make_pair(15, 5), &fl, 1);
    vector<Bullet *> bullets;
    vector<Enemy *> enemies;
    Game game;
    game.startgame();


    

    setTerminalMode(false);
    return 0;
}
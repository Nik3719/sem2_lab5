#include "entinity.h"
#include "field.h"
#include "Tools.h"
#include <thread>
#include <mutex>

class Game
{
private:
    vector<Bullet *> bullets;
    vector<Enemy *> enemies;
    Player* player;
    int score = 0;
    int life = 3;
    Field* fl; 

public:
    Game();
    ~Game();
    void startgame();
    void fieldHandler();
    void enemyHandler();
    void playerHandler();
    void bullethHandler(); 

};




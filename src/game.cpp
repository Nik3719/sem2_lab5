#include "game.h"

mutex mtx;

Game::Game()
{
    this->fl = new Field(30, 30);
    this->player = new Player('1', {15, 5}, fl, 1);
}

Game::~Game()
{
    for (auto bullet : bullets)
    {
        delete bullet;
    }
    for (auto enemy : enemies)
    {
        delete enemy;
    }
}

void Game::startgame()
{
    std::thread enemyThread([&]()
                            { enemyHandler(); });
    std::thread playerThread([&]()
                             { playerHandler(); });
    std::thread bulletThread([&]()
                             { bullethHandler(); });
    std::thread fieldThread([&]()
                            { fieldHandler(); });

    enemyThread.join();
    playerThread.join();
    bulletThread.join();
    fieldThread.join();
}

void Game::fieldHandler()
{
    while (true)
    {
        if (life <= 0)
        {
            cout << "Game Over" << "\nscore " << score << endl;
            exit(1);
        }
        fl->printField();
        cout << "SCORE = " << score << " LIFE = " << life << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Небольшая пауза
        fl->printGap();
    }
}

void Game::enemyHandler()
{
    while (true)
    {
        mtx.lock();
        if (rand() % 10 == 0)
        {

            enemies.push_back(new Enemy('E', {rand() % 30, fl->getHeight() - 3}, fl, 1));
        }
        for (size_t i = 0; i < enemies.size(); i++)
        {
            pair<int, int> coordsEnemy = enemies[i]->getCoords();
            pair<int, int> newCoordsEnemy = enemies[i]->purposeCoords();
            if (coordsEnemy.second == 1)
            {
                char block = (*fl)(coordsEnemy.first, coordsEnemy.second - 1);
                (*fl)(coordsEnemy.first, coordsEnemy.second) = block;
                delete enemies[i]; 
                enemies.erase(enemies.begin() + i);
                life--;
                continue;
            }
            if (newCoordsEnemy == player->getCoords())
            {
                char block = fl->getBlock();
                (*fl)(coordsEnemy.first, coordsEnemy.second) = block;
                delete enemies[i]; 
                enemies.erase(enemies.begin() + i);
                life--;
                continue;
            }
            for (int j = 0; j < bullets.size(); j++)
            {
                if (newCoordsEnemy == bullets[j]->getCoords())
                {
                    char block = fl->getBlock();
                    (*fl)(coordsEnemy.first, coordsEnemy.second) = block;

                    delete enemies[i]; 
                    enemies.erase(enemies.begin() + i);

                    (*fl)(bullets[j]->getCoords().first, bullets[j]->getCoords().second) = block;
                    delete bullets[j]; 
                    bullets.erase(bullets.begin() + j);

                    score++;
                    continue;
                }
            }

            coordsEnemy = enemies[i]->getCoords();
            if (coordsEnemy.second == 1)
            {
                char block = (*fl)(coordsEnemy.first, coordsEnemy.second - 1);
                (*fl)(coordsEnemy.first, coordsEnemy.second) = block;
                delete enemies[i]; 
                enemies.erase(enemies.begin() + i);
                life--;

                continue;
            }
            enemies[i]->move(life);
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Небольшая пауза
    }
}

void Game::playerHandler()
{
    while (true)
    {
        pair<bool, char> click = kbhit();
        if (click.first)
        {
            char ch = click.second;
            if (ch == 'q')
            {
                exit(1);
            }
            if (ch == ' ')
            {
                // player.shot();
                int coordY = player->getCoords().second + 1;
                if (coordY != fl->getHeight())
                {
                    bullets.push_back(new Bullet('+', {player->getCoords().first, coordY},
                                                 fl, 1, this->player->idBullets));
                    this->player->idBullets++;
                }

                continue;
            }
            player->moveCoords(ch);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Небольшая пауза
    }
}

void Game::bullethHandler()
{

    while (true)
    {
        mtx.lock();
        for (size_t i = 0; i < bullets.size(); i++)
        {
            if (bullets[i]->getLife() == 0)
            {
                delete bullets[i]; 
                bullets.erase(bullets.begin() + i);
                continue;
            }
            pair<int, int> coordsBullets = bullets[i]->getCoords();

            bullets[i]->moveCoords('w');
            coordsBullets = bullets[i]->getCoords();
            if (coordsBullets.second == fl->getHeight() - 1)
            {
                char block = (*fl)(coordsBullets.first, coordsBullets.second - 1);

                (*fl)(coordsBullets.first, coordsBullets.second) = block;
                delete bullets[i]; 
                bullets.erase(bullets.begin() + i);
                continue;
            }
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Небольшая пауза
    }
}
#include "Tools.h"

void setTerminalMode(bool enableRaw)
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    if (enableRaw)
    {
        t.c_lflag &= ~(ICANON | ECHO); // Отключаем каноничный режим и эхо
    }
    else
    {
        t.c_lflag |= ICANON | ECHO; // Включаем каноничный режим и эхо
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

pair<bool, char> kbhit()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    newt.c_lflag &= ~ECHO;
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return {(ch != EOF), ch};
}
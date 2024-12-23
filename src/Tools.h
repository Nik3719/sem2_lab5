#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

void setTerminalMode(bool enableRaw);
pair<bool, char> kbhit();
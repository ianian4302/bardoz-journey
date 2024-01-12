#include <iostream>
#include <raylib.h>

#include "gameManager.h"

using namespace std;
int main()
{
    cout << "bardoz journey" << endl;
    InitGame();
    Game();
    EndGame();
    return 0;
}
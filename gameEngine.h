
#include "main.h"


class gameEngine
{
private:

public:
    gameEngine();
    ~gameEngine();

    void launch(Game,Board[SIZEROW][SIZECOL],Player,Player);
    void launchSkynet(Game,Skynet,Board[SIZEROW][SIZECOL],Player,Player);
};



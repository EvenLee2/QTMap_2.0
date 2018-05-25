#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include "icon.h"
class Player: public RPGObj
{
public:
    Player(){}
    ~Player(){}
   void setobj(string mapFile);
    bool move(int direction, int steps=1);
        //direction =1,2,3,4 for 上下左右

    bool ifmove(int posx, int posy);

private:
    int begin=0;
    vector<RPGObj>_object;
};

#endif // PLAYER_H

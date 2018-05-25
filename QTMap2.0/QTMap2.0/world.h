#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>

#include "player.h"

class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    bool handlePlayerMove(int direction, int steps);
        //假定只有一个玩家
    bool Player_if_move(int posx, int posy);

    static int live;
    static int passworldnumber;
    static int word;
    void clear();
    int getWord() const{

        return this->word;
    }
    vector<RPGObj> _objs;
private:

    Player _player;
};

#endif // WORLD_H

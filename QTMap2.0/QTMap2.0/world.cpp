#include "world.h"
#include "icon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <QGLWidget>
using namespace std;
int World::live=1;
int World::word=1;
int World::passworldnumber=0;
void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    if(passworldnumber==0){
        mapFile="c:\\Qt\\map\\map.txt";
    }

    const char * out=mapFile.c_str();
    ifstream _map(out);
    char ch[100]="";
    string s="";
    RPGObj _obj;
    int i=0;
    while(!_map.eof())
    {
       _map.getline(ch,100);
       vector<string> res;
       s=ch;
       string result;
           //将字符串读到input中
       stringstream input(s);
       while(input>>result)
            res.push_back(result);
       _obj.initObj(res[0]);
       _obj.setPosX(atoi(res[1].c_str()));
       _obj.setPosY(atoi(res[2].c_str()));
       if(i==0){

           _player.initObj("player");
           _player.setPosX(_obj.getPosX());
           _player.setPosY(_obj.getPosY());
       }else{
           this->_objs.push_back(_obj);
       }
       i++;
    }



}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    if(live>0){
        this->_player.show(painter);
    }

}
bool World::Player_if_move(int posx, int posy){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        //cout<<"1"<<endl;
        if(((*it).getPosX()<=posx&&(*it).getPosX()+(*it).getWidth()>posx)&&
                ((*it).getPosY()<=posy&&(*it).getPosY()+(*it).getHeight()>posy)){

            if((*it).canDie()){
            live--;
            cout<<"your hp--!"<<endl;
            }
            if((*it).canTalk()){
                word=0;
            cout<<"let us have a talk"<<endl;

            vector<RPGObj>::iterator it;
            string s="fruit";
            RPGObj obj;
            obj.initObj(s);
            obj.setPosX(3);
            obj.setPosY(6);
            this->_objs.push_back(obj);

            }
            if((*it).canPass()){
            passworldnumber=1;
            cout<<"you will pass!"<<endl;
            }
            if(!(*it).canCover())return false;
        }
        if((*it).getPosX()==posx&&(*it).getPosY()==posy){
            if((*it).canEat()){
                it=_objs.erase(it);
                break;
            }
        }
    }
   // cout<<"test"<<endl;
    return true;
}

bool World::handlePlayerMove(int direction, int steps){
    switch (direction){
        case 1:
            if(!Player_if_move(_player.getPosX(),_player.getPosY()))return false;
            _player.move(direction,steps);
            return true;
            break;
        case 2:
            if(!Player_if_move(_player.getPosX(),_player.getPosY()+2))return false;
            _player.move(direction,steps);
            return true;
        case 3:
            if(!Player_if_move(_player.getPosX()-1,_player.getPosY()+1))return false;
             _player.move(direction,steps);
            return true;
        case 4:
            if(!Player_if_move(_player.getPosX()+1,_player.getPosY()+1))return false;
             _player.move(direction,steps);
            return true;
    }
}
void World::clear(){
    _objs.clear();
}

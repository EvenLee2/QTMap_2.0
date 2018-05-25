#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_dieable = false;
        this->_talkable = false;
        this->_passable = false;

    }
    else if (type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_dieable =false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if (type.compare("fruit")==0){
        this->_coverable = true;
        this->_eatable = true;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("tree1")==0){
        this->_coverable= false;
        this->_eatable= false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("house")==0){
        this->_coverable= false;
        this->_eatable=false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = true;
    }
    else if(type.compare("statue")==0){
        this->_coverable=false;
        this->_eatable=false;
        this->_dieable = false;
        this->_talkable = true;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("bottom")==0){
        this->_coverable=true;
        this->_eatable= false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("road1")==0){
        this->_coverable=true;
        this->_eatable=false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("bottle")==0){
        this->_coverable=true;
        this->_eatable=true;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }
    else if(type.compare("store")==0){
        this->_coverable=false;
        this->_eatable=false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = true;
    }
    else if(type.compare("talkboard")==0){
        this->_coverable=false;
        this->_eatable=false;
        this->_dieable = false;
        this->_talkable = false;
        this->_deleteable = true;
        this->_passable = false;
    }
    else if(type.compare("well")==0){
        this->_coverable=false;
        this->_eatable=false;
        this->_dieable = true;
        this->_talkable = false;
        this->_deleteable = false;
        this->_passable = false;
    }

    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("C:\\photores.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}




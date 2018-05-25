#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <vector>
#include <QGLWidget>
#include <fstream>
#include <sstream>
#include <string>
#include<string.h>
#include <map>
#include<QString>
#include <iostream>

using namespace std;
int MW1::talkpass=0;
int MW1::talknumber=0;
int MW1::quitnumber=0;
int MW1::createtalkboard=1;
string MW1::rec[100]=" ";
MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
   startButton = new QPushButton(this);
    startButton->setGeometry(350,300,300,100);

  startButton->setStyleSheet("QPushButton{border-image:url(./Images/startButton.png)}""QPushButton:pressed{margin:2px 2px 2px 2px}");

  QObject::connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
  quitButton = new QPushButton(this);
   quitButton->setGeometry(350,400,300,100);

 quitButton->setStyleSheet("QPushButton{border-image:url(./Images/startButton.png)}""QPushButton:pressed{margin:2px 2px 2px 2px}");

 QObject::connect(quitButton,SIGNAL(clicked()),this,SLOT(quit()));
  //init game world
  talkButton = new QPushButton(this);
  talkButton->setGeometry(450,300,100,100);
  talkButton->setStyleSheet("QPushButton{border-image:url(./Images/captainWin.png)}""QPushButton:pressed{margin:2px 2px 2px 2px}");
  QObject::connect(talkButton,SIGNAL(clicked()),this,SLOT(starttalk()));
  talkButton->setVisible(false);
    _game.initWorld("");//TODO 应该是输入有效的地图文件
}

MW1::~MW1()
{
    delete ui;
}


void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
this->_game.show(pa);
    int i=0;
    if(_game.getWord()==0){
        QPainter painter(this);
        cout<<talknumber<<endl;

        /*
        //设置一个矩形
        QRectF rect(20, 20, 300, 200);

        //为了更直观地看到字体的位置，我们绘制出这个矩形
        painter.drawRect(rect);


        painter.setPen(QColor(Qt::red));

        //我们这里先让字体水平居中
        painter.drawText(rect, Qt::AlignHCenter, "yafeilinux");
    */

        QFont font("正楷", 20,  true);
        //设置下划线QFont::AllUppercase,
       // font.setUnderline(true);
        //设置上划线
       // font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::black);

        painter.drawText(120, 80,"你好");
        talkButton->setVisible(false);

        createtalkboard=0;
        if(createtalkboard==0){
        vector<RPGObj>::iterator it;
        string ss="talkboard";
        RPGObj obj1;
        obj1.initObj(ss);
        obj1.setPosX(0);
        obj1.setPosY(10);
        this->_game._objs.push_back(obj1);
        createtalkboard=1;
        cout<<"the board will be created"<<endl;
    }
        createtalkboard=1;
        string mapFile="c:\\Qt\\map\\talk.txt";
        const char * out=mapFile.c_str();
        ifstream _map(out);
        char ch[10000]="";
        string s="";
        RPGObj _obj;
        int i=0;

        while(!_map.eof())
        {


            _map.getline(ch,10000);

           vector<string> res;
           s=ch;
           string result;
               //将字符串读到input中
           stringstream input(s);
           while(input>>result)
                res.push_back(result);
           cout<<res[0]<<endl;

           rec[i]=res[0];
           cout<<rec[i]<<endl;
           i++;
           /*
           QPainter painter(this);

           /*
           //设置一个矩形
           QRectF rect(20, 20, 300, 200);

           //为了更直观地看到字体的位置，我们绘制出这个矩形
           painter.drawRect(rect);


           painter.setPen(QColor(Qt::red));

           //我们这里先让字体水平居中
           painter.drawText(rect, Qt::AlignHCenter, "yafeilinux");
       */

           /*QFont font("正楷", 20,  true);
           //设置下划线QFont::AllUppercase,
          // font.setUnderline(true);
           //设置上划线
          // font.setOverline(true);
           //设置字母大小写
           font.setCapitalization(QFont::SmallCaps);
           //设置字符间的间距
           font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
           //使用字体
           painter.setFont(font);
           painter.setPen(Qt::white);
           QString re=QString::fromStdString(res[0]);
           painter.drawText(120, 80,re);

talkpass--;

           */
           //delete this;

          // painter.translate(50, 50);
           //painter.rotate(90);
          // painter.drawText(0, 0, tr("helloqt"));
        }


    }

    _game.word++;

    if(talknumber!=0){
        QPainter painter(this);
        cout<<talknumber<<endl;

        /*
        //设置一个矩形
        QRectF rect(20, 20, 300, 200);

        //为了更直观地看到字体的位置，我们绘制出这个矩形
        painter.drawRect(rect);


        painter.setPen(QColor(Qt::red));

        //我们这里先让字体水平居中
        painter.drawText(rect, Qt::AlignHCenter, "yafeilinux");
    */

        QFont font("正楷", 20,  true);
        //设置下划线QFont::AllUppercase,
       // font.setUnderline(true);
        //设置上划线
       // font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::black);
        QString re=QString::fromStdString(rec[talknumber-1]);
        painter.drawText(120, 80,re);

 cout<<rec[talknumber-1]<<endl;

        talkpass--;
        //

       // painter.translate(50, 50);
        //painter.rotate(90);
       // painter.drawText(0, 0, tr("helloqt"));

    }

if(quitnumber!=0){
    delete this;
   }
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{

    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    else if(e->key() == Qt::Key_Z)
    {
         talkpass++;
         cout<<"talk will be passed!"<<endl;

         if(talknumber==1){




         }
         talknumber++;
         if(talknumber==10){
             vector<RPGObj>::iterator it2;
             for(it2=this->_game._objs.begin();it2!=this->_game._objs.end();it2++){
             if((*it2).canDelete()){
             it2=_game._objs.erase(it2);
             cout<<"yes"<<endl;
             break;
             }
         }
         }
         if(talknumber==11){
         talknumber=1;

         }
    }
    this->repaint();
    if(_game.passworldnumber==1){
        _game.clear();
        _game.initWorld("c:\\Qt\\map\\map2.txt");
        _game.passworldnumber=0;
        repaint();
}
}
void MW1::on_pushButton_clicked()
{




    vector<RPGObj>::iterator it;
    string s="fruit";
    RPGObj obj;
    obj.initObj(s);
    obj.setPosX(3);
    obj.setPosY(6);
    this->_game._objs.push_back(obj);


}

void MW1::start()
{




    startButton->setVisible(false);
    quitButton->setVisible(false);

}

void MW1::starttalk()
{



cout<<"hi"<<endl;
talknumber++;

   //talkButton->setVisible(false);

}

void MW1::quit()
{




    quitnumber++;


}

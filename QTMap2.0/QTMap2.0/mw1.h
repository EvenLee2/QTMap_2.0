#ifndef MW1_H
#define MW1_H
#include<QPushButton>
#include <QMainWindow>
#include<QKeyEvent>
#include<QEvent>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include<string.h>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
     QPushButton* startButton;
     QPushButton* talkButton;
     QPushButton* quitButton;
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);

    void keyPressEvent(QKeyEvent *);
   static int talkpass;
   static int talknumber;
    static int quitnumber;
    static int createtalkboard;
   static string rec[100];
private slots:
   void on_pushButton_clicked();

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer1;
    QTimer *timer2;
        //时钟，控制玩家移动频率
public slots:
    void start();
    void starttalk();
    void quit();
};

#endif // MW1_H

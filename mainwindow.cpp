#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QDateTime>
#include <QScrollArea>
#include <QScrollArea>
#include <QTableWidget>
#include <QTextCodec>

#include<iostream>
#include "formula/Fraction.h"
#include "formula/Operation.h"
#include "formula/OperationFactory.h"
#include "formula/Generate.h"
#include "language/Language.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define get_langue_str(x,y) CS2QS(x.get_##y())
/*类型转换*/
QString  CS2QS(char *x)
{
    QString ret= QString(x);
    return ret;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

        ui->setupUi(this);
        this->resize(1000,600);
        srand((unsigned)time(NULL));  // 随机函数值动态变化

        // 创建文件菜单
        menu_F = ui->menuBar->addMenu(get_langue_str(language,file));
        // 创建打开文件动作
        openAction = new QAction(get_langue_str(language,openfile), this);
        // 添加图标
        QIcon openIcon(":/myimages/images/file.png");
        openAction->setIcon(openIcon);
        // 设置快捷键
        openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
        // 在文件菜单中设置新的打开动作
        menu_F->addAction(openAction);

        copyAction = new QAction(get_langue_str(language,copyfile), this);
        QIcon copyIcon(":/myimages/images/copy.png");
        copyAction->setIcon(copyIcon);
        copyAction->setShortcut(QKeySequence(tr("Ctrl+C")));
        menu_F->addAction(copyAction);
        exitAction = new QAction(get_langue_str(language,exit), this);
        exitAction->setShortcut(QKeySequence(tr("Ctrl+Q")));
        menu_F->addAction(exitAction);

        // 设置记录菜单
        menu_R = ui->menuBar->addMenu(get_langue_str(language,record));
        resetAction = new QAction(get_langue_str(language,reset), this);
        menu_R->addAction(resetAction);

        // 设置语言菜单
        menu_L = ui->menuBar->addMenu(get_langue_str(language,language));
        QAction *chineseAction = new QAction(tr("&简体中文"), this);
        menu_L->addAction(chineseAction);
        QAction *chineseTAction = new QAction(tr("&繁体中文"), this);
        menu_L->addAction(chineseTAction);
        QAction *englishAction = new QAction(tr("&English"), this);
        menu_L->addAction(englishAction);

        // 设置帮助菜单
        menu_H = ui->menuBar->addMenu(get_langue_str(language,help));
        parameterAction = new QAction(get_langue_str(language,params), this);
        menu_H->addAction(parameterAction);
        aboutAction = new QAction(get_langue_str(language,about), this);
        menu_H->addAction(aboutAction);

        //第一行布局
        numberLE->setPlaceholderText(get_langue_str(language,input));
        numberLE->setAlignment(Qt::AlignHCenter);
        layout->addWidget(numberLE, 0, 0, 1, 2);
        startBtn->setText(get_langue_str(language,start));
        layout->addWidget(startBtn, 0, 2, 1, 1);



        char *buf=getRecord();
        userRecord->setText(buf);
        historyRecord = new QLabel(this);
        historyRecord->setText(get_langue_str(language,history));
        layout->addWidget(historyRecord, 1, 0, 1, 1);
        userRecord->setAlignment(Qt::AlignHCenter);
        layout->addWidget(userRecord, 1, 1, 1, 1);
        layout->addWidget(timeLabel, 0, 4, 1, 1);

        submitBtn = new QPushButton(this);
        submitBtn->setText(get_langue_str(language,submit));
        this->setTime();
        layout->addWidget(submitBtn, 1, 2, 1, 1);

        //score->setText(get_langue_str(language,score));
        this->setScore();
        layout->addWidget(score, 1, 4, 1, 1);

        // 第三行算式生成布局
        layout->addWidget(formulaWidget, 2, 0, 1, 5);
        ui->centralWidget->setLayout(layout);


    connect(startBtn, &QPushButton::clicked, this, &MainWindow::generate);
    connect(submitBtn, &QPushButton::clicked, this, &MainWindow::judge);
    connect(chineseAction,SIGNAL(triggered()),this,SLOT(setChinese()));
    connect(chineseTAction,SIGNAL(triggered()),this,SLOT(setChineseT()));
    connect(englishAction,SIGNAL(triggered()),this,SLOT(setEnglish()));
    connect(resetAction,SIGNAL(triggered()),this,SLOT(resetRecord()));
}
void MainWindow::resetRecord()
{
    ofstream recordFile("userRecord.txt");
    string str=to_string(0) + "/" + to_string(0);
    if (recordFile.is_open())
    {
        recordFile << str;
        recordFile.close();
    }
     userRecord->setText(QString::fromStdString(str));
}

char* MainWindow::getRecord()
{
    // 第二行布局
    ifstream recordFile("userRecord.txt");
    if (!recordFile.is_open())
    {
        cout << "Error opening file";
        exit (1);
    }
    while (!recordFile.eof())
    {
        recordFile.getline(buffer,100);
        cout << buffer << endl;
    }
    return buffer;
}

/*更新UI*/
void MainWindow::setUI()
{
   menu_F->setTitle((get_langue_str(language,file)));
   openAction->setText(get_langue_str(language,openfile));
   copyAction->setText(get_langue_str(language,copyfile));
   exitAction->setText(get_langue_str(language,exit));
   menu_L->setTitle(get_langue_str(language,language));
   menu_H->setTitle(get_langue_str(language,help));
   parameterAction->setText(get_langue_str(language,params));
   aboutAction->setText(get_langue_str(language,about));
   submitBtn->setText(get_langue_str(language,submit));
   startBtn->setText(get_langue_str(language,start)); ;
   numberLE->setPlaceholderText(get_langue_str(language,input));
   historyRecord->setText(get_langue_str(language,history));
   menu_R->setTitle(get_langue_str(language,record));
   resetAction->setText(get_langue_str(language,reset));
   this->setScore();
   this->setTime();
   this->setFormulaWidget();
}

void MainWindow::setChinese()
{
    language.setLanguageType(LANGUAGE_CHINESE);
    this->setUI();
}
void MainWindow::setChineseT()
{
    language.setLanguageType(LANGUAGE_CHINESE_T);
    this->setUI();
}

void MainWindow::setEnglish()
{
    language.setLanguageType(LANGUAGE_ENGLISH);
    this->setUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*更新界面时间*/
void MainWindow::setTime()
{
    /*动态获取界面文本内容*/
    QString temp = get_langue_str(language,mtime);
    QString s =get_langue_str(language,second);
    QString str = QString(temp+"%1"+s).arg(QString::number(timeCnt, 10));
    timeLabel->setText(str);
}
void MainWindow::setFormulaWidget()
{
    formulaWidget->setHorizontalHeaderLabels(
                QStringList() << get_langue_str(language,formula)
                            << get_langue_str(language,uinput)
                            << get_langue_str(language,answer)
                );    // 设置列名
}

// 更新计时器时间
void MainWindow::timerUpdate()
{
    timeCnt++;
    this->setTime();
}

void MainWindow::generate()
{
    srand((unsigned)time(NULL));  // 随机函数值动态变化
        // 关联定时器溢出信号和相应的槽函数
    this->setTime();
    timeCnt = 0;
    connect(timer,&QTimer::timeout, this, &MainWindow::timerUpdate);
    timer->start(1000);
    startBtn->disconnect();      // 关闭开始按钮的信息传递

    formulaCount = numberLE->text().toInt();
    if (formulaCount==0) return ;
    formulaWidget->setRowCount(formulaCount);   // 设置题目占的行数
    formulaWidget->setColumnCount(3);
    this->setFormulaWidget();
    formulaWidget->setColumnWidth(0, 500);
    formulaWidget->setColumnWidth(1, 200);
    formulaWidget->setColumnWidth(2, 200);
    formulaWidget->setColumnHidden(2,true);
    for(int i = 0; i < formulaCount; i++)
    {
        QTableWidgetItem *item0 = formulaWidget->item(i,0);
        QTableWidgetItem *item2 = formulaWidget->item(i,2);
        Generate FORMULA;
        if(item0) {
            item0->setFlags((item0->flags()&(~Qt::ItemIsEditable)));
        }
        else {
            item0 = new QTableWidgetItem;
            item0->setText(QString::fromLocal8Bit(FORMULA.formulaString.c_str()));
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
            item0->setFlags(item0->flags() & (~Qt::ItemIsSelectable));
            formulaWidget->setItem(i, 0, item0);

            item2 = new QTableWidgetItem;
            item2->setText(QString::fromLocal8Bit(FORMULA.resultString.c_str()));
            item2->setFlags(item2->flags() & (~Qt::ItemIsEditable));
            item2->setFlags(item2->flags() & (~Qt::ItemIsSelectable));
            item2->setTextAlignment(Qt::AlignHCenter);
            formulaWidget->setItem(i, 2, item2);
        }
    }
    CanSubmit = true;   //当前可以提交
}

void MainWindow::setScore()
{
     QString unit = get_langue_str(language,unit);
     score->setText(get_langue_str(language,score)+qscore+unit);
}

void MainWindow::judge()
{
    /*如果未生成题目或已经提交过了，就不能提交*/
    if (formulaCount == 0 || !CanSubmit)
        return ;
    /*解绑计时器的回调函数*/
    timer->disconnect();
    startBtn->connect(startBtn, &QPushButton::clicked, this, &MainWindow::generate);

    formulaWidget->setColumnHidden(2,false);
    int rightNum = 0;               // 计算正确的个数
    float perScore = 100.0 / formulaCount;   // 每道题占有分数
    for(int i = 0; i < formulaCount; i++) {
        QTableWidgetItem *item1 = formulaWidget->item(i,1);
        QTableWidgetItem *item2 = formulaWidget->item(i,2);
        if(item1) {
            QString ret = item1->text();
            QString ans = item2->text();
            if(ret != ans) item2->setForeground(QBrush(QColor(255, 0, 0)));
            else rightNum++;
        }
        else
        {
            item2->setForeground(QBrush(QColor(255, 0, 0)));
        }
    }
    float scores = rightNum * perScore;
    int dex = scores * 100;
    scores = dex / 100.0;
    QString pre = get_langue_str(language,score);
    QString temp = QString("%1").arg(scores);
    qscore = temp;
    this->setScore();
    CanSubmit = false;

    // 记录本次答题
    QString qstr = userRecord->text();
    string str = qstr.toStdString();
    int rightCount = 0, allCount = 0;
    bool flag = false;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '/') {
            flag = true;
            continue;
        }
        int tmp = str[i] - '0';
        if(!flag)
            rightCount = rightCount*10 + tmp;
        else
            allCount = allCount*10 + tmp;
    }

    rightCount += rightNum;
    allCount += formulaCount;
    str = "";
    str = to_string(rightCount) + "/" + to_string(allCount);
    ofstream recordFile("userRecord.txt");
    if (recordFile.is_open())
    {
        recordFile << str;
        recordFile.close();
    }
    userRecord->setText(QString::fromStdString(str));
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include "language/Language.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int timeId;
    int timeCnt = 0;
    QPushButton *startBtn = new QPushButton(this);
    QPushButton *stopBtn = new QPushButton(this);
    QPushButton *clearBtn = new QPushButton(this);
    QLabel *timeLabel = new QLabel(this);
    QTimer *timer = new QTimer(this);
    QLineEdit *numberLE = new QLineEdit(this);
    QGridLayout *layout = new QGridLayout;
    QTableWidget *formulaWidget = new QTableWidget(this);
    QLabel *score = new QLabel(this);  // 分数
    QLabel *userRecord = new QLabel(this);   // 用户历史记录卡
    QLabel *historyRecord;
    int formulaCount=0;
    bool CanSubmit = false;
    Language language;
    QMenu *menu_F;
    QAction *openAction;
    QAction *copyAction;
    QAction *exitAction;
    QMenu *menu_L;
    QMenu *menu_H ;
    QAction *parameterAction;
    QAction *aboutAction;
    QAction *resetAction;
    QPushButton *generateBtn;
    QPushButton *submitBtn;
    QLabel *unitLabel ;
    QMenu *menu_R;
    QString qscore="0";
    QString qtime="0";
    char buffer[256];

private slots:

    void timerUpdate();

    void generate();
    void judge();
    void setChinese();
    void setEnglish();
    void setChineseT();
    void setUI();
    char *getRecord();
    void setScore();
    void setTime();
    void resetRecord();
    void setFormulaWidget();
};

#endif // MAINWINDOW_H

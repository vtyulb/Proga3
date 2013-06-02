#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int mode = 0;
    setIgnore(true);
    ui->widget->gamer = true;
    if (mode == 0) {
        setIgnore(false);
        QObject::connect(ui->down, SIGNAL(clicked()), ui->widget, SLOT(down()));
        QObject::connect(ui->up, SIGNAL(clicked()), ui->widget, SLOT(up()));
        QObject::connect(ui->left, SIGNAL(clicked()), ui->widget, SLOT(left()));
        QObject::connect(ui->right, SIGNAL(clicked()), ui->widget, SLOT(right()));

        QObject::connect(ui->attack, SIGNAL(clicked()), ui->widget, SLOT(attack()));
        QObject::connect(ui->newgame, SIGNAL(clicked()), ui->widget, SLOT(newgame()));
        QObject::connect(ui->about, SIGNAL(clicked()), this, SLOT(showAbout()));


        QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
        QObject::connect(ui->actionAttack, SIGNAL(triggered()), ui->widget, SLOT(attack()));
        QObject::connect(ui->actionDown, SIGNAL(triggered()), ui->widget, SLOT(down()));
        QObject::connect(ui->actionLeft, SIGNAL(triggered()), ui->widget, SLOT(left()));
        QObject::connect(ui->actionNew_game, SIGNAL(triggered()), ui->widget, SLOT(newgame()));
        QObject::connect(ui->actionRight, SIGNAL(triggered()), ui->widget, SLOT(right()));
        QObject::connect(ui->actionUp, SIGNAL(triggered()), ui->widget, SLOT(up()));
        QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
        QObject::connect(ui->actionUndo, SIGNAL(triggered()), ui->widget, SLOT(ctrlz()));
        QObject::connect(ui->actionCheat, SIGNAL(triggered()), ui->widget, SLOT(cheatEnable()));
        QObject::connect(ui->actionSave_game, SIGNAL(triggered()), ui->widget, SLOT(saveField()));
        QObject::connect(ui->actionLoad_game, SIGNAL(triggered()), ui->widget, SLOT(loadField()));

        QObject::connect(ui->actionHard_2, SIGNAL(triggered()), ui->widget, SLOT(setLevelHard()));
        QObject::connect(ui->actionSimple_2, SIGNAL(triggered()), ui->widget, SLOT(setLevelSimple()));

        QObject::connect(ui->actionHard, SIGNAL(triggered()), ui->widget, SLOT(helpMeHard()));
        QObject::connect(ui->actionSimple, SIGNAL(triggered()), ui->widget, SLOT(helpMeSimple()));

        QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->widget, SLOT(setFieldSize(int)));
        QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showHelp()));

        QObject::connect(ui->actionHard_2, SIGNAL(triggered()), this, SLOT(setHard()));
        QObject::connect(ui->actionSimple_2, SIGNAL(triggered()), this, SLOT(setSimple()));
        QObject::connect(ui->HardButton, SIGNAL(clicked()), this, SLOT(setHard()));
        QObject::connect(ui->LowButton, SIGNAL(clicked()), this, SLOT(setSimple()));

        QObject::connect(ui->actionSetSize, SIGNAL(clicked()), ui->widget, SLOT(setSize()));
    }

    QSettings s;
    QByteArray geomData = s.value("MainWindow/Geometry").toByteArray();

    restoreGeometry(geomData);
    ui->spinBox->setValue(ui->widget->size - 10);
    MainWindow::setHard();
}

void MainWindow::showAbout()
{
    QMessageBox::about(this,
                       tr("Proga3"),
                       tr("This program is created by V.S.Tyulbashev"));
}

void MainWindow::showHelp()
{
    QMessageBox::about(this,
                       tr("CRISSCROSS"),
                       tr("about crisscross text"));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->widget->keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    QSettings s;
    s.setValue("MainWindow/Geometry", saveGeometry());
    delete ui;
}

void MainWindow::setHard()
{
    ui->actionHard_2->setChecked(true);
    ui->actionSimple_2->setChecked(false);
    ui->HardButton->setChecked(true);
    ui->LowButton->setChecked(false);
}

void MainWindow::setSimple()
{
    ui->actionSimple_2->setChecked(false);;
    ui->actionHard_2->setChecked(true);
    ui->HardButton->setChecked(false);
    ui->LowButton->setChecked(true);
}

void MainWindow::setSize(int i)
{
    ui->widget->setFieldSize(i);
}

void MainWindow::setGamer(bool b)
{
    ui->widget->gamer = b;
}

void MainWindow::setIgnore(bool b)
{
    ui->widget->ignore = b;
}

bool MainWindow::checkIgnore()
{
    return !ui->widget->ignore;
}

int MainWindow::whoWon()
{
    return ui->widget->whoWon();
}

void MainWindow::defend(int x, int y)
{
    ui->widget->defend(x, y);
}

int MainWindow::lastX()
{
    return ui->widget->lastX();
}

int MainWindow::lastY()
{
    return ui->widget->lastY();
}

TPoint MainWindow::helpHim()
{
    return ui->widget->helpMeHard();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

struct TPoint {
    int x;
    int y;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setSize(int i);
    void setGamer(bool b);
    void setIgnore(bool b);

    bool checkIgnore();
    void defend(int x, int y);
    int whoWon();
    int lastX();
    int lastY();
    TPoint helpHim();
public slots:
    void showAbout();
    void showHelp();

    void setHard();
    void setSimple();
private:
    void keyPressEvent(QKeyEvent *event);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

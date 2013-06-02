#include "proga3plugin.h"
#include "mainwindow.h"

struct Proga3PluginPrivate {
    QVariant lastResult;
    QList<QVariant> optResults;
    QString lasterror;

};

proga3Plugin::proga3Plugin(QObject *parent) :
    QObject(parent)
{
    d = new Proga3PluginPrivate;
}

QList<Alg> proga3Plugin::algList()
{
    QList<Alg> l;
    Alg a;

    a.kumirHeader = QString::fromUtf8("алг начать игру(цел размер поля, цел интеллект, лог кумир начинает)");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг передать свой ход(цел X, Y)");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг сделать ход");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг цел последний ход исполнителя X");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг цел последний ход исполнителя Y");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг лог игра закончена");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг цел результат игры");
    l << a;
    a.kumirHeader = QString::fromUtf8("алг подсказка (цел уровень)");
    l << a;

    return l;
}

QString proga3Plugin::name()
{
    return QString::fromUtf8("Proga3::CrissCross");
}

QList<QVariant> proga3Plugin::algOptResults()
{
    return d->optResults;
}

QVariant proga3Plugin::result()
{
    QVariant v = d->lastResult;
    return v;
}

void proga3Plugin::runAlg(QString alg, QList<QVariant> params)
{
    d->lasterror = "";
    d->lastResult = QVariant();
    if (alg == QString::fromUtf8("начать игру")) {
        mainWidget->setSize(params[0].toInt());
        if (params[1].toInt() == 0) mainWidget->setHard(); else
                                    mainWidget->setSimple();
        mainWidget->setGamer(params[2].toBool());
        mainWidget->setIgnore(false);
    } else if (alg == QString::fromUtf8("передать свой ход")) {
        mainWidget->defend(params[1].toInt(), params[0].toInt());
    } else if (alg == QString::fromUtf8("цел последний ход исполнителя X")) {
        d->lastResult = mainWidget->lastX();
    } else if (alg == QString::fromUtf8("цел последний ход исполнителя Y")) {
        d->lastResult = mainWidget->lastY();
    } else if (alg == QString::fromUtf8("лог игра закончена")) {
        d->lastResult = mainWidget->checkIgnore();
    } else if (alg == QString::fromUtf8("цел результат игры")) {
        d->lastResult = mainWidget->whoWon();
    } else if (alg == QString::fromUtf8("подсказка")) {
        TPoint p = mainWidget->helpHim();
        d->optResults[0] = p.x;
        d->optResults[1] = p.y;
    }
}

void proga3Plugin::showField()
{
    Proga3Window.show();
}

void proga3Plugin::hideField()
{
    Proga3Window.hide();
}

void proga3Plugin::setMode(int mode)
{

}

void proga3Plugin::reset()
{
    d->lasterror = "";
    d->lastResult = QVariant();
}

QString proga3Plugin::errorText() const
{
    return d->lasterror;
}

void proga3Plugin::connectSignalSendText(const QObject *obj, const char *method)
{
    connect(this, SIGNAL(sendText(QString)), obj, method);
}

void proga3Plugin::connectSignalSync(const QObject *obj, const char *method)
{
    connect(this, SIGNAL(sync()), obj, method);
}

QString proga3Plugin::help()
{
    return "No HELP!!!";
}

void proga3Plugin::handleResetRequest()
{
    reset();
}

void proga3Plugin::handleLoadImageRequest(const QString &fileName)
{

}

void proga3Plugin::handleNewImageRequest(int w, int h, const QString &bg)
{

}

//QWidget *proga3Plugin::mainWidget()
//{
//    return QWidget(&mainWidget);
//}

//Q_EXPORT_PLUGIN2(proga3, Proga3Plugin)

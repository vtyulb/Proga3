#ifndef PROGA3PLUGIN_H
#define PROGA3PLUGIN_H

#include <QObject>
#include <QtGui>
#include "plugin_interface.h"
#include "mainwindow.h"

class proga3Plugin : public QObject,
                     kumirPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(kumirPluginInterface)
public:
    explicit proga3Plugin(QObject *parent = 0);
    inline void start() { }
    QList<Alg> algList();//Список алгоритмов
    QString name(); //Имя
    QList<QVariant> algOptResults();
    QVariant result();
    void runAlg(QString alg, QList<QVariant> params);

    void showField();
    inline void showPult() { }
    inline void hidePult() { }
    void hideField();
    inline void showOpt() { }
    inline bool hasPult() { return false; }
    inline bool hasOpt() { return false; }
    inline QString optText() { return ""; }
    void setMode(int mode);

    void reset();
    QString errorText() const;

    void connectSignalSendText(const QObject *obj, const char *method);
    void connectSignalSync(const QObject *obj, const char *method);

    QString help();

    MainWindow *mainWidget;
    inline QWidget * pultWidget() { return 0; }
private slots:
    void handleResetRequest();
    void handleNewImageRequest(int w, int h, const QString &bg);
    void handleLoadImageRequest(const QString &fileName);
signals:
    void sendText(const QString &text);
    void sync();
private:
    MainWindow Proga3Window;
    struct Proga3PluginPrivate *d;

public slots:

};

#endif // PROGA3PLUGIN_H

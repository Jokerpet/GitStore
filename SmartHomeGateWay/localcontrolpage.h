#ifndef LOCALCONTROLPAGE_H
#define LOCALCONTROLPAGE_H

#include <QWidget>

namespace Ui {
class LocalControlPage;
}
class QSerialPort;
class LocalControlPage : public QWidget
{
    Q_OBJECT

public:
    explicit LocalControlPage(QWidget *parent = nullptr);
    ~LocalControlPage();

private slots:
    void on_btnSerialOpen_clicked();

    void on_btnOpenLight1_clicked();

    void on_btnOpenLight2_clicked();

    void on_btnOpenLight3_clicked();

    void on_btnOpenLight4_clicked();

    void on_btnOpenRGB_clicked();

    void on_btnOpenAlarm_clicked();

    void on_btnOpenAlarm_2_clicked();

    void on_btnOpenSteer_clicked();

    void on_btnCloseSteer_clicked();

    void on_btnOpenFan_clicked();

    void on_btnCloseFan_clicked();

    void on_btnOpenRelay1_clicked();

    void on_btnCloseRelay1_clicked();

    void on_btnOpenRelay2_clicked();

    void on_btnCloseRelay2_clicked();

    void on_btnOpenLock_clicked();

    void on_btnCloseLock_clicked();

private:
    Ui::LocalControlPage *ui;
    QSerialPort *serialport;
};

#endif // LOCALCONTROLPAGE_H

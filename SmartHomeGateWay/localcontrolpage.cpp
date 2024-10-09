#include "localcontrolpage.h"
#include "ui_localcontrolpage.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QColorDialog>
LocalControlPage::LocalControlPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalControlPage),
    serialport(new QSerialPort)
{
    ui->setupUi(this);
    foreach(const QSerialPortInfo &info,
            QSerialPortInfo::availablePorts()){
        ui->cbSerialPortName->addItem(info.portName());
    }
    serialport->setDataBits(QSerialPort::Data8);
    serialport->setStopBits(QSerialPort::OneStop);
    serialport->setParity(QSerialPort::NoParity);
    serialport->setFlowControl(QSerialPort::NoFlowControl);
}

LocalControlPage::~LocalControlPage()
{
    delete ui;
}

void LocalControlPage::on_btnSerialOpen_clicked()
{
    if(serialport->isOpen())
    {//关闭
        serialport->close();
        ui->btnSerialOpen->setText("打开");
    }
    else {//打开
        serialport->setPortName(ui->cbSerialPortName->currentText());
        serialport->setBaudRate(ui->cbSerialBandrate->currentText().toInt());
        bool ok = serialport->open(QIODevice::ReadWrite);
        if(ok)
            ui->btnSerialOpen->setText("关闭");
    }
}

void LocalControlPage::on_btnOpenLight1_clicked()
{
    QString cmd = QString("FE FE 00 FF FF 1A 10 11 %1 FF").arg(ui->hsLight1->value(),2,16,QLatin1Char('0'));
    QByteArray data =
            QByteArray::fromHex(cmd.toLocal8Bit());
    serialport->write(data);
}

void LocalControlPage::on_btnOpenLight2_clicked()
{

    QString cmd = QString("FE FE 00 FF FF 1A 10 12 %1 FF").arg(ui->hsLight2->value(),2,16,QLatin1Char('0'));
    QByteArray data =
            QByteArray::fromHex(cmd.toLocal8Bit());
    serialport->write(data);
}

void LocalControlPage::on_btnOpenLight3_clicked()
{
    QString cmd = QString("FE FE 00 FF FF 1A 10 13 %1 FF").arg(ui->hsLight3->value(),2,16,QLatin1Char('0'));
    QByteArray data =
            QByteArray::fromHex(cmd.toLocal8Bit());
    serialport->write(data);
}

void LocalControlPage::on_btnOpenLight4_clicked()
{
    QString cmd = QString("FE FE 00 FF FF 1A 10 14 %1 FF").arg(ui->hsLight4->value(),2,16,QLatin1Char('0'));
    QByteArray data =
            QByteArray::fromHex(cmd.toLocal8Bit());
    serialport->write(data);
}

void LocalControlPage::on_btnOpenRGB_clicked()
{
    QColor c = QColorDialog::getColor(
                Qt::black,this,"选择颜色");

    QString cmd = QString("FE FE 00 FF FF 1A 10 15 %1 %2 %3 FF")
            .arg(c.green(),2,16,QLatin1Char('0'))
            .arg(c.red(),2,16,QLatin1Char('0'))
            .arg(c.blue(),2,16,QLatin1Char('0'));
    QByteArray data =
            QByteArray::fromHex(cmd.toLocal8Bit());
    serialport->write(data);
    ui->lbRGB->setStyleSheet(
                QString("background-color: rgb(%1, %2, %3);")
                .arg(c.red()).arg(c.green()).arg(c.blue()));
}

void LocalControlPage::on_btnOpenAlarm_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 50 21 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenAlarm_2_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 50 21 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenSteer_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 60 25 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnCloseSteer_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 60 25 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenFan_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 27 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnCloseFan_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 27 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenRelay1_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 28 01 FF");
    serialport->write(data);
}


void LocalControlPage::on_btnCloseRelay1_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 28 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenRelay2_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 29 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnCloseRelay2_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 29 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenLock_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 80 2A 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnCloseLock_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 80 2A 02 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnOpenMotor_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 26 01 FF");
    serialport->write(data);
}

void LocalControlPage::on_btnCloseMotorr_clicked()
{
    QByteArray data =
            QByteArray::fromHex("FE FE 00 FF FF 1A 70 26 02 FF");
    serialport->write(data);
}

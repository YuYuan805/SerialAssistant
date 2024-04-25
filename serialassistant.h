#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class SerialAssistant; }
QT_END_NAMESPACE

class SerialAssistant : public QWidget
{
    Q_OBJECT

public:
    SerialAssistant(QWidget *parent = nullptr);
    ~SerialAssistant();

private slots:

    void on_serialRefresh_clicked();

    void on_serialLink_clicked();

    void on_serialBreak_clicked();

private slots: // my function
    void serialMsgDispose();

    void on_serialInfoClear_clicked();

    void on_serialBySendInfo_clicked();

private:
    Ui::SerialAssistant *ui;
    QSerialPort qserialport;
};
#endif // SERIALASSISTANT_H

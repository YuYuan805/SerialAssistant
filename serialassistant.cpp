#include "serialassistant.h"
#include "ui_serialassistant.h"
#include "messagebox.h"

SerialAssistant::SerialAssistant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);
    // The serial refresh is executed with the constructor
    on_serialRefresh_clicked();
}

SerialAssistant::~SerialAssistant()
{
    delete ui;
}



// Refresh the serial
void SerialAssistant::on_serialRefresh_clicked()
{
    ui->serialChoose->clear();
    // QSerialPortInfo::availablePorts() -> QList<> {}
    for (const auto &info : QSerialPortInfo::availablePorts()) {
        ui->serialChoose->addItem(info.portName());
    }
}

// Link the serial
void SerialAssistant::on_serialLink_clicked()
{
    qserialport.setPortName(ui->serialChoose->currentText());
    qserialport.setBaudRate(ui->serialBaudRate->currentText().toInt());

    qserialport.open(QIODevice::ReadWrite);
    if (qserialport.isOpen()) {
        MessageBOX::Message("串口连接成功");
        connect(&qserialport, &QSerialPort::readyRead, this, &SerialAssistant::serialMsgDispose);
    } else {
        MessageBOX::Message("串口连接失败");
    }
}

void SerialAssistant::serialMsgDispose() {
    auto info = qserialport.readAll();
    ui->receiveInfo->insertPlainText(info);
    ui->receiveInfo->insertPlainText("\n");
}

void SerialAssistant::on_serialBreak_clicked()
{
    qserialport.clear();
    if (qserialport.isOpen()) {
        MessageBOX::Message("串口关闭失败");
    } else {
        MessageBOX::Message("串口关闭成功");
    }
}

void SerialAssistant::on_serialInfoClear_clicked()
{
    ui->receiveInfo->clear();
}

void SerialAssistant::on_serialBySendInfo_clicked()
{
    auto info = ui->sendInfo->toPlainText().toUtf8();
    qserialport.write(info, info.size());
}

#include "messagebox.h"

std::shared_ptr<QMessageBox> MessageBOX::msg_box;

void MessageBOX::Message(QString &&msg) {
    //setMessage(std::forward<QString>(msg));
    if (msg_box == nullptr) {
        msg_box = std::make_shared<QMessageBox>();
    }
    msg_box->setWindowTitle("提示");
    msg_box->setText(msg);
    msg_box->setStandardButtons(QMessageBox::Ok);
    msg_box->exec();
}

void MessageBOX::Message(QString &msg) {
    Message(std::move(msg));
}


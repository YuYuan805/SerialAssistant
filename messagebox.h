#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QtWidgets>
#include <memory>

class MessageBOX
{
public:
    MessageBOX() = default;
    static void Message(QString &msg);
    static void Message(QString &&msg);

private:
    static std::shared_ptr<QMessageBox> msg_box;
};


#endif // MESSAGEBOX_H

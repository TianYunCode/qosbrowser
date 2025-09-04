#include "fend/uilogin/UiLoginDialog.h"
#include "fend/uimain/UiMain.h"
#include "middle/ManGlobal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MG->init(argc, argv);
    UiMain w;
    UiLoginDialog login;
    login.show();
    return a.exec();
}

#include "dialerapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialerApp w;
    w.show();

    return a.exec();
}

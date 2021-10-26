#include "menu_principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu_principal w;
    w.show();

    return a.exec();
}

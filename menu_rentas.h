#ifndef MENU_RENTAS_H
#define MENU_RENTAS_H
#include "menu_principal.h"

#include <QStackedWidget>

namespace Ui {
class Menu_rentas;
}

class Menu_rentas : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Menu_rentas(QWidget *parent = 0);
    ~Menu_rentas();

private slots:
    void on_pushButtonNuevaRenta_clicked();

private:
    Ui::Menu_rentas *ui;
};

#endif // MENU_RENTAS_H

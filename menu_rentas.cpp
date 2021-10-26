#include "menu_rentas.h"
#include "ui_menu_rentas.h"


Menu_rentas::Menu_rentas(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::Menu_rentas)
{
    ui->setupUi(this);

}

Menu_rentas::~Menu_rentas()
{
    delete ui;
}

void Menu_rentas::on_pushButtonNuevaRenta_clicked()
{

}

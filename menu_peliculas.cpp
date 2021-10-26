#include "menu_peliculas.h"
#include "ui_menu_peliculas.h"

menu_peliculas::menu_peliculas(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::menu_peliculas)
{
    ui->setupUi(this);
}

menu_peliculas::~menu_peliculas()
{
    delete ui;
}

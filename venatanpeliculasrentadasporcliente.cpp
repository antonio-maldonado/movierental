#include "venatanpeliculasrentadasporcliente.h"
#include "ui_venatanpeliculasrentadasporcliente.h"

venatanpeliculasrentadasporcliente::venatanpeliculasrentadasporcliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::venatanpeliculasrentadasporcliente)
{
    ui->setupUi(this);
}

venatanpeliculasrentadasporcliente::~venatanpeliculasrentadasporcliente()
{
    delete ui;
}

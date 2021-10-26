#include "ventanapeliculasrentadascliente.h"
#include "ui_ventanapeliculasrentadascliente.h"
#include "menu_principal.h"

ventanaPeliculasRentadasCliente::ventanaPeliculasRentadasCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaPeliculasRentadasCliente)
{
    ui->setupUi(this);
    administradorNotas=new Administrador_notas_de_renta;
}

ventanaPeliculasRentadasCliente::~ventanaPeliculasRentadasCliente()
{
    delete ui;
}
 v

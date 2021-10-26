#include "ventanapeliculasrentadasporelcliente.h"
#include "ui_ventanapeliculasrentadasporelcliente.h"
#include "menu_principal.h"


ventanapeliculasrentadasporelcliente::ventanapeliculasrentadasporelcliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanapeliculasrentadasporelcliente)
{
    ui->setupUi(this);

}

ventanapeliculasrentadasporelcliente::~ventanapeliculasrentadasporelcliente()
{
    delete ui;
}

#ifndef VENTANAPELICULASRENTADASCLIENTE_H
#define VENTANAPELICULASRENTADASCLIENTE_H
#include "menu_principal.h"
#include "administrador_notas_de_renta.h"


#include <QDialog>

namespace Ui {
class ventanaPeliculasRentadasCliente;
}

class ventanaPeliculasRentadasCliente : public QDialog
{
    Q_OBJECT

public:
    explicit ventanaPeliculasRentadasCliente(QWidget *parent = 0);
    ~ventanaPeliculasRentadasCliente();

private:
    Ui::ventanaPeliculasRentadasCliente *ui;
    Administrador_notas_de_renta *administradorNotas;
};

#endif // VENTANAPELICULASRENTADASCLIENTE_H

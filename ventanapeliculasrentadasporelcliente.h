#ifndef VENTANAPELICULASRENTADASPORELCLIENTE_H
#define VENTANAPELICULASRENTADASPORELCLIENTE_H

#include <QMainWindow>

namespace Ui {
class ventanapeliculasrentadasporelcliente;
}

class ventanapeliculasrentadasporelcliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanapeliculasrentadasporelcliente(QWidget *parent = 0);
    ~ventanapeliculasrentadasporelcliente();

private:
    Ui::ventanapeliculasrentadasporelcliente *ui;
};

#endif // VENTANAPELICULASRENTADASPORELCLIENTE_H

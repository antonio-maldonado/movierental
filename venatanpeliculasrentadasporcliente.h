#ifndef VENATANPELICULASRENTADASPORCLIENTE_H
#define VENATANPELICULASRENTADASPORCLIENTE_H

#include <QDialog>

namespace Ui {
class venatanpeliculasrentadasporcliente;
}

class venatanpeliculasrentadasporcliente : public QDialog
{
    Q_OBJECT

public:
    explicit venatanpeliculasrentadasporcliente(QWidget *parent = 0);
    ~venatanpeliculasrentadasporcliente();

private:
    Ui::venatanpeliculasrentadasporcliente *ui;
};

#endif // VENATANPELICULASRENTADASPORCLIENTE_H

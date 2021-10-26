#ifndef VENATANPELICULASRENTADASPORELCLIENTE_H
#define VENATANPELICULASRENTADASPORELCLIENTE_H

#include <QMainWindow>

namespace Ui {
class venatanpeliculasrentadasporelcliente;
}

class venatanpeliculasrentadasporelcliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit venatanpeliculasrentadasporelcliente(QWidget *parent = 0);
    ~venatanpeliculasrentadasporelcliente();

private:
    Ui::venatanpeliculasrentadasporelcliente *ui;
};

#endif // VENATANPELICULASRENTADASPORELCLIENTE_H

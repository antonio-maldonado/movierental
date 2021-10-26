#ifndef CLIENTES_H
#define CLIENTES_H
#include "qstring.h"
class Clientes{
private:
    QString nombre;
    int codigo_cliente;
    int edad;
public:
    Clientes();
    void set_nombre(QString nombre);
    void set_codigo_cliente(int codigo_cliente);
    void set_edad(int edad);

    QString get_nombre();
    int get_codigo_cliente();
    int get_edad();

};

#endif // CLIENTES_H

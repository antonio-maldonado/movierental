#ifndef ADMINISTRADOR_DE_CLIENTES_H
#define ADMINISTRADOR_DE_CLIENTES_H
#include "clientes.h"
#include "qvector.h"
#include "qstring.h"

class Administrador_de_clientes{
private:
    QVector <Clientes*> *lista_clientes;
 public:
    Administrador_de_clientes();
    void registra_cliente(int codigo_cliente, QString nombre_cliente, int edad);
    void elimina_cliente(int codigo_cliente);
    Clientes *busca_cliente(int codigo_cliente);
    void modifica_cliente (int codigo_cliente,QString nombre_cliente, int edad);
    QVector<Clientes*> *get_lista_clientes();


};

#endif // ADMINISTRADOR_DE_CLIENTES_H

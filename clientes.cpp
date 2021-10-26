#include "clientes.h"
Clientes::Clientes(){
    nombre="";
    codigo_cliente=0;
    edad=0;
}




void Clientes::set_nombre(QString nombre){
    this->nombre=nombre;
}

void Clientes::set_edad(int edad){
    this->edad=edad;
}

void Clientes::set_codigo_cliente(int codigo_cliente){
    this->codigo_cliente=codigo_cliente;
}



QString Clientes::get_nombre(){
    return nombre;
}

int Clientes::get_edad(){
    return edad;
}


int Clientes::get_codigo_cliente(){
    return codigo_cliente;
}

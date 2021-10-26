#ifndef ADMINISTRADOR_NOTAS_DE_RENTA_H
#define ADMINISTRADOR_NOTAS_DE_RENTA_H
#include "notas_de_renta.h"
#include "qstring.h"
#include "qvector.h"

class Administrador_notas_de_renta{
private:
    QVector <Notas_de_renta*> *lista_notas_de_renta;
public:
    Administrador_notas_de_renta();
    void realizar_nota_de_renta(int numero_nota, QString cliente);
    void agregar_pelicula_en_nota(int numero_nota, int codigo, QString titulo, float precio);
    void elimina_pelicula_de_nota(int numero_nota,int codigo_pelicula);
    void eliminar_nota(int numero_nota);
    Notas_de_renta *buscanota (int numero_nota);
    QVector <Notas_de_renta*> *get_lista_notas_de_renta();




};


#endif // ADMINISTRADOR_NOTAS_DE_RENTA_H

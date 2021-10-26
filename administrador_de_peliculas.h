#ifndef ADMINISTRADOR_DE_PELICULAS_H
#define ADMINISTRADOR_DE_PELICULAS_H
#include "peliculas.h"
#include "qvector.h"
#include "qstring.h"
class Administrador_de_peliculas{

private:
    QVector <Peliculas*> *catalogo_de_peliculas;
public:
    Administrador_de_peliculas();
    void registrar_pelicula(int codigo, QString titulo, float precio_base,int cantidad_copias, int tipo_pelicula);
    void modificar_pelicula(int codigo, QString titulo, float Precio_base,int cantidad_copias, int tipo_pelicula);
    Peliculas *buscar_pelicula(int codigo);
    void eliminar_pelicula(int codigo);
    QVector <Peliculas*> *get_catalogo_de_peliculas();

    void mostrar_peliculas();

};

#endif // ADMINISTRADOR_DE_PELICULAS_H

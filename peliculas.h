#ifndef PELICULAS_H
#define PELICULAS_H
#include <QString>
class Peliculas{

protected:
    int codigo_pelicula;
    QString titulo;
    float precio_base;
    float precio_de_renta;
    int numero_de_copias;
    int tipoPelicula;

public:

    void set_codigo_pelicula (int codigo_pelicula);
    void set_titulo(QString titulo);
    void set_precio_base(float precio_base);
    void set_tipoPelicula(int tipoPelicula);
    virtual void set_precio_de_renta();
    void set_numero_de_copias(int numero_de_copias);

    int get_codigo_pelicula();
    QString get_titulo();
    float get_precio_base();
    int get_numero_de_copias();
    int get_tipoPelicula();
    virtual float get_precio_de_renta();
};
#endif // PELICULAS_H

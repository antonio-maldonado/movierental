#ifndef PELICULAS_DE_LIQUIDACION_H
#define PELICULAS_DE_LIQUIDACION_H
#include "peliculas.h"
class Pelicula_de_liquidacion:public Peliculas{
private:
    float precio_de_renta;

public:

    void set_precio_de_renta();
    float get_precio_de_renta();

};


#endif // PELICULAS_DE_LIQUIDACION_H

#ifndef PELICULAS_ESTRENO_H
#define PELICULAS_ESTRENO_H
#include "peliculas.h"
class Peliculas_de_estreno: public Peliculas{
private:

    float precio_de_renta;

public:

    void set_precio_de_renta();
    float get_precio_de_renta();

};


#endif // PELICULAS_ESTRENO_H

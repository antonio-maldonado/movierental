#include "peliculas_estreno.h"

void Peliculas_de_estreno::set_precio_de_renta(){
    float aumento=1.15;
    precio_de_renta=precio_base*aumento;
}

float Peliculas_de_estreno::get_precio_de_renta(){
    return precio_de_renta;
}

#include "peliculas_de_liquidacion.h"

void Pelicula_de_liquidacion::set_precio_de_renta(){
    float aumento=1.12;
    precio_de_renta=precio_base*aumento;
}

float Pelicula_de_liquidacion::get_precio_de_renta(){
    return precio_de_renta;
}

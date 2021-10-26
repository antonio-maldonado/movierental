#include "peliculas.h"



void Peliculas::set_titulo(QString titulo){
    this->titulo=titulo;

}
void Peliculas::set_codigo_pelicula(int codigo_pelicula){
    this->codigo_pelicula=codigo_pelicula;

}

void Peliculas::set_precio_base(float precio_base){
    this->precio_base=precio_base;
}
void Peliculas::set_precio_de_renta(){
    this->precio_de_renta=precio_base;
}

void Peliculas::set_numero_de_copias(int numero_de_copias){
    this->numero_de_copias=numero_de_copias;
}
void Peliculas::set_tipoPelicula(int tipoPelicula){
    this->tipoPelicula=tipoPelicula;
}

QString Peliculas::get_titulo(){
    return titulo;
}

int Peliculas::get_codigo_pelicula(){
    return codigo_pelicula;

}

float Peliculas::get_precio_base(){
    return precio_base;
}
float Peliculas::get_precio_de_renta(){
    return precio_de_renta;
}

int Peliculas::get_numero_de_copias(){
    return numero_de_copias;
}
int Peliculas::get_tipoPelicula(){
    return tipoPelicula;
}

#include "notas_de_renta.h"
Notas_de_renta::Notas_de_renta(){
    lista_peliculas_rentadas=new QVector <datos_peliculas_rentadas*>;
}

void Notas_de_renta::set_cliente (QString cliente) {
    this->cliente=cliente;
}

void Notas_de_renta::set_numero_de_nota (int numero_de_nota) {
    this->numero_de_nota=numero_de_nota;
}

void Notas_de_renta::set_total_a_pagar ( ) {
     total_a_pagar=0;
    for (int i=0; i<(*lista_peliculas_rentadas).size();i++){

       total_a_pagar=total_a_pagar+((*lista_peliculas_rentadas)[i]->precio_renta);
    }
}

void Notas_de_renta::agregar_pelicula_rentada(int codigo,QString titulo,float Precio_renta){
   datos_peliculas_rentadas *pelicula_rentada  =new datos_peliculas_rentadas;
   pelicula_rentada->codigo_pelicula=codigo;
   pelicula_rentada->titulo_pelicula=titulo;
   pelicula_rentada->precio_renta=Precio_renta;

   (*lista_peliculas_rentadas).push_back(pelicula_rentada);
}

void Notas_de_renta::elimina_pelicula_rentada (int codigo_pelicula){
    for (int i=0; i<(*lista_peliculas_rentadas).size();i++){
       if((*lista_peliculas_rentadas)[i]->codigo_pelicula==codigo_pelicula){
           (*lista_peliculas_rentadas).remove(i);
       }
    }
}

float Notas_de_renta::get_total_a_pagar ( ) {
return total_a_pagar;
}
void Notas_de_renta::set_cantidad_de_peliculas_rentadas(){

    cantidad_peliculas_rentadas=(*lista_peliculas_rentadas).size();
}

QVector <datos_peliculas_rentadas*> *Notas_de_renta::get_lista_peliculas_rentadas(){
    if((*lista_peliculas_rentadas).size()>0){
        return lista_peliculas_rentadas;
    }else{
        return NULL;
    }

}


QString Notas_de_renta::get_cliente ( ) {
return cliente;
}

int Notas_de_renta::get_numero_de_nota(){
    return numero_de_nota;
}

int Notas_de_renta::get_cantidad_de_peliculas_rentadas(){
    return cantidad_peliculas_rentadas;
}

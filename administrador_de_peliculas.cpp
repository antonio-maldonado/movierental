#include "administrador_de_peliculas.h"
#include "peliculas.h"
#include "peliculas_estreno.h"
#include "peliculas_de_liquidacion.h"
#include "tipo_pelicula.h"
#include "qvector.h"





Administrador_de_peliculas::Administrador_de_peliculas(){


   catalogo_de_peliculas =new QVector <Peliculas*>;
}
void Administrador_de_peliculas::registrar_pelicula (int codigo, QString titulo, float precio_base,int cantidad_copias, int tipo_pelicula){

    if(tipo_pelicula==pelicula_estreno){
Peliculas_de_estreno *pelicula;
pelicula =new Peliculas_de_estreno;
pelicula->set_codigo_pelicula(codigo);
pelicula->set_titulo(titulo);
pelicula->set_precio_base(precio_base);
pelicula->set_precio_de_renta();
pelicula->set_numero_de_copias(cantidad_copias);
pelicula->set_tipoPelicula(tipo_pelicula);


(*catalogo_de_peliculas).push_back(pelicula);
    }
    if (tipo_pelicula==pelicula_liquidacion){
        Pelicula_de_liquidacion *pelicula;
        pelicula =new Pelicula_de_liquidacion;
        pelicula->set_codigo_pelicula(codigo);
        pelicula->set_titulo(titulo);
        pelicula->set_precio_base(precio_base);
        pelicula->set_precio_de_renta();
        pelicula->set_numero_de_copias(cantidad_copias);
          pelicula->set_tipoPelicula(tipo_pelicula);

       (*catalogo_de_peliculas).push_back(pelicula);
    }
if (tipo_pelicula==pelicula_normal){
    Peliculas *pelicula;
    pelicula=new Peliculas;
    pelicula->set_codigo_pelicula(codigo);
    pelicula->set_titulo(titulo);
    pelicula->set_precio_base(precio_base);
    pelicula->set_precio_de_renta();
    pelicula->set_numero_de_copias(cantidad_copias);
  pelicula->set_tipoPelicula(tipo_pelicula);
   (*catalogo_de_peliculas).push_back(pelicula);

}
}

Peliculas *Administrador_de_peliculas::buscar_pelicula(int codigo){
    for(int i=0;i<(*catalogo_de_peliculas).size();i++){
           if ((*catalogo_de_peliculas)[i]->get_codigo_pelicula()==codigo){
               return (*catalogo_de_peliculas)[i];
           }
       };
       return NULL;

}
void Administrador_de_peliculas::modificar_pelicula(int codigo, QString titulo, float precio_base, int cantidad_copias, int tipo_pelicula){

             for(int i=0;i<(*catalogo_de_peliculas).size();i++){
        if ((*catalogo_de_peliculas)[i]->get_codigo_pelicula()==codigo){

            if(tipo_pelicula==pelicula_estreno){
        Peliculas_de_estreno *pelicula;
        pelicula =new Peliculas_de_estreno;
        pelicula->set_codigo_pelicula(codigo);
        pelicula->set_titulo(titulo);
        pelicula->set_precio_base(precio_base);
        pelicula->set_precio_de_renta();
        pelicula->set_numero_de_copias(cantidad_copias);
        pelicula->set_tipoPelicula(tipo_pelicula);


        (*catalogo_de_peliculas).replace(i,pelicula);
            }
            if (tipo_pelicula==pelicula_liquidacion){
                Pelicula_de_liquidacion *pelicula;
                pelicula =new Pelicula_de_liquidacion;
                pelicula->set_codigo_pelicula(codigo);
                pelicula->set_titulo(titulo);
                pelicula->set_precio_base(precio_base);
                pelicula->set_precio_de_renta();
                pelicula->set_numero_de_copias(cantidad_copias);
                  pelicula->set_tipoPelicula(tipo_pelicula);

               (*catalogo_de_peliculas).replace(i,pelicula);
            }
        if (tipo_pelicula==pelicula_normal){
            Peliculas *pelicula;
            pelicula=new Peliculas;
            pelicula->set_codigo_pelicula(codigo);
            pelicula->set_titulo(titulo);
            pelicula->set_precio_base(precio_base);
            pelicula->set_precio_de_renta();
            pelicula->set_numero_de_copias(cantidad_copias);
              pelicula->set_tipoPelicula(tipo_pelicula);

           (*catalogo_de_peliculas).replace(i,pelicula);

        }




        }
    }
}

void Administrador_de_peliculas::eliminar_pelicula(int codigo){
    for(int i=0;i<(*catalogo_de_peliculas).size();i++){
           if ((*catalogo_de_peliculas)[i]->get_codigo_pelicula()==codigo){
              (*catalogo_de_peliculas).removeAt(i);
           }
       };

}
  QVector <Peliculas*> *Administrador_de_peliculas::get_catalogo_de_peliculas(){


      return catalogo_de_peliculas;
     }

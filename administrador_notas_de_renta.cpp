#include "administrador_notas_de_renta.h"
Administrador_notas_de_renta::Administrador_notas_de_renta(){
    lista_notas_de_renta=new QVector <Notas_de_renta*>;
}

void Administrador_notas_de_renta::realizar_nota_de_renta(int numero_nota, QString cliente){
    Notas_de_renta *nuevaNotadeRenta = new Notas_de_renta;
    nuevaNotadeRenta->set_numero_de_nota(numero_nota);
    nuevaNotadeRenta->set_cliente(cliente);

    (*lista_notas_de_renta).push_back(nuevaNotadeRenta);


}
Notas_de_renta *Administrador_notas_de_renta::buscanota(int numero_nota){
for(int i=0;i<(*lista_notas_de_renta).size();i++){
           if ((*lista_notas_de_renta)[i]->get_numero_de_nota()==numero_nota){
               return (*lista_notas_de_renta)[i];
           }
       };
       return NULL;

}

void Administrador_notas_de_renta::agregar_pelicula_en_nota(int numero_nota, int codigo, QString titulo, float precio){
    for(int i=0;i<(*lista_notas_de_renta).size();i++){
               if ((*lista_notas_de_renta)[i]->get_numero_de_nota()==numero_nota){
                    (*lista_notas_de_renta)[i]->agregar_pelicula_rentada(codigo,titulo,precio);
                    (*lista_notas_de_renta)[i]->set_cantidad_de_peliculas_rentadas();
               }
    }

}


void Administrador_notas_de_renta::eliminar_nota(int numero_nota){
    Notas_de_renta *NotaParaEliminar = new Notas_de_renta;

    for (int i = 0; i<(*lista_notas_de_renta).size();i++){
        if ((*lista_notas_de_renta)[i]->get_numero_de_nota()==numero_nota){
            QVector <datos_peliculas_rentadas*> *lista_peliculas_devueltas =new QVector <datos_peliculas_rentadas*>;
            lista_peliculas_devueltas=NotaParaEliminar->get_lista_peliculas_rentadas();
            if (lista_peliculas_devueltas!=NULL){
                for (int j=0; j<(*lista_peliculas_devueltas).size();j++){
                    (*lista_peliculas_devueltas).remove(j);
                }
                delete lista_peliculas_devueltas;
            }

        }
(*lista_notas_de_renta).remove(i);
    }


}

   QVector <Notas_de_renta*> *Administrador_notas_de_renta::get_lista_notas_de_renta(){
    return lista_notas_de_renta;
}

#ifndef NOTAS_DE_RENTA_H
#define NOTAS_DE_RENTA_H
#include "peliculas.h"
#include "qvector.h"
#include "qstring.h"
#include "QDate"

struct datos_peliculas_rentadas{
    int codigo_pelicula;
    QString titulo_pelicula;
    float precio_renta;


};

class Notas_de_renta{

private:
    int numero_de_nota;
    int cantidad_peliculas_rentadas;
    QString cliente;
    float total_a_pagar;
    QVector <datos_peliculas_rentadas*> *lista_peliculas_rentadas;
 public:
  Notas_de_renta();
   void set_cliente(QString cliente);
   void set_numero_de_nota(int numero_de_nota);
   void set_total_a_pagar();
   void agregar_pelicula_rentada(int codigo,QString titulo,float Precio_renta);
   void elimina_pelicula_rentada(int codigo_pelicula);
   void set_cantidad_de_peliculas_rentadas();
   void set_fecha_renta(int dia,int mes,int anio);
   void set_fecha_devolcuion();

   QString get_cliente();
   QVector <datos_peliculas_rentadas*> *get_lista_peliculas_rentadas();
   int get_numero_de_nota();
   float get_total_a_pagar();
   int get_cantidad_de_peliculas_rentadas();
   QDate get_fecha_renta();
   QDate get_fecha_devolucion();




};

#endif // NOTAS_DE_RENTA_H

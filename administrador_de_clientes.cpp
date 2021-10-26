#include "administrador_de_clientes.h"
#include "clientes.h"

Administrador_de_clientes::Administrador_de_clientes(){
    lista_clientes=new QVector <Clientes*>;
}

void Administrador_de_clientes::registra_cliente(int codigo_cliente, QString nombre_cliente, int edad){
    Clientes *cliente;
cliente=new Clientes;

cliente->set_codigo_cliente(codigo_cliente);
cliente->set_nombre(nombre_cliente);
cliente->set_edad(edad);

(*lista_clientes).push_back(cliente);
}

Clientes *Administrador_de_clientes::busca_cliente(int codigo_cliente){
    for(int i=0;i<(*lista_clientes).size();i++){
           if ((*lista_clientes)[i]->get_codigo_cliente()==codigo_cliente){
               return (*lista_clientes)[i];
           }
       };
       return NULL;

}
void Administrador_de_clientes::modifica_cliente(int codigo_cliente, QString nombre_cliente, int edad){
    for (int i=0;i<(*lista_clientes).size();i++){
        if ((*lista_clientes)[i]->get_codigo_cliente()==codigo_cliente){
            Clientes *cliente = new Clientes;
            cliente->set_codigo_cliente(codigo_cliente);
            cliente->set_nombre(nombre_cliente);
            cliente->set_edad(edad);

            (*lista_clientes).replace(i,cliente);

        }
    }
}

void Administrador_de_clientes::elimina_cliente(int codigo_cliente){
    for(int i=0;i<(*lista_clientes).size();i++){
           if ((*lista_clientes)[i]->get_codigo_cliente()==codigo_cliente){
              (*lista_clientes).removeAt(i);
           }
       };

}
  QVector<Clientes*> *Administrador_de_clientes::get_lista_clientes(){
      return lista_clientes;
  }

#include "menu_principal.h"
#include "ui_menu_principal.h"
#include "QTableWidgetItem"
#include "QTableView"
#include <QMessageBox>


Menu_principal::Menu_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu_principal)
{
ui->setupUi(this);
ui->ventanaAltaSBajasModificaciones->hide();
ui->ventanaAltaBajaModificacionesdelCliente->hide();
ui->VentanaNuevaRenta->hide();
ui->RentasActivas->hide();
ui->PeliculasEnNotaDeRenta->hide();
ui->menuPeliculas->show();

administrador_de_clientes1 = new Administrador_de_clientes;
administrador_de_peliculas1=new Administrador_de_peliculas;
administrador_de_notas1 =new Administrador_notas_de_renta;
numero_de_nota=0;


}
void Menu_principal::actualizaTablaPeliculas(){

QVector <Peliculas*> *listaTemporalPeliculas;
listaTemporalPeliculas = new QVector <Peliculas*>;

ui->tableWidgetListaPeliculas->clear();
ui->tableWidgetListaPeliculas->setColumnCount(0);
ui->tableWidgetListaPeliculas->setRowCount(0);
ui->tableWidgetListaPeliculas->setColumnCount(4);

 QStringList ColumnasTabla;
 ColumnasTabla<<"Codigo Pelicula"<<"Titulo"<<"Precio de Renta"<<"Copias Disponibles";
 ui->tableWidgetListaPeliculas->setHorizontalHeaderLabels(ColumnasTabla);
 ui->tableWidgetListaPeliculas->setColumnWidth(0,120);
 ui->tableWidgetListaPeliculas->setColumnWidth(1,200);
 ui->tableWidgetListaPeliculas->setColumnWidth(2,120);
 ui->tableWidgetListaPeliculas->setColumnWidth(3,120);
   if (administrador_de_peliculas1->get_catalogo_de_peliculas()!=NULL){
        listaTemporalPeliculas=administrador_de_peliculas1->get_catalogo_de_peliculas();
              for (int i=0;i<(*listaTemporalPeliculas).size();i++){
                  ui->tableWidgetListaPeliculas->insertRow(ui->tableWidgetListaPeliculas->rowCount());
                  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,0,new QTableWidgetItem(QString::number((*listaTemporalPeliculas)[i]->get_codigo_pelicula())));
                  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,1,new QTableWidgetItem(((*listaTemporalPeliculas)[i]->get_titulo())));
                  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,2,new QTableWidgetItem(QString::number((*listaTemporalPeliculas)[i]->get_precio_de_renta())));
                  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,3,new QTableWidgetItem(QString::number((*listaTemporalPeliculas)[i]->get_numero_de_copias())));
    }
  }
}
void Menu_principal::actualizaTablaRentasActivas(){
    ui->tableWidgetRentasActivas->clear();
    ui->tableWidgetRentasActivas->setColumnCount(0);
    ui->tableWidgetRentasActivas->setRowCount(0);

    ui->tableWidgetRentasActivas->setColumnCount(3);
    QStringList ColumnasTabla;
    ColumnasTabla<<"Numero de Renta"<<"Cliente"<<"Numero de Peliculas Rentadas";
    ui->tableWidgetRentasActivas->setHorizontalHeaderLabels(ColumnasTabla);
    ui->tableWidgetRentasActivas->setColumnWidth(0,120);
    ui->tableWidgetRentasActivas->setColumnWidth(1,200);
    ui->tableWidgetRentasActivas->setColumnWidth(2,200);

    QVector <Notas_de_renta*> *listaTemporalNotasDeRenta;
    listaTemporalNotasDeRenta=new QVector <Notas_de_renta*>;
    listaTemporalNotasDeRenta=administrador_de_notas1->get_lista_notas_de_renta();

for(int i=0;i<(*listaTemporalNotasDeRenta).size();i++){
   ui->tableWidgetRentasActivas->insertRow(ui->tableWidgetRentasActivas->rowCount());
   ui->tableWidgetRentasActivas->setItem(ui->tableWidgetRentasActivas->rowCount()-1,0,new QTableWidgetItem(QString::number((*listaTemporalNotasDeRenta)[i]->get_numero_de_nota())));
    ui->tableWidgetRentasActivas->setItem(ui->tableWidgetRentasActivas->rowCount()-1,1,new QTableWidgetItem((*listaTemporalNotasDeRenta)[i]->get_cliente()));
     ui->tableWidgetRentasActivas->setItem(ui->tableWidgetRentasActivas->rowCount()-1,2,new QTableWidgetItem(QString::number((*listaTemporalNotasDeRenta)[i]->get_cantidad_de_peliculas_rentadas())));
}
}
void Menu_principal::actualizaTablaDeClientes(){
    QVector<Clientes*> *listaTemporalClientes;
    listaTemporalClientes= new QVector<Clientes*>;

    ui->tableWidgetListaClientes->clear();
    ui->tableWidgetListaClientes->setColumnCount(0);
    ui->tableWidgetListaClientes->setRowCount(0);
    ui->tableWidgetListaClientes->setColumnCount(3);

    QStringList columnas;
    columnas<<"Codigo Cliente"<<"Nombre Cliente"<<"Edad";
    ui->tableWidgetListaClientes->setHorizontalHeaderLabels(columnas);
    ui->tableWidgetListaClientes->setColumnWidth(0,120);
    ui->tableWidgetListaClientes->setColumnWidth(1,230);
    ui->tableWidgetListaClientes->setColumnWidth(2,100);

    if(administrador_de_clientes1->get_lista_clientes()!=NULL){
        listaTemporalClientes=administrador_de_clientes1->get_lista_clientes();
        for (int i=0;i<(*listaTemporalClientes).size();i++){
        ui->tableWidgetListaClientes->insertRow(ui->tableWidgetListaClientes->rowCount());
        ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,0,new QTableWidgetItem(QString::number((*listaTemporalClientes)[i]->get_codigo_cliente())));
        ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,1,new QTableWidgetItem(((*listaTemporalClientes)[i]->get_nombre())));
        ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,2,new QTableWidgetItem(QString::number((*listaTemporalClientes)[i]->get_edad())));



        }
    }


}
void Menu_principal::actualizarTablaPeliculasRentadas(int numero_nota){
    Notas_de_renta *nota_recibida = new Notas_de_renta;
    nota_recibida=administrador_de_notas1->buscanota(numero_nota);
    ui->lineEditNombreClientePeliculasRentadas->setText(nota_recibida->get_cliente());
    QVector <datos_peliculas_rentadas*> *listaTemporal = new QVector <datos_peliculas_rentadas*>;
    listaTemporal=nota_recibida->get_lista_peliculas_rentadas();

    ui->tableWidgetPeliculasRentadas->clear();
    ui->tableWidgetPeliculasRentadas->setColumnCount(0);
    ui->tableWidgetPeliculasRentadas->setRowCount(0);
    ui->tableWidgetPeliculasRentadas->setColumnCount(2);
    QStringList ColumnasTabla;
    ColumnasTabla<<"Codigo"<<"Titulo";
    ui->tableWidgetPeliculasRentadas->setHorizontalHeaderLabels(ColumnasTabla);
    ui->tableWidgetPeliculasRentadas->setColumnWidth(0,120);
    ui->tableWidgetPeliculasRentadas->setColumnWidth(1,200);

if (listaTemporal!=NULL){
    for (int i=0;i<(*listaTemporal).size();i++){

            ui->tableWidgetPeliculasRentadas->insertRow(ui->tableWidgetPeliculasRentadas->rowCount());
            ui->tableWidgetPeliculasRentadas->setItem(ui->tableWidgetPeliculasRentadas->rowCount()-1,0,new QTableWidgetItem(QString::number((*listaTemporal)[i]->codigo_pelicula)));
             ui->tableWidgetPeliculasRentadas->setItem(ui->tableWidgetPeliculasRentadas->rowCount()-1,1,new QTableWidgetItem((*listaTemporal)[i]->titulo_pelicula));
         }
 }


}

Menu_principal::~Menu_principal()
{
    delete ui;
}



void Menu_principal::on_actionIr_al_menu_triggered()
{
    ui->lineEditCodigoPelicula->setText("");
    ui->lineEditTituloPelicula->setText("");
    ui->lineEditPrecioRentaBase->setText("");
    ui->spinBoxCantidadPeliculas->setValue(0);

ui->menuPeliculas->hide();
ui->ventanaAltaSBajasModificaciones->show();
ui->ventanaAltaBajaModificacionesdelCliente->hide();
ui->VentanaNuevaRenta->hide();
ui->RentasActivas->hide();
ui->PeliculasEnNotaDeRenta->hide();

ui->lineEditCodigoPelicula->setDisabled(false);
actualizaTablaPeliculas();
}


void Menu_principal::on_actionIr_al_menu_2_triggered()
{
    ui->menuPeliculas->hide();
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->VentanaNuevaRenta->hide();
    ui->RentasActivas->hide();
    ui->PeliculasEnNotaDeRenta->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->show();
    actualizaTablaDeClientes();

}
void Menu_principal::on_actionRealizar_renta_triggered()
{
    ui->menuPeliculas->hide();
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->show();
    ui->lineEditCodigoPeliculaParaRenta->setDisabled(true);
    ui->pushButtonAgregarPeliculaRenta->setDisabled(true);
    ui->RentasActivas->hide();
    ui->PeliculasEnNotaDeRenta->hide();


}
void Menu_principal::on_actionVentana_Principal_triggered()
{
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->RentasActivas->hide();
    ui->menuPeliculas->show();
    ui->PeliculasEnNotaDeRenta->hide();
}




void Menu_principal::on_pushButtonRegistrarPelicula_clicked()
{
    int codigo_pelicula=0;
    codigo_pelicula=ui->lineEditCodigoPelicula->text().toInt();
    QString titulo_pelicula="";
    titulo_pelicula.append(ui->lineEditTituloPelicula->text());

    float precio_base=0;
    precio_base=ui->lineEditPrecioRentaBase->text().toFloat();

    int tipo_pelicula=0;
      if(ui->checkBoxPeliculaEstreno->isChecked()){
         tipo_pelicula=pelicula_estreno;
      }
      if(ui->checkBoxPeliculaLiquidacion->isChecked()){
           tipo_pelicula=pelicula_liquidacion;
      }

      if (ui->checkBoxPeliculaNormal->isChecked()){
          tipo_pelicula=pelicula_normal;
      }
int cantidad_copias=ui->spinBoxCantidadPeliculas->value();

administrador_de_peliculas1->registrar_pelicula(codigo_pelicula,titulo_pelicula,precio_base,cantidad_copias, tipo_pelicula);

Peliculas *pelicula;
pelicula=administrador_de_peliculas1->buscar_pelicula(codigo_pelicula);


if(pelicula!=NULL){
  ui->tableWidgetListaPeliculas->insertRow(ui->tableWidgetListaPeliculas->rowCount());
  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,0,new QTableWidgetItem(QString::number(pelicula->get_codigo_pelicula())));
  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,1,new QTableWidgetItem((pelicula->get_titulo())));
  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,2,new QTableWidgetItem(QString::number(pelicula->get_precio_de_renta())));
  ui->tableWidgetListaPeliculas->setItem(ui->tableWidgetListaPeliculas->rowCount()-1,3,new QTableWidgetItem(QString::number(pelicula->get_numero_de_copias())));
}
ui->lineEditCodigoPelicula->setText("");
ui->lineEditTituloPelicula->setText("");
ui->lineEditPrecioRentaBase->setText("");
ui->spinBoxCantidadPeliculas->setValue(0);
}

void Menu_principal::on_pushButtonModificarPelicula_clicked()
{

    int codigo_pelicula=0;
    codigo_pelicula=ui->lineEditCodigoPelicula->text().toInt();
    QString titulo_pelicula="";
    titulo_pelicula.append(ui->lineEditTituloPelicula->text());

    float precio_base=0;
    precio_base=ui->lineEditPrecioRentaBase->text().toFloat();

    int tipo_pelicula=0;
      if(ui->checkBoxPeliculaEstreno->isChecked()){
         tipo_pelicula=pelicula_estreno;
      }
      if(ui->checkBoxPeliculaLiquidacion->isChecked()){
           tipo_pelicula=pelicula_liquidacion;
      }

      if (ui->checkBoxPeliculaNormal->isChecked()){
          tipo_pelicula=pelicula_normal;
      }
int cantidad_copias=ui->spinBoxCantidadPeliculas->value();

administrador_de_peliculas1->modificar_pelicula(codigo_pelicula,titulo_pelicula,precio_base,cantidad_copias, tipo_pelicula);
ui->lineEditCodigoPelicula->setText("");
ui->lineEditTituloPelicula->setText("");
ui->lineEditPrecioRentaBase->setText("");
ui->spinBoxCantidadPeliculas->setValue(0);
ui->lineEditCodigoPelicula->setDisabled(false);
actualizaTablaPeliculas();


}


void Menu_principal::on_EliminaPelicula_clicked()
{
      int codigo_pelicula;
      codigo_pelicula=ui->lineEditCodigoPelicula->text().toInt();
      administrador_de_peliculas1->eliminar_pelicula(codigo_pelicula);
      ui->lineEditCodigoPelicula->setText("");
      ui->lineEditTituloPelicula->setText("");
      ui->lineEditPrecioRentaBase->setText("");
      ui->spinBoxCantidadPeliculas->setValue(0);
      ui->lineEditCodigoPelicula->setDisabled(false);
      actualizaTablaPeliculas();

}
void Menu_principal::on_tableWidgetListaPeliculas_itemClicked(QTableWidgetItem *item)
{
    int fila_seleccionada=item->row();

       QTableWidgetItem *Tabla_de_peliculas;
       Tabla_de_peliculas=ui->tableWidgetListaPeliculas->item(fila_seleccionada,0);

      int id_de_pelicula=0;
      id_de_pelicula=Tabla_de_peliculas->text().toInt();

      Peliculas *pelicula_seleccionada;
      pelicula_seleccionada=administrador_de_peliculas1->buscar_pelicula(id_de_pelicula);
      ui->lineEditCodigoPelicula->setText(QString::number(pelicula_seleccionada->get_codigo_pelicula()));
      ui->lineEditCodigoPelicula->setDisabled(true);
      ui->lineEditTituloPelicula->setText(pelicula_seleccionada->get_titulo());
      ui->spinBoxCantidadPeliculas->setValue(pelicula_seleccionada->get_numero_de_copias());
      ui->lineEditPrecioRentaBase->setText(QString::number(pelicula_seleccionada->get_precio_base()));

}



void Menu_principal::on_pushButtonRegistrarCliente_clicked()
{
int codigo_cliente;
codigo_cliente=ui->lineEditCodigoCliente->text().toInt();

QString nombre;
nombre.append(ui->lineEditNombreCliente->text());

int edad;
edad=ui->lineEditEdad->text().toInt();

administrador_de_clientes1->registra_cliente(codigo_cliente,nombre,edad);

Clientes *cliente;
cliente=administrador_de_clientes1->busca_cliente(codigo_cliente);


if(cliente!=NULL){
    ui->tableWidgetListaClientes->insertRow(ui->tableWidgetListaClientes->rowCount());
    ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,0,new QTableWidgetItem(QString::number(cliente->get_codigo_cliente())));
    ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,1,new QTableWidgetItem((cliente->get_nombre())));
    ui->tableWidgetListaClientes->setItem(ui->tableWidgetListaClientes->rowCount()-1,2,new QTableWidgetItem(QString::number(cliente->get_edad())));

}
ui->lineEditCodigoCliente->setText("");
ui->lineEditNombreCliente->setText("");
ui->lineEditEdad->setText("");

}

void Menu_principal::on_tableWidgetListaClientes_itemClicked(QTableWidgetItem *item)
{


        int fila_seleccionada=item->row();

           QTableWidgetItem *celda_codigo_cliente;
           celda_codigo_cliente=ui->tableWidgetListaClientes->item(fila_seleccionada,0);
           QTableWidgetItem *celda_nombre_cliente;
           celda_nombre_cliente=ui->tableWidgetListaClientes->item(fila_seleccionada,1);
           QTableWidgetItem *celda_edad_cliente;
           celda_edad_cliente=ui->tableWidgetListaClientes->item(fila_seleccionada,2);

          int codigo_cliente_seleccionado=0;
          codigo_cliente_seleccionado=celda_codigo_cliente->text().toInt();
          QString nombre_cliente_seleccionado="";
          nombre_cliente_seleccionado=celda_nombre_cliente->text();
          int edad_cliente_seleccionado;
          edad_cliente_seleccionado=celda_edad_cliente->text().toInt();



          ui->lineEditCodigoCliente->setText(QString::number(codigo_cliente_seleccionado));
          ui->lineEditCodigoCliente->setDisabled(true);
          ui->lineEditNombreCliente->setText(nombre_cliente_seleccionado);
          ui->lineEditEdad->setText(QString::number(edad_cliente_seleccionado));



}

void Menu_principal::on_pushButtonModificarCliente_clicked()
{
    int codigo_clientes=0;
    codigo_clientes=ui->lineEditCodigoCliente->text().toInt();

    QString nombre_cliente="";
    nombre_cliente.append(ui->lineEditNombreCliente->text());

    int edad_cliente=0;
    edad_cliente=ui->lineEditEdad->text().toInt();

    administrador_de_clientes1->modifica_cliente(codigo_clientes,nombre_cliente,edad_cliente);

    ui->lineEditCodigoCliente->setText("");
    ui->lineEditNombreCliente->setText("");
    ui->lineEditEdad->setText("");
    ui->lineEditCodigoCliente->setDisabled(false);
    actualizaTablaDeClientes();

}
void Menu_principal::on_pushButtonEliminarCliente_clicked()
{

        int codigo_cliente;
        codigo_cliente=ui->lineEditCodigoCliente->text().toInt();
        administrador_de_clientes1->elimina_cliente(codigo_cliente);
        ui->lineEditCodigoCliente->setText("");
        ui->lineEditNombreCliente->setText("");
        ui->lineEditEdad->setText("");

        ui->lineEditCodigoCliente->setDisabled(false);
        actualizaTablaDeClientes();


}
void Menu_principal::on_pushButtonNuevaRenta_clicked()
{

int codigo_cliente;
codigo_cliente=ui->lineEditCodigoClienteParaRenta->text().toInt();

Clientes *cliente = new Clientes;
cliente=administrador_de_clientes1->busca_cliente(codigo_cliente);



if (cliente!=NULL){
numero_de_nota++;


    ui->lineEditCodigoPeliculaParaRenta->setDisabled(false);
    ui->pushButtonAgregarPeliculaRenta->setDisabled(false);

    ui->lineEditNombreClienteParaLarenta->setText(cliente->get_nombre());
    ui->lineEditMuestranumeroNota->setText(QString::number(numero_de_nota));
    administrador_de_notas1->realizar_nota_de_renta(numero_de_nota,cliente->get_nombre());

}
}

void Menu_principal::on_pushButtonAgregarPeliculaRenta_clicked()
{


    int codigo_pelicula_para_rentar;
    int codigo_nota;
    codigo_nota=ui->lineEditMuestranumeroNota->text().toInt();
    codigo_pelicula_para_rentar=ui->lineEditCodigoPeliculaParaRenta->text().toInt();

    Peliculas *peliculaRentada=new Peliculas;
    peliculaRentada=administrador_de_peliculas1->buscar_pelicula(codigo_pelicula_para_rentar);

    if (peliculaRentada!=NULL){

    int codigo=peliculaRentada->get_codigo_pelicula();
    QString titulo=peliculaRentada->get_titulo();
    float precio=peliculaRentada->get_precio_de_renta();
    administrador_de_notas1->agregar_pelicula_en_nota(codigo_nota,codigo,titulo,precio);
    administrador_de_peliculas1->modificar_pelicula(codigo,titulo,peliculaRentada->get_precio_base(),(peliculaRentada->get_numero_de_copias()-1),peliculaRentada->get_tipoPelicula());

    ui->tableWidgetPeliculasParaNota->setColumnCount(3);
    QStringList ColumnasTabla;
    ColumnasTabla<<"Codigo Pelicula"<<"Titulo"<<"Precio de Renta";
    ui->tableWidgetPeliculasParaNota->setHorizontalHeaderLabels(ColumnasTabla);
    ui->tableWidgetPeliculasParaNota->setColumnWidth(0,120);
    ui->tableWidgetPeliculasParaNota->setColumnWidth(1,200);
    ui->tableWidgetPeliculasParaNota->setColumnWidth(2,120);
 Notas_de_renta *notaTemporal=new Notas_de_renta;

 QVector <datos_peliculas_rentadas*> *listaTemporal = new QVector <datos_peliculas_rentadas*>;

 notaTemporal=administrador_de_notas1->buscanota(codigo_nota);

  listaTemporal=notaTemporal->get_lista_peliculas_rentadas();

   for(int i=0;i<(*listaTemporal).size();i++){
    ui->tableWidgetPeliculasParaNota->insertRow(ui->tableWidgetPeliculasParaNota->rowCount());
    ui->tableWidgetPeliculasParaNota->setItem(ui->tableWidgetPeliculasParaNota->rowCount()-1,0,new QTableWidgetItem(QString::number((*listaTemporal)[i]->codigo_pelicula)));
    ui->tableWidgetPeliculasParaNota->setItem(ui->tableWidgetPeliculasParaNota->rowCount()-1,1,new QTableWidgetItem((*listaTemporal)[i]->titulo_pelicula));
    ui->tableWidgetPeliculasParaNota->setItem(ui->tableWidgetPeliculasParaNota->rowCount()-1,2,new QTableWidgetItem(QString::number((*listaTemporal)[i]->precio_renta)));

   }

 if ((*listaTemporal).size()!=0){
 notaTemporal->set_total_a_pagar();
 }

 ui->lineEditMuestraTotalaPagar->setText(QString::number((notaTemporal)->get_total_a_pagar()));
 ui->lineEditCodigoPeliculaParaRenta->setText("");
    }



}

void Menu_principal::on_actionVer_Rentas_triggered()
{
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->menuPeliculas->hide();
    ui->PeliculasEnNotaDeRenta->hide();
    ui->RentasActivas->show();
    actualizaTablaRentasActivas();
}

void Menu_principal::on_tableWidgetRentasActivas_itemClicked(QTableWidgetItem *item)
{
 int  fila_seleccionada;
 fila_seleccionada= item->row();
    QTableWidgetItem *celda_numero_nota=ui->tableWidgetRentasActivas->item(fila_seleccionada,0);

    ui->lineEditNumeroDeNotaPeliculasRentadas->setText(celda_numero_nota->text());
    ui->PeliculasEnNotaDeRenta->show();
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->RentasActivas->hide();
    ui->menuPeliculas->hide();
    int numero_Nota=ui->lineEditNumeroDeNotaPeliculasRentadas->text().toInt();

   actualizarTablaPeliculasRentadas(numero_Nota);


}



void Menu_principal::on_pushButtonfinalizarnota_clicked()
{
    ui->lineEditCodigoClienteParaRenta->setText("");
    ui->lineEditCodigoPeliculaParaRenta->setText("");
    ui->lineEditMuestranumeroNota->setText("");
    ui->lineEditNombreClienteParaLarenta->setText("");
    ui->lineEditMuestraTotalaPagar->setText("");
    ui->tableWidgetPeliculasParaNota->clear();
    ui->tableWidgetPeliculasParaNota->setColumnCount(0);
    ui->tableWidgetPeliculasParaNota->setRowCount(0);


}
void Menu_principal::on_tableWidgetPeliculasRentadas_itemClicked(QTableWidgetItem *item)
{
    int fila_seleccionada=item->row();

       QTableWidgetItem *celda_codigo_pelicula;
       celda_codigo_pelicula=ui->tableWidgetPeliculasRentadas->item(fila_seleccionada,0);

       ui->lineEditPeliculaSeleccionadaenNota->setText(celda_codigo_pelicula->text());

}

void Menu_principal::on_pushButtonfinalizarconsulta_clicked()
{
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->menuPeliculas->hide();
    ui->PeliculasEnNotaDeRenta->hide();
    ui->RentasActivas->show();
    actualizaTablaRentasActivas();
}

void Menu_principal::on_pushButtonRecibirTodasLasPeliculas_clicked()
{
    int numero_nota=ui->lineEditNumeroDeNotaPeliculasRentadas->text().toInt();
    administrador_de_notas1->eliminar_nota(numero_nota);
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->menuPeliculas->hide();
    ui->PeliculasEnNotaDeRenta->hide();

    QMessageBox msgBox;
          msgBox.setText("Peliculas Devueltas Exitosamente");
          msgBox.exec();


    ui->RentasActivas->show();

    actualizaTablaRentasActivas();

}





void Menu_principal::on_pushButtonRecibirUnaPelicula_clicked()
{
int codigo_pelicula=0;
codigo_pelicula=ui->lineEditPeliculaSeleccionadaenNota->text().toInt();
int numero_nota=0;
numero_nota=ui->lineEditNumeroDeNotaPeliculasRentadas->text().toInt();

Notas_de_renta *notaTemporal =new Notas_de_renta;
notaTemporal=administrador_de_notas1->buscanota(numero_nota);

if(notaTemporal->get_cantidad_de_peliculas_rentadas()>1){

notaTemporal->elimina_pelicula_rentada(codigo_pelicula);
actualizarTablaPeliculasRentadas(numero_nota);

}else {
    administrador_de_notas1->eliminar_nota(numero_nota);
    ui->ventanaAltaSBajasModificaciones->hide();
    ui->ventanaAltaBajaModificacionesdelCliente->hide();
    ui->VentanaNuevaRenta->hide();
    ui->menuPeliculas->hide();
    ui->PeliculasEnNotaDeRenta->hide();
    QMessageBox msgBox;
    msgBox.setText("Se han eliminado tedas las peliculas de la nota, la nota sera eliminada");
    msgBox.exec();
    ui->RentasActivas->show();
    actualizaTablaRentasActivas();

}
notaTemporal->set_cantidad_de_peliculas_rentadas();
}


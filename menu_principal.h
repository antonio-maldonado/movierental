#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QVector>
#include <QTableWidgetItem>
#include "administrador_de_peliculas.h"
#include "administrador_de_clientes.h"
#include "administrador_notas_de_renta.h"
#include "tipo_pelicula.h"
#include <QtWidgets>


namespace Ui {
class Menu_principal;
}

class Menu_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu_principal(QWidget *parent = 0);
    ~Menu_principal();
    void actualizaTablaPeliculas();
    void actualizaTablaRentasActivas();
   void  actualizaTablaDeClientes();
   void actualizarTablaPeliculasRentadas(int numero_nota);

private slots:

    void on_actionIr_al_menu_triggered();

    void on_actionIr_al_menu_2_triggered();

    void on_pushButtonRegistrarPelicula_clicked();

    void on_actionVentana_Principal_triggered();

    void on_pushButtonRegistrarCliente_clicked();

    void on_actionRealizar_renta_triggered();

    void on_pushButtonNuevaRenta_clicked();

    void on_pushButtonAgregarPeliculaRenta_clicked();

    void on_actionVer_Rentas_triggered();


    void on_tableWidgetRentasActivas_itemClicked(QTableWidgetItem *item);

    void on_EliminaPelicula_clicked();

    void on_tableWidgetListaPeliculas_itemClicked(QTableWidgetItem *item);

    void on_pushButtonModificarPelicula_clicked();

    void on_tableWidgetListaClientes_itemClicked(QTableWidgetItem *item);

    void on_pushButtonfinalizarnota_clicked();

    void on_pushButtonfinalizarconsulta_clicked();

    void on_pushButtonRecibirTodasLasPeliculas_clicked();

    void on_pushButtonModificarCliente_clicked();

    void on_pushButtonEliminarCliente_clicked();

    void on_pushButtonRecibirUnaPelicula_clicked();

    void on_tableWidgetPeliculasRentadas_itemClicked(QTableWidgetItem *item);

private:
    Ui::Menu_principal *ui;


 Administrador_de_peliculas *administrador_de_peliculas1;
 Administrador_de_clientes *administrador_de_clientes1;
 Administrador_notas_de_renta *administrador_de_notas1;
 int numero_de_nota;

};

#endif // MENU_PRINCIPAL_H

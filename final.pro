#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T09:36:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        menu_principal.cpp \
    peliculas.cpp \
    administrador_de_peliculas.cpp \
    peliculas_estreno.cpp \
    peliculas_de_liquidacion.cpp \
    administrador_de_clientes.cpp \
    clientes.cpp \
    notas_de_renta.cpp \
    administrador_notas_de_renta.cpp

HEADERS  += menu_principal.h \
    peliculas.h \
    administrador_de_peliculas.h \
    peliculas_estreno.h \
    peliculas_de_liquidacion.h \
    tipo_pelicula.h \
    clientes.h \
    administrador_de_clientes.h \
    notas_de_renta.h \
    administrador_notas_de_renta.h

FORMS    += menu_principal.ui

DISTFILES +=

RESOURCES +=

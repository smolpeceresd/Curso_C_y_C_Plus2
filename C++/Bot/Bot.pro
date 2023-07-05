TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bot.cpp \
        concesionario.cpp \
        main.cpp \
        nodo.cpp \
        vehiculo.cpp

HEADERS += \
    bot.h \
    concesionario.h \
    funciones.h \
    nodo.h \
    structs.h \
    vehiculo.h

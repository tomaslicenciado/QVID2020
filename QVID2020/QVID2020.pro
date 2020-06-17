QT += sql network widgets

HEADERS += \
    adminbd.h \
    basicsir.h \
    cpp_desolve.h \
    csvtodb.h \
    grafico.h \
    interfaz.h \
    interfazsir.h

SOURCES += \
    adminbd.cpp \
    basicsir.cpp \
    cpp_desolve.cpp \
    csvtodb.cpp \
    grafico.cpp \
    interfaz.cpp \
    interfazsir.cpp \
    main.cpp

FORMS += \
    interfaz.ui \
    interfazsir.ui

CONFIG += static

RESOURCES += \
    recursos.qrc

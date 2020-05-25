QT += sql network widgets

HEADERS += \
    adminbd.h \
    csvtodb.h \
    interfaz.h

SOURCES += \
    adminbd.cpp \
    csvtodb.cpp \
    interfaz.cpp \
    main.cpp

FORMS += \
    interfaz.ui

CONFIG += static

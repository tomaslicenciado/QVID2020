/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_5;
    QTextEdit *teInfo;
    QGridLayout *gridLayout_6;
    QComboBox *listRegiones;
    QComboBox *listPaises;
    QPushButton *pbCalcular;
    QGridLayout *gridLayout_3;
    QLabel *lPriFecha;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lUltFecha;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbSalir;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pbComparar;
    QGridLayout *gridLayout_7;
    QCheckBox *chkRecup;
    QCheckBox *chkConfir;
    QCheckBox *chkMuert;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *lCero;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_8;
    QProgressBar *prbProgreso;
    QPushButton *pbActualizar;
    QLabel *lActBD;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *lTotalCant;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbSIR;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName(QString::fromUtf8("Interfaz"));
        Interfaz->resize(747, 633);
        Interfaz->setMinimumSize(QSize(640, 480));
        gridLayout = new QGridLayout(Interfaz);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 9, 1, 1);

        teInfo = new QTextEdit(Interfaz);
        teInfo->setObjectName(QString::fromUtf8("teInfo"));
        teInfo->setMinimumSize(QSize(256, 285));
        teInfo->setMaximumSize(QSize(256, 285));
        teInfo->setReadOnly(true);

        gridLayout->addWidget(teInfo, 6, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        listRegiones = new QComboBox(Interfaz);
        listRegiones->setObjectName(QString::fromUtf8("listRegiones"));
        listRegiones->setMinimumSize(QSize(136, 20));
        listRegiones->setMaximumSize(QSize(163, 20));

        gridLayout_6->addWidget(listRegiones, 0, 1, 1, 1);

        listPaises = new QComboBox(Interfaz);
        listPaises->setObjectName(QString::fromUtf8("listPaises"));
        listPaises->setMinimumSize(QSize(125, 20));
        listPaises->setMaximumSize(QSize(125, 20));

        gridLayout_6->addWidget(listPaises, 0, 0, 1, 1);

        pbCalcular = new QPushButton(Interfaz);
        pbCalcular->setObjectName(QString::fromUtf8("pbCalcular"));

        gridLayout_6->addWidget(pbCalcular, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lPriFecha = new QLabel(Interfaz);
        lPriFecha->setObjectName(QString::fromUtf8("lPriFecha"));
        lPriFecha->setMinimumSize(QSize(85, 25));
        lPriFecha->setMaximumSize(QSize(85, 20));

        gridLayout_3->addWidget(lPriFecha, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 11, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        lUltFecha = new QLabel(Interfaz);
        lUltFecha->setObjectName(QString::fromUtf8("lUltFecha"));
        lUltFecha->setMinimumSize(QSize(85, 25));
        lUltFecha->setMaximumSize(QSize(85, 20));

        gridLayout_4->addWidget(lUltFecha, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 11, 9, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pbSalir = new QPushButton(Interfaz);
        pbSalir->setObjectName(QString::fromUtf8("pbSalir"));

        gridLayout_9->addWidget(pbSalir, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_9, 14, 9, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 9, 9, 1, 1);

        label = new QLabel(Interfaz);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label, 0, 9, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 5, 1, 1);

        pbComparar = new QPushButton(Interfaz);
        pbComparar->setObjectName(QString::fromUtf8("pbComparar"));
        pbComparar->setMinimumSize(QSize(98, 23));
        pbComparar->setMaximumSize(QSize(98, 23));

        gridLayout->addWidget(pbComparar, 14, 8, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        chkRecup = new QCheckBox(Interfaz);
        chkRecup->setObjectName(QString::fromUtf8("chkRecup"));

        gridLayout_7->addWidget(chkRecup, 0, 1, 1, 1);

        chkConfir = new QCheckBox(Interfaz);
        chkConfir->setObjectName(QString::fromUtf8("chkConfir"));

        gridLayout_7->addWidget(chkConfir, 0, 0, 1, 1);

        chkMuert = new QCheckBox(Interfaz);
        chkMuert->setObjectName(QString::fromUtf8("chkMuert"));

        gridLayout_7->addWidget(chkMuert, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_7, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 0, 1, 1, 1);

        lCero = new QLabel(Interfaz);
        lCero->setObjectName(QString::fromUtf8("lCero"));
        lCero->setMinimumSize(QSize(50, 20));
        lCero->setMaximumSize(QSize(50, 20));
        lCero->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(lCero, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_5, 10, 9, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        prbProgreso = new QProgressBar(Interfaz);
        prbProgreso->setObjectName(QString::fromUtf8("prbProgreso"));
        prbProgreso->setMinimumSize(QSize(120, 23));
        prbProgreso->setMaximumSize(QSize(120, 23));
        prbProgreso->setValue(24);

        gridLayout_8->addWidget(prbProgreso, 0, 1, 1, 1);

        pbActualizar = new QPushButton(Interfaz);
        pbActualizar->setObjectName(QString::fromUtf8("pbActualizar"));
        pbActualizar->setMinimumSize(QSize(130, 23));
        pbActualizar->setMaximumSize(QSize(130, 23));

        gridLayout_8->addWidget(pbActualizar, 0, 0, 1, 1);

        lActBD = new QLabel(Interfaz);
        lActBD->setObjectName(QString::fromUtf8("lActBD"));
        lActBD->setMinimumSize(QSize(145, 23));
        lActBD->setMaximumSize(QSize(145, 23));
        lActBD->setAutoFillBackground(true);
        lActBD->setFrameShadow(QFrame::Plain);
        lActBD->setMargin(0);

        gridLayout_8->addWidget(lActBD, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_8, 14, 0, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        lTotalCant = new QLabel(Interfaz);
        lTotalCant->setObjectName(QString::fromUtf8("lTotalCant"));
        lTotalCant->setMinimumSize(QSize(100, 20));
        lTotalCant->setMaximumSize(QSize(100, 20));

        gridLayout_2->addWidget(lTotalCant, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 9, 2, 1);

        pbSIR = new QPushButton(Interfaz);
        pbSIR->setObjectName(QString::fromUtf8("pbSIR"));

        gridLayout->addWidget(pbSIR, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);


        retranslateUi(Interfaz);
        QObject::connect(pbSalir, SIGNAL(released()), Interfaz, SLOT(close()));
        QObject::connect(listPaises, SIGNAL(highlighted(QString)), Interfaz, SLOT(listar_regiones(QString)));
        QObject::connect(pbCalcular, SIGNAL(pressed()), Interfaz, SLOT(calcular_datos()));
        QObject::connect(pbCalcular, SIGNAL(pressed()), Interfaz, SLOT(repaint()));
        QObject::connect(chkConfir, SIGNAL(clicked()), Interfaz, SLOT(repaint()));
        QObject::connect(chkRecup, SIGNAL(clicked()), Interfaz, SLOT(repaint()));
        QObject::connect(chkMuert, SIGNAL(clicked()), Interfaz, SLOT(repaint()));
        QObject::connect(pbActualizar, SIGNAL(pressed()), Interfaz, SLOT(actualizar_bd()));
        QObject::connect(pbComparar, SIGNAL(pressed()), Interfaz, SLOT(proximamente()));
        QObject::connect(Interfaz, SIGNAL(sRango(int,int)), prbProgreso, SLOT(setRange(int,int)));
        QObject::connect(Interfaz, SIGNAL(sValor(int)), prbProgreso, SLOT(setValue(int)));
        QObject::connect(pbSIR, SIGNAL(pressed()), Interfaz, SLOT(mostrar_SIR()));

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QWidget *Interfaz)
    {
        Interfaz->setWindowTitle(QCoreApplication::translate("Interfaz", "Form", nullptr));
        pbCalcular->setText(QCoreApplication::translate("Interfaz", "Calcular Gr\303\241ficas", nullptr));
        lPriFecha->setText(QString());
        lUltFecha->setText(QString());
        pbSalir->setText(QCoreApplication::translate("Interfaz", "Salir", nullptr));
        label->setText(QCoreApplication::translate("Interfaz", "Ferreyra Tom\303\241s", nullptr));
        pbComparar->setText(QCoreApplication::translate("Interfaz", "Comparar Datos", nullptr));
        chkRecup->setText(QCoreApplication::translate("Interfaz", "Recuperados", nullptr));
        chkConfir->setText(QCoreApplication::translate("Interfaz", "Confirmados", nullptr));
        chkMuert->setText(QCoreApplication::translate("Interfaz", "Muertes", nullptr));
        lCero->setText(QCoreApplication::translate("Interfaz", "0", nullptr));
        pbActualizar->setText(QCoreApplication::translate("Interfaz", "Actualizar Base de Datos", nullptr));
        lActBD->setText(QString());
        lTotalCant->setText(QString());
        pbSIR->setText(QCoreApplication::translate("Interfaz", "Calcular SIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H

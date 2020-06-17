/********************************************************************************
** Form generated from reading UI file 'interfazsir.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZSIR_H
#define UI_INTERFAZSIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <grafico.h>

QT_BEGIN_NAMESPACE

class Ui_InterfazSIR
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *opcionesLayout;
    QGridLayout *datosLayout;
    QLineEdit *leS;
    QLineEdit *leR;
    QLabel *lDInf;
    QLineEdit *leDInf;
    QLabel *lS;
    QLabel *lC;
    QLineEdit *leTC;
    QLineEdit *leN;
    QLabel *lDInc;
    QLabel *lR;
    QLineEdit *leDInc;
    QLineEdit *leC;
    QLabel *lTI;
    QLabel *lN;
    QLineEdit *leM;
    QLabel *lM;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbDatos;
    QRadioButton *rbHistorico;
    QPlainTextEdit *teDatos;
    QPushButton *pbGraficar;
    QSpinBox *sbPeriodo;
    QLabel *lPeriodo;
    QTabWidget *tabGraficos;
    Grafico *tabCRM;
    QHBoxLayout *horizontalLayout;
    Grafico *tabSIRM;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbSalir;

    void setupUi(QWidget *InterfazSIR)
    {
        if (InterfazSIR->objectName().isEmpty())
            InterfazSIR->setObjectName(QString::fromUtf8("InterfazSIR"));
        InterfazSIR->resize(800, 500);
        InterfazSIR->setMinimumSize(QSize(800, 500));
        InterfazSIR->setMaximumSize(QSize(800, 500));
        gridLayoutWidget_2 = new QWidget(InterfazSIR);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 591, 121));
        opcionesLayout = new QGridLayout(gridLayoutWidget_2);
        opcionesLayout->setObjectName(QString::fromUtf8("opcionesLayout"));
        opcionesLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        opcionesLayout->setContentsMargins(0, 0, 0, 0);
        datosLayout = new QGridLayout();
        datosLayout->setObjectName(QString::fromUtf8("datosLayout"));
        leS = new QLineEdit(gridLayoutWidget_2);
        leS->setObjectName(QString::fromUtf8("leS"));

        datosLayout->addWidget(leS, 2, 1, 1, 1);

        leR = new QLineEdit(gridLayoutWidget_2);
        leR->setObjectName(QString::fromUtf8("leR"));

        datosLayout->addWidget(leR, 2, 3, 1, 1);

        lDInf = new QLabel(gridLayoutWidget_2);
        lDInf->setObjectName(QString::fromUtf8("lDInf"));
        lDInf->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lDInf, 4, 0, 1, 1);

        leDInf = new QLineEdit(gridLayoutWidget_2);
        leDInf->setObjectName(QString::fromUtf8("leDInf"));

        datosLayout->addWidget(leDInf, 5, 0, 1, 1);

        lS = new QLabel(gridLayoutWidget_2);
        lS->setObjectName(QString::fromUtf8("lS"));
        lS->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lS, 0, 1, 1, 1);

        lC = new QLabel(gridLayoutWidget_2);
        lC->setObjectName(QString::fromUtf8("lC"));
        lC->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lC, 0, 2, 1, 1);

        leTC = new QLineEdit(gridLayoutWidget_2);
        leTC->setObjectName(QString::fromUtf8("leTC"));

        datosLayout->addWidget(leTC, 5, 2, 1, 1);

        leN = new QLineEdit(gridLayoutWidget_2);
        leN->setObjectName(QString::fromUtf8("leN"));

        datosLayout->addWidget(leN, 2, 0, 1, 1);

        lDInc = new QLabel(gridLayoutWidget_2);
        lDInc->setObjectName(QString::fromUtf8("lDInc"));
        lDInc->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lDInc, 4, 1, 1, 1);

        lR = new QLabel(gridLayoutWidget_2);
        lR->setObjectName(QString::fromUtf8("lR"));
        lR->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lR, 0, 3, 1, 1);

        leDInc = new QLineEdit(gridLayoutWidget_2);
        leDInc->setObjectName(QString::fromUtf8("leDInc"));

        datosLayout->addWidget(leDInc, 5, 1, 1, 1);

        leC = new QLineEdit(gridLayoutWidget_2);
        leC->setObjectName(QString::fromUtf8("leC"));

        datosLayout->addWidget(leC, 2, 2, 1, 1);

        lTI = new QLabel(gridLayoutWidget_2);
        lTI->setObjectName(QString::fromUtf8("lTI"));
        lTI->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lTI, 4, 2, 1, 1);

        lN = new QLabel(gridLayoutWidget_2);
        lN->setObjectName(QString::fromUtf8("lN"));
        lN->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lN, 0, 0, 1, 1);

        leM = new QLineEdit(gridLayoutWidget_2);
        leM->setObjectName(QString::fromUtf8("leM"));

        datosLayout->addWidget(leM, 5, 3, 1, 1);

        lM = new QLabel(gridLayoutWidget_2);
        lM->setObjectName(QString::fromUtf8("lM"));
        lM->setAlignment(Qt::AlignCenter);

        datosLayout->addWidget(lM, 4, 3, 1, 1);


        opcionesLayout->addLayout(datosLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rbDatos = new QRadioButton(gridLayoutWidget_2);
        rbDatos->setObjectName(QString::fromUtf8("rbDatos"));
        rbDatos->setMinimumSize(QSize(100, 15));
        rbDatos->setMaximumSize(QSize(100, 15));

        horizontalLayout_3->addWidget(rbDatos);


        opcionesLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        rbHistorico = new QRadioButton(gridLayoutWidget_2);
        rbHistorico->setObjectName(QString::fromUtf8("rbHistorico"));
        rbHistorico->setMinimumSize(QSize(170, 15));
        rbHistorico->setMaximumSize(QSize(170, 15));

        opcionesLayout->addWidget(rbHistorico, 0, 1, 1, 1);

        teDatos = new QPlainTextEdit(gridLayoutWidget_2);
        teDatos->setObjectName(QString::fromUtf8("teDatos"));

        opcionesLayout->addWidget(teDatos, 1, 1, 1, 1);

        pbGraficar = new QPushButton(InterfazSIR);
        pbGraficar->setObjectName(QString::fromUtf8("pbGraficar"));
        pbGraficar->setGeometry(QRect(640, 100, 111, 23));
        sbPeriodo = new QSpinBox(InterfazSIR);
        sbPeriodo->setObjectName(QString::fromUtf8("sbPeriodo"));
        sbPeriodo->setGeometry(QRect(670, 50, 42, 22));
        sbPeriodo->setMaximum(700);
        sbPeriodo->setValue(200);
        lPeriodo = new QLabel(InterfazSIR);
        lPeriodo->setObjectName(QString::fromUtf8("lPeriodo"));
        lPeriodo->setGeometry(QRect(620, 20, 131, 21));
        tabGraficos = new QTabWidget(InterfazSIR);
        tabGraficos->setObjectName(QString::fromUtf8("tabGraficos"));
        tabGraficos->setGeometry(QRect(6, 139, 781, 321));
        tabCRM = new Grafico();
        tabCRM->setObjectName(QString::fromUtf8("tabCRM"));
        horizontalLayout = new QHBoxLayout(tabCRM);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabGraficos->addTab(tabCRM, QString());
        tabSIRM = new Grafico();
        tabSIRM->setObjectName(QString::fromUtf8("tabSIRM"));
        horizontalLayout_2 = new QHBoxLayout(tabSIRM);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabGraficos->addTab(tabSIRM, QString());
        pbSalir = new QPushButton(InterfazSIR);
        pbSalir->setObjectName(QString::fromUtf8("pbSalir"));
        pbSalir->setGeometry(QRect(700, 470, 75, 23));

        retranslateUi(InterfazSIR);
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leN, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leS, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leC, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leR, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leM, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leDInf, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leDInc, SLOT(setEnabled(bool)));
        QObject::connect(rbDatos, SIGNAL(toggled(bool)), leTC, SLOT(setEnabled(bool)));
        QObject::connect(pbGraficar, SIGNAL(pressed()), InterfazSIR, SLOT(iniciarGraficos()));
        QObject::connect(pbSalir, SIGNAL(pressed()), InterfazSIR, SLOT(salir()));

        tabGraficos->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InterfazSIR);
    } // setupUi

    void retranslateUi(QWidget *InterfazSIR)
    {
        InterfazSIR->setWindowTitle(QCoreApplication::translate("InterfazSIR", "Form", nullptr));
        lDInf->setText(QCoreApplication::translate("InterfazSIR", "DInf", nullptr));
        lS->setText(QCoreApplication::translate("InterfazSIR", "S", nullptr));
        lC->setText(QCoreApplication::translate("InterfazSIR", "C", nullptr));
        lDInc->setText(QCoreApplication::translate("InterfazSIR", "DInc", nullptr));
        lR->setText(QCoreApplication::translate("InterfazSIR", "R", nullptr));
        lTI->setText(QCoreApplication::translate("InterfazSIR", "TC", nullptr));
        lN->setText(QCoreApplication::translate("InterfazSIR", "N", nullptr));
        lM->setText(QCoreApplication::translate("InterfazSIR", "M", nullptr));
        rbDatos->setText(QCoreApplication::translate("InterfazSIR", "Ingresar Datos", nullptr));
        rbHistorico->setText(QCoreApplication::translate("InterfazSIR", "Calcular datos desde hist\303\263rico", nullptr));
        teDatos->setPlainText(QCoreApplication::translate("InterfazSIR", "Se usar\303\241n los siguientes datos:\n"
"\n"
"* Dur. infecci\303\263n: 7 d\303\255as\n"
"* Dur. incubaci\303\263n:  6 d\303\255as\n"
"* Tasa de contagios:   2.68", nullptr));
        pbGraficar->setText(QCoreApplication::translate("InterfazSIR", "Graficar", nullptr));
        lPeriodo->setText(QCoreApplication::translate("InterfazSIR", "Cantidad de d\303\255as a calcular", nullptr));
        tabGraficos->setTabText(tabGraficos->indexOf(tabCRM), QCoreApplication::translate("InterfazSIR", "Modelo CRM", nullptr));
        tabGraficos->setTabText(tabGraficos->indexOf(tabSIRM), QCoreApplication::translate("InterfazSIR", "Modelo SIRM", nullptr));
        pbSalir->setText(QCoreApplication::translate("InterfazSIR", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfazSIR: public Ui_InterfazSIR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZSIR_H

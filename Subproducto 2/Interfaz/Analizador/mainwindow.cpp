#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>

#include "lexicalAnalyzer.cpp"
#include "sintaxAnalyzer.cpp"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonLexico_clicked()  ///Boton del Lexico
{
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada

    ///Mostreo en la interfaz
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels(QStringList() << "Lexema" << "Token" << "Tipo");
    QFont headerFont = model->horizontalHeaderItem(0)->font();  // Obtén la fuente actual de la cabecera
    headerFont.setBold(true);  // Establece la fuente en negritas
    model->horizontalHeaderItem(0)->setFont(headerFont);
    model->horizontalHeaderItem(1)->setFont(headerFont);
    model->horizontalHeaderItem(2)->setFont(headerFont);

    int countlexema = TablaSimbolo.size();
    int rowCount= 0;
    /*for(int row = countlexema;row<model->rowCount();row++){//Elimina las filas sobrantes del lexemas
        rowCount = model->removeRow(countlexema);
    }*/
    for (int row = 0; row < countlexema; row++) {
        rowCount = model->rowCount();

        //Le ponemos formato para insertar a la tabla
        QStandardItem *itemLex = new QStandardItem(QString::fromStdString(TablaSimbolo[row].lexema));
        itemLex->setTextAlignment(Qt::AlignCenter);
        QStandardItem *itemTok = new QStandardItem(QString::fromStdString(TablaSimbolo[row].token));
        itemTok->setTextAlignment(Qt::AlignCenter);
        QStandardItem *itemT = new QStandardItem(QString::fromStdString(to_string(TablaSimbolo[row].tipo)));
        itemT->setTextAlignment(Qt::AlignCenter);

        if (rowCount<=row){//Insertamos el contenido de las filas segun su cantidad
            model->insertRow(rowCount);

            model->setItem(row,0,itemLex);
            model->setItem(row,1,itemTok);
            model->setItem(row,2,itemT);
        }/*else{
            model->setItem(row,0,itemLex);
            model->setItem(row,1,itemTok);
            model->setItem(row,2,itemT);
        }*/

    }

    ui->TablaLexico->setModel(model);//Actualizamos el modelo de la tabla a mostrar
    //ui->TablaLexico->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");
    ui->TablaLexico->setColumnWidth(0,185);
    ui->TablaLexico->setColumnWidth(1,300);
    ui->TablaLexico->setColumnWidth(2,125);
}

void MainWindow::on_buttonSintatico_clicked()
{
    ui->textSintatico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    ui->textSintatico->setPlainText(QString::fromStdString(funcionSintatico(TablaSimbolo))); //Se escribe el texto resultante del sintatico
}

void MainWindow::on_leer_triggered()//Funcion para leer el archivo txt
{
    ui->inputCode->clear();//Limpiamos nuestro cuadro de texto
    QFile archivo("CodeInput.txt");
    if (!archivo.exists()){
        qCritical()<<"No se encontro";
        QMessageBox::warning(this,tr("FileError"),tr("No se encontro el archivo")); //Ventana emergente de advertencia de que no se encontro el txt
        return;
    }
    if(!archivo.open(QIODevice::ReadOnly)){
        qCritical()<< archivo.errorString();
        QMessageBox::warning(this,tr("FileError"),tr("No se abrio correctamente el archivo")); //Ventana emergente de advertencia de que no se abrio correctamente
        return;
    }
    QTextStream in(&archivo);
    ui->inputCode->insertPlainText(in.readAll());
    archivo.close();
}



void MainWindow::on_guardar_triggered() //Funcion para escribir en el archivo txt
{
    QMessageBox msgBox;//Creamos un objeto para crear una ventana emergente para modificar el archivo
    msgBox.setText("El archivo txt se modificará");
        msgBox.setInformativeText("¿Estas seguro de guardar estos cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Save){ //Se guardara el archivo
        QFile archivo("CodeInput.txt");
        if(!archivo.open(QIODevice::WriteOnly|QIODevice::Truncate)){
            qCritical()<< archivo.errorString();
            QMessageBox::warning(this,tr("FileError"),tr("No se abrio correctamente el archivo"));
            return;
        }
        QTextStream out(&archivo);
        out<< (ui->inputCode->toPlainText().toUtf8());
        archivo.flush();
        archivo.close();
    }
}

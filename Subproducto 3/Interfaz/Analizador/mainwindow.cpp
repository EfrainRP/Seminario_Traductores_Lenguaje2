#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QStandardItemModel>
#include <QScrollBar>

#include "lexicalAnalyzer.cpp"
#include "sintaxAndSemanticAnalyzer.cpp"
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Conectar el desplazamiento vertical de plainTextEdit1 al de textEdit2
    connect(ui->inputCode->verticalScrollBar(), &QScrollBar::valueChanged, ui->numberLine->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->numberLine->verticalScrollBar(), &QScrollBar::valueChanged, ui->inputCode->verticalScrollBar(), &QScrollBar::setValue);
    //numberLineBreak();
    // Conectar el desplazamiento horizontal de plainTextEdit1 al de textEdit2 (si es necesario)
    //connect(ui->inputCode->horizontalScrollBar(), &QScrollBar::valueChanged, ui->numberLine->horizontalScrollBar(), &QScrollBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonLexico_clicked()  ///Boton para analizar hasta el analizador Lexico
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
    ui->TablaLexico->setColumnWidth(0,(ui->TablaLexico->width()*0.25));//185
    ui->TablaLexico->setColumnWidth(1,(ui->TablaLexico->width()*0.46));//300
    ui->TablaLexico->setColumnWidth(2,(ui->TablaLexico->width()*0.25));//125
}

void MainWindow::on_buttonSintatico_clicked()//Boton para realizar el analisis hasta el sintatico
{

    ui->textSintatico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    ui->textSintatico->setPlainText(QString::fromStdString(funcionSintaticoSemantico(TablaSimbolo, true))); //Se escribe el texto resultante del sintatico
}

void MainWindow::on_buttonSemantico_clicked()
{
    ui->textSemantico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    ui->textSemantico->setPlainText(QString::fromStdString(funcionSintaticoSemantico(TablaSimbolo, false))); //Se escribe el texto resultante del semantico
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
    msgBox.setWindowIcon(QIcon(":/imagenes/pregunta.png"));
    msgBox.setIcon(QMessageBox::Question);
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

void MainWindow::on_actionLimpiar_triggered()
{
    /*int rowTableLexical = ui->TablaLexico->model()->rowCount();
    qCritical()<<"no entro";
    if (ui->TablaLexico->model()){
        qCritical()<<"entro";
        for (int r=rowTableLexical;r>=0;r--){
            ui->TablaLexico->model()->removeRow(r);
        }
    }*/

    QStandardItemModel *model = new QStandardItemModel();
    ui->TablaLexico->setModel(model);//Cambia el modelo de la tabla a un modelo vacio

    //Limpiara respectivamente los cuadros de textos de la interfaz
    ui->textSintatico->clear();
    ui->textSemantico->clear();
    ui->inputCode->clear();
}

void MainWindow::on_inputCode_textChanged()
{
    QString row = "1\n";
    int r = 2;
    for(int x=0; x<ui->inputCode->toPlainText().length(); x++){
        if (ui->inputCode->toPlainText().at(x) =='\n'){
            //qCritical()<<input.length()<<"  salto  "<<x;
            row.append(QString::number(r++)+"\n");
        }
    }
    ui->numberLine->setPlainText(row);
}




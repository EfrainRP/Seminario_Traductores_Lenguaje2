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
#include "SintaxSemanticGenerator.cpp"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Conectar el desplazamiento vertical de inputCode al de numberLine
    connect(ui->numberLine->verticalScrollBar(), &QScrollBar::valueChanged, ui->inputCode->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->inputCode->verticalScrollBar(), &QScrollBar::valueChanged, ui->numberLine->verticalScrollBar(), &QScrollBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLexicalTable(vector<tablaSimbolo>& TablaSimbolo)
{
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
        }

    }

    ui->TablaLexico->setModel(model);//Actualizamos el modelo de la tabla a mostrar

    //Ajustara el ancho de las columnas con respecto al ancho de la tabla
    ui->TablaLexico->setColumnWidth(0,(ui->TablaLexico->width()*0.25));//185
    ui->TablaLexico->setColumnWidth(1,(ui->TablaLexico->width()*0.46));//300
    ui->TablaLexico->setColumnWidth(2,(ui->TablaLexico->width()*0.25));//125
}
void MainWindow::on_buttonLexico_clicked()  ///Boton para analizar hasta el analizador Lexico
{
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    showLexicalTable(TablaSimbolo); //Mostramos la tabla en la interfaz
}

void MainWindow::on_buttonSintatico_clicked()//Boton para realizar el analisis hasta el sintatico
{

    ui->textSintatico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    showLexicalTable(TablaSimbolo); //Mostramos la tabla en la interfaz
    ui->textSintatico->setPlainText(QString::fromStdString(funcionSintaticoSemantico(TablaSimbolo, 1))); //Se escribe el texto resultante del sintatico
}

void MainWindow::on_buttonSemantico_clicked()
{
    ui->textSemantico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    showLexicalTable(TablaSimbolo); //Mostramos la tabla en la interfaz
    ui->textSintatico->setPlainText(QString::fromStdString(funcionSintaticoSemantico(TablaSimbolo, 1))); //Se escribe el texto resultante del sintatico
    ui->textSemantico->setPlainText(QString::fromStdString(funcionSintaticoSemantico(TablaSimbolo, 2))); //Se escribe el texto resultante del semantico
}

void MainWindow::on_leer_triggered()//Funcion para leer el archivo txt
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
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
    ui->inputCode->insertPlainText(in.readAll());//Insertar el texto leido del archivo a la interfaz
    archivo.close();
}



void MainWindow::on_guardar_triggered() //Funcion para escribir en el archivo txt
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
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
    ui->tabWidget->setCurrentWidget(ui->analizar);
    QStandardItemModel *model = new QStandardItemModel();
    ui->TablaLexico->setModel(model);//Cambia el modelo de la tabla a un modelo vacio

    //Limpiara respectivamente los cuadros de textos de la interfaz
    ui->textSintatico->clear();
    ui->textSemantico->clear();
    ui->inputCode->clear();
    ui->textGenerator->clear();
}

void MainWindow::on_inputCode_textChanged()
{
    QString row = "1"; //Inicia la cadena para el numberLine
    int r = 2;  //Empezaremos a enumerar en la linea 2
    for(int x=0; x<ui->inputCode->toPlainText().length(); x++){//Recorrera el texto para enumerar los renglones
        if (ui->inputCode->toPlainText().at(x) =='\n'){
            row.append("\n"+QString::number(r++));//Ira agregando los numeros con sus respectivos saltos de renglon
        }
    }
    ui->numberLine->setPlainText(row);//Se insertar en el texto para renglones
}

void MainWindow::on_actionTodo_triggered()
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
    //ui->textSintatico->clear();//Limpiamos nuestro cuadro de texto
    //ui->textSemantico->clear();//Limpiamos nuestro cuadro de texto
    vector<tablaSimbolo> TablaSimbolo = funcionLexico(ui->inputCode->toPlainText()); //Obtenemos la tabla de simbolo de la entrada
    showLexicalTable(TablaSimbolo); //Mostramos la tabla en la interfaz

    //Ejecucion y actualizacion de la vista de los analizadores sintatico y semantico
    string sintac = funcionSintaticoSemantico(TablaSimbolo, 1);
    string semantic = funcionSintaticoSemantico(TablaSimbolo, 2);

    ui->textSintatico->setPlainText(QString::fromStdString(sintac)); //Se escribe el texto resultante del sintatico
    ui->textSemantico->setPlainText(QString::fromStdString(semantic)); //Se escribe el texto resultante del semantico

    //Actualiza la vista del generador de codigo
    size_t pos = sintac.find("analysis completed");
    bool boolSintac = (pos!=string::npos)? true : false;

    pos = semantic.find("analysis completed");
    bool boolSemantic = (pos!=string::npos)? true : false;

    string genCode = funcionSintaticoSemantico(TablaSimbolo, 3); //Cadena del generador de codigo
    if(boolSintac && boolSemantic && genCode.size()>0){ //Confirmara si los mensajes son correctos (si se ejecuto bien)
        ui->tabWidget->setCurrentWidget(ui->generador);
        ui->textGenerator->setPlainText(QString::fromStdString(genCode)); //Se escribe el texto resultante en el nuevo tab del generador de codigo
    }else{
        ui->textGenerator->clear();
    }
}


void MainWindow::on_actionL_xico_triggered()
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
    on_buttonLexico_clicked();
}


void MainWindow::on_actionSint_tico_triggered()
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
    on_buttonSintatico_clicked();
}


void MainWindow::on_actionSem_ntico_triggered()
{
    ui->tabWidget->setCurrentWidget(ui->analizar);
    on_buttonSemantico_clicked();
}


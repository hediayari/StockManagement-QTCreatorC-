#include "employe.h"
#include "dialoghedi.h"
#include "ui_dialoghedi.h"

#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>


Dialoghedi::Dialoghedi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoghedi)
{
    ui->setupUi(this);
    this->setWindowTitle("WEDEVAPP");
    ui->tableView->setModel(emp.afficher());
ui->comboBox->setModel(emp.afficheroncombo());
ui->comboBox_4->setModel(emp.afficheroncombo());
}

Dialoghedi::~Dialoghedi()
{
    delete ui;
}

void Dialoghedi::on_pushButton_2_clicked()//aller du menu a ajouter
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_10_clicked()//aller retour au  menu
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialoghedi::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialoghedi::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void Dialoghedi::on_pushButton_6_clicked()
{
      ui->stackedWidget->setCurrentIndex(4);
}


void Dialoghedi::on_pushButton_20_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_19_clicked()
{
    EMPLOYE e(ui->lineEditid1->text().toInt(),ui->lineEditid2->text(),ui->lineEdit3->text(),ui->dateEdit->text(),ui->lineEdit4->text().toInt(),ui->lineEdit5->text().toInt());
       bool test= e.ajouter();

       QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


       if (test)
       {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
           notifyIcon->showMessage("GESTION DES  EMPLYOES ","Liste employe pret dans PDF",QSystemTrayIcon::Information,15000);
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView->setModel(emp.afficher());
}

void Dialoghedi::on_pushButton_9_clicked() //generer pdf
{
    emp.genererPDF();
}

void Dialoghedi::on_comboBox_currentIndexChanged(int index) //combo modifier
{
    int a;
        a=index;
        index=a;
        ui->comboBox->currentText();
}


void Dialoghedi::on_pushButton_21_clicked() //button modifier
{
    bool    test=emp.modifier(ui->comboBox->currentText().toInt(),ui->lineEdit_20->text().toInt(), ui->lineEdit_11->text().toInt()) ;
          if (test)
          {
                ui->tableView->setModel(emp.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}




void Dialoghedi::on_comboBox_4_currentIndexChanged(int index) //combo supp
{
    int a;
        a=index;
    ui->comboBox_4->currentText();//combo mt3 supprimer
}




void Dialoghedi::on_pushButton_24_clicked()
{
    bool test=emp.supprimer(ui->comboBox_4->currentText().toInt());
    if(test)
    {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}



void Dialoghedi::on_pushButton_8_clicked()
{
    EMPLOYE *e =new EMPLOYE(ui->lineEditid1->text().toInt(),ui->lineEditid2->text(),ui->lineEdit3->text(),ui->dateEdit->text(),ui->lineEdit4->text().toInt(),ui->lineEdit5->text().toInt());
    if(ui->tridesemp->isChecked()){
       ui->tableView->setModel(e->trides());

    }
    if(ui->triascemp->isChecked()){
        ui->tableView->setModel(e->triasc());    }
    delete e;
}

void Dialoghedi::on_comboBox_3_currentIndexChanged(int index)//rechercher
{
    ui->comboBox_3->currentText();
}

void Dialoghedi::on_lineEdit_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_3->currentText()=="ID")
    {
        query->prepare("SELECT * FROM AJID WHERE ID LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);


    }
    else {
        if(ui->comboBox_3->currentText()=="NOM"){
            query->prepare("SELECT * FROM AJID WHERE NOM LIKE'"+arg1+"%'");//
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }


    else {
        if(ui->comboBox_3->currentText()=="PREN")
        {
            query->prepare("SELECT * FROM AJID WHERE PREN LIKE'"+arg1+"%'");//
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);

        }
    }}}

void Dialoghedi::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_4->currentText();
    ui->label_10->setText(emp.showold(arg1));
}

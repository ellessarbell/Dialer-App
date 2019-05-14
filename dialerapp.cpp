#include "dialerapp.h"
#include "ui_dialerapp.h"


#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

DialerApp::DialerApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialerApp),
    myModel(new MyAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(myModel);
}

DialerApp::~DialerApp()
{
    delete ui;
}

void DialerApp::on_actionOpen_an_address_book_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Address Book"), "",
        tr("Address Book (*.csv);;All files (*)"));

    std::cout << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

void DialerApp::on_tableView_clicked(const QModelIndex &index)
{
    std::cout << index.row() << "," << index.column() << std::endl;
    ui->phoneLabel->setText(myModel->getPhoneNumber(index.row()));
}

void DialerApp::on_deleteButton_clicked()
{
    myModel->buttonPress('X');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_oneButton_clicked()
{
    myModel->buttonPress('1');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_twoButton_clicked()
{
    myModel->buttonPress('2');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_threeButton_clicked()
{
    myModel->buttonPress('3');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_fourButton_clicked()
{
    myModel->buttonPress('4');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_fiveButton_clicked()
{
    myModel->buttonPress('5');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_sixButton_clicked()
{
    myModel->buttonPress('6');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_sevenButton_clicked()
{
    myModel->buttonPress('7');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_eightButton_clicked()
{
    myModel->buttonPress('8');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_nineButton_clicked()
{
    myModel->buttonPress('9');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_zeroButton_clicked()
{
    myModel->buttonPress('0');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_starButton_clicked()
{
    myModel->buttonPress('*');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_poundButton_clicked()
{
    myModel->buttonPress('#');
    ui->phoneLabel->setText(myModel->getPhoneNumber(-1));
}

void DialerApp::on_callButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("calling " + ui->phoneLabel->text());
    msgBox.exec();
    ui->phoneLabel->clear();
    phoneNumber.clear();
}

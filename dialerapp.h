#ifndef DIALERAPP_H
#define DIALERAPP_H

#include <QMainWindow>
#include "myaddressbookmodel.h"

namespace Ui {
class DialerApp;
}

class DialerApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialerApp(QWidget *parent = nullptr);
    ~DialerApp();

private slots:
    void on_actionOpen_an_address_book_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_deleteButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_zeroButton_clicked();

    void on_starButton_clicked();

    void on_poundButton_clicked();

    void on_callButton_clicked();

private:
    Ui::DialerApp *ui;
    MyAddressBookModel *myModel;
    QString phoneNumber;
};

#endif // DIALERAPP_H

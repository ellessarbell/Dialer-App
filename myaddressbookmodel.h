#ifndef MYADDRESSBOOKMODEL_H
#define MYADDRESSBOOKMODEL_H

#include <QAbstractTableModel>

class MyAddressBookModel: public QAbstractTableModel
{
public:
    MyAddressBookModel(QObject *parent);


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void openFile(QString filePath);
    QString getPhoneNumber(int index);
    void setFilterString(QString fStr);
    void buttonPress(QChar character);

private:
    std::vector <QString> firstNames;
    std::vector <QString> lastNames;
    std::vector <QString> phoneNumbers;

    std::vector<int> filteredIndex;

    QString phoneNumber;
};

#endif // MYADDRESSBOOKMODEL_H

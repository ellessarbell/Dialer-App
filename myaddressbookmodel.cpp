#include "myaddressbookmodel.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <cctype>

MyAddressBookModel::MyAddressBookModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int MyAddressBookModel::rowCount(const QModelIndex &parent) const
{
    return filteredIndex.size();
}

int MyAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyAddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: //first name
                return firstNames.at(filteredIndex[index.row()]);
            case 1:
                return lastNames.at(filteredIndex[index.row()]);
            case 2:
                return phoneNumbers.at(filteredIndex[index.row()]);
        }

       // return QString("Rows%1, Column%2")
       //       .arg(index.row())
       //       .arg(index.column());
    }
    return QVariant();
}

void MyAddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    firstNames.clear();
    lastNames.clear();
    phoneNumbers.clear();

    for(int i = 0; !in.atEnd(); i++){
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(i == 0) continue;

        for(int j = 0; j < fields.length(); j++)
        {
            std::cout << "[" << j << "]" << fields[j].toStdString();
        }
        std::cout << std::endl;

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers.push_back(fields[7]);
        filteredIndex.push_back(i);
    }

    file.close();

    emit layoutChanged();
}

void MyAddressBookModel::buttonPress(QChar character)
{
    if(character == 'X')
    {
        phoneNumber.chop(1);
        return;
    }
    else if(phoneNumber.size() == 12)
    {
        setFilterString(phoneNumber);
    }
    else if(phoneNumber.size() == 3 || phoneNumber.size() == 7)
    {
        phoneNumber = phoneNumber + "-" + character;
    }
    else
    {
        phoneNumber = phoneNumber + character;
    }

    setFilterString(phoneNumber);
}

QString MyAddressBookModel::getPhoneNumber(int index)
{
    if(index >= 0)
    {
       setFilterString(phoneNumber);
       return phoneNumbers.at(filteredIndex[index]);
    }
    else
        return phoneNumber;

}

void MyAddressBookModel::setFilterString(QString fStr)
{
    filteredIndex.clear();
    QChar letter;
    QString firstName, lastName;

    for (unsigned int i = 0; i < phoneNumbers.size(); i++)
    {
        firstName = firstNames[i];
        lastName = lastNames[i];

        if(phoneNumbers[i].startsWith(fStr))
        {
            filteredIndex.push_back(i);
        }


        for (int j = 0; j < fStr.size(); j++)
        {
            letter = firstName[j];

            // if number is 2
            if(letter == 'a' || letter == 'A' || letter == 'b' || letter == 'B'
                    || letter == 'c' || letter == 'C')
            {
                firstName[j] = '2';
            }

            // if number is 3
            else if(letter == 'd' || letter == 'D' || letter == 'e' || letter == 'E'
                    || letter == 'f' || letter == 'F')
            {
                firstName[j] = '3';
            }

            // if number is 4
            else if(letter == 'g' || letter == 'G' || letter == 'h' || letter == 'H'
                    || letter == 'i' || letter == 'I')
            {
                firstName[j] = '4';
            }

            // if number is 5
            else if(letter == 'j' || letter == 'J' || letter == 'k' || letter == 'K'
                    || letter == 'l' || letter == 'L')
            {
                firstName[j] = '5';
            }

            // if number is 6
            else if(letter == 'm' || letter == 'M' || letter == 'n' || letter == 'N'
                    || letter == 'o' || letter == 'O')
            {
                firstName[j] = '6';
            }

            // if number is 7
            else if(letter == 'p' || letter == 'P' || letter == 'q' || letter == 'Q'
                    || letter == 'r' || letter == 'R' || letter == 's' || letter == 'S')
            {
                firstName[j] = '7';
            }

            // if number is 8
            else if(letter == 't' || letter == 'T' || letter == 'u' || letter == 'U'
                    || letter == 'v' || letter == 'V')
            {
                firstName[j] = '8';
            }

            // if number is 9
            else if(letter == 'w' || letter == 'W' || letter == 'x' || letter == 'X'
                    || letter == 'y' || letter == 'Y' || letter == 'z' || letter == 'Z')
            {
                firstName[j] = '9';
            }


            letter = lastName[j];

            // if number is 2
            if(letter == 'a' || letter == 'A' || letter == 'b' || letter == 'B'
                    || letter == 'c' || letter == 'C')
            {
                lastName[j] = '2';
            }

            // if number is 3
            else if(letter == 'd' || letter == 'D' || letter == 'e' || letter == 'E'
                    || letter == 'f' || letter == 'F')
            {
                lastName[j] = '3';
            }

            // if number is 4
            else if(letter == 'g' || letter == 'G' || letter == 'h' || letter == 'H'
                    || letter == 'i' || letter == 'I')
            {
                lastName[j] = '4';
            }

            // if number is 5
            else if(letter == 'j' || letter == 'J' || letter == 'k' || letter == 'K'
                    || letter == 'l' || letter == 'L')
            {
                lastName[j] = '5';
            }

            // if number is 6
            else if(letter == 'm' || letter == 'M' || letter == 'n' || letter == 'N'
                    || letter == 'o' || letter == 'O')
            {
                lastName[j] = '6';
            }

            // if number is 7
            else if(letter == 'p' || letter == 'P' || letter == 'q' || letter == 'Q'
                    || letter == 'r' || letter == 'R' || letter == 's' || letter == 'S')
            {
                lastName[j] = '7';
            }

            // if number is 8
            else if(letter == 't' || letter == 'T' || letter == 'u' || letter == 'U'
                    || letter == 'v' || letter == 'V')
            {
                lastName[j] = '8';
            }

            // if number is 9
            else if(letter == 'w' || letter == 'W' || letter == 'x' || letter == 'X'
                    || letter == 'y' || letter == 'Y' || letter == 'z' || letter == 'Z')
            {
                lastName[j] = '9';
            }
        }


        if(fStr.size() >= 8 || fStr.size() >= 4)
        {
            fStr.remove(3, 1);
            fStr.remove(6, 1);
        }
        if(firstName.startsWith(fStr))
        {
            filteredIndex.push_back(i);
        }
        if(lastName.startsWith(fStr))
        {
            filteredIndex.push_back(i);
        }
    }

    emit layoutChanged();
}

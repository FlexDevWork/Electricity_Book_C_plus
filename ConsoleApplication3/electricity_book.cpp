#include "electricity_book.h"

void electricity_book::setElectricityBookRecords(vector<electricity_book_record>& electricity_book_records)
{
    this->_electricity_book_records = electricity_book_records;
}

vector<electricity_book_record> electricity_book::getElectricityBookRecords()
{
    return _electricity_book_records;
}

const electricity_book& operator++(electricity_book& electricity_book)
{
    for (int i = 0; i < electricity_book._electricity_book_records.size(); ++i)
    {
        int value = electricity_book._electricity_book_records[i].getValue();
        electricity_book._electricity_book_records[i].setValue(++value);
    }
    return electricity_book;
}

electricity_book& operator-=(electricity_book& electricity_book, const int right)
{
    for (int i = 0; i < electricity_book._electricity_book_records.size(); ++i)
    {
        int newValue = electricity_book._electricity_book_records[i].getValue() - right;
        electricity_book._electricity_book_records[i].setValue(newValue);
    }
    return electricity_book;
}

std::ostream& operator<<(std::ostream& out, const electricity_book& electricity_book)
{
    out << "**Book records start**" << endl;
    for (auto& electricityBookRecord : electricity_book._electricity_book_records)
    {
        out << electricityBookRecord << endl;
    }
    out << "**Book records end**" << endl;
    return out;
}

vector<electricity_book_record> electricity_book::getElectricityBookRecords(int year)
{
    vector<electricity_book_record> result = vector<electricity_book_record>();
    for (int i = 0; i < this->_electricity_book_records.size(); ++i)
    {
        electricity_book_record record = this->_electricity_book_records[i];
        tm date = record.getDate();
        if (date.tm_year == year)
        {
            result.push_back(record);
        }
    }
    return result;
}

vector<electricity_book_record> electricity_book::getElectricityBookRecords(int month, int year)
{
    vector<electricity_book_record> result = vector<electricity_book_record>();
    for (int i = 0; i < this->_electricity_book_records.size(); ++i)
    {
        electricity_book_record record = this->_electricity_book_records[i];
        tm date = record.getDate();
        if (date.tm_mon == month && date.tm_year == year)
        {
            result.push_back(record);
        }
    }
    return result;
}

vector<electricity_book_record> electricity_book::getElectricityBookRecords(int day, int month, int year)
{
    vector<electricity_book_record> result = vector<electricity_book_record>();
    for (int i = 0; i < this->_electricity_book_records.size(); ++i)
    {
        electricity_book_record record = this->_electricity_book_records[i];
        tm date = record.getDate();
        if (date.tm_mday == day && date.tm_mon == month && date.tm_year == year)
        {
            result.push_back(record);
        }
    }
    return result;
}

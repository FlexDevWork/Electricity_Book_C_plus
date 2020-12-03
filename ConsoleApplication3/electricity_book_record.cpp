#include "electricity_book_record.h"

void electricity_book_record::setValue(int value)
{
    if (value > 9999)
    {
        throw "maximum value 9999";
    }

    this->_value = value;
}

int electricity_book_record::getValue()
{
    if (this->_value < 0)
    {
        throw "The value cannot be negative test";
    }
    return this->_value;
}

void electricity_book_record::setDate(tm date)
{
    this->_date = date;
}

tm electricity_book_record::getDate()
{
    return this->_date;
}

void electricity_book_record::setPaidAmount(int paid_amount)
{
    this->_paid_amount = paid_amount;
}

size_t electricity_book_record::getPaidAmount()
{
    return this->_paid_amount;
}

std::ostream& operator<<(std::ostream& out, const electricity_book_record& electricity_book_record)
{
    out << "[value = " << electricity_book_record._value << "\tdate = " << electricity_book_record._date.tm_year << "-" << electricity_book_record._date.tm_mon << "-" << electricity_book_record._date.tm_mday << "\tpaid amount = " << electricity_book_record._paid_amount << "]";
    return out;
}

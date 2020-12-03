#pragma once
#ifndef ELECTRICITY_BOOK_RECORD_H
#define ELECTRICITY_BOOK_RECORD_H

#include <string>
#include <ctime>
#include <iostream>

class electricity_book_record
{
private:
    int _value;
    tm _date;
    int _paid_amount;

public:
    void setValue(int value);

    int getValue();

    void setDate(tm date);

    tm getDate();

    void setPaidAmount(int paid_amount);

    size_t getPaidAmount();

    friend std::ostream& operator<<(std::ostream& out, const electricity_book_record& electricity_book_record);
};

#endif
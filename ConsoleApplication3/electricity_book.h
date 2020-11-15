#pragma once
#ifndef ELECTRICITY_BOOK_H
#define ELECTRICITY_BOOK_H

#include "electricity_book_record.h"
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class electricity_book
{
private:
    vector<electricity_book_record> _electricity_book_records;

public:
    void setElectricityBookRecords(vector<electricity_book_record>& electricity_book_records);

    vector<electricity_book_record> getElectricityBookRecords();

    friend const electricity_book& operator++(electricity_book& _electricity_book);

    friend electricity_book& operator-=(electricity_book& electricity_book, const int right);

    friend std::ostream& operator<<(std::ostream& out, const electricity_book& electricity_book);

    vector<electricity_book_record> getElectricityBookRecords(int year);

    vector<electricity_book_record> getElectricityBookRecords(int month, int year);

    vector<electricity_book_record> getElectricityBookRecords(int day, int month, int year);
};

#endif
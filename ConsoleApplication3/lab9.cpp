#include <iostream>
#include <vector>
#include <string>
#include "electricity_book.h"
#include "electricity_book_record.h"

using namespace std;

tm CreateTmStruct(int day, int month, int year)
{
    struct tm tmStruct;
    tmStruct.tm_mon = month;
    tmStruct.tm_year = year;
    tmStruct.tm_mday = day;
    return tmStruct;
}

int main()
{
    try
    {

        vector<electricity_book_record> electricityBookRecords = vector<electricity_book_record>();
        electricity_book_record record1 = electricity_book_record();
        tm date1 = CreateTmStruct(24, 09, 2020);
        record1.setDate(date1);
        record1.setValue(3);
        electricityBookRecords.push_back(record1);

        electricity_book_record record2 = electricity_book_record();
        tm date2 = CreateTmStruct(2, 10, 2020);
        record2.setDate(date2);
        record2.setValue(4);
        electricityBookRecords.push_back(record2);

        electricity_book_record record3 = electricity_book_record();
        tm date3 = CreateTmStruct(1, 10, 2020);
        record3.setDate(date3);
        record3.setValue(5);
        electricityBookRecords.push_back(record3);

        electricity_book book = electricity_book();
        book.setElectricityBookRecords(electricityBookRecords);

        cout << book << endl;

       ++book;
        vector<electricity_book_record> electricityBookRecords2 = book.getElectricityBookRecords();
        cout << book << endl;

        book -= 2;
        vector<electricity_book_record> electricityBookRecords3 = book.getElectricityBookRecords();
        cout << book << endl;

        vector<electricity_book_record> electricityBookRecords4 = book.getElectricityBookRecords(1, 10, 2020);
        cout << "electricityBookRecords4" << endl;
        for (auto& electricityBookRecord : electricityBookRecords4)
        {
            cout << electricityBookRecord.getValue() << endl;
        }
        cout << "-----------------------" << endl;

        vector<electricity_book_record> electricityBookRecords5 = book.getElectricityBookRecords(10, 2020);
        cout << "electricityBookRecords5" << endl;
        for (auto& electricityBookRecord : electricityBookRecords5)
        {
            cout << electricityBookRecord.getValue() << endl;
        }
        cout << "-----------------------" << endl;

        vector<electricity_book_record> electricityBookRecords6 = book.getElectricityBookRecords(2020);
        cout << "electricityBookRecords6" << endl;
        for (auto& electricityBookRecord : electricityBookRecords6)
        {
            cout << electricityBookRecord.getValue() << endl;
        }
        cout << "-----------------------" << endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }
}
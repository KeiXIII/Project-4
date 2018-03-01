#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#ifndef DOCTOROFFICE_H
#define DOCTOROFFICE_H

class DoctorOffice{
private:
    bool** free;
    int size;
    
public:
    DoctorOffice();
    DoctorOffice(int size);
    ~DoctorOffice();
    bool open(int year, int month, int day);
    int showAvailTimes(int day);
    void setAvailTimes(int month, int day, int year, string apptTime); 
    void editAppt(int month, int day, int year, string apptTime);
    void print(int size);
};

#endif /* DOCTOROFFICE_H */

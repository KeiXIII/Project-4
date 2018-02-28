#include<iostream>

using namespace std;

#ifndef DOCTOR_H
#define DOCTOR_H

class Doctor
{
    private:
        DoctorOffice do; // Object creation will call the constructor
        int date,month,year;
        string time;
        bool docOpen;
  
    public:
        VisitDate();
        DoctorAvailable();
    
};

#endif /* DOCTOR_H */

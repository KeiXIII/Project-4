/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Programmed by: Brandon Lung
 */


#include "DoctorOffice.h"

const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* openHours[] = {"8am", "9am", "10am", "11am", "1pm", "2pm", "3pm", "4pm", "5pm"};

//default
DoctorOffice::DoctorOffice(){ 
}

//constructs the months based on the days; ie. January is 31 days
DoctorOffice::DoctorOffice(int size){
    this->size = size;
    free = new bool*[size];
    for(int i = 0; i < size; i++){
        free[i] = new bool[9];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 9; j++){
            free[i][j] = true;
        }
    }
}

DoctorOffice::~DoctorOffice(){
    for(int i = 0; i < size; i++) {
        delete [] free[i];
    }
    delete [] free;
}

//returns true if weekday, false if weekend
bool DoctorOffice::open(int year, int month, int day){
    time_t nowTime;
    struct tm* timeInfo;
    time ( &nowTime );
    timeInfo = localtime ( &nowTime );
    timeInfo->tm_year = year - 1900;
    timeInfo->tm_mon = month - 1;
    timeInfo->tm_mday = day;
    mktime(timeInfo);
    cout << months[month-1] << " " << day << "," << year << " is a " << week[timeInfo->tm_wday] << "." << endl;
    //office is closed on weekends; returns false if Sat or Sun
    if ( week[timeInfo->tm_wday] == "Sunday" || week[timeInfo->tm_wday] == "Saturday" ){
        return false;
    }
    else{
        //returns true if it is a weekday
        return true;
    }
}

//returns the number of slots open to book appointments
int DoctorOffice::showAvailTimes(int day){
    int count = 0;
    cout << "Available Times are: ";
    for(int i = 0; i < 9; i++){
        if(free[day -1][i] == true){
            if(i == 8)
                cout << openHours[i] << endl;
            else
                cout << openHours[i] << ", ";
            count++;
        }
    }
    return count;
}

//determines if slot is already taken; if not, patient is booked for the given date
//doesn't check if weekend or not; use open function before setting appt
void DoctorOffice::setAvailTimes(int month, int day, int year, string apptTime){
    int count = 0;
    while (count < 9){
        if(openHours[count] != apptTime)
            count++;
        else
            break;
    }
    if(openHours[count] == apptTime){
        if(free[day-1][count] == true){
            free[day-1][count] = false;
            cout << "Patient appointment is entered for: " << months[month-1] << " " << day << ", " << year << " at " << apptTime << "." << endl << endl;
        }else
            cout << "Another patient already took this time slot for: " << months[month-1] << " " << day << ", " << year << " at " << apptTime << "." << endl << endl;
    }                 
}

void DoctorOffice::editAppt(int month, int day, int year, string apptTime){
    int count = 0;
    while (count < 9){
        if(openHours[count] != apptTime)
            count++;
        else
            break;
    }
    if(openHours[count] == apptTime){
        if(free[day-1][count] == false){
            free[day-1][count] = true;
            cout << "Removed patient appointment and slot open for: " << months[month-1] << " " << day << ", " << year << " at " << apptTime << "." << endl << endl;
        }else
            cout << "Slot is still available for: " << months[month-1] << " " << day << ", " << year << " at " << apptTime << "." << endl << endl;
    }                 
}

void DoctorOffice::print(int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 9; j++){
            cout << free[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


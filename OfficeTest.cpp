/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Programmed by: Brandon Lung
 */

#include "DoctorOffice.h"

int main(){
    
    //building 2d array
    DoctorOffice March(31);
    
    //testing constructor
    March.print(31);
    
    //testing open function; ie. March 3, 2018 (Saturday) and March 5, 2018 (Monday)
    if(March.open(2018,3,3) == false)
        cout << "Office is closed." << endl << endl;
    else
        cout << "Office is open." << endl << endl;
    
    if(March.open(2018,3,2) == false)
        cout << "Office is closed." << endl << endl;
    else
        cout << "Office is open." << endl << endl;
    
    int avail;
    //shows avail slots for appointments; returns how many slots are open
    avail = March.showAvailTimes(2);
    cout << "There are " << avail << " spots left." << endl << endl;
    
    //sets appt on the given day
    March.setAvailTimes(3, 2, 2018, "10am");
    
    //shows again after appt added
    avail = March.showAvailTimes(2);
    cout << "There are " << avail << " spots left." << endl << endl;
    
    //tests to see if appt actually exists; should output that spot is taken
    March.setAvailTimes(3, 2, 2018, "10am");
    
    //removes appt
    March.editAppt(3, 2, 2018, "10am");
    
    March.setAvailTimes(3, 2, 2018, "1pm");
    avail = March.showAvailTimes(2);
    cout << "There are " << avail << " spots left." << endl << endl;
    
    March.print(31);
    
    
    return 0;
}


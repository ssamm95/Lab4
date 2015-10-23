/*
 * header.h
 *
 *  Created on: Oct 16, 2015
 *      Author: ssammut
 */

#ifndef Lab4_header_h
#define Lab4_header_h

#include <iostream>
using namespace std;

//enum types
enum sex {M,F};
enum antigen {A,AB,O,B};
enum unit {Heart,Kidney,Lung,Liver};

struct patient
{
    char first_name[50];
    char last_name[50];
    sex gender;
    antigen blood_type;
    unit organ;
    int age;
    int year_added;
    int ID;
};

//function declarations
void action(int option, int i, int &list_size, int &quit, char argument[]);
void arg1 (char argument []);


#endif

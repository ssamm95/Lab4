#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "header.h"

using namespace std;

void action(int option, int i, int &list_size ,int &quit, char argument[])
{
    int j;
    char gender; //temp variable
    string blood_type,organ;	//temp variables
    patient patient[100]; //array of type patient struct

    if(option==1)	//entering patient information
    {
        cout << "\nPlease enter the Patient Record (First Name, Last Name, Gender, Blood Type, Organ, Age, Year Added):\n";
        cin >>patient[i].first_name>>patient[i].last_name>>gender>>blood_type>>organ>>patient[i].age>>patient[i].year_added;
        cout << "\n...[Adding]\n\n";

        //translate info into enum types

        if(gender=='M')
            patient[i].gender=M;
        if(gender=='F')
            patient[i].gender=F;
        if((gender!='M')&&(gender!='F'))
            cout << "\nInvalid gender.";

        if(blood_type=="A")
            patient[i].blood_type=A;
        if(blood_type=="AB")
            patient[i].blood_type=AB;
        if(blood_type=="O")
            patient[i].blood_type=O;
        if(blood_type=="B")
            patient[i].blood_type=B;
        if((blood_type!="A")&&(blood_type!="AB")&&(blood_type!="O")&&(blood_type!="B"))
            cout << "\nInvalid blood type.";

        if(organ=="Heart")
            patient[i].organ=Heart;
        if(organ=="Kidney")
            patient[i].organ=Kidney;
        if(organ=="Lung")
            patient[i].organ=Lung;
        if(organ=="Liver")
            patient[i].organ=Liver;
        if((organ!="Heart")&&(organ!="Kidney")&&(organ!="Lung")&&(organ!="Liver"))
            cout << "\nInvalid organ.";

        patient[i].ID=list_size+1;

        list_size++; //update list size once patient info added

    }

    if(option==2)	//displaying patients
       {
           cout << "\nID\tName\t\tGender\tBlood\tOrgan\tAge\tWaiting Since";
           cout << "\n----------------------------------------------------------------------\n";
           for(j=0;j<list_size;j++)
           {
               cout << patient[j].ID << "\t" << patient[j].first_name <<","<<patient[j].last_name << "\t";

               //translate info out of enum types

               if(patient[j].gender==0)
               {
            	   cout << "M\t";
               }
               if(patient[j].gender==1)
               {
            	   cout << "F\t";
               }
               if(patient[j].blood_type==0)
               {
            	   cout << "A\t";
               }
               if(patient[j].blood_type==1)
               {
            	   cout << "AB\t";
               }
               if(patient[j].blood_type==2)
               {
                   cout << "O\t";
               }
               if(patient[j].blood_type==3)
               {
            	   cout << "B\t";
               }
               if(patient[j].organ==0)
               {
            	   cout << "Heart\t";
               }
               if(patient[j].organ==1)
               {
            	   cout << "Kidney\t";
               }
               if(patient[j].organ==2)
               {
            	   cout << "Lung\t";
               }
               if(patient[j].organ==3)
               {
            	   cout << "Liver\t";
               }

               cout << patient[j].age << "\t" << patient[j].year_added << "\n\n";
           }
       }

    if(option==3)	//saving patient list to file
       {
           ofstream myfile;	//outputting to file
           myfile.open("transplantPatients.txt");
           myfile << "Patients: " << list_size <<endl;

           myfile << "\nID\tName\t\tGender\tBlood\tOrgan\tAge\tWaiting Since";
           myfile << "\n----------------------------------------------------------------------\n";

           for(j=0;j<list_size;j++) //outputting to file
           {
        		   	   myfile << patient[j].ID << "\t" << patient[j].first_name <<","<<patient[j].last_name << "\t";
        	           if(patient[j].gender==0)
        	           {
        	        	   myfile << "M\t";
        	           }
        	           if(patient[j].gender==1)
        	           {
        	               	myfile << "F\t";
        	           }
        	           if(patient[j].blood_type==0)
        	           {
        	               	  myfile << "A\t";
        	           }
        	           if(patient[j].blood_type==1)
        	           {
        	               	   myfile << "AB\t";
        	           }
        	           if(patient[j].blood_type==2)
        	           {
        	                      myfile << "O\t";
        	           }
        	           if(patient[j].blood_type==3)
        	           {
        	               	  myfile << "B\t";
        	           }
        	           if(patient[j].organ==0)
        	           {
        	               	  myfile << "Heart\t";
        	           }
        	           if(patient[j].organ==1)
        	           {
        	               	   myfile << "Kidney\t";
        	           }
        	           if(patient[j].organ==2)
        	           {
        	               	   myfile << "Lung\t";
        	           }
        	           if(patient[j].organ==3)
        	           {
        	               	   myfile << "Liver\t";
        	           }

        	           	   	   myfile << patient[j].age << "\t" << patient[j].year_added << "\n\n";
        	      	   }myfile.close();

        	      	   cout << "...[Saving]" <<endl;
       }

    if(option==4) //quit loop
        quit=1;

    else if((option!=1)&&(option!=2)&&(option!=3)&&(option!=4))
        cout << "\nInvalid option. Please try again.\n\n";
}


void arg1 (char argument []) //function for displaying text file contents in command line
{
    string line;

    if(strcmp(argument,"transplantPatients.txt")==0) //check if argument from command line is "trasnplantPatients.txt"
    {
        ifstream myfile ("transplantPatients.txt");	//receiving input from file
        if (myfile.is_open())
        {
            while (getline (myfile,line))
            {
                cout << line << endl;	//output contents of file
            }
            myfile.close();
        }
    }

    else
        cout << "\nInvalid Argument. Please try again\n";

}

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "header.h"

using namespace std;


int main(int argc, char *argv[])

{
    int i,option,list_size=0, quit;
    if(argc==1) //execution in command line without file name
    {
        for(i=0;i<100;i++)
    {
            cout << "[Organ Transplant List]\nThere is currently " << list_size << " patient(s) on the list\n\n";
            cout << "Please choose and option (enter a number):\n1.    Add patient\n2.    Show Patients\n3.    Save Patient List\n4.    Quit";
            cin >> option;

            action(option,i,list_size,quit,argv[1]);	//call action function

            if(quit==1)
                break;
    }
    }

    if(argc==2)	//execution in the command line with file name
    {
        arg1(argv[1]);
    }

    else if(argc < 1)
        cout << "Invalid number of arguments.\n";

    return(0);

}

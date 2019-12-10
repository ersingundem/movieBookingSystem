#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "functions.h"



int main() {
	int onum;
	while(1){
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<< "\tWelcome to the movie ticket booking system" << endl;
	cout<<"-----------------------------------------------------------"<< endl;
	cout<<"-----------------------------------------------------------"<< endl;
	cout<< "| |\t\t\t1. Book Ticket\t\t\t| |" <<endl;
	cout<< "| |\t\t\t2. Show Ticket\t\t\t| |" <<endl;
	cout<< "| |\t\t\t3. Add Movie\t\t\t| |" <<endl;
	cout<< "| |\t\t\t4. Edit Movie\t\t\t| |" <<endl;
	cout<< "| |\t\t\t5. Delete Movie\t\t\t| |" <<endl;
	cout<< "| |\t\t\t0. Quit\t\t\t\t| |" <<endl;
	cout<<"-----------------------------------------------------------"<< endl;
	cout<<"-----------------------------------------------------------"<< endl;
	cout<<" "<<endl;
	cout<<"Please enter the transaction you want to perform" <<endl;
	cin>>onum;
	cout<<" "<<endl;
	

	if (onum==1)
	bookTicket();
	else if (onum==2)
	showTicket();
	else if (onum==3)
	addMovie();
	else if(onum==4)
	editMovie();
	else if(onum==5)
	deleteMovie();
	else
	cout<<"Invalid Operation!"<<endl;
}
}


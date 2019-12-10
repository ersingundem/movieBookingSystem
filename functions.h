#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;
string moviename,movietime;
string newmoviename,newmovietime;
string name, pnumber,yourmovie;

int seatnumber= (rand() % 40)+1;
string pass = "1234";



void bookTicket(){
	int onum;
ifstream handler("movies.txt");
	vector<string> mtext;
	char line[255]; 
    int linenum=1; 
    while(!handler.eof()) { 
      handler.getline(line,255); 
      cout << linenum<<".Movie: "<<line;
      mtext.push_back(line);
      cout << "\n"; 
      linenum++;
    } 
    handler.close();
cout<<"Name: ";
cin>>name;
cout<<"Phone number: ";
cin>>pnumber;
cout<<"Which movie would you like to chose: ";
cin>>linenum;
yourmovie = mtext[linenum-1];
cout<<"The ticket succesfully created.";

ofstream ticket;
ticket.open("ticket.txt",ios::out | ios::trunc);


ticket<<"-----------------------------------------------------------"<< endl;
ticket<<"Your Ticket:" <<endl;
ticket<<"-----------------------------------------------------------"<< endl;
ticket<<"Name: "<< name<<endl;
ticket<<"Phone Number: "<<pnumber<<endl;
ticket<<"Seat: "<< seatnumber<<endl;
ticket<<"-----------------------------------------------------------"<< endl;
ticket<<"Movie Name:\t\t\t Movie Time: " <<endl;
ticket<<yourmovie<<endl;
ticket.close();



}
void showTicket(){
ifstream ticket;
ticket.open("ticket.txt");
string movieticket="";
if ( ticket.is_open()){

    while ( getline(ticket, movieticket) ){
      cout << movieticket << endl;
    }

    ticket.close();
  }
}
void addMovie(){	
cout<<"Only administrators can perform this operation!"<<endl;
cout<<"Enter administrator password to login: " <<endl;
cin>>pass;
if(pass=="1234"){
	cout<<"You entered the system succesfully!"<<endl;
	ofstream handler;
	handler.open("movies.txt",ios::out | ios::trunc);
	int b;
	cout<<"How many movie do you want to add: "<<endl;
	cin>>b;
	vector <string> m;
	vector <string> t;
	cout<<"Enter the data of the movie you want to add"<<endl;
	for(int i=0;i<b;i++){
		cout<<i+1<<".Movie"<<endl<<" \tMovie Name ="<<"\t";
    	cin>>moviename;
    	m.push_back(moviename);
    	cout<<" \tMovie Time ="<<"\t";
    	cin>>movietime;
    	t.push_back(movietime);	
     }
cout<< "Movies added succesfully."<<endl;
	for(int i=0;i<b;i++){
    	handler<<m[i]<<"\t\t\t";
		handler<<t[i]<<endl;
             }
          handler.close();	
}
else
cout<<"Wrong Password! "<<endl;
}
void editMovie(){
cout<<"Only administrators can perform this operation!"<<endl;
cout<<"Enter administrator password to login: " <<endl;
cin>>pass;
if(pass=="1234"){
	cout<<"You entered the system succesfully!"<<endl;
	ifstream handler("movies.txt");
	vector<string> mtext;
	char line[255]; 
    int linenum=1; 
    while(!handler.eof()) { 
      handler.getline(line,255); 
      cout << linenum<<".Movie: "<<line;
      mtext.push_back(line);
      cout << "\n"; 
      linenum++;
    } 
    handler.close();
cout<<"Which movie would you like to edit?";
cin>>linenum;
cout<<"Movie name:";
cin>>newmoviename;
cout<<"Movie time:";
cin>>newmovietime;
string line2 = newmoviename + "\t\t\t"+ newmovietime;

mtext[linenum-1]= line2;
cout<<"The movie edited succesfully"<<endl;
ofstream editer;
editer.open("movies.txt",ios::out | ios::trunc);
	for(int a=0;a<mtext.size();a++){
    	editer<< mtext[a] <<endl;
	}
          editer.close();

	
}
else
cout<<"Wrong Password! "<<endl;
}	
void deleteMovie(){
	cout<<"Only administrators can perform this operation!"<<endl;
cout<<"Enter administrator password to login: " <<endl;
cin>>pass;
if(pass=="1234"){
	cout<<"You entered the system succesfully!"<<endl;
	ifstream handler("movies.txt");
	vector<string> mtext;
	char line[255]; 
    int linenum=1; 
    while(!handler.eof()) { 
      handler.getline(line,255); 
      cout << linenum<<".Movie: "<<line;
      mtext.push_back(line);
      cout << "\n"; 
      linenum++;
    } 
    handler.close();
cout<<"Which movie would you like to delete: ";
cin>>linenum;
linenum = linenum-1;
mtext.erase(mtext.begin()+linenum);
cout<<"The movie deleted succesfully."<<endl;
ofstream deleter;
deleter.open("movies.txt",ios::out | ios::trunc);
	for(int c=0;c<mtext.size();c++){
    	deleter<< mtext[c] <<endl;
	}
          deleter.close();
}
else
cout<<"Wrong Password! "<<endl;	
}

/*
		++++++++++++++++++++++++++++++++++++++++++++++++++
		+++ SOFTWARE FOR THE USE IN LAPTOP REPAIR SHOP +++
		++++++++++++++++++++++++++++++++++++++++++++++++++
 
		 //////////////////////////////////////////////
		   NAME:- S.Jahnavi Prasad
		   Class:- K18RD  Roll No:- 56
		   Subject:- OBJECT ORIENTED PROGRAMMING 
		   Subject Code:- CSE202 
		   Course :- B.Tech CSE(Hons.)
		   University:- Lovely Professional University 
		 //////////////////////////////////////////////
 
		      ###########################################
		      ##  JP Laptop Repair and Service Center  ##
		      ###########################################
*/
#include<iostream>     //for input and output streams
#include<fstream>      //for reading and writing files
#include<string>       //for string characters
#include<iomanip>      //for setw function  
#include<conio.h>      //for clrscr()
#include<stdio.h>      //for gets and puts function
#include<process.h>    //for exit function
using namespace std;

class cust
{
	string name, mobile, brand, model, os, processor, ram, storage, complaint;
	public:
		void readc();
		void writec();
		void bill();
};
void cust::readc()
{
	cout<<"\nName:\t";
	cin.ignore(); 
	getline( cin, name );
	cout<<"\nMobile Number:\t"; cin>>mobile;
	cout<<"\n\n\t\t\t\tCustomer Registered";
	cout<<"\n\nEnter Laptop Details\t";
	cout<<"\n\nBrand:\t"; cin>>brand;
	cout<<"\nModel:\t"; cin>>model;
	cout<<"\nOperating System:\t"; cin>>os;
	cout<<"\nProcessor:\t"; cin>>processor;
	cout<<"\nRAM:\t"; cin>>ram;
	cout<<"\nStorage:\t"; cin>>storage;
	cout<<"\nEnter the problems being faced by the laptop\n";
	cin.ignore();
	getline( cin, complaint );
}
void cust::writec()
{
	cout<<"\n\t\t\t\tName:"<<name;
	cout<<"\n\t\t\t\tMobile Number:"<<mobile;
	cout<<"\n\t\t\t\tBrand:"<<brand;
	cout<<"\n\t\t\t\tModel:"<<model;
	cout<<"\n\t\t\t\tOperating System:"<<os;
	cout<<"\n\t\t\t\tProcessor:"<<processor;
	cout<<"\n\t\t\t\tRAM:"<<ram;
	cout<<"\n\t\t\t\tStorage:"<<storage;
  ofstream file;
  file.open ("file.txt");
  file<<name<<"\n"<<mobile<<"\n"<<brand<<"\n"<<model<<"\n"<<os<<"\n"<<processor<<"\n"<<ram<<"\n"<<storage<<"\n"<<complaint<<"\n";
  file.close();
  cout<<"\n\n\t\t\t\tComplaint registered";
  cout<<"\n\t\t\t\t"<<complaint;
}

class repair
{
	string line;
	public:
	void repairstatus();
};
void repair::repairstatus()
	{
		string name;
		cout<<"\nEnter customer name : \t";
		cin.ignore(); 
	    getline( cin, name );
		ifstream myfile ("repairstatus.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
            	cout << line << '\n';
    		}
    	myfile.close();
  		}
  		else cout << "Unable to open file";
  		
	}
	
void cust::bill()
{
    string line;
    ifstream myfile;
    myfile.open("bill.txt");
    cout<<"\n";
	while(getline(myfile, line)) 
    {
     cout << line << endl;
    }
}
    	
main()
{
	int menu;
	char choice;
	cust obj1;
	repair obj2;
	
	start:
	cout<<"\n\n\n\n\n\t\t\tJP Laptop Repair and Service Center\n";
	cout<<"\t\t\t\t\tMain Menu\n";
	cout<<"1. New Customer\n";
	cout<<"2. Repair Status\n";
	cout<<"3. Customer Bill\n";
	cout<<"\nEnter your choice\t";
	cin>>menu;
	cout<<"\n\n";
	
	switch(menu)
    {
     case 1:
        system("cls");
	 	cout<<"\t\t\t\tEnter Customer Details";
	    obj1.cust::readc();
	 	cout<<"\n\t\t\t\tCross check Customer Details\n";
		obj1.cust::writec();
		cout<<"\n\n\n\nDo you want to go back to main menu? [y/n] : ";
	    cin>>choice;
	    system("cls");
		if(choice == 'y')
	    goto start;
	    else 
		break;
     case 2: 
        system("cls");
	 	cout<<"\t\t\t\tRepair Status Query";
	    obj2.repair::repairstatus(); 
	    cout<<"\n\n\n\nDo you want to go back to main menu? [y/n] : ";
	    cin>>choice;
	    system("cls");
	    if(choice == 'y')
	    goto start;
	    else 
		break;
     case 3: 
        system("cls");
	    cout<<"\n\n\t\t\t\tThe Bill\n";
		string name;
		cout<<"\nEnter customer name : \t";
		cin.ignore(); 
	    getline( cin, name );
		obj1.cust::writec();
		obj1.cust::bill();
		cout<<"\n\n\n\nDo you want to go to main menu? [y/n] : ";
	    cin>>choice;
	    system("cls");
	    if(choice == 'y')
	    goto start;
	    else 
		break;
    }
}

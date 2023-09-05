#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Hospital{
private:
string Name, Address, BGroup;
public:
Hospital():Name(""), Address(""), BGroup(""){}

setName(string name){
 Name = name;
}

setAddress(string address){
 Address = address;
}

setBGroup(string group){
BGroup = group;
}

string getName(){
 return Name;
}

string getAddress(){
 return Address;
}

string getBGroup(){
 return BGroup;
}
};

admit(Hospital patient){
system("cls");
string name, address, group;

cout<<"\tEnte Name Of Patient: ";
cin>>name;
patient.setName(name);

cout<<"\tEnter Address Of Patient: ";
cin>>address;
patient.setAddress(address);

cout<<"\tEnter Blood Gruop Of Patient: ";
cin>>group;
patient.setBGroup(group);

ofstream outfile("D:/Hospital.txt", ios::app);
if(!outfile){
cout<<"\tError: File Can't Opent!"<<endl;
}
else{
outfile<<"\t"<<patient.getName()<<" : "<<patient.getAddress()<<" : "<<patient.getBGroup()<<endl<<endl;
cout<<"\tPatient Admited!"<<endl;
}
outfile.close();
Sleep(3000);
}

discharge(){
	system("cls");
string name;
cout<<"\tEnter Name of Patient: ";
cin>>name;

ifstream infile("D:/Hospital.txt");
ofstream outfile("D:/Hospital Temp.txt");
if(!infile || !outfile){
cout<<"\tError: File Can't Open!"<<endl;
}
else{
string line;
bool found = false;

while(getline(infile, line)){
stringstream ss;
ss<<line;
string patientName;
ss>>patientName;
if(name == patientName){
found = true;
cout<<"\tPatient Discharged!"<<endl;
}
else{
outfile<<line<<endl;
}
}
if(!found){
cout<<"\tIncorrect Name!"<<endl;
}
}
outfile.close();
infile.close();
remove("D:/Hospital.txt");
rename("D:/Hospital Temp.txt", "D:/Hospital.txt");
Sleep(3000);
}

int main(){
Hospital patient;

bool exit = false;
while(!exit){
system("cls");
int val;
cout<<"\tHospital Management System"<<endl;
cout<<"\t**************************"<<endl;
cout<<"\t1.Admit Patient."<<endl;
cout<<"\t2.Discharge Patient."<<endl;
cout<<"\t3.Exit."<<endl;
cout<<"\tEnter Choice: ";
cin>>val;

if(val==1){
admit(patient);
}

else if(val==2){
discharge();
}

else if(val==3){
system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}
Sleep(5000);
}
}



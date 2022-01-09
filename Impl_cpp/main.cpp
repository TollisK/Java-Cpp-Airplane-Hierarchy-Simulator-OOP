#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "plane.h"
using namespace std;
int Object::idd = 0; 
 
void clone_encrypt_and_print(Object& object){
	int num,num2;
	Object *clone;
	String str,str2;
	char c,c2;
	clone = object.clone();
	str2 = object.toString();
	cout <<"Original tostring:"<<endl;
	str2.print();
	
	if(object.equal(*clone)==1){
		cout <<endl<< "the clone is equal to the original!"<<endl;
	}
	else{
		cout <<endl<< "the clone is not equal to the original!"<<endl;
	}
	if(object.identical(*clone)==1){
		cout << "the clone is identical to the original!"<<endl;
	}
	else{
		cout << "the clone is not identical to the original!"<<endl;
	}
	str = clone->toString();
	cout <<"Cloned tostring:"<<endl;
	str.print();
	for(int i=0;i<500;i++){ //antistrefei 500 tyxaia grammata apo to toString
		num = rand()%str.get_length();
		c = str.at(num);
		num2 = rand()%str.get_length();
		c2 = str.at(num2);
		str.updateAt(num2,c);
		str.updateAt(num,c2);
	}
	cout << endl<<endl<<"Cloned and encrypted tostring:"<<endl;
	str.print();
	str2.concat(str.get_string());
	cout << endl<<"Both string lenght: "<<str2.get_length()<<endl;
	if(str2.get_length()%2==0){
		cout << "the 2 characters in the middle are: "<<str2.at(str.get_length()/2)<<" and "<<str2.at((str.get_length()/2)+1)<<endl;
	}
	else{
		cout <<"the character in the middle is: "<<str2.at(str2.get_length()/2)<<endl;
	}
	str2.clear();
	cout << "final lenght: "<<str2.get_length()<<endl;
	delete clone;
}

int main(void){
	srand(time(NULL));
	String Secname("Security"),Mainame("Maintanance"),Clename("Cleaning"),Planetitle("boeing 787");
	Plane plane(Planetitle);
	SecurityEmployee *Secuemp;
	Secuemp = new SecurityEmployee(Secname);
	MaintananceEmployee *Mainemp;
	Mainemp = new MaintananceEmployee(Mainame);
	CleaningEmployee *Cleanemp;
	Cleanemp = new CleaningEmployee(Clename);
	plane.process(Secuemp);
	plane.process(Mainemp);	
	plane.process(Cleanemp);
	plane.ready_check();
	clone_encrypt_and_print(plane);
	delete Secuemp;
	delete Mainemp;
	delete Cleanemp;
}

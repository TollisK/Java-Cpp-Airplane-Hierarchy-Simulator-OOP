#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "planecom.h"
using namespace std;
class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEmployee;
class Plane : public Object
{
private:
	String title;
	int capacity;
	PassengerCompartment *passcom;
	CargoBay *cargobay;
	EquipmentCompartment *equicom1,*equicom2,*equicom3;
public:
	Plane(String& nam)
	:capacity(rand()%100 + 101),title(nam) //plane capacity = 100-200
	{
		equicom1 = new EquipmentCompartment;
		equicom2 = new EquipmentCompartment;
		equicom3 = new EquipmentCompartment;
		cargobay = new CargoBay;
		passcom = new PassengerCompartment(capacity);
		cout << "Plane just created!"<<endl;
	}
	void ready_check(){
		if(passcom->ready_check() == 1&&cargobay->ready_check() == 1&&equicom1->ready_check() == 1&&equicom2->ready_check() == 1&&equicom3->ready_check() == 1)
			cout << "Plane is ready to take off!"<<endl;
		else{
			cout << "Plane is not ready to take off yet!"<<endl;
		}
	}
	String toString();
	void process(SecurityEmployee*);
	void process(MaintananceEmployee*);
	void process(CleaningEmployee*);
	Object* clone();
	
	string get_titlestr() const{
		return title.get_string();
	}
	int get_capacity() const{
		return capacity;
	}
	String* get_title() {
		return &title;
	}
	
	PassengerCompartment* get_passcom(){
		return passcom;
	}
	CargoBay * get_cargobay(){
		return cargobay;
	}
	EquipmentCompartment * get_equicom1(){
		return equicom1;
	}
	EquipmentCompartment * get_equicom2(){
		return equicom2;
	}
	EquipmentCompartment * get_equicom3(){
		return equicom3;
	}
	
	Plane(Plane& plan)
	:capacity(plan.get_capacity()),Object(plan),title(*(plan.get_title()))
	{
		cout << "Plane just created!"<<endl;
		equicom1  = new EquipmentCompartment(*plan.get_equicom1());
		equicom2  = new EquipmentCompartment(*plan.get_equicom2());
		equicom3  = new EquipmentCompartment(*plan.get_equicom3());
		cargobay = new CargoBay(*plan.get_cargobay());
		passcom = new PassengerCompartment(*plan.get_passcom());
	}
	virtual ~Plane(){
		delete equicom1;
		delete equicom2;
		delete equicom3;
		delete cargobay;
		delete passcom;
		cout << "Plane to be destroyed!"<<endl;
	}
};
#endif

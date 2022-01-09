#include <iostream>
#include "planecom.h"
using namespace std;
Object* PassengerCompartment::clone(){
	return new PassengerCompartment(*this);
}

Object* EquipmentCompartment::clone(){
	return new EquipmentCompartment(*this);
}
Object* CargoBay::clone(){
	return new CargoBay(*this);
}
String PlaneComponent::toString(){
	String str("||PlaneComponent: Employee counter = "+ to_string(emp_counter)+"||Object: id = "+to_string(Object::get_id()));
	return str;
}


String PassengerCompartment::toString(){
	String str("||PassengerCompartment: ");
	str.concat(PlaneComponent::toString().get_string());
	if(PassComp!=NULL){
		str.concat("\n");
		str.concat(PassComp->toString().get_string());
	}
	return str;
}

String PrivateCompartment::toString(){
	String str("||PrivateCompartment: ");
	str.concat(PlaneComponent::toString().get_string());
	return str;
}

String EquipmentCompartment::toString(){
	String str("||EquipmentCompartment: ");
	str.concat(PrivateCompartment::toString().get_string());
	return str;
}

String CargoBay::toString(){
	String str("||Cargobay: " + PrivateCompartment::toString().get_string()+"\n||Cargobay's EquipmentCompartment: "+ EqCom->toString().get_string());
	return str;
}
void EquipmentCompartment::process(Employee* Emp){
	Emp->workOn(this);
	this->set_counter();
}

void PassengerCompartment::process(Employee* Emp){
	Emp->workOn(this);
	this->set_counter();
	if(PassComp != NULL){
		PassComp->process(Emp);
	}
}

void CargoBay::process(Employee* Emp){
	Emp->workOn(this);
	this->set_counter();
	Emp->workOn(EqCom);
	EqCom->set_counter();
}

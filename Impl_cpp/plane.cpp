#include <iostream>
#include "plane.h"
using namespace std;

Object* Plane::clone(){
	return new Plane(*this);
}

String Plane::toString(){
	String str("||Plane: title = "+ title.get_string() + "  capacity = " + to_string(capacity)+ "||Object: id = "+to_string(Object::get_id())+"\n");
	str.concat(passcom->toString().get_string()+"\n");
	str.concat(equicom1->toString().get_string()+"\n");
	str.concat(equicom2->toString().get_string()+"\n");
	str.concat(equicom3->toString().get_string()+"\n");
	str.concat(cargobay->toString().get_string());
	return str;
}

void Plane::process(SecurityEmployee* SecuEmp){
	equicom1->process(SecuEmp);
	equicom2->process(SecuEmp);
	equicom3->process(SecuEmp);
	
	cargobay->process(SecuEmp);
	
	passcom->process(SecuEmp);
}

void Plane::process(MaintananceEmployee* MainEmp){
	equicom1->process(MainEmp);
	equicom2->process(MainEmp);
	equicom3->process(MainEmp);
	
	cargobay->process(MainEmp);
	
	passcom->process(MainEmp);
}

void Plane::process(CleaningEmployee* CleanEmp){
	equicom1->process(CleanEmp);
	equicom2->process(CleanEmp);
	equicom3->process(CleanEmp);
	
	cargobay->process(CleanEmp);
	
	passcom->process(CleanEmp);
}

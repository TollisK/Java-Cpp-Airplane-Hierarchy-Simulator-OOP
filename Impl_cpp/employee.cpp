#include <iostream>
#include "employee.h"
using namespace std;
String Employee::toString(){
	String str("||Employee: name = "+ name.get_string() + "||Object: id = "+to_string(Object::get_id())+"\n");
	return str;
}

String SecurityEmployee::toString(){
	String str("||SecurityEmployee: ");
	str.concat(Employee::toString().get_string());
	return str;
}

String MaintananceEmployee::toString(){
	String str("||MaintananceEmployee: ");
	str.concat(Employee::toString().get_string());
	return str;
}
String CleaningEmployee::toString(){
	String str("||CleaningEmployee: ");
	str.concat(Employee::toString().get_string());
	return str;
}
Object* SecurityEmployee::clone(){
	return new SecurityEmployee(*this);
}
Object* MaintananceEmployee::clone(){
	return new MaintananceEmployee(*this);
}
Object* CleaningEmployee::clone(){
	return new CleaningEmployee(*this);
}

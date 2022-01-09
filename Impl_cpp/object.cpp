#include <iostream>
#include "object.h"

using namespace std;


Object* Object::clone(){
	Object *obj = this;
	return obj;
}

int Object::equal(Object& Obj){
	if(id==Obj.get_id()){
		return 1;
	}
	return 0;
}


int Object::identical(Object& Obj){
	if(this == &Obj){
		return 1;
	}
	return 0;
}


#ifndef OBJECT_H
#define OBJECT_H
using namespace std;
class String;
class Object 
{
private:
	int id;
public:
	int get_id() const{
		return id;
	}
	static int idd;
	void set_id(int i){
		id = i;
	}
	Object()
	:id(idd++)
	{
		cout << "Object just created!"<<endl;
	}
	Object(const Object& obj)
	:id(obj.id)
	{
	}
	virtual int equal(Object& Obj);
	int identical(Object& Obj);
	virtual String toString()=0;
	virtual Object *clone();
	virtual ~Object(){
		cout << "Object to be destroyed!"<<endl;
	}
};
#endif

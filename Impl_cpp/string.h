#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "object.h"
using namespace std;

template < typename T > std::string to_string( const T& n ){
	ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

class String : public Object
{
private:
	string str;
public:
	String(string stri = "default")
	:str(stri)
	{
		cout << "String just created!"<<endl;
	}
	void set_str(string stri){
		str = stri;
	}
	int get_length(){
		return str.length();
	}
	void clear(){
		str.clear();
	}
	void concat(string str2){
		str = str+str2;
	}
	char at(int i){
		return str[i];
	}
	void updateAt(int i,char c){
		str[i] = c;
	}
	void print(){
		cout << str << endl;
	}
	string get_string() const{
		return str;
	}
	String(String& stri)
	:Object(stri)
	{

		str = stri.get_string();
	}
	
	String& operator=(const String& stri)
	{
		str = stri.get_string();
		return *this;
	}
	
	String toString(){
	}
	virtual ~String(){
		cout << "String to be destroyed!"<<endl;
	}
};
#endif

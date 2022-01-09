#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"
using namespace std;
class CargoBay;
class PassengerCompartment;
class EquipmentCompartment;

class Employee : public Object 
{
private:
	String name;
public:
	
	Employee(String& nam)
	:name(nam)
	{
		cout << "Employee just created!"<<endl;
	}
	void set_name(string stri){
		name.set_str(stri);
	}
	String get_name(){
		return name;
	}
	string get_namestr() const{
		return name.get_string();
	}
	
	virtual void workOn(EquipmentCompartment*) = 0;
	virtual void workOn(CargoBay*) = 0;
	virtual void workOn(PassengerCompartment*) = 0;	
	virtual void report(EquipmentCompartment*)=0;
	virtual void report(CargoBay*)=0;
	virtual void report(PassengerCompartment*)=0;
	String toString();
	Employee(Employee& emp)
	{
		name.set_str(emp.get_namestr());
		cout << "Employee just created!"<<endl;
	}
	virtual ~Employee(){
		cout << "Employee to be destroyed!"<<endl;
	}
};

class SecurityEmployee : public Employee // se kathe synistwsa
{
public:
	
	SecurityEmployee(SecurityEmployee& secemp)
	:Employee(secemp)
	{
		set_id(secemp.get_id());
		cout << "SecurityEmployee just created!"<<endl;
	}
	
	SecurityEmployee(String& name)
	:Employee(name)
	{
		cout << "SecurityEmployee just created!"<<endl;
	}
	void report(EquipmentCompartment* Eqcom){
		cout << "Security Employee: Equipment Compartment - OK"<<endl;
	}
	void report(CargoBay* Cargo){
		cout << "Security Employee: CargoBay - OK"<<endl;
	}
	void report(PassengerCompartment* Passcom){
		cout << "Security Employee: Passenger Compartment - OK"<<endl;
	}
		
	void workOn(EquipmentCompartment* EquiCom){
		report(EquiCom);
	}
	void workOn(CargoBay* cargobay){
		report(cargobay);
	}
	void workOn(PassengerCompartment* passcomp){
		report(passcomp);
	}
	
	String toString();
	Object *clone();
	virtual ~SecurityEmployee(){
		cout << "SecurityEmployee to be destroyed!"<<endl;
	}
};

class MaintananceEmployee : public Employee 
{
public:
	MaintananceEmployee(MaintananceEmployee& mainemp)
	:Employee(mainemp)
	{
		set_id(mainemp.get_id());
		cout << "MaintananceEmployee just created!"<<endl;
	}
	MaintananceEmployee(String& name)
	:Employee(name)
	{
		cout << "MaintananceEmployee just created!"<<endl;
	}
	void report(EquipmentCompartment* Eqcom){
		cout << "Maintanance Employee: Equipment Compartment - OK"<<endl;
	}
	void report(CargoBay* cargo){
		cout << "Maintanance Employee: CargoBay - OK"<<endl;
	}
	void report(PassengerCompartment*){
	}
		
	void workOn(EquipmentCompartment* EquiCom){
		report(EquiCom);
	}
	void workOn(CargoBay* cargobay){
		report(cargobay);
	}
	void workOn(PassengerCompartment* passcomp){
	}
	String toString();
	Object *clone();
	virtual ~MaintananceEmployee(){
		cout << "MaintananceEmployee to be destroyed!"<<endl;
	}
};

class CleaningEmployee : public Employee
{
public:
	
	CleaningEmployee(CleaningEmployee& cleanemp)
	:Employee(cleanemp)
	{
		set_id(cleanemp.get_id());
		cout << "CleaningEmployee just created!"<<endl;
	}
	
	CleaningEmployee(String& name)
	:Employee(name)
	{
		cout << "CleaningEmployee just created!"<<endl;
	}
	void report(EquipmentCompartment*){
	}
	void report(CargoBay* cargo){
		cout << "Cleaning Employee: CargoBay - OK"<<endl;
	}
	void report(PassengerCompartment* Passcom){
		cout << "Cleaning Employee: Passenger Compartment - OK"<<endl;
	}
		
	void workOn(EquipmentCompartment*){
	}
	void workOn(CargoBay* cargobay){
		report(cargobay);
	}
	void workOn(PassengerCompartment* passcomp){
		report(passcomp);
	}
	String toString();
	Object *clone();
	virtual ~CleaningEmployee(){
		cout << "CleaningEmployee to be destroyed!"<<endl;
	}
};
#endif

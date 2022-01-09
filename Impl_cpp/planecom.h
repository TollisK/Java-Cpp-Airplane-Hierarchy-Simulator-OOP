#ifndef PLANECOM_H
#define PLANECOM_H
#include <iostream>
#include "string.h"
#include "employee.h"
using namespace std;
class PlaneComponent : public Object 
{
private:
	int emp_counter; //metavlhth gia to ready_check toy plane
public:
	void set_counter(){
		emp_counter++;
	}
	void set_count(int i){
		emp_counter = i;
	}
	int emp_count() const{
		return emp_counter;
	}
	String toString();
	virtual int ready_check()=0;
	virtual void process(Employee*) = 0;
	PlaneComponent()
	:Object()
	{
		cout << "PlaneComponent just created!"<<endl;
	}
	
	PlaneComponent(PlaneComponent& Planecom)
	:emp_counter(Planecom.emp_count())
	{
		cout << "PlaneComponent just created!"<<endl;
	}
	virtual ~PlaneComponent(){
		cout << "PlaneComponent to be destroyed!"<<endl;
	}
};

class PassengerCompartment: public PlaneComponent
{
private:
	PassengerCompartment* PassComp;  // eswteriko PassengerCompartment
public:
	PassengerCompartment(int capacity = 0)
	:PassComp(NULL),PlaneComponent()
	{
		if(rand()%capacity > 45){ //anadromikh synarthsh tyxaias dhmioyrgias PassengerCompartment poy einai analogh toy plane capacity 
			PassComp = new PassengerCompartment(capacity);
		}
		cout << "PassengerCompartment just created!"<<endl;
	}
	String toString();
	void process(Employee*);
	int ready_check(){
		if(emp_count() > 1){ //an exoyn perasei panw apo 1 employee sto compartment tote einai etoimo 
			cout << "Passenger Compartment OK!"<<endl;
			return 1;
		}
		return 0;	
	}
	
	PassengerCompartment* get_passcomp(){
		return PassComp;
	}
	
	PassengerCompartment(PassengerCompartment& passcom)
	:PlaneComponent(passcom)
	{
		set_id(passcom.get_id());
		if(passcom.get_passcomp() != NULL){
			PassComp = new PassengerCompartment(*passcom.get_passcomp());
		}
		cout << "PassengerCompartment just created!"<<endl;
	
	}
	Object *clone();
	virtual ~PassengerCompartment(){
		if(PassComp!=NULL){
			delete PassComp;
		}
		cout << "PassengerCompartment to be destroyed!"<<endl;
	}
};

class PrivateCompartment : public PlaneComponent
{
public:
	
	virtual int ready_check(){
	};
	virtual void process(Employee*){
	};
	String toString();
	PrivateCompartment()
	:PlaneComponent()
	{
		cout << "PrivateCompartment just created!"<<endl;
	}
	PrivateCompartment(PrivateCompartment& Pricom)
	:PlaneComponent(Pricom)
	{
		cout << "PrivateCompartment just created!"<<endl;
	}
	virtual ~PrivateCompartment(){
		cout << "PrivateCompartment to be destroyed!"<<endl;
	}
};

class EquipmentCompartment : public PrivateCompartment
{
public:
	EquipmentCompartment()
	:PrivateCompartment()
	{
		cout << "EquipmentCompartment just created!"<<endl;
	}
	int ready_check(){
		if(emp_count() > 1){
			cout << "Equipment Compartment OK!"<<endl;
			return 1;
		}
		return 0;	
	}
	String toString();
	void process(Employee*);
	
	EquipmentCompartment(EquipmentCompartment& Eqcom)
	:PrivateCompartment(Eqcom)
	{
		set_id(Eqcom.get_id());
		cout << "EquipmentCompartment just created!"<<endl;
	}
	
	Object *clone();
	virtual ~EquipmentCompartment(){
		cout << "EquipmentCompartment to be destroyed!"<<endl;
	}
};

class CargoBay : public PrivateCompartment 
{
private:
	EquipmentCompartment *EqCom;
public:
	
	CargoBay()
	:PrivateCompartment()
	{
		EqCom = new EquipmentCompartment;
		cout << "CargoBay just created!"<<endl;
	}
	void process(Employee*);
	int ready_check(){
		if(emp_count() > 2){
			cout <<"CargoBay OK!"<<endl;
			return 1;
		}
		return 0;	
	}
	EquipmentCompartment * get_eqcom(){
		return EqCom;
	}
	String toString();
	CargoBay(CargoBay& cargo)
	:PrivateCompartment(cargo)
	{
		set_id(cargo.get_id());
		cout << "CargoBay just created!"<<endl;
		EqCom = new EquipmentCompartment(*cargo.get_eqcom());
	}
	Object *clone();
	virtual ~CargoBay(){
		delete EqCom;
		cout << "CargoBay to be destroyed!"<<endl;
	}
};
#endif

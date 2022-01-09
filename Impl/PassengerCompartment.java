
package ergjava;


public class PassengerCompartment extends PlaneComponent{
    protected PassengerCompartment PassComp;
    public PassengerCompartment(int capacity){
        super();
        if(Math.random()*capacity >40){
            PassComp = new PassengerCompartment(capacity);
        }
        System.out.println("PassengerCompartment just created!");
    }
    @Override
    public String toString(){
        String str = "||PassengerCompartment: ";
        str = str.concat(super.toString());
        if(PassComp!=null){
            str = str.concat(super.toString());
        }
        return str;
    }
    @Override
    public void process(Employee emp){
        emp.workOn(this);
        if(PassComp != null){
            PassComp.process(emp);
        }
    }
    @Override
    public int ready_check(){
        if(emp_counter == 2){
            System.out.println("Passenger Compartment OK!");
            return 1;
        }
        return 0;
    }
    
}

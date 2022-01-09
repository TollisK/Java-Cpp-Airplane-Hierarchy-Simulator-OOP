
package ergjava;


public class CargoBay extends PrivateCompartment{
    protected EquipmentCompartment EqCom;
    public CargoBay(){
        super();
        EqCom = new EquipmentCompartment();
        System.out.println("CargoBay just created!");
    }
    @Override
    public void process(Employee emp){
        emp.workOn(this);
        emp.workOn(EqCom);
    }
    @Override
    public int ready_check(){
        if(emp_counter == 3){
            System.out.println("CargoBay OK!");
            return 1;
        }
        return 0;
    }
    @Override
    public String toString(){
        String str = "||CargoBay: " + super.toString() + "\n||CargoBay's EquipmentCompartment: "+EqCom.toString();
        return str;
    }
    
}
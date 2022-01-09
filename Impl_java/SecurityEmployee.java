
package ergjava;

public class SecurityEmployee extends Employee{
    public SecurityEmployee(String nam){
        super(nam);
        System.out.println("SecurityEmployee just created!");
    }
        
    @Override
    public void report(EquipmentCompartment EqCom){
        System.out.println("Security Employee: EquipmentCompartment - OK");
        EqCom.emp_counter ++ ;
    }
    @Override
    public void report(CargoBay cargo){
        System.out.println("Security Employee: CargoBay - OK");
        cargo.emp_counter ++;
    }
    @Override
    public void report(PassengerCompartment Passcom){
        System.out.println("Security Employee: PassengerCompartment - OK");
        Passcom.emp_counter ++;
    }
    @Override
    public void workOn(EquipmentCompartment EqCom){
        report(EqCom);
    }
    @Override
    public void workOn(CargoBay cargo){
        report(cargo);
    }
    @Override
    public void workOn(PassengerCompartment Passcom){
        report(Passcom);
    }
    @Override
    public String toString(){
        String str = "||Security Employee: "+super.toString();
        return str;
    }
    
    
    
}

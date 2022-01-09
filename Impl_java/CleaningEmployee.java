
package ergjava;

public class CleaningEmployee extends Employee{
    public CleaningEmployee(String nam){
        super(nam);
        System.out.println("CleaningEmployee just created!");
    }
    @Override
    public void report(EquipmentCompartment EqCom){
    }
    @Override
    public void report(CargoBay cargo){
        System.out.println("Cleaning Employee: CargoBay - OK");
        cargo.emp_counter ++;
    }
    @Override
    public void report(PassengerCompartment Passcom){
        System.out.println("Cleaning Employee: PassengerCompartment - OK");
        Passcom.emp_counter ++;
    }
    @Override
    public void workOn(EquipmentCompartment EqCom){
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
        String str = "||Cleaning Employee: "+super.toString();
        return str;
    }
}

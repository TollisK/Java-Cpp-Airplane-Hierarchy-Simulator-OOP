
package ergjava;

public class MaintenanceEmployee extends Employee{
    public MaintenanceEmployee(String nam){
        super(nam);
        System.out.println("MaintenanceEmployee just created!");
    }
    @Override
    public void report(EquipmentCompartment EqCom){
        System.out.println("Maintenance Employee: EquipmentCompartment - OK");
        EqCom.emp_counter ++;
    }
    @Override
    public void report(CargoBay cargo){
        System.out.println("Maintenance Employee: CargoBay - OK");
        cargo.emp_counter ++;
    }
    @Override
    public void report(PassengerCompartment Passcom){
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
    }
    @Override
    public String toString(){
        String str = "||Maintenance Employee: "+super.toString();
        return str;
    }
}

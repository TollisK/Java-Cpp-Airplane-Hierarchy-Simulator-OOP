
package ergjava;

public class EquipmentCompartment extends PrivateCompartment{
    public EquipmentCompartment(){
        super();
        System.out.println("EquipmentCompartment just created!");
    }
    @Override
    public int ready_check(){
        if(emp_counter == 3){
            System.out.println("Equipment Compartment OK!");
            return 1;
        }
        System.out.println("EMP_COUNTER equicom =  " + emp_counter);
        return 0;
    }
    @Override
    public String toString(){
        String str = "||EquipmentCompartment: ";
        str = str.concat(super.toString());
        return str;
    }
    @Override
     public void process(Employee emp){
         emp.workOn(this);
     }
}

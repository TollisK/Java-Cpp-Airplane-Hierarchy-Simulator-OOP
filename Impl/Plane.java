
package ergjava;

public class Plane {
    protected String title;
    protected int capacity;
    protected PassengerCompartment passcom;
    protected CargoBay cargobay;
    protected EquipmentCompartment equicom1,equicom2,equicom3;
    public Plane(String nam){
        capacity = (int) (Math.random()*100 + 100);
        title = nam;
        equicom1 = new EquipmentCompartment();
        equicom2 = new EquipmentCompartment();
        equicom3 = new EquipmentCompartment();
        cargobay = new CargoBay();
        passcom = new PassengerCompartment(capacity);
        System.out.println("Plane just created!");
    }
    public void ready_check(){
        if(passcom.ready_check() == 1 && cargobay.ready_check() == 1&&equicom1.ready_check()==1&&equicom2.ready_check()==1&&equicom3.ready_check()==1){
            System.out.println("Plane is ready to take off!");
        }
        else{
            System.out.println("Plane is not ready to take off yet!");
        }
    }
    @Override
    public String toString(){
        String str = "||Plane: title = "+title + "  capacity = "+capacity;
        str = str.concat("\n");
        str = str.concat(passcom.toString());
        str = str.concat("\n");
        str = str.concat(cargobay.toString());
        str = str.concat("\n");
        str = str.concat(equicom1.toString());
        str = str.concat("\n");
        str = str.concat(equicom2.toString());
        str = str.concat("\n");
        str = str.concat(equicom3.toString());
        return str;
    }
    
    public void process(SecurityEmployee SecuEmp){
        equicom1.process(SecuEmp);
        equicom2.process(SecuEmp);
        equicom3.process(SecuEmp);
        cargobay.process(SecuEmp);
        passcom.process(SecuEmp);
    }
    public void process(MaintenanceEmployee MainEmp){
        equicom1.process(MainEmp);
        equicom2.process(MainEmp);
        equicom3.process(MainEmp);
        cargobay.process(MainEmp);
        passcom.process(MainEmp);
    }
    public void process(CleaningEmployee CleanEmp){
        equicom1.process(CleanEmp);
        equicom2.process(CleanEmp);
        equicom3.process(CleanEmp);
        cargobay.process(CleanEmp);
        passcom.process(CleanEmp);
    }
}

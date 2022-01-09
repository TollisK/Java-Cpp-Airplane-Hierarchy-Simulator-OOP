
package ergjava;

abstract public class Employee {
    protected String name;
    public Employee(String nam){
        name = nam;
        System.out.println("Employee just created!");
    }
    @Override
    public String toString(){
        String str = "||Employee: name = "+name;
        return str;
    }
    public void workOn(EquipmentCompartment eq){
        
    }
    public void workOn(CargoBay eq){
        
    }
    public void workOn(PassengerCompartment eq){
        
    }
    public void report(EquipmentCompartment eq){
        
    }
    public void report(CargoBay eq){
        
    }
    public void report(PassengerCompartment eq){
        
    }
    
}

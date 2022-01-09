
package ergjava;

public class PrivateCompartment extends PlaneComponent{
    @Override
    public String toString(){
        String str = "||PrivateComponent: ";
        str = str.concat(super.toString());
        return str;
    }
    @Override
    public int ready_check(){
        return 0;
    }
    @Override
    public void process(Employee emp){
        
    }
    
    public PrivateCompartment(){
        super();
        System.out.println("PrivateCompartment just created!");
    }
}

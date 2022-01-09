
package ergjava;


abstract public class PlaneComponent {
    protected int emp_counter;
    @Override
    public String toString(){
        String str = "||PlaneComponent: Employee counter = "+emp_counter;
        return str;
    }
    public int ready_check(){
        return 1;
    }
    public void process(Employee emp){
       
    }
    public PlaneComponent(){
        System.out.println("PlaneComponent just created!");
    }
}

package ergjava;


public class Ergjava {

    public static void main(String[] args) {
        Plane plane = new Plane("Boeing 787");
        SecurityEmployee Secuemp = new SecurityEmployee("Security");
        MaintenanceEmployee Mainemp = new MaintenanceEmployee("Maintanance");
        CleaningEmployee Cleanemp = new CleaningEmployee("Cleaning");
        plane.process(Secuemp);
        plane.process(Mainemp);
        plane.process(Secuemp);
        plane.ready_check();
    }
}

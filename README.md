# Airplane Hierarchy Simulator
This project implements a simulator of a plane, with its compartments and the hierarchy of its employees.

### Εντολή για την μεταγλώττιση του προγράμματος:
    javac Ergjava.java Plane.java PlaneComponent.java PassengerCompartment.java
    PrivateCompartment.java EquipmentCompartment.java CargoBay.java Employee.java
    CleaningEmployee.java SecurityEmployee.java MaintenanceEmployee.java

### Εκτέλεση:
    java ergjava.Ergjava

Η εργασία γράφτηκε σε NetBeans IDE 8.2 σε περιβάλλον WINDOWS 10 και δοκιμάστηκε και
μεταγλωττίστηκε σε UBUNTU


### Ergjava.java: 
Περιέχει την κύρια συνάρτηση η οποία δημιουργεί αντικείμενο plane και τρία ακόμα για κάθε είδος εργαζομένου .Επίσης, καλεί την process του αεροπλάνου για κάθε εργαζόμενο και την ready_check που αναγράφει στην έξοδο αν το αεροπλάνο είναι έτοιμο να πετάξει.
### PlaneComponent.java: 
Είναι υποκλάση της Object και περιέχει μια μεταβλητή emp_counter η οποία χρησιμεύει στην ready_check και αυξάνεται κάθε φορά που δουλεύει κάποιος εργαζόμενος.
### PassengerCompartment.java:
Είναι υποκλάση του PlaneComponent η οποία περιέχει στο ιδιωτικό μέρος και μια εσωτερική ή πολλές εσωτερικές PassengerCompartment ανάλογα την χωρητικότητα του αεροπλάνου αφού στον constructor του δημιουργείται αναδρομικά παίρνοντας έναν τυχαίο αριθμό από το 0 μέχρι την χωρητικότητα και πρέπει να είναι μεγαλύτερο του 45 για να δημιουργήσει και εσωτερικό. Επιπλέον στο ready_check κοιτάει αν έχουν περάσει και οι 2 εργαζόμενοι και στην συνάρτηση process που δέχεται ως όρισμα έναν εργαζόμενο καλεί την workOn αυτού για το ίδιο και για καθέ εσωτερικό του.
### PrivateCompartment.java:
Το Private Compartment που είναι υποκλάση του PlaneComponent αποτελεί υπερκλάση του EquipmentCompartment και του CargoBay το οποίο CargoBay περιέχει και ως ιδιωτικό μέρος και ένα πεδίο Equipment Compartment.
### Employee.java: 
Είναι abstract κλάση που έχει ένα πεδίο όνομα ορισμένο ως String και αποτελεί υπερκλάση για τα τρία είδη employee SecurityEmployee, MaintananceEmployee και CleaningEmployee. Κάθε είδος έχει μια μέθοδο workOn με όρισμα το κάθε τμήμα αεροπλάνου που δουλεύουν και καλεί την report που εκτυπώνει μήνυμα επαλήθευσης.
### Plane.java: 
Αποτελεί υποκλάση του Object και περιέχει στο ιδιωτικό κομμάτι εναν τίτλο ως συμβολοσειρά ένα πεδίο capacity που παίρνει μια τιμή τυχαία μεταξύ 100-200 και τα τμήματα του, δηλαδή ένα PassengerCompartment, ένα CargoBay και 3 EquipmentCompartment.Για την συνάρτηση ready_check καλεί κάθε ready_check των μελών του και εκτυπώνει το ανάλογο μήνυμα και τέλος έχει και μέθοδο process με ορίσματα κάθε είδος εργαζομένου που παρόμοια με την ready_check καλεί κάθε process των μελών του.
Κάθε κλάση επίσης περιέχει και την συνάρτηση toString η οποία δημιουργεί και επιστρέφει
αντικείμενο String μαζί με τις περιγραφές και όλων των κλάσεων που έχουν πρόσβαση.



#include <iostream>
#include <string>
#include <vector>
#include <limits>  

using namespace std;

class person {

protected:
    string name;
    int age;
    string address;
    string gender;
    long int NIC;
public:
    person(string Add = "") {
        NIC = 0;
        name = "";
        age = 0;
        address = Add;
    }


};

class patient : public person {

protected:
    int patientID;
    string disease;
    string admittedDate;
    string dischargedDate;
public:
    patient(int pID, string dis, string aDate, string dDate, long int nic,
        string n, int a, string add, string g)
        : person(add)
    {
        patientID = pID;
        disease = dis;
        admittedDate = aDate;
        dischargedDate = dDate;
        NIC = nic;
        name = n;
        age = a;
        gender = g;

    }

    void display() {

        cout << "\n--- Patient Details ---\n";
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "NIC: " << NIC << endl;
        cout << "Address: " << address << endl;

    }
};

struct Doctor {

    int id;
    string name;
    string specialty;
    string timeSlot;

};

vector<Doctor> doctors = {

    {1, "Dr. Perera", "Cardiologist", "9:00 AM - 11:00 AM"},
    {2, "Dr. Silva", "Dermatologist", "11:30 AM - 1:30 PM"},
    {3, "Dr. Fernando", "Neurologist", "2:00 PM - 4:00 PM"},
    {4, "Dr. Jayawardena", "Pediatrician", "4:30 PM - 6:00 PM"}

};

struct Nurse {

    int nurse_id;
    string name;
    int votes;
    string shift;

};

vector<Nurse> nurses = {

    {101, "Alice", 5, "Morning"},
    {102, "Mary", 3, "Evening"},
    {103, "Sita", 7, "Night"},
    {104, "Nimal", 2, "Morning"},
    {105, "Kavindi", 4, "Evening"}

};

struct Vote {

    int doctor_id;
    int nurse_id;
    int value; 

};

vector<Vote> votes = {

    {1, 101, 2},   // 2 votes for Alice under Dr. Perera
    {1, 104, 1},   // 1 vote for Nimal under Dr. Perera
    {2, 102, 3},   // 3 votes for Mary under Dr. Silva
    {3, 103, 4},   // 4 votes for Sita under Dr. Fernando
    {4, 105, 2}    // 2 votes for Kavindi under Dr. Jayawardena

};

vector<patient> patients;

struct Medicine {

    int id;
    string name;
    double price;
    int stock;

};

vector<Medicine> medicines = {

    {1, "Paracetamol", 50.0, 200},
    {2, "Amoxicillin", 120.0, 100},
    {3, "Vitamin C", 80.0, 150},
    {4, "Cough Syrup", 150.0, 100},
    {5, "Ibuprofen", 70.0, 150},
    {6, "Azithromycin", 200.0, 80},
    {7, "Omeprazole", 100.0, 120},
    {8, "Cetirizine", 60.0, 200},
    {9, "Metformin", 90.0, 100},
    {10, "Insulin", 500.0, 50},
    {11, "Salbutamol Inhaler", 350.0, 70},
    {12, "Doxycycline", 150.0, 100},
    {13, "Hydrocortisone Cream", 120.0, 80},
    {14, "Folic Acid", 40.0, 200},
    {15, "Paracetamol + Codeine", 90.0, 100},
    {16, "Diclofenac", 80.0, 150},
    {17, "Loratadine", 60.0, 200},
    {18, "Aspirin", 50.0, 180},
    {19, "Saline Solution", 120.0, 100},
    {20, "Ranitidine", 100.0, 120}

};



void makeAppointment(Doctor d) {

    cout << "\n--- Appointment Confirmation ---\n";
    cout << "Doctor: " << d.name << endl;
    cout << "Specialty: " << d.specialty << endl;
    cout << "Time Slot: " << d.timeSlot << endl;
    cout << "Your appointment has been booked!\n";

}

void showDoctorTimetable() {

    cout << "\n--- Doctor Timetable ---\n";
    for (auto& d : doctors) {
        cout << d.id << ". " << d.name
            << " | " << d.specialty
            << " | " << d.timeSlot << endl;
    }

    int choice;
    cout << "\nEnter Doctor ID to make an appointment (0 to cancel): ";
    cin >> choice;

    if (choice > 0 && choice <= doctors.size()) {
        makeAppointment(doctors[choice - 1]);
    }
    else if (choice == 0) {
        cout << "Appointment cancelled.\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

}


void patient_registration() {

    string name, address, gender;
    int age;
    long int NIC;

    cout << "\n--- Patient Registration ---\n";

    cout << "Name: ";
    cin.ignore();
	getline(cin, name);
    
    cout << "Age: ";
    cin >> age;
    cin.ignore(); 

    cout << "Address: ";
    getline(cin, address);

    cout << "Gender: ";
    cin >> gender;
    cin.ignore(); 

    cout << "NIC: ";
    cin >> NIC;
    cin.ignore(); 
    
    patient p((int)patients.size() + 1, "N/A", "Today", "N/A", NIC, name, age, address, gender);
    patients.push_back(p);

    cout << "\nPatient Registration Successful!\n";
    p.display();


}


void admin() {

    string password;
	cout << "enter admin password: ";
	cin >> password;

    if (password == "admin123") {

		int choice;

        cout << "\n--- Admin Section ---\n";

        cout << "What do you want to see?" << endl;
        cout << "1. Patient " << endl;
        cout << "2. Doctor " << endl;
		cout << "3. Nurse " << endl;
		cout << "4. Vote" << endl;
		cout << "5. Medicine" << endl;
		cout << "6. Exit Admin Section" << endl;

        cout << "Enter your choice: ";
		cin >> choice;

        if (choice == 1) {
            cout << "\n--- Patient List ---\n";
            for (auto& p : patients) {
                p.display();
                cout << "---------------------\n";
            }
        }
        else if (choice == 2) {
            cout << "\n--- Doctor List ---\n";
            for (auto& d : doctors) {
                cout << "Doctor ID: " << d.id << endl;
                cout << "Name: " << d.name << endl;
                cout << "Specialty: " << d.specialty << endl;
                cout << "Time Slot: " << d.timeSlot << endl;
                cout << "---------------------\n";
            }
		}
        else if (choice == 3) {
            cout << "\n--- Nurse List ---\n";
            for (auto& n : nurses) {
                cout << "Nurse ID: " << n.nurse_id << endl;
                cout << "Name: " << n.name << endl;
                cout << "Votes: " << n.votes << endl;
                cout << "Shift: " << n.shift << endl;
                cout << "---------------------\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- Vote List ---\n";
            for (auto& v : votes) {
                cout << "Doctor ID: " << v.doctor_id << endl;
                cout << "Nurse ID: " << v.nurse_id << endl;
                cout << "Vote Value: " << v.value << endl;
                cout << "---------------------\n";
            }
        }
        else if (choice == 5) {
            cout << "\n--- Medicine List ---\n";
            for (auto& m : medicines) {
                cout << "Medicine ID: " << m.id << endl;
                cout << "Name: " << m.name << endl;
                cout << "Price: " << m.price << endl;
                cout << "Stock: " << m.stock << endl;
                cout << "---------------------\n";
            }
        }
        else if (choice == 6) {
            cout << "\nExiting Admin Section...\n";
		}
        else {
            cout << "Invalid choice.\n";
        }  
    }

    else {
        cout << "Incorrect password. Access denied.\n";
        
    }

}

void OrderMedicineList() {

    int choice, qty;
    double grandTotal = 0; 

    do {
        cout << "\n--- Medicine List ---\n";
        for (auto& m : medicines) {
            cout << m.id << ". " << m.name
                << " | Price: Rs." << m.price
                << " | Stock: " << m.stock << endl;
        }

        cout << "Enter Medicine ID to order (0 to finish): ";
        cin >> choice;

        if (choice == 0) break;

        if (choice > 0 && choice <= medicines.size()) {
            cout << "Enter quantity: ";
            cin >> qty;

            if (qty <= medicines[choice - 1].stock) {
                double total = qty * medicines[choice - 1].price;
                grandTotal += total;
                medicines[choice - 1].stock -= qty;
                cout << "\nOrder Successful!\n";
                cout << "Medicine: " << medicines[choice - 1].name << endl;
                cout << "Quantity: " << qty << endl;
                cout << "Subtotal: Rs." << total << endl;
            }
            else {
                cout << "Not enough stock available.\n";
            }
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (true);

    cout << "\nYour total cost (without delivery): Rs." << grandTotal << endl;

    int deliveryOption;
    cout << "Do you want home delivery? (1 = Yes, 0 = No): ";
    cin >> deliveryOption;

    if (deliveryOption == 1) {
        string deliveryAddress;
        int distance;

        cout << "Enter your delivery address: ";
        cin.ignore();
        getline(cin, deliveryAddress);

        cout << "How many kilometers is your address from the hospital? ";
        cin >> distance;

        if (distance > 50) {
            grandTotal += 500;
            cout << "Delivery fee Rs.500 added.\n";
            cout << "Delivery in 3-5 business days.\n";
        }
        else {
            grandTotal += 300;
            cout << "Delivery fee Rs.300 added.\n";
            cout << "Delivery in 2-3 business days.\n";
        }
    }
    else {
        cout << "You chose to pick up the medicine from the hospital pharmacy.\n";
    }

    cout << "\nFinal Total: Rs." << grandTotal << endl;

}


void menu(int choice) {

    if (choice == 1) {
        patient_registration();
    }
    else if (choice == 2) {
        showDoctorTimetable();
    }
    else if (choice == 3) {
        OrderMedicineList(); 
    }
    else if (choice == 4) {
        admin();
    }
    else if (choice == 5) {
        cout << "\nThank you for joining with us. \n";
        cout << "\nExisting program...\n";
    }
    else {
        cout << "Invalid choice\n";
    }

}



int main() {

    int choice;

    do {
        cout << "\n" << "                                  ================================= \n";
        cout << "                                            SIRILOKA HOSPITAL        \n";
        cout << "                                  =================================\n";

        cout << "How can I help you today ?" << endl;
        cout << "  1. Patient Registration" << endl;
        cout << "  2. Make an appointment" << endl;
        cout << "  3. Order Medicine" << endl;
        cout << "  4. For Admin" << endl;
        cout << "  5. Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        menu(choice);

    } while (choice != 5);



    return 0;

}

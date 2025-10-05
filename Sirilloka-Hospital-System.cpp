#include <iostream>
#include <string>
#include <vector>
#include <limits>  // add at the top for numeric_limits

using namespace std;

// ================== Person Class ==================
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

// ================== Patient Class ==================
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

// ================== Doctor Struct ==================
struct Doctor {
    int id;
    string name;
    string specialty;
    string timeSlot;
};

// Doctor timetable
vector<Doctor> doctors = {
    {1, "Dr. Perera", "Cardiologist", "9:00 AM - 11:00 AM"},
    {2, "Dr. Silva", "Dermatologist", "11:30 AM - 1:30 PM"},
    {3, "Dr. Fernando", "Neurologist", "2:00 PM - 4:00 PM"},
    {4, "Dr. Jayawardena", "Pediatrician", "4:30 PM - 6:00 PM"}
};

// ================== Global Data ==================
vector<patient> patients;

// ================== Functions ==================
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
    cin >> name;
    cin.ignore();

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
    cout << "\n--- Admin Section ---\n";
    cout << "What do you want to see?" << endl;
	cout << "1. Patient List" << endl;
    cout << "2. Doctor Timetable" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "\n--- Patient List ---\n";
        for (auto& p : patients) {
            p.display();
            cout << "---------------------\n";
        }
    }
    else if (choice == 2) {
        cout << "\n--- Doctor Timetable ---\n";
        for (auto& d : doctors) {
            cout << d.id << ". " << d.name
                << " | " << d.specialty
                << " | " << d.timeSlot << endl;
        };
    }
    else {
        cout << "Invalid choice.\n";
	}

}

void menu(int choice) {
    if (choice == 1) {
        patient_registration();
    }
    else if (choice == 2) {
        showDoctorTimetable();
    }
    else if (choice == 3) {
        cout << "\nOrder Medicine option coming soon...\n";
    }
    else if (choice == 4) {
        admin();
    }
    else if (choice == 5) {
        cout << "\nExiting program...\n";
    }
    else {
        cout << "Invalid choice\n";
    }
}


int main() {
    int choice;
    do {
        cout << "\n" << "                                  ================================= \n";
        cout << "                                             SIRILOKA HOSPITAL        \n";
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

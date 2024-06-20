#include <iostream>
#include <string>
using namespace std;

struct Patient
{
	int id;
	string name;
	string dob;
	char gender;
};

struct Doctor
{
	int id;
	string name;
	string specialization;
};

struct Appointment
{
	int id;
	int patient;
	int doctor;
	string date;
};

// A template class for creating a generic linked list
template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node *next;
	};

public:
	// Constructor
	LinkedList() : head(nullptr) {}

	~LinkedList()
	{
		while (head != nullptr)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Function to add a new node at the end of the list
	void add(T data)
	{
		Node *newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node *current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

private:
	Node *head;
};

int main()
{
	// Create a linked list to store patients
	LinkedList<Patient> patientList;
	LinkedList<Doctor> doctorList;
	LinkedList<Appointment> appointmentList;

	while (true)
	{
		// Display the menu
		cout << "1. Register a patient" << endl;
		cout << "2. Register a doctor" << endl;
		cout << "3. Register an appointment" << endl;
		cout << "4. Display patients" << endl;
		cout << "5. Display doctors" << endl;
		cout << "6. Display appointments" << endl;
		cout << "7. Exit" << endl;

		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		cout << endl;

		// Process the user's choice
		switch (choice)
		{
		case 1:
		{
			Patient newPatient;
			cout << "Enter patient ID: ";
			cin >> newPatient.id;
			cout << "Enter patient name: ";
			cin.ignore(); // Ignore the newline character
			getline(cin, newPatient.name);
			cout << "Enter patient DOB: ";
			cin >> newPatient.dob;
			cout << "Enter patient gender (M/F): ";
			cin >> newPatient.gender;

			patientList.add(newPatient);
			break;
		}
		case 2:
		{
			Doctor newDoctor;
			cout << "Enter doctor ID: ";
			cin >> newDoctor.id;
			cout << "Enter doctor name: ";
			cin.ignore(); // Ignore the newline character
			getline(cin, newDoctor.name);
			cout << "Enter doctor specialization: ";
			cin >> newDoctor.specialization;

			doctorList.add(newDoctor);
			break;
		}
		case 3:
		{
			Appointment newAppointment;
			cout << "Enter appointment ID: ";
			cin >> newAppointment.id;
			cout << "Enter patient ID: ";
			cin >> newAppointment.patient;
			cout << "Enter doctor ID: ";
			cin >> newAppointment.doctor;

			appointmentList.add(newAppointment);
			break;
		}
		case 4:
		{
			break;
		}
			//			case 5:
			//				patientList.print();
			//				break;
			//			case 6:
			//				patientList.print();
			//				break;
		case 7:
			cout << "Exited the program!" << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	return 0;
}

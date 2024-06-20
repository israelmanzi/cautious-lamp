#include <iostream>
#include <string>
using namespace std;

// Function to validate date format (yyyy-mm-dd)
bool validateDate(const string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	return true;
}

// Function to display the main menu
void displayMenu()
{
	cout << "::MAIN MENU::" << endl;
	cout << "1. Register a Patient" << endl;
	cout << "2. Register a Doctor" << endl;
	cout << "3. Register an Appointment" << endl;
	cout << "4. Display Patients" << endl;
	cout << "5. Display Doctors" << endl;
	cout << "6. Display Appointments" << endl;
	cout << "7. Exit" << endl;
}

// Class representing an appointment
class Appointment
{
public:
	int appointmentID;
	int patientID;
	int doctorID;
	string appointmentDate;

	// Default constructor
	Appointment() : appointmentID(0), patientID(0), doctorID(0), appointmentDate("default") {}

	// Parameterized constructor
	Appointment(int id, int pID, int dID, const string &date)
		: appointmentID(id), patientID(pID), doctorID(dID), appointmentDate(date) {}
};

// Class representing a doctor
class Doctor
{
public:
	int doctorID;
	string name;
	string specialization;

	// Default constructor
	Doctor() : doctorID(0), name("default"), specialization("default") {}

	// Parameterized constructor
	Doctor(int id, const string &docName, const string &docSpecialization)
		: doctorID(id), name(docName), specialization(docSpecialization) {}
};

// Class representing a patient
class Patient
{
public:
	int patientID;
	string name;
	string dateOfBirth;
	string gender;

	// Default constructor
	Patient() : patientID(0), name("default"), dateOfBirth("default"), gender("default") {}

	// Parameterized constructor
	Patient(int id, const string &patName, const string &dob, const string &patGender)
		: patientID(id), name(patName), dateOfBirth(dob), gender(patGender) {}
};

// Linked list node for patients
class PatientNode
{
public:
	Patient patient;
	PatientNode *next;

	// Default constructor
	PatientNode() : patient(), next(nullptr) {}

	// Parameterized constructor
	PatientNode(const Patient &pat) : patient(pat), next(nullptr) {}

	// Function to add a patient to the list
	PatientNode *addPatient(const Patient &pat)
	{
		PatientNode *currentNode = this;
		while (currentNode != nullptr)
		{
			if (currentNode->patient.patientID == pat.patientID)
			{
				cout << "Patient with ID " << pat.patientID << " already exists" << endl;
				return nullptr;
			}
			currentNode = currentNode->next;
		}

		PatientNode *newNode = new PatientNode(pat);
		if (this->patient.patientID == 0)
		{
			this->patient = pat;
			return this;
		}

		PatientNode *temp = this;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return newNode;
	}

	// Function to display all patients
	void displayPatients()
	{
		cout << endl
			 << "PATIENTS" << endl;
		PatientNode *currentNode = this;
		if (currentNode->patient.patientID == 0)
		{
			cout << "No Patients available" << endl;
			return;
		}
		while (currentNode != nullptr)
		{
			cout << "Patient ID: " << currentNode->patient.patientID << ", "
				 << "Name: " << currentNode->patient.name << ", "
				 << "Date of Birth: " << currentNode->patient.dateOfBirth << ", "
				 << "Gender: " << currentNode->patient.gender << endl;
			currentNode = currentNode->next;
		}
		cout << endl;
	}

	// Function to search for a patient by ID
	PatientNode *searchPatient(int patID)
	{
		PatientNode *currentNode = this;
		while (currentNode != nullptr)
		{
			if (currentNode->patient.patientID == patID)
			{
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		return nullptr;
	}
};

// Linked list node for doctors
class DoctorNode
{
public:
	Doctor doctor;
	DoctorNode *next;

	// Default constructor
	DoctorNode() : doctor(), next(nullptr) {}

	// Parameterized constructor
	DoctorNode(const Doctor &doc) : doctor(doc), next(nullptr) {}

	// Function to add a doctor to the list
	DoctorNode *addDoctor(const Doctor &doc)
	{
		DoctorNode *currentNode = this;
		while (currentNode != nullptr)
		{
			if (currentNode->doctor.doctorID == doc.doctorID)
			{
				cout << "Doctor with ID " << doc.doctorID << " already exists" << endl;
				return nullptr;
			}
			currentNode = currentNode->next;
		}

		DoctorNode *newNode = new DoctorNode(doc);
		if (this->doctor.doctorID == 0)
		{
			this->doctor = doc;
			return this;
		}

		DoctorNode *temp = this;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return this;
	}

	// Function to display all doctors
	void displayDoctors()
	{
		cout << endl
			 << "DOCTORS" << endl;
		DoctorNode *currentNode = this;
		if (currentNode->doctor.doctorID == 0)
		{
			cout << "No Doctors available" << endl;
			return;
		}
		while (currentNode != nullptr)
		{
			cout << "Doctor ID: " << currentNode->doctor.doctorID << ", "
				 << "Name: " << currentNode->doctor.name << ", "
				 << "Specialization: " << currentNode->doctor.specialization << endl;
			currentNode = currentNode->next;
		}
		cout << endl;
	}

	// Function to search for a doctor by ID
	DoctorNode *searchDoctor(int docID)
	{
		DoctorNode *currentNode = this;
		while (currentNode != nullptr)
		{
			if (currentNode->doctor.doctorID == docID)
			{
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		return nullptr;
	}
};

// Linked list node for appointments
class AppointmentNode
{
public:
	Appointment appointment;
	AppointmentNode *next;

	// Default constructor
	AppointmentNode() : appointment(), next(nullptr) {}

	// Parameterized constructor
	AppointmentNode(const Appointment &apt) : appointment(apt), next(nullptr) {}

	// Function to search for a doctor by ID
	DoctorNode *searchDoctor(int docID, DoctorNode *docHead)
	{
		return docHead->searchDoctor(docID);
	}

	// Function to search for a patient by ID
	PatientNode *searchPatient(int patID, PatientNode *patHead)
	{
		return patHead->searchPatient(patID);
	}

	// Function to add an appointment to the list
	AppointmentNode *addAppointment(const Appointment &apt, DoctorNode *docHead, PatientNode *patHead)
	{
		AppointmentNode *currentNode = this;
		while (currentNode != nullptr)
		{
			if (currentNode->appointment.appointmentID == apt.appointmentID)
			{
				cout << "Appointment with ID " << apt.appointmentID << " already exists" << endl;
				return nullptr;
			}
			currentNode = currentNode->next;
		}

		DoctorNode *doc = searchDoctor(apt.doctorID, docHead);
		if (doc == nullptr)
		{
			cout << "Doctor with ID " << apt.doctorID << " does not exist" << endl;
			return nullptr;
		}

		PatientNode *pat = searchPatient(apt.patientID, patHead);
		if (pat == nullptr)
		{
			cout << "Patient with ID " << apt.patientID << " does not exist" << endl;
			return nullptr;
		}

		AppointmentNode *newNode = new AppointmentNode(apt);
		if (this->appointment.appointmentID == 0)
		{
			this->appointment = apt;
			return this;
		}

		AppointmentNode *temp = this;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return this;
	}

	// Function to display all appointments
	void displayAppointments()
	{
		cout << endl
			 << "APPOINTMENTS" << endl;
		AppointmentNode *currentNode = this;
		if (currentNode->appointment.appointmentID == 0)
		{
			cout << "No Appointments available" << endl;
			return;
		}
		while (currentNode != nullptr)
		{
			cout << "Appointment ID: " << currentNode->appointment.appointmentID << ", "
				 << "Doctor ID: " << currentNode->appointment.doctorID << ", "
				 << "Patient ID: " << currentNode->appointment.patientID << ", "
				 << "Date: " << currentNode->appointment.appointmentDate << endl;
			currentNode = currentNode->next;
		}
		cout << endl;
	}
};

int main()
{
	int choice;
	PatientNode *patientList = new PatientNode();
	DoctorNode *doctorList = new DoctorNode();
	AppointmentNode *appointmentList = new AppointmentNode();

	do
	{
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int id;
			string name, dob, gender;
			cout << "Enter patient ID: ";
			cin >> id;
			cout << "Enter patient name: ";
			cin >> name;
			cout << "Enter patient date of birth (yyyy-mm-dd): ";
			cin >> dob;
			while (!validateDate(dob))
			{
				cout << "Invalid date format. Please enter again (yyyy-mm-dd): ";
				cin >> dob;
			}
			cout << "Enter patient gender: ";
			cin >> gender;
			Patient newPatient(id, name, dob, gender);
			patientList->addPatient(newPatient);
			break;
		}
		case 2:
		{
			int id;
			string name, specialization;
			cout << "Enter doctor ID: ";
			cin >> id;
			cout << "Enter doctor name: ";
			cin >> name;
			cout << "Enter doctor specialization: ";
			cin >> specialization;
			Doctor newDoctor(id, name, specialization);
			doctorList->addDoctor(newDoctor);
			break;
		}
		case 3:
		{
			int id, patID, docID;
			string date;
			cout << "Enter appointment ID: ";
			cin >> id;
			cout << "Enter patient ID: ";
			cin >> patID;
			cout << "Enter doctor ID: ";
			cin >> docID;
			cout << "Enter appointment date (yyyy-mm-dd): ";
			cin >> date;
			while (!validateDate(date))
			{
				cout << "Invalid date format. Please enter again (yyyy-mm-dd): ";
				cin >> date;
			}
			Appointment newAppointment(id, patID, docID, date);
			appointmentList->addAppointment(newAppointment, doctorList, patientList);
			break;
		}
		case 4:
			patientList->displayPatients();
			break;
		case 5:
			doctorList->displayDoctors();
			break;
		case 6:
			appointmentList->displayAppointments();
			break;
		case 7:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
			break;
		}
	} while (choice != 7);

	return 0;
}

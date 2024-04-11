#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50

struct Patient {
    int id;
    char fullName[MAX_NAME_LENGTH];
    int age;
    int roomNumber;
};

struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

void registerPatient(char fullName[], int age, int roomNumber) {
    if (patientCount < MAX_PATIENTS) {
        patients[patientCount].id = patientCount + 1;
        strcpy(patients[patientCount].fullName, fullName);
        patients[patientCount].age = age;
        patients[patientCount].roomNumber = roomNumber;
        patientCount++;
        printf("Patient registered successfully.\n");
    } else {
        printf("Maximum patient limit reached.\n");
    }
}

void displayPatients() {
    if (patientCount == 0) {
        printf("No patients registered.\n");
    } else {
        printf("Registered Patients:\n");
        printf("%-5s %-20s %-5s %-10s\n", "ID", "Full Name", "Age", "Room Number");
        for (int i = 0; i < patientCount; i++) {
            printf("%-5d %-20s %-5d %-10d\n", patients[i].id, patients[i].fullName, patients[i].age, patients[i].roomNumber);
        }
    }
}

void searchPatient(char searchKey[]) {
    int found = 0;
    printf("Search Results:\n");
    printf("%-5s %-20s %-5s %-10s\n", "ID", "Full Name", "Age", "Room Number");
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].fullName, searchKey) == 0 ||
            patients[i].age == atoi(searchKey) ||
            patients[i].roomNumber == atoi(searchKey)) {
            found = 1;
            printf("%-5d %-20s %-5d %-10d\n", patients[i].id, patients[i].fullName, patients[i].age, patients[i].roomNumber);
        }
    }
    if (!found) {
        printf("No matching patients found.\n");
    }
}

int main() {
    int choice;
    char fullName[MAX_NAME_LENGTH];
    int age, roomNumber;
    char searchKey[MAX_NAME_LENGTH];

    do {
        printf("\n1. Register Patient\n2. Display Patients\n3. Search Patient\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient's full name: ");
                scanf(" %[^\n]s", fullName); // Read full name with spaces
                printf("Enter patient's age: ");
                scanf("%d", &age);
                printf("Enter patient's room number: ");
                scanf("%d", &roomNumber);
                registerPatient(fullName, age, roomNumber);
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Enter search key (name, age, or room number): ");
                scanf(" %[^\n]s", searchKey); // Read search key with spaces
                searchPatient(searchKey);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

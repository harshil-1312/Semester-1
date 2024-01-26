
//***************************************************************************** 
// Full Name  : Harshil Prajapati
//student ID#: 175255215
//Email       : hprajapati8@myseneca.ca
//Section    :IPC144ZRA.5605.2227
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation
//***************************************************************************** 


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


void displayAllPatients(const struct Patient patient[], int Maximum, int FMT)
{
    int i = 0;
    int dis_no = 0;
    displayPatientTableHeader();
    for (i = 0; i < Maximum; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], FMT);
            dis_no++;
        }
    }
    if (dis_no == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}



// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


void searchPatientData(const struct Patient patient[], int Maximum)
{
    char phoneNumber[PHONE_LEN];
    int Result = 0;
    int i = 0;
    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    printf("\n");
    for (i = 0; i < Maximum; i++)
    {
        if (patient[i].patientNumber != 0 && strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            Result = 1;
        }
    }
    if (Result == 0)
    {
        printf("\n*** No records found ***\n");
    }
    putchar('\n');
}
// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int Maximum)
{
    int i = 0;
    int ind_x = -1;
    for (i = 0; i < Maximum && ind_x == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            ind_x = i;
        }
    }
    if (ind_x == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[ind_x].patientNumber = nextPatientNumber(patient, Maximum);
        inputPatient(&patient[ind_x]);
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int Maximum)
{
    printf("Enter the patient number: ");
    int patient_no = inputInt();


    putchar('\n');

    int ind_x = findPatientIndexByPatientNum(patient_no, patient, Maximum);


    if (ind_x == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }


    else
    {
        menuPatientEdit(&patient[ind_x]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int Maximum)
{
    printf("Enter the patient number: ");
    int patient_no = inputInt();

    int ind_x = findPatientIndexByPatientNum(patient_no, patient, Maximum);
    if (ind_x == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        putchar('\n');
        displayPatientData(&patient[ind_x], FMT_FORM);

        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        int Result_r = inputCharOption("yn");

        if (Result_r == 'y')
        {
            patient[ind_x].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int Maximum)
{

    printf("Search by patient number: ");
    int patient_no = inputInt();
    putchar('\n');
    int ind_x = findPatientIndexByPatientNum(patient_no, patient, Maximum);
    if (ind_x == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&patient[ind_x], FMT_FORM);
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int Maximum)
{
    int i = 0;

    char Call_Entries[11] = {0};


    int display_num = 0;


    printf("Search by phone number: ");

    inputCString(Call_Entries, 11, 11);

    putchar('\n');

    displayPatientTableHeader();

    for (i = 0; i < Maximum; i++)
    {
        if (strcmp(Call_Entries, patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            display_num++;
        }
    }
    if (display_num == 0)
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int Maximum)
{
    int i = 0;
    int maximum = patient[i].patientNumber;
    for (i = 1; i < Maximum; i++)
    {
        if (patient[i].patientNumber > maximum)
            maximum = patient[i].patientNumber;
    }
    return maximum + 1;
}
// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int Maximum)
{
    int i = 0;
    int done = -1;
    for (i = 0; i < Maximum && done == -1; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            done = i;
        }
    }

    return done;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n------------------\nNumber: %05d\nName  : ", patient->patientNumber);
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone *Phone)
{

    printf("Phone Information\n-----------------\nHow will the patient like to be contacted?\n1. Cell\n2. Home\n3. Work\n4. TBD\nSelection: ");
    int select = inputInt(1, 4);
    putchar('\n');
    if (select == 4)
    {
        strcpy(Phone->description, "TBD");
        Phone->number[0] = 0;
    }
    else
    {
        if (select == 1)
            strcpy(Phone->description, "CELL");
        if (select == 2)
            strcpy(Phone->description, "HOME");
        if (select == 3)
            strcpy(Phone->description, "WORK");
        printf("Contact: %s\n", Phone->description);
        printf("Number : ");
        inputCString(Phone->number, 10, 10);
        putchar('\n');
    }
}
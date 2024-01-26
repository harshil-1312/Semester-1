/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Smit Anjaykumar Patel
Student ID#: 104424213
Email      : sapatel59@myseneca.ca
Section    : IPC144NMM.10348.2221
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


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
    printf("Pat.# Name            Phone#\n");
    printf("----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patients pet *Patients, int FMT)
{
    if (FMT == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               Patients->Name_n, Patients->patient_Number);
        displayFormattedPhone(Patients->Phone_p.number);
        printf(" (%s)\n", Patients->Phone_p.description);
    }
    else
    {
        printf("%05d %-15s ", Patients->patient_Number,
               Patients->Name_n);
        displayFormattedPhone(Patients->Phone_p.number);
        printf(" (%s)\n", Patients->Phone_p.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *Data_data)
{
    int Sele_ction;

    do
    {
        printf("Veterinary Clinic System\n");
        printf("=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n");
        printf("0) Exit System\n"
               "-------------------------\n"
               "Selection: ");


        Sele_ction = inputIntRange(0, 2);
        putchar('\n');
        switch (Sele_ction)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            Sele_ction = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!Sele_ction)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(Data_data->Patients_p, Data_data->max_Patient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (Sele_ction);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patients pet Patients[], int Maximum)
{
    int Sele_ction;

    do
    {
        printf("Patient Management\n");
        printf("=========================\n"
               "1) VIEW   Patient Data\n");
        printf("2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n");
        printf("-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        Sele_ction = inputIntRange(0, 5);
        putchar('\n');
        switch (Sele_ction)
        {
        case 1:
            displayAllPatients(Patients, Maximum, FMT_tables_fmt);
            suspend();
            break;
        case 2:
            searchPatientData(Patients, Maximum);
            break;
        case 3:
            addPatient(Patients, Maximum);
            suspend();
            break;
        case 4:
            editPatient(Patients, Maximum);
            break;
        case 5:
            removePatient(Patients, Maximum);
            suspend();
            break;
        }
    } while (Sele_ction);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patients pet *Patients)
{
    int Sele_ction;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               Patients->patient_Number, Patients->Name_n);

        displayFormattedPhone(Patients->Phone_p.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n");
        printf("-------------------------\n"
               "Selection: ");

        Sele_ction = inputIntRange(0, 2);
        putchar('\n');

        if (Sele_ction == 1)
        {
            printf("Name  : ");
            inputCString(Patients->Name_n, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (Sele_ction == 2)
        {
            inputPhoneData(&Patients->Phone_p);
            printf("Patient record updated!\n\n");
        }

    } while (Sele_ction);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patients pet Patients[], int Maximum, int FMT)
{
    int Xx = 0;
    int dis_played_No = 0;
    displayPatientTableHeader();
    for (Xx = 0; Xx < Maximum; Xx++)
    {
        if (Patients[Xx].patient_Number != 0)
        {
            displayPatientData(&Patients[Xx], FMT);
            dis_played_No++;
        }
    }
    if (dis_played_No == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patients pet Patients[], int Maximum)
{
    int sele_ction = -1;
    do
    {
        printf("Search Options\n==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");


        sele_ction = inputInt(0, 2);
        putchar('\n');
        if (sele_ction == 1)
        {
            searchPatientByPatientNumber(Patients, Maximum);
            putchar('\n');
            suspend();
        }
        if (sele_ction == 2)
        {
            searchPatientByPhoneNumber(Patients, Maximum);
            putchar('\n');
            suspend();
        }

    } while (sele_ction != 0);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patients pet Patients[], int Maximum)
{
    int Xx = 0;
    int I_index = -1;
    for (Xx = 0; Xx < Maximum && I_index == -1; Xx++)
    {
        if (Patients[Xx].patient_Number == 0)
        {
            I_index = Xx;
        }
    }
    if (I_index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        Patients[I_index].patient_Number = nextPatientNumber(Patients, Maximum);
        inputPatient(&Patients[I_index]);
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patients pet Patients[], int Maximum)
{
    printf("Enter the patient number: ");
    int Patient_numb = inputInt();


    putchar('\n');

    int i_index = findPatientIndexByPatientNum(Patient_numb, Patients, Maximum);


    if (i_index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }


    else
    {
        menuPatientEdit(&Patients[i_index]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patients pet Patients[], int Maximum)
{
    printf("Enter the patient number: ");
    int Patient_Num = inputInt();

    int i_index = findPatientIndexByPatientNum(Patient_Num, Patients, Maximum);
    if (i_index == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        putchar('\n');
        displayPatientData(&Patients[i_index], FMT_FORM);

        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        int Result_r = inputCharOption("yn");

        if (Result_r == 'y')
        {
            Patients[i_index].patient_Number = 0;
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
void searchPatientByPatientNumber(const struct Patients pet Patients[], int Maximum)
{

    printf("Search by patient number: ");
    int patient_Num = inputInt();
    putchar('\n');
    int i_index = findPatientIndexByPatientNum(patient_Num, Patients, Maximum);
    if (i_index == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&Patients[i_index], FMT_FORM);
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patients pet Patients[], int max)
{
    int Xx = 0;

    char Phone_Entries[11] = {0};


    int displayed_No = 0;


    printf("Search by phone number: ");

    inputCString(Phone_Entries, 10, 10);

    putchar('\n');

    displayPatientTableHeader();

    for (Xx = 0; Xx < max; Xx++)
    {
        if (strcmp(Phone_Entries, Patients[Xx].Phone_p.number) == 0)
        {
            displayPatientData(&Patients[Xx], FMT_tables_fmt);
            displayed_No++;
        }
    }
    if (displayed_No == 0)
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patients pet Patients[], int Maximum)
{
    int Xx = 0;
    int maximum = Patients[Xx].patient_Number;
    for (Xx = 1; Xx < Maximum; Xx++)
    {
        if (Patients[Xx].patient_Number > maximum)
            maximum = Patients[Xx].patient_Number;
    }
    return maximum + 1;
}
// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patients pet Patients[], int Maximum)
{
    int Xx = 0;
    int Result_r = -1;
    for (Xx = 0; Xx < Maximum && Result_r == -1; Xx++)
    {
        if (patientNumber == Patients[Xx].patient_Number)
        {
            Result_r = Xx;
        }
    }

    return Result_r;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patients pet *Patients)
{
    printf("Patient Data Input\n------------------\nNumber: %05d\nName  : ", Patients->patient_Number);
    inputCString(Patients->Name_n, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&Patients->Phone_p);
    printf("*** New patient record added ***\n\n");
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone_p *Phone_p)
{

    printf("Phone Information\n-----------------\nHow will the patient like to be contacted?\n1. Cell\n2. Home\n3. Work\n4. TBD\nSelection: ");
    int sele_ction = inputInt(1, 4);
    putchar('\n');
    if (sele_ction == 4)
    {
        strcpy(Phone_p->description, "TBD");
        Phone_p->number[0] = 0;
    }
    else
    {
        if (sele_ction == 1)
            strcpy(Phone_p->description, "CELL");
        if (sele_ction == 2)
            strcpy(Phone_p->description, "HOME");
        if (sele_ction == 3)
            strcpy(Phone_p->description, "WORK");
        printf("Contact: %s\n", Phone_p->description);
        printf("Number : ");
        inputCString(Phone_p->number, 10, 10);
        putchar('\n');
    }
}
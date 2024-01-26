
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection = -1;
    do
    {
        printf("Search Options\n==========================\n1) By patient number\n2) By phone number\n..........................\n0) Previous menu\n..........................\nSelection: ");
        selection = inputInt(0, 2);
        putchar('\n');
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }

    } while (selection != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)

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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* clinic_Data)
{
    int i,j;
    struct Appointment end;

    //sort by year

    for (i = clinic_Data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (clinic_Data->appointments[j].date.year > clinic_Data->appointments[j + 1].date.year)
            {
                end = clinic_Data->appointments[j];
                clinic_Data->appointments[j] = clinic_Data->appointments[j + 1];
                clinic_Data->appointments[j + 1] = end;
            }
        }
    }

    //sort by month

    for (i = clinic_Data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (clinic_Data->appointments[j].date.year == clinic_Data->appointments[j + 1].date.year
               
                && clinic_Data->appointments[j].date.month > clinic_Data->appointments[j + 1].date.month)
            {
                end = clinic_Data->appointments[j];
                
                clinic_Data->appointments[j] = clinic_Data->appointments[j + 1];
                
                clinic_Data->appointments[j + 1] = end;
            }
        }
    }

    //sort by day

    for (i = clinic_Data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (clinic_Data->appointments[j].date.year == clinic_Data->appointments[j + 1].date.year
                && clinic_Data->appointments[j].date.month == clinic_Data->appointments[j + 1].date.month
                && clinic_Data->appointments[j].date.day > clinic_Data->appointments[j + 1].date.day)
            {
                end = clinic_Data->appointments[j];
                clinic_Data->appointments[j] = clinic_Data->appointments[j + 1];
                clinic_Data->appointments[j + 1] = end;
            }
        }
    }

    //sort by hour

    for (i = clinic_Data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (clinic_Data->appointments[j].date.year == clinic_Data->appointments[j + 1].date.year

                && clinic_Data->appointments[j].date.month == clinic_Data->appointments[j + 1].date.month
                
                && clinic_Data->appointments[j].date.day == clinic_Data->appointments[j + 1].date.day
                
                && clinic_Data->appointments[j].time.hour > clinic_Data->appointments[j + 1].time.hour)
            {
                end = clinic_Data->appointments[j];
                clinic_Data->appointments[j] = clinic_Data->appointments[j + 1];
                clinic_Data->appointments[j + 1] = end;
            }
        }
    }

    // sort by minute

    for (i = clinic_Data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (clinic_Data->appointments[j].date.year == clinic_Data->appointments[j + 1].date.year

                && clinic_Data->appointments[j].date.month == clinic_Data->appointments[j + 1].date.month
                
                && clinic_Data->appointments[j].date.day == clinic_Data->appointments[j + 1].date.day
                
                && clinic_Data->appointments[j].time.hour == clinic_Data->appointments[j + 1].time.hour
                
                && clinic_Data->appointments[j].time.min > clinic_Data->appointments[j + 1].time.min)
            {
                end = clinic_Data->appointments[j];
                clinic_Data->appointments[j] = clinic_Data->appointments[j + 1];
                clinic_Data->appointments[j + 1] = end;
            }
        }
    }

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < clinic_Data->maxAppointments; i++)
    {
        for (j = 0; j < clinic_Data->maxPatient; j++)
        {
            if (clinic_Data->appointments[i].patientNumber && clinic_Data->patients[j].patientNumber)
            {
                if (clinic_Data->appointments[i].patientNumber == clinic_Data->patients[j].patientNumber)
                {
                    displayScheduleData(&clinic_Data->patients[j], &clinic_Data->appointments[i], 1);
                }
            }
        }
    }
    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* clinic_Data)
{
    int a, b;
    struct Date date;
    printf("Year        : "); 
    date.year = inputIntPositive();   
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    if ((date.year % 400 == 0) ||
        (date.year % 4 == 0 && date.year % 100 != 0))
    {
        if (date.month == 2)
        {
            printf("Day (1-29)  : ");
            date.day = inputIntRange(1, 29);
        }
    }
    else if (date.month == 1 || date.month == 3
        || date.month == 5 || date.month == 7
        || date.month == 8 || date.month == 10
        || date.month == 12)
    {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    else if (date.month == 2)
    {
        printf("Day (1-28)  : ");
        date.day = inputIntRange(1, 28);
    }
    else
    {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }
    printf("\n");
    displayScheduleTableHeader(&date, 0);

    for (a = 0; a < clinic_Data->maxAppointments; a++)
    {
        for (b = 0; b < clinic_Data->maxPatient; b++)
        {
            if (clinic_Data->appointments[a].patientNumber == clinic_Data->patients[b].patientNumber)
            {
                if (clinic_Data->appointments[a].date.year == date.year
                    && clinic_Data->appointments[a].date.month == date.month
                    && clinic_Data->appointments[a].date.day == date.day)
                {
                    displayScheduleData(&clinic_Data->patients[b], &clinic_Data->appointments[a], 0);
                }
            }
        }
    }
    printf("\n");
}

void addAppointment(struct Appointment* appointment, int maxAppointments, struct Patient* patients, int maxPatient){
    int end_date = 0;
    int end_time = 0;
    int number = 0;
    int done = 0;
    int i = 0;
    int final_result = 0;
    int Available = 0;
    int end = 0;
    int end_patient = 0;

    struct Date d;
    struct Time t;
    int isEqual(const struct Date* one_date, const struct Date* two_date)
{
    return one_date->year == two_date->year && one_date->month == two_date->month && one_date->day == two_date->day;
}
    for (i = 0; i < maxAppointments && !Available; i++){
        if (appointment[i].patientNumber < 1){
            Available = i;
        }
    }
    while (!end && Available){
        while (!end_patient){
            printf("Patient Number: ");
            number = inputIntPositive();
            int result = findPatientIndexByPatientNum(number, patients, maxPatient);
            
            if (result > -1){
                end_patient = 1;
            }else{
                printf("Invalid Entry, try again: \n");
             }
        }

        while (!end_date){
            printf("Year        : ");
            d.year = inputIntPositive();
            int feb = d.year; 
             if(d.year % 4 == 0)
            {
                feb = 29;
            }
            else{
                feb = 28;
            }
            int months[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
            printf("Month (1-12): ");
            d.month = inputIntRange(1, 12);

            printf("Day (1-%d)  : ", months[d.month - 1]);
            d.day = inputIntRange(1, months[d.month - 1]);
            
            end_date = 1;
        }

        while (!end_time){
            final_result = 0;
            printf("Hour (0-23)  : ");
            t.hour = inputIntRange(0, 23);
            
            printf("Minute (0-59): ");
            t.min = inputIntRange(0, 59);
            
            if (t.hour == END_HOUR) {
                if (t.min != 0) {
                    final_result = 1;
                }
             }

            if (t.hour >= START_HOUR && t.hour <= END_HOUR && (t.min % INTERVAL == 0) && !final_result){
               end_time = 1;
            }else{
                printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, INTERVAL);
             }
        }
        done = 0;

        for (i = 0; i < maxAppointments && !done; i++){
            if (isEqual(&d, &appointment[i].date) && appointment[i].time.hour == t.hour && appointment[i].time.min == t.min){
                done = 1;
            }
        }

        if (done){
            printf("\nERROR: Appointment timeslot is not available!\n\n");
            end_date = 0;
            end_time = 0;
        }else{
            end = 1;
            appointment[Available].date = d;
            appointment[Available].time = t;
            appointment[Available].patientNumber = number;
            printf("\n*** Appointment scheduled! ***\n\n");
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int patientNumber;
    struct Date date;
    int s;
    int index;
    char num;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    if ((date.year % 400 == 0) || (date.year % 4 == 0 && date.year % 100 != 0))
    {
        if (date.month == 2)
        {
            printf("Day (1-29)  : ");
            date.day = inputIntRange(1, 29);
        }
    }
    else if (date.month == 1 || date.month == 3
        || date.month == 5 || date.month == 7
        || date.month == 8 || date.month == 10
        || date.month == 12)
    {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    else if (date.month == 2)
    {
        printf("Day (1-28)  : ");
        date.day = inputIntRange(1, 28);
    }
    else
    {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }
    putchar('\n');
    printf("Name  : %s\n", patients[index].name);
    printf("Number: %05d\n", patients[index].patientNumber);
    printf("Phone : ");
    displayFormattedPhone(patients[index].phone.number);
    printf(" (%s)\n", patients[index].phone.description);
    printf("Are you sure you want to remove this appointment (y,n): ");
    num = inputCharOption("yn");
    if (num == 'n')
    {
        printf("Operation aborted.\n\n");
    }
    else
    {
        for (s = 0; s < maxAppointments; s++)
        {
            if (appointments[s].patientNumber == patientNumber
                && appointments[s].date.year == date.year
                && appointments[s].date.month == date.month
                && appointments[s].date.day == date.day)
            {
                appointments[s].patientNumber = 0;
            }
        }
        printf("\nAppointment record has been removed!\n");
    }
    putchar('\n');
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)


void searchPatientByPhoneNumber(const struct Patient patient[], int Maximum)
{
    int i = 0;

    char Call_Entries[10] = {0};


    int display_num = 0;


    printf("Search by phone number: ");

    inputCString(Call_Entries, 10, 10);

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
// (Copy your code from MS#2)


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
// (Copy your code from MS#2)


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
// (Copy your code from MS#2)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n------------------\nNumber: %05d\nName  : ", patient->patientNumber);
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
}

// Get user input for phone contact information
// (Copy your code from MS#2)


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

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////


// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char* file, struct Patient patients[], int max) 
{
    int a;
    int add = 0;
    FILE* fptr = fopen(file, "r");

    if (fptr != NULL) 
    {
        for (a = 0; a < max && !feof(fptr); a++)
        {
            fscanf(fptr, "%d|%[^|]|%[^|]|%[^\n]%*c",
                &patients[a].patientNumber, 
                 patients[a].name,
                 patients[a].phone.description,
                 patients[a].phone.number
            );

            if (!feof(fptr)) 
            {
                add++;
            }
        }
        fclose(fptr);       
    }
    else
    {
        printf("ERROR: some message ..\n");
    }
    return add;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:

int importAppointments(const char* file, struct Appointment appoints[], int max) 
{
        int b;
        int add = 1;
        FILE* fptr = fopen(file, "r");

        if (fptr != NULL) 
        {
            for (b = 0; b < max && !feof(fptr); b++)
            {
                fscanf(fptr, "%d,%d,%d,%d,%d,%d,%*c",
                    &appoints[b].patientNumber, 
                    &appoints[b].date.year, 
                    &appoints[b].date.month,
                    &appoints[b].date.day,
                    &appoints[b].time.hour,
                    &appoints[b].time.min
                );

                if (!feof(fptr))
                {
                    add++;
                }
            }      
            fclose(fptr);
        }
        else
        {
            printf("ERROR: some message ..\n");
        }
        return add;
}


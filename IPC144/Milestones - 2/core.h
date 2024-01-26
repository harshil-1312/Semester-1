
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

#ifndef CORE_H
#define CORE_H

void clearInputBuffer(void);

int inputInt();

int inputIntPositive(void);

int inputIntRange(int lower_limit, int upper_limit);

char inputCharOption(const char* character);

void inputCString(char* input_string,int min_l, int max_l);

void displayFormattedPhone(const char* phone);

#endif /* CORE_H_ */
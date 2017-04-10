//Michael Shearer
//Assignment 2
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//Base Class
class ticketObject {
	int issueID = 0;
	char callerName[40], description[100];
	string issueStatus, issueType, issuePriority;
	int type, usersImpacted;
public:
	ticketObject();
	void captureTicket();
	void showTicket();
	void closeTicket();
};

//Constructor
ticketObject::ticketObject() {
	issueStatus = "OPEN";
}

//CaptureTicket function
void ticketObject::captureTicket() {
	char type;
	cout << "What is the name of the caller? " << endl;
	gets_s(callerName);
	cout << "What is the type of issue? Press: (1)Server\n(2)Application\n(3)Access" << endl;
	cin >> type;
	switch (type) {
	case 1: issueType = "Server";
	case 2: issueType = "Application";
	case 3: issueType = "Access";
	}
	cout << "Please enter a description of the problem encountered: " << endl;
	gets_s(description);
	cout << "How many users are impacted by the problem? ? " << endl;
	cin >> usersImpacted;
	cin.clear();
	cin.ignore();
	if (usersImpacted < 10) {
		issuePriority = "Low";
	}
	else if ((usersImpacted >= 10) && (usersImpacted < 50)) {
		issuePriority = "Medium";
	}
	else if (usersImpacted >= 50) {
		issuePriority = "High";
	}
	issueID = issueID++;
}


//ShowTicketFunction
void ticketObject::showTicket() {
	cout << "________________________" << endl;
	cout << "Name of caller: " << callerName << endl;
	cout << "Issue Type: " << issueType << endl;
	cout << "Issue Description: " << description << endl;
	cout << "Number of Users Impacted: " << usersImpacted << endl;
	cout << "Your ticket priority: " << issuePriority << endl;
	cout << "Your Ticket ID is: " << issueID << endl;
	cout << "________________________" << endl;
}

//CloseTicketFunction
void ticketObject::closeTicket() {
	issueStatus = "CLOSED";
	cout << "This ticket is now closed. " << endl;
}


//Main Function
int main()
{
	char proceed;
	int ticketNum = 0;
	ticketObject myTicketArray[100];


	cout << "This program lets a user input up to 100 customer service request tickets. When the user has entere 100 or chooses to quit early, the program displays the tickets in the order that they were placed. The program conclues by closing the first ticket entered and displaying it. " << endl;
	cout << "Would you like to create a ticket? Press (Y)Yes or (N)No " << endl;
	cin >> proceed;
	while ((proceed == 'y' || proceed == 'Y') && (ticketNum < 100)) {
		for (int i = 0; i < 100; i++) {
			myTicketArray[i].captureTicket();
			ticketNum++;
			cout << "Would you like to create another ticket? " << endl;
			cin >> proceed;
			continue;
		}
	}
	cout << "There are " << ticketNum << "tickets" << endl;
	cout << "________________________" << endl;
	for (int i = 0; i < 100; i++) {
		myTicketArray[i].showTicket();
	}

	myTicketArray[0].closeTicket();
	myTicketArray[0].showTicket();
	//comment
	return 0;
}


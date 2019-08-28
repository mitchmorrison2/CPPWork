#include <iostream>
#include <fstream>

using namespace std;

void patientInvoice(int ID, int costOfRoomTotal, int labTestsTotal, int medicineCosts);
int roomCharges(int ID);
int medicineCostsAmount();
void hospitalSummary(int roomTotal, int testsTotal, int medicineTotal);
void labTestsCalculator(int& totalLabTestsCost);

int main()
{
	// when program is run, make for loop (0-99) for each patient ID in the hospital
	// menu display of options (1. add cost to patient with ID input first, 2. Generate patient invoice, 3. Generate hospital invoice)
	// use a while (true) loop to keep displaying the menu options after selecting options that call the other methods
	
	
	while(true) {
		
			while (true) {
			cout << "Enter the patient ID number (1-99):   " << endl;
			int ID = 0;
			cin >> ID;
				if (ID > 1 && ID < 99) {
					break;
				}
			}
			
			int costOfRoomTotal = 0;
			costOfRoomTotal = roomCharges(ID); //returns int value
			int labTestsTotal = 0;
			labTestsCalculator(labTestsTotal); //uses pass by reference
			int medicineCosts;
			medicineCosts = medicineCostsAmount(); //returns int value
			
			patientInvoice(ID, costOfRoomTotal, labTestsTotal, medicineCosts); //pass in variables to properly display invoice
			
			int roomTotal;
			roomTotal += costOfRoomTotal;
			
			int testsTotal;
			testsTotal += labTestsTotal;
			
			int medicineTotal;
			medicineTotal += medicineCosts;
			
			//adding all charges to new variables which will later be passed into hospital charges summary
			
			cout << "Would you like to: 1. generate the hospital summary of charges or 2. add more charges?: ";
			int choice;
			cin >> choice;
			
			if (choice == 1) {
				hospitalSummary(roomTotal, testsTotal, medicineTotal);
				break;
			}
		} //end invoice for patient option
		return 0;
	}
	

void patientInvoice(int ID, int costOfRoomTotal, int labTestsTotal, int medicineCosts) {
	 cout << endl << "Patient Invoice for #" << ID << endl << "============================" << endl;
	 cout << "The total room charges for patient " << ID << " is $" << costOfRoomTotal << endl ;
	 cout << "The total lab test charges for patient " << ID << " is $" << labTestsTotal << endl;
	 cout << "The total medicine charges for patient " << ID << " is $" << medicineCosts << endl;
	 cout << "The total charges for patient " << ID << " is $" << costOfRoomTotal + labTestsTotal + medicineCosts << endl << endl;
	 
}


void hospitalSummary(int roomTotal, int testsTotal, int medicineTotal) {
		
		cout << endl <<"All incurred charges within the hospital: " << endl << "=====================================" << endl;
		cout << "The total room costs add to $" << roomTotal << endl;
		cout << "The total tests costs add to $" << testsTotal << endl;
		cout << "The total medicine costs add to $" << medicineTotal << endl;
		cout << "The total cost of all charges adds to $" << roomTotal + testsTotal + medicineTotal << endl;
} //end method


int roomCharges(int ID) {
	cout << endl; 
	cout << "What kind of room and how long was patient " << ID << " staying in?" << endl << "1. Private room (525 / day)" << endl << "2. Semi-Private room (412 / day)" << endl << "3. ICU (877 / day)" << endl;
	cout << "Enter the corresponding numbers separated by a space: ";
	int roomType, lengthOfStay;
	cin >> roomType  >> lengthOfStay;
	cout << endl;
	int costOfRoomTotal = 0;
	
	//room type costs if and else if statements
	if (roomType == 1) {
		if (lengthOfStay > 6) {
			costOfRoomTotal = ((525 * 6) + ((525 * .88) * (lengthOfStay - 6)));
		}
		else if (lengthOfStay < 6) {
			costOfRoomTotal = (525 * lengthOfStay);
		}
	}
	else if (roomType == 2) {
		if (lengthOfStay > 6) {
			costOfRoomTotal = ((412 * 6) + ((412 * .88) * (lengthOfStay - 6)));
		}
		else if (lengthOfStay < 6) {
			costOfRoomTotal = (412 * lengthOfStay);
		}
	}
	else if (roomType == 3) {
		if (lengthOfStay > 6) {
			costOfRoomTotal = ((877 * 6) + ((877 * .88) * (lengthOfStay - 6)));
		}
		else if (lengthOfStay < 6) {
			costOfRoomTotal = (877 * lengthOfStay);
		}
	}
	return costOfRoomTotal;
}

void labTestsCalculator(int& totalLabTestsCost) {
	
	cout << "Enter amount of Level 1 tests undergone (125/test): ";
	int test1;
	cin >> test1;
	cout << "Enter amount of Level 2 tests undergone (250/test): ";
	int test2;
	cin >> test2;
	cout << "Enter amount of Level 3 tests undergone (550/test): ";
	int test3;
	cin >> test3;
	totalLabTestsCost = ((test1 * 125) + (test2 * 250) + (test3 * 550));
	//return totalLabTestsCost;
}

int medicineCostsAmount() {
	int totalMedicineCost;
	cout << endl;
	cout << "Enter the total cost of the medecine for the patient: ";
	cin >> totalMedicineCost;
	if (totalMedicineCost > 4000) {
		totalMedicineCost = totalMedicineCost * (.95);
	}
	return totalMedicineCost;
}

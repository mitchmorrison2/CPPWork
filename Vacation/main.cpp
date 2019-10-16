#include <stdio.h>
#include <iostream>
#include <string.h>

//class Vacation {
//	
//	public: // member functions()
	
	using namespace std;
	
	int displayMenu();
	void bookFlights();
	void bookHotels();
	void displayItinerary();
	void displayArrays(string descriptionArray[], double pricesArray[], char name[]);
	int getNumber();
	void callOptions();
	void displayTotalAndPay();
	void clearBookings();
	
	
	//data members
	
	static string flightOptions[] {"Morning", "Afternoon", "Evening"};
	static double flightPrices[] {500.00, 600.00, 700.00};
	static string hotelStays[] {"One night", "Two nights", "Three nights"};
	static double hotelPrices[] {100.00, 240.00, 390.00};
	static int option;
	static int number;
	static string bookings[2]; //flight then hotel
	static double prices[2]; //flight then hotel
	
	


using namespace std;

int main() {
	
	callOptions(); //rather than calling each individual message this if the users chooses to start over with the display menu they can
	
	return 0;
}

int displayMenu() {
	cout << endl;
	cout << "Welcome to Display Menu" << endl;
	cout << "1. Browse Flights and add booking to itinerary" << endl;
	cout << "2. Browse Hotel Stays and add booking to itinerary" << endl;
	cout << "3. View itinerary" << endl;
	cout << "4. Display total and pay" << endl;
	cout << "5. Cancel bookings" << endl;
	cout << "6. Exit menu" << endl;
	cout << "Enter option: ";
	
	cin >> option;
	return option;
	
}

void bookFlights() {
	displayArrays(flightOptions, flightPrices, "Flights\0");
	int choice;
	choice = getNumber();
	if (choice == 1) {
		bookings[0] = flightOptions[0];
		prices[0] = flightPrices[0];
	}
	else if (choice == 2) {
		bookings[0] = flightOptions[1];
		prices[0] = flightPrices[1];
	}
	else if (choice == 3) {
		bookings[0] = flightOptions[2];
		prices[0] = flightPrices[2];
	}
}

void bookHotels() {
	displayArrays(hotelStays, hotelPrices, "Hotels\0");
	int choice;
	choice = getNumber();
	if (choice == 1) {
		bookings[1] = hotelStays[0];
		prices[1] = hotelPrices[0];
	}
	else if (choice == 2) {
		bookings[1] = hotelStays[1];
		prices[1] = hotelPrices[1];
	}
	else if (choice == 3) {
		bookings[1] = hotelStays[2];
		prices[1] = hotelPrices[2];
	}
}

void displayItinerary() {
		printf("%-15s %10s\n", "Bookings", "Prices");
		printf("----------------------\n");
		for (int x = 0; x < 2; x++) {
			printf("%-15s %10.2f\n", bookings[x].c_str(), prices[x]);
		}
		printf("----------------------\n");
		double totalPlusTax = (prices[0] + prices[1]) * (1.0825);
		printf("%-15s %10.2f\n", "Total + Tax", totalPlusTax);
	
}

void displayArrays(string descriptionArray[], double pricesArray[], char name[]) {
	printf("\n%-7s %-11s %10s\n", "Number", name, "Prices");
	printf("---------------------------------\n");
	for (int i = 0; i < 3; i++) {
		printf("%-7d %-11s %10.2f\n", i+1 , descriptionArray[i].c_str(), pricesArray[i]);
	}
}

int getNumber() {
	cout << "Enter your choice: or -1 to redisplay menu: ";
	while (true) {
		cin >> number;
		if (number > 0 && number < 4) {
			break;
		}
		else if (number != -1) {
			cout << "Please enter a valid choice: ";
		}
		else {
			callOptions(); // essentially restarts the program
		}
		cout << endl;
	}
	
	return number;
}

void callOptions() {
	while (true) {
		option = displayMenu();
		
		if (option == 1) {
			bookFlights();
		}
		else if (option == 2) {
			bookHotels();
		}
		else if (option == 3) {
			displayItinerary();
		}
		else if (option == 4) {
			displayTotalAndPay();
		}
		else if (option == 5) {
			clearBookings();
		}
		else if (option == 6) {
			break;
		}
		else {
			cout << "Please enter a valid option";
		}
	}
}

void displayTotalAndPay() {
	double totalPlusTax = (prices[0] + prices[1]) * (1.0825);
	printf("\n%-15s %10.2f\n", "Total + Tax", totalPlusTax);
	printf("Say floolaborg out loud to pay -\n");
	printf("Thanks! Your bookings will now be cleared\n\n");
}

void clearBookings() {
	for (int y = 0; y < 2; y++) {
		bookings[y] = '\0';
		prices[y] = 0;
	}
}

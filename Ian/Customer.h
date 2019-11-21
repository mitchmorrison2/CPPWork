#ifndef _CUST_
#define _CUST_

#include <iostream>
#include <string>
#include <vector>
#include "HourMin.h"
#include "Simulation.h"

class Customer{
public:
    /**
     Constructor: takes an input of type HourMin for the arrival time of the customer. Initializes start and end as this inputted arrival time.  The constructor also sets the private variable being_helped to false.
     
     @param arrival an HourMin object representing the arrival time of the customer.
     */
	Customer(HourMin arrival): start(arrival), end(arrival), being_helped(false){}
    
    /**
     This function sets the private member variable duration (which represents the time spent at checkout) equal to minutes.
     
     @param minutes the number of minutes taken at checkout.
     */
	void duration_in_min(const int& minutes);
    
    /**
     This function represents the customer being helped at time currentTime. It sets the variable being_helped to true. Then, it sets the HourMin object end equal to the current time, advanced by the duration of checkout.
     
     @param currentTime an HourMin object representing the current time.
     */
	void help(HourMin currentTime);
    
    /**
     This function determines whether the customer is being helped by returning the value of private member variable being_helped.
     
     @return true if the customer is being helped, false if not.
     */
	bool is_being_helped() const;
    
    /**
     This function determines if the Customer is done being helped.
     
     @param currentTime a HourMin representation of the current time.
     
     @return true if the Customer has been helped and if the current time exceeds the ending time, else, returns false.
     */
	bool is_done(const HourMin& currentTime) const;
    
    /**
     This function returns the number of minutes from start to end.
     
     @return the number of minutes from start to end.
     */
	int get_minutes() const;
    
    /**
     This function prints the Customer information in the form "Arrival: [START] Exit: [END]"
     */
	void print() const;
    
private:
    HourMin start, end;
	int duration;
	bool being_helped;
};

void Customer::duration_in_min(const int& minutes){
    duration = minutes;
    return;
}
void Customer::help(HourMin currentTime){
    if(!being_helped){
        being_helped = true;
    }
    currentTime.advance_min(duration);
    end.set_min(currentTime.get_min());
    end.set_hour(currentTime.get_hour());
    //end = currentTime;
    return;
}

bool Customer::is_being_helped() const{
    return being_helped;
}

bool Customer::is_done(const HourMin& currentTime) const{
    return (being_helped && (currentTime.total_minutes()>=end.total_minutes())); //use before.
}
int Customer::get_minutes() const{
    return start.minutes_to(end);
}
void Customer::print() const{\
    std::cout << "Arrival: " << start.as_string() << " Exit: " << end.as_string();
    return;
}

#endif

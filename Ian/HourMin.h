#ifndef _HOURMIN_
#define _HOURMIN_

#include <iostream>
#include <string>
#include <vector>
#include "Simulation.h"

class HourMin {
public:
    /**
     Constructer: takes two inputs to create an HourMin object. Both inputs are ints. The first represents the number of hours. The class member variable hour is inititalized as this input.
     The second represents the number of minutes. The class member variable min is inititlized as this input.
     
     @param _hour the number of hours.
     @param _min the number of minutes.
     */
	HourMin(int _hour, int _min): hour(_hour), min(_min){
            format();
        }
    
    /**
     This function is passed  an int which represents the number of minutes to advance the HourMin object by. It advances the HourMin object by the inputted int and reformats the class member variable formatted.
     
     @param numMinutes the number of minutes to advance the HourMin object by.
     */
    void advance_min(const int& numMinutes);
    
    /**
     This function determines whether the HourMin object comes before another HourMin object in time.
     
     @param other Another HourMin object to which the HourMin object is compared.
     
     @return true if the HourMin object is before other. If not, false.
     */
    bool before(const HourMin& other) const;
    
    /**
     This function determines the time difference from the HourMin object to other,  in minutes.
     
     @param other Another HourMin object to which the HourMin object is compared
     
     @return An int which represents the difference, in minutes, between the HourMin object and other.
     */
    int minutes_to(const HourMin& other) const;
    
    /**
     This function returns a string which gives a representation of the HourMin object in the form Hour:Min.
     
     @return a string which represents the HourMin object in the form Hour:Min;
     */
    std::string as_string() const;
    
    /**
     This function returns the total number of minutes in the HourMin object, including the minutes that come from the variable hour.
     
     @return an int for the total number of minutes in teh HourMin object.
     */
    int total_minutes() const;
    
    void set_hour(const int& newHour){
        hour = newHour;
    }
    void set_min(const int& newMin){
        min = newMin;
    }
    
    int get_min(){
        return min;
    }
    
    int get_hour(){
        return hour;
    }

private:
    int hour, min;
	std::string formatted;
    
    /**
     This function formats the string formatted so that formatted reflects the HourMin in the form "Hour:Min"
     */
    void format();
};



void HourMin::advance_min(const int& numMinutes){
    const int min_in_hour = 60;
    min = (min + numMinutes) % min_in_hour;
    hour += (min + numMinutes) / min_in_hour;
    format();
    return;
}


bool HourMin::before(const HourMin& other) const{ //should other by const
    return (total_minutes() < other.total_minutes());
}


int HourMin::minutes_to(const HourMin& other) const{
    return other.total_minutes() - total_minutes();
}


std::string HourMin::as_string() const{
    return formatted;
}


int HourMin::total_minutes() const{
    const int min_in_hour = 60;
    return hour * min_in_hour + min;
}

void HourMin::format(){ //String or void?
       formatted = std::to_string(hour) + ":" + std::to_string(min);
       return;
   }

#endif

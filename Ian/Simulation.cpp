#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "HourMin.h"
#include "Simulation.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

double exp_rand(double avg){
    double random = rand()/(RAND_MAX + 1.0);
    return avg * log (1 - random) / log(exp(1.0));
}

bool bernoulli_rand(double p){
    double random = static_cast<double>(rand()) / RAND_MAX;
    return (p <= random);
}

void enter(const HourMin& now, int dT, std::vector<Customer>& queue){
    size_t num_entries = get_entries(now, dT);
    for(size_t i = 0; i < num_entries; i++){
        Customer entry = Customer(now);
        queue.push_back(entry);
    }
    return;
}

void finish(const HourMin& now, std::vector<Customer>& queue, std::vector<Customer>& finished){ //customer at the front of the queue might not be first to finish checkout
    //runs through entire queue, looking for customers that are done. If they are, removes them and puts them in finished. Remember, the current time is always incremented. do not have many current times
    //
    for(size_t i = 0; i < queue.size(); i++){
        if(queue[i].is_done(now)){
            finished.push_back(queue[i]);
            queue.erase(begin(queue)+i);
            i--;
        }
    }
    return;
}

void help(const HourMin& now, std::vector<Customer>& queue){
    
    return;
}

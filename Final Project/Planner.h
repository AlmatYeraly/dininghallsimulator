// Planner Class
// Inherits from Person Class
// This type of people know which stations they need to go through
// Since everyone goes through Swipe and Drink stations, the stations before Drink are randomized

#ifndef PLANNER_H_
#define PLANNER_H_

#include "Person.h"
#include "Station.h"

class Planner:public Person
{
private:
	vector<Station *> schedule; // Vector of stations that a person will go through before sitting down
public:
	// Two constructors
	// This takes in a vector of all stations for all the options
	// ints one, two, three, and four are used as indexes of the vector of all stations
	// one, two, three, and four are the order of which stations a person will go to
	// one is used for Swipe and three or four are used for Drink
	Planner(vector<Station*>& all, int one, int two, int three, int number_, int entry_time);
	Planner(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time);

	void next_q(); // Sends a person to their next station

	int get_time(); // Returns start_time
	int get_number(); // Returns the number (id) of a person
	bool done(); // Returns if a person is done getting food

	void set_time(int time); // Updates end_time until done
};

#endif
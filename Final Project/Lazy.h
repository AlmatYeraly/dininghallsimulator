// Lazy Class
// Inherits from Person Class
// This type of people go through only one station of food
// They will choose a station with the least amount of people in the queue
// They just want to get food and sit down

#ifndef LAZY_H_
#define LAZY_H_

#include "Person.h"
#include "Station.h"

class Lazy:public Person
{
private:
	vector<Station*> stations; // Vector of all the stations
								// Used in finding a station with the lease amount of people in the queue
	vector<Station*> schedule; // Vector of stations that a person will go through before sitting down
public:
	// Constructor
	// Takes in a vector of all stations for options
	// int one is used for pushing Swipe to the schedule
	// Vector stations is used to see which stations have the least amount of people in the queue
	// Drink will be pushed last
	Lazy(vector<Station*>& all, int one, int number_, int entry_time);

	void next_q(); // Sends people to their next stations
					// This determines which stations have the least amount of people for a lazy person to go

	int get_time(); // Returns start_time. Used for pushing people to the first queue based on their entry time
	int get_number(); // Returns the number (id) of a person. Used for identifying people
	bool done(); // Returns if a person is done getting food. Used for tracking how many people are done

	void set_time(int time); // Updates end_time until done
};

#endif
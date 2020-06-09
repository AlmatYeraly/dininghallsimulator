// Person Class
// Planner and Lazy inherit from Person
// Every person will go through Swipe and Drink stations

// Scott Griffith helped us with next_q
// Previously, it did not push people to next stations
// So, he pointed out our mistake

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <vector>

using std::vector;

class Person
{
protected:
	int next = 1; // Used as the position of a person in their schedule of stations
	int number; // Used as an id to a person
	int start_time; // Tells when a person enters the dining hall
	int end_time = 0; // Tells when a person sits down
	bool is_done; // Tells if a person is done getting food. Usually initialized as false
public:
	virtual void next_q() = 0; // Sends a person to the next station

	virtual int get_time() = 0; // Returns the start_time
								// Used to push a person into the process
	virtual int get_number() = 0; // Returns the number (id) of a person
	virtual bool done() = 0; // Returns whether a person is done getting food

	virtual void set_time(int time) = 0; // Updates the end_time until done
};

#endif
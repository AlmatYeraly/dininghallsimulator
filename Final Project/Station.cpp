#include "Station.h"
#include <iostream>

// Constructor
Station::Station(int processing_)
{
	processing_time = processing_;
	time_left = processing_;
}

// Pushes person to the queue
void Station::add_person(Person * person)
{
	this->line.push(person);
}

// Processes the front person in the queue
// Takes int total_time to track the time for a person
// Person's end_time is updated with total_time
// If the queue is empty, does nothing
// Once there is a person in the queue, this starts decremeting time_left
// When time_left hits 0, sends the front person to the next station in their schedule and pops them from the queue
// time_left then restarts for next person to process
void Station::process(int total_time)
{
	if (line.size() == 0) { }
	else
	{
		time_left--;

		line.front()->set_time(total_time + 2);

		if (time_left == 0)
		{
			line.front()->next_q();
			line.pop();
			time_left = processing_time;
		}
	}
}

// Returns the queue size
// Used for identifying which station has the least amount of people for lazy people to go
int Station::get_line_size()
{
	return line.size();
}

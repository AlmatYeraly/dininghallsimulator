// Station Class
// This processes people in the line
// Utilizes queue of people
// Each station has its own processing time for each person

#ifndef STATION_H_
#define STATION_H_

#include "Person.h"
#include <queue>

using std::queue;

class Station
{
private:
	queue<Person*> line; // queue of people to process
	int processing_time; // Processing time 
	int time_left; // Time left to process one person
public:
	// Constructor
	Station(int processing_); // Takes an int for its processing_time

	void add_person(Person * person); // Adds person to the queue
	void process(int total_time); // Processes the front person in the queue

	int get_line_size(); // Returns the size of a queue
						// This helps lazy people find a station with the least amount of people
};

#endif
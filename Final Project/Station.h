#ifndef STATION_H_
#define STATION_H_

#include "Person.h"
#include <queue>

using std::queue;

class Station
{
private:
	queue<Person*> line;
	int processing_time;
	int time_left;
public:
	Station(int processing_);

	void add_person(Person * person);
	void process();

	int get_time();
	queue<Person *> get_line();
	void set_time_left(int time);
	int get_line_size();
};

#endif
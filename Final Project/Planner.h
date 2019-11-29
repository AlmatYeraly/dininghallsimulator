#ifndef PLANNER_H_
#define PLANNER_H_

#include <vector>
#include "Person.h"
#include "Station.h"

using std::vector;

class Planner:public Person
{
private:
	vector<Station *> schedule;
	int next = 1;
public:
	Planner(vector<Station*>& all, int one, int two, int three, int number_, int entry_time);
	Planner(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time);

	void next_q();
	int get_schedule_size();
	int get_time();
	int get_number();
};

#endif
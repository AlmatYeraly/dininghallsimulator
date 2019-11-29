#include "Planner.h"

Planner::Planner(vector<Station*>& all, int one, int two, int three, int number_, int entry_time)
{
	schedule.push_back(all[one]);
	schedule.push_back(all[two]);
	schedule.push_back(all[three]);

	number = number_;
	start_time = entry_time;
}

Planner::Planner(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time)
{

	number = number_;
	start_time = entry_time;
}

void Planner::next_q()
{
	schedule[next]->add_person(this);
	next++;
}

int Planner::get_schedule_size()
{
	return schedule.size();
}

int Planner::get_time()
{
	return start_time;
}

int Planner::get_number()
{
	return number;
}

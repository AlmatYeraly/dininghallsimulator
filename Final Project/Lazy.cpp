#include "Lazy.h"

Lazy::Lazy(vector<Station*>& all, int one, int two, int three, int number_, int entry_time)
{
	schedule.push_back(all[one]);
	schedule.push_back(all[two]);
	schedule.push_back(all[three]);

	number = number_;
	start_time = entry_time;
}

Lazy::Lazy(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time)
{
	schedule.push_back(all.at(one));
	schedule.push_back(all.at(two));
	schedule.push_back(all.at(three));
	schedule.push_back(all.at(four));

	number = number_;
	start_time = entry_time;
}

void Lazy::next_q()
{
	queue<Person*> line_ = schedule[next]->get_line();
	schedule[next]->add_person(this);
	next++;
}

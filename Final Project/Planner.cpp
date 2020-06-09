#include "Planner.h"

// Constructor for a Planner who gets only one type of food
Planner::Planner(vector<Station*>& all, int one, int two, int three, int number_, int entry_time)
{
	schedule.push_back(all[one]);
	schedule.push_back(all[two]);
	schedule.push_back(all[three]);

	number = number_;
	start_time = entry_time;
	is_done = false;
}

// Constructor for a Planner who gets two types of food
Planner::Planner(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time)
{

	schedule.push_back(all[one]);
	schedule.push_back(all[two]);
	schedule.push_back(all[three]);
	schedule.push_back(all[four]);

	number = number_;
	start_time = entry_time;
	is_done = false;
}

// Sends people to their next stations
// next is used as the position
// Sends a person to the next station in the schedule by utilizing Station's add_person 
// When next gets to the last station, person is done 
// This outputs how much time a person spent getting food
void Planner::next_q()
{
	if (next < schedule.size())
	{
		schedule[next]->add_person(this);
		next++;
	}
	else
	{
		is_done = true;
		std::cout << "Person " << number << " spent " << end_time - start_time << " seconds. \n";
	}
}

// Returns the start_time
// Used for pushing people to the first station based on their entry_time
int Planner::get_time()
{
	return start_time;
}

// Returns the number (id) of a person
// Used for identifying people
int Planner::get_number()
{
	return number;
}

// Returns whether a person is done getting food or not
// Used for tracking how many people are done
bool Planner::done()
{
	return is_done;
}

// Updates the end_time until a person is done
void Planner::set_time(int time)
{
	end_time = time;
}

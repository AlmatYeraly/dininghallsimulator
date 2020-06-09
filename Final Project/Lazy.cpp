#include "Lazy.h"

// Constructor
Lazy::Lazy(vector<Station*>& all, int one, int number_, int entry_time)
{
	stations = all;
	schedule.push_back(all[one]);

	number = number_;
	start_time = entry_time;
	is_done = false;
}

// Sends people to their next stations
// This determines which stations have the least amount of people in the queue then pushes it to the schedule
// After getting through food, the Drink station is pushed to the schedule
// After going through the Drink, a person is done 
// This also outputs how long it took from start till sitting down
void Lazy::next_q()
{
	// This finds the station with the least amount of people in the queue
	// Also records the index of the smallest station so that it can be pushed to the schedule later
	int smallest = stations.size() ^ 20;
	int index = 0;
	for (int i = 1; i <= stations.size() - 2; i++)
	{
		if (stations[i]->get_line_size() <= smallest)
		{
			smallest = stations[i]->get_line_size();
			index = i;
		}
	}


	if (next == 1) // Pushes the smallest station to the schedule
	{
		schedule.push_back(stations[index]);
		schedule[next]->add_person(this);
		next++;
	}
	else if (next == 2) // Pushes the Drink station
	{
		schedule.push_back(stations[7]);
		schedule[next]->add_person(this);
		next++;
	}
	else if(next == 3) // Person is done. Outputs the time it took for a person to sit down
	{
		is_done = true;
		std::cout << "Person " << number << " spent " << end_time - start_time << " seconds. \n";
	}
}

// Returns the start_time
// Used for pushing people to the first station based on their entry_time
int Lazy::get_time()
{
	return start_time;
}

// Returns the number (id) of a person
// Used for identifying people
int Lazy::get_number()
{
	return number;
}

// Returns whether a person is done getting food or not
// Used for tracking how many people are done
bool Lazy::done()
{
	return is_done;
}

// Updates the end_time until a person is done
void Lazy::set_time(int time)
{
	end_time = time;
}

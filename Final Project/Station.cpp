#include "Station.h"
#include <iostream>

Station::Station(int processing_)
{
	processing_time = processing_;
	time_left = processing_;
}

void Station::add_person(Person * person)
{
	this->line.push(person);
	std::cout << "add person\n ";
}


void Station::process()
{
	if (line.size() == 0)
	{

	}
	else
	{

		time_left--;

		if (time_left == 0)
		{
			line.front()->next_q();
			std::cout << "Person " << line.front()->get_number() << " \n";
			line.pop();
			time_left = processing_time;
		}
	}
}

int Station::get_time()
{
	return processing_time;
}

queue<Person*> Station::get_line()
{
	return line;
}

void Station::set_time_left(int time)
{
	time_left = time;
}

int Station::get_line_size()
{
	return line.size();
}

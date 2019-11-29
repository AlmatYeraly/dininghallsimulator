#include <iostream>
#include "Station.h"
#include "Person.h"
#include "Planner.h"
#include <random>
#include <ctime>

Station random_schedule(vector<Station> all);
Station lazy_schedule(vector<Station> all);

int main()
{
	srand(time(NULL));
	Station Swipe(1);
	Station Drink(2);

	Station Burger(3);
	Station Right_Main1(4);
	Station Right_Main2(5);

	Station Pizza(6);
	Station Left_Main1(7);
	Station Left_Main2(8);

	vector<Station*> all;
	all.push_back(&Swipe);
	all.push_back(&Burger);
	all.push_back(&Right_Main1);
	all.push_back(&Right_Main2);
	all.push_back(&Pizza);
	all.push_back(&Left_Main1);
	all.push_back(&Left_Main2);
	all.push_back(&Drink);
	

	vector<Person*> people;
	vector<Person*> people2;
	vector<Person*> people3;
	vector<Person*> tables;

	for (int i = 0; i < 100; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 0));
	}


	int time = 0;
	while (tables.size() != people.size())
	{
		vector<Person *> schedule;
		if (people.front()->get_time() == time)
		{
			for (int i = 0; i < people.size(); i++)
			{
				if (people[i]->get_time() == time)
				{
					Swipe.add_person(people[i]);
				}
			}
		}

		Swipe.process();
		Drink.process();
		Burger.process();
		Right_Main1.process();
		Right_Main2.process();
		Pizza.process();
		Left_Main1.process();
		Left_Main2.process();
		time++;

		for (int i = 0; i < people.size(); i++)
		{
			if (people[i]->get_schedule_size() == 0)
			{
				tables.push_back(people[i]);
			}
		}
	}

	system("pause");
	return 0;
}

Station random_schedule(vector<Station> all)
{
	int random = (rand() % 6);


	return all[random];
}

Station lazy_schedule(vector<Station> all)
{
	int smallest = 100;
	int index = 0;
	for (int i = 0; i < all.size(); i++)
	{
		if (all[i].get_line_size() < smallest)
		{
			smallest = all[i].get_line_size();
			index = i;
		}
	}
	return all[index];
}
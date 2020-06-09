// Madi Binyon and Almat Yeraly
// CS-273 Data Structures
// Final Project
// Dining Hall Simulation
// All code is written by us, unless specified
// Scott Griffith helped us along the way by pointing out errors in the code and giving us ideas how to approach issues

#include <iostream>
#include "Station.h"
#include "Person.h"
#include "Planner.h"
#include "Lazy.h"
#include <random>
#include <ctime>

int main()
{
	srand(time(NULL));

	// Initializing stations
	// Swipe is always the first and Drink is always the last
	// Everyone will go through Swipe and Drink
	Station Swipe(1);
	Station Drink(2);

	Station Burger(10);
	Station Right_Main1(5);
	Station Right_Main2(6);

	Station Pizza(5);
	Station Left_Main1(8);
	Station Left_Main2(9);

	// Pushing all stations into one vector
	// This is done for an easy access to stations for initializing people
	vector<Station*> all;
	all.push_back(&Swipe);
	all.push_back(&Burger);
	all.push_back(&Right_Main1);
	all.push_back(&Right_Main2);
	all.push_back(&Pizza);
	all.push_back(&Left_Main1);
	all.push_back(&Left_Main2);
	all.push_back(&Drink);

	// Initializing the vector of people
	// Everyone in the vector will get processed
	vector<Person*> people;


	bool full = false; // This will be used to stop the process
	int tables; // This will be used to stop the process
				// The process will stop when full = true and tables == people.size()


	// Creating different variations of people to push into the process
	// Remove comments and play around with number in initializers to get different variations
	for (int i = 0; i < 60; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 0));
		// people.push_back(new Lazy(all, 0, 50 + i, 0));
		// people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, i, 0));
	}

	for (int i = 60; i < 90; i++)
	{
		// people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 0));
		// people.push_back(new Lazy(all, 0, 50 + i, 0));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, i, 0));
	}

	for (int i = 90; i < 100; i++)
	{
		// people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 0));
		people.push_back(new Lazy(all, 0, i, 0));
		// people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, i, 0));
	}

	/*for (int i = 0; i < 3; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 5));
		people.push_back(new Lazy(all, 0, 3 + i, 5));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 9 + i, 5));
	}

	for (int i = 3; i < 10; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 10));
		people.push_back(new Lazy(all, 0, 7 + i, 10));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 14 + i, 10));
	}

	for (int i = 10; i < 18; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 15));
		people.push_back(new Lazy(all, 0, 8 + i, 15));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 16 + i, 15));
	}

	for (int i = 18; i < 26; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 20));
		people.push_back(new Lazy(all, 0, 8 + i, 20));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 16 + i, 20));
	}

	for (int i = 26; i < 33; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 25));
		people.push_back(new Lazy(all, 0, 7 + i, 25));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 14 + i, 25));
	}

	for (int i = 33; i < 36; i++)
	{
		people.push_back(new Planner(all, 0, rand() % 6 + 1, 7, i, 30));
		people.push_back(new Lazy(all, 0, 3 + i, 30));
		people.push_back(new Planner(all, 0, rand() % 6 + 1, rand() % 6 + 1, 7, 9 + i, 30));
	}
	*/



	// Processing
	// Scott Griffith gave the idea for processing 
	// The stations will keep processing until every person in the people vector is done 
	// A person is done after being processed through Drink
	std::cout << people.size() << "\n";

	int time = 0; // This tracks the time passed 
				// Every step through the loop increments time by 1
	while (!full)
	{
		// Pushing people from the people vector into Swipe station
		// This will push people to the swipe based on their entry time
		for (int i = 0; i < people.size(); i++)
		{
			if (people[i]->get_time() == time)
			{
				Swipe.add_person(people[i]);
			}
		}

		// This stops the loop when everyone is done being processed
		// The process will only stop when tables == people.size()
		tables = 0;
		for (int i = 0; i < people.size(); i++)
		{
			if (people[i]->done())
			{
				tables++;
			}
			
			if (tables == people.size())
				full = true;

		}

		// Processing people
		Swipe.process(time);
		Drink.process(time);
		Burger.process(time);
		Right_Main1.process(time);
		Right_Main2.process(time);
		Pizza.process(time);
		Left_Main1.process(time);
		Left_Main2.process(time);
		time++;
	}

	std::cout << "\n Simulation took " << time + 1 << " seconds \n";

	system("pause");
	return 0;
}
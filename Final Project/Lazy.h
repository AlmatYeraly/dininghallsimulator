#ifndef LAZY_H_
#define LAZY_H_

#include <vector>
#include "Person.h"
#include "Station.h"

using std::vector;

class Lazy:public Person
{
private:
	vector<Station*> schedule;
	int next = 1;
public:
	Lazy(vector<Station*>& all, int one, int two, int three, int number_, int entry_time);
	Lazy(vector<Station*>& all, int one, int two, int three, int four, int number_, int entry_time);

	void next_q();
};

#endif
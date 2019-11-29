#ifndef PERSON_H_
#define PERSON_H_

class Person
{
protected:
	int number;
	int start_time;
	int end_time;
public:
	virtual void next_q() = 0;
	virtual int get_time() = 0;
	virtual int get_number() = 0;
	virtual int get_schedule_size() = 0;
};

#endif
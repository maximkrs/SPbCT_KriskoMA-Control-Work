#include <string>

#pragma once
class Eventt
{
public:
	
	Eventt() {};

	Eventt(std::string day_of_week, int hour, int minute, std::string subject, int auditory)
	{
		this->auditory = auditory;
		this->day_of_week = day_of_week;
		this->hour = hour;
		this->minute = minute;
		this->subject = subject;
	}

	std::string get_Day_Of_Week()
	{
		return day_of_week;
	}

	int get_Hour()
	{
		return hour;
	}

	int get_Time()
	{
		return minute;
	}

	int get_Aud()
	{
		return auditory;
	}

	std::string get_Subject()
	{
		return subject;
	}

	std::string day_of_week;
	int hour;
	int minute;
	std::string subject;
	int auditory;
};


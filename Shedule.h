#include"Eventt.cpp"
#include<vector>
#include<iostream>

using namespace std;

#pragma once
class Shedule
{
public:

	string convert_To_Day_Name(int a)
	{
		if (a == 1) return "Monday";
		if (a == 2) return "Tuesday";
		if (a == 3) return "Wednesday";
		if (a == 4) return "Thursday";
		if (a == 5) return "Friday";
		if (a == 6) return "Sunday";
		if (a == 7) return "Sathurday";
	}

	int convert_To_Day_Number(string a)
	{
		if (a == "Monday") return 1;
		if (a == "Tuesday") return 2;
		if (a == "Wednesday") return 3;
		if (a == "Thursday") return 4;
		if (a == "Friday") return 5;
		if (a == "Sunday") return 6;
		if (a == "Sathurday") return 7;
	}

	vector <Eventt> print_One_Day(vector <Eventt> roster, string day)
	{
		for (int i = 0; i < n; i++)
		{
			if (list[i].get_Day_Of_Week() == day)
			{
				roster.push_back(list[i]);
			}
		}
		return roster;
	}

	vector <Eventt> print_All(vector <Eventt> roster)
	{
		for (int i = 0; i < n; i++)
		{
			roster.push_back(list[i]);
		}
		return roster;
	}

	void add_New_Event(std::string day_of_week, int h, int m, std::string subject, int aud)
	{
		Eventt a(day_of_week, h, m, subject, aud);
		list.push_back(a);
		n++;
	}

	void delete_Event(std::string day_of_week, int h, int m, int aud)
	{
		for (int i = 0; i < n; i++)
		{
			int flag = 0;
			if (list[i].get_Day_Of_Week() == day_of_week) flag++;
			if (list[i].get_Hour() == h) flag++;
			if (list[i].get_Time() == m) flag++;
			if (list[i].get_Aud() == aud) flag++;
			if (flag == 4) { list.erase(list.begin() + i); n--; }
		}
	}

	std::vector <Eventt> list;
	int n = 0;
};
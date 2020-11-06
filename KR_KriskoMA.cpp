// KR_KriskoMA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include"Shedule.h"

using namespace std;

Shedule timetable;

void add_From_Console()
{
    string day, sub;
    int h, m, aud;
    cout << "Новая запись:" << endl << "Введите день недели: "; cin >> day;
    cout << "Введите час: "; cin >> h;
    cout << "Введите минуты: "; cin >> m;
    cout << "Введите предмет: "; cin >> sub;
    cout << "Введите аудиторию: "; cin >> aud;
    timetable.add_New_Event(day, h, m, sub, aud);
    cout << endl;
}

void add_From_File()
{
    vector <vector <string>> splitted_line;
    vector <string> buff;
    string line, buf;
    ifstream in("f.txt");
    if (in.is_open())
    {
        getline(in, line);
        int flag = 1;
        for (int i = 0; i < line.size(); i++)
        {
            if (flag % 5 == 0) splitted_line.push_back(buff);

            if (line[i] == ' ')
            {
                buff.push_back(buf);
                flag++;
                continue;
            }

            buf += line[i];
        }
    }
    in.close();
    for (int i = 0; i < splitted_line.size(); i++)
    {
        timetable.add_New_Event(splitted_line[i][0], stoi(splitted_line[i][1]), stoi(splitted_line[i][2]), splitted_line[i][3], stoi(splitted_line[i][4]));
    }
}

void print_To_Console(Eventt obj)
{
    cout << "День недели: " << obj.get_Day_Of_Week() << endl << "Время: " << obj.get_Hour() << ":" << obj.get_Time() << endl << "Предмет: " << obj.get_Subject()
        << endl << "Аудитория: " << obj.get_Aud() << endl << endl;
}

int find_Earliest(vector <Eventt> list, int flag=0)
{
    int e=0;

    if (flag == 1)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (timetable.convert_To_Day_Number(list[i].get_Day_Of_Week())<timetable.convert_To_Day_Number(list[e].get_Day_Of_Week())) e=i;
        }
    }

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].get_Hour() < list[e].get_Hour() && list[i].get_Day_Of_Week() == list[e].get_Day_Of_Week()) e = i;
    }

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].get_Time() < list[e].get_Time() && list[i].get_Hour() == list[e].get_Hour()) e = i;
    }

    return e;
}

void print_One_Day_Timetable()
{
    int e, n;
    string a;
    vector <Eventt> roster;
    cout << "Введите день, за который нужно вывести расписание: "; cin >> a;
    roster = timetable.print_All(roster);
    n = roster.size();
    for (int i = 0; i < n; i++)
    {
        e = find_Earliest(roster);
        print_To_Console(roster[e]);
        roster.erase(roster.begin() + e);
    }
    cout << endl << endl;
}

void print_Timetable()
{
    int e, n;
    vector <Eventt> roster;
    roster = timetable.print_All(roster);
    n = roster.size();
    for (int i = 0; i < n; i++)
    {
        e = find_Earliest(roster,1);
        print_To_Console(roster[e]);
        roster.erase(roster.begin() + e);
    }
    cout << endl << endl;
}

void print_To_File()
{
    ofstream out;
    out.open("d.txt");
    if (out.is_open())
    {
        int e, n;
        vector <Eventt> roster;
        roster = timetable.print_All(roster);
        n = roster.size();
        for (int i = 0; i < n; i++)
        {
            e = find_Earliest(roster);
            out << "День недели: " << roster[i].get_Day_Of_Week() << endl << "Время: " << roster[i].get_Hour() << ":" << roster[i].get_Time() << endl << "Предмет: " 
                << roster[i].get_Subject() << endl << "Аудитория: " << roster[i].get_Aud() << endl << endl;
            roster.erase(roster.begin() + e);
        }
    }
}

void delete_Element()
{
    string day;
    int h, m, aud;
    cout << "Введите данные для удаления:" << endl << "Введите день недели: "; cin >> day;
    cout << "Введите час: "; cin >> h;
    cout << "Введите минуты: "; cin >> m;
    cout << "Введите аудиторию: "; cin >> aud;
    timetable.delete_Event(day, h, m, aud);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Список команд:" << endl << "1 — добавить запись из консоли" << endl << "2 — добавить запись из файла" << endl << "3 — вывести расписание за один день"
        << endl << "4 — вывести все расписание" << endl << "5 — вывести расписание в файл" << endl << "6 — удалить запись" << endl <<"7 — выход" << endl << endl;

    timetable.add_New_Event("Monday", 12, 40, "Maths", 22);
    timetable.add_New_Event("Monday", 14, 20, "PE", 10);

    while (true)
    {
        int c;
        cout << "Введите команду: "; cin >> c;
        cout << endl;
        if (c == 1) add_From_Console();
        if (c == 2) add_From_File();
        if (c == 3) print_One_Day_Timetable();
        if (c == 4) print_Timetable();
        if (c == 5) print_To_File();
        if (c == 6) delete_Element();
        if (c == 7) break;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const uint CMD_ADD = 0;
const uint CMD_NEXT = 1;
const uint CMD_DUMP = 2;

map<string, uint> cmdMapping = {
	{"ADD", CMD_ADD},
	{"NEXT", CMD_NEXT},
	{"DUMP", CMD_DUMP},
};

const vector<uint> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

uint currentMonth = 0;

void add(vector<vector<string>>& schedule, uint day, string issue) {
	if(day >= schedule.size()) {
		return;
	}

	schedule[day].push_back(issue);
}

void dump(vector<vector<string>>& schedule, uint day) {
	if(day >= schedule.size()) {
		cout << "Day not found" << endl;
		return;
	}

	cout << schedule[day].size();
	for (auto s : schedule[day]) {
		cout << " " << s;
	}
	cout << endl;
}

void next(vector<vector<string>>& schedule) {
	currentMonth++;
	if (currentMonth > 11) {
		currentMonth = 0;
	}

	vector<vector<string>> newMonth = schedule;

	int newSize = days[currentMonth],
		curSize = schedule.size(),
		sizeDiff = newSize - curSize;

	if (sizeDiff == 0) {
		return;
	}

	if (sizeDiff < 0) {
		while (sizeDiff != 0) {
			uint i = curSize + sizeDiff;
			sizeDiff++;
			if (schedule[i].size() == 0) {
				continue;
			}
			schedule[newSize - 1].insert(
				end(schedule[newSize - 1]),
				begin(schedule[i]),
				end(schedule[i])
			);
		}
	}

	schedule.resize(newSize);
}

void testAdd() {
	vector<vector<string>> schedule(days[1]);
	add(schedule, 30, "test 31");
	add(schedule, 0, "test 1");
	add(schedule, 0, "test 2");
	cout << "#1 Test Add " << (schedule[0][0] == "test 1" ? "OK" : "FAIL") << endl;
	cout << "#2 Test Add " << (schedule[0][1] == "test 2" ? "OK" : "FAIL") << endl;
}

void testNext() {
	vector<vector<string>> schedule(days[0]);
	add(schedule, 4, "Salary");
	add(schedule, 30, "Walk");
	add(schedule, 29, "WalkPreparation");
	next(schedule);
	cout << "#3 Test Next " << (schedule[4].size() > 0 && schedule[4][0] == "Salary" ? "OK" : "FAIL") << endl;
	cout << "#4 Test Add " << ((schedule[27].size() == 2 && schedule[27][0] == "WalkPreparation" && schedule[27][1] == "Walk") ? "OK" : "FAIL") << endl;
}

int scheduler() {
//	testAdd();
//	testNext();
	vector<vector<string>> schedule(days[currentMonth]);
	map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
	cout << m[1]  << endl;
	uint qty;
	cin >> qty;

	for(uint i = 0; i < qty; i++) {
		string cmdName;
		cin >> cmdName;

		if (cmdMapping.count(cmdName) == 0) {
			cout << "Invalid command " << cmdName;
			break;
		}

		uint day;
		string issue;

		switch (cmdMapping[cmdName]) {
		case CMD_ADD:
			cin >> day >> issue;
			day--;
			add(schedule, day, issue);
			break;
		case CMD_NEXT:
			next(schedule);
			break;
		case CMD_DUMP:
			cin >> day;
			day--;
			dump(schedule, day);
			break;
		}
	}

	return 0;
}


/*
У каждого из нас есть ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел, а именно, обработку следующих операций:
ADD is

Добавить дело с названием s в день i.
NEXT

Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий, добавленные дни изначально не будут содержать дел. Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить на последний день нового месяца.

Обратите внимание, что количество команд этого типа может превышать 11.
DUMP i

Вывести все дела в день i.

Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
Формат ввода

Сначала число операций Q, затем описания операций.

Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.
Формат вывода

Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.
*/

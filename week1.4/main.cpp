#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	const TasksInfo& GetPersonTasksInfo(const string& person)  {
		return this->persons.at(person);
	};

	void AddNewTask(const string& person) {
		if (this->persons.find(person) == this->persons.end()) {
			this->persons[person][TaskStatus::NEW] = 0;
		}
		this->persons[person][TaskStatus::NEW]++;
	};

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		TasksInfo updated, untoched;

		int undoneCnt = this->getAllUndoneTasks(person);
		if (undoneCnt == 0) {
			return make_tuple(updated, untoched);
		}

		TasksInfo& task_info = this->persons.at(person);

		updated = {
			{TaskStatus::NEW, 0},
			{TaskStatus::IN_PROGRESS, 0},
			{TaskStatus::TESTING, 0},
			{TaskStatus::DONE, 0}
		};
		untoched = {
			{TaskStatus::NEW, task_info[TaskStatus::NEW]},
			{TaskStatus::IN_PROGRESS, task_info[TaskStatus::IN_PROGRESS]},
			{TaskStatus::TESTING, task_info[TaskStatus::TESTING]}
		};

		task_count = min(task_count, this->getAllUndoneTasks(person));

		TaskStatus curentStatus = TaskStatus::NEW;
		TaskStatus nextStatus = static_cast<TaskStatus>(static_cast<uint>(curentStatus) + 1);

		while (task_count > 0) {
			if (untoched[curentStatus] > 0) {
				task_info[curentStatus]--;
				task_info[nextStatus]++;
				untoched[curentStatus]--;
				updated[nextStatus]++;
				task_count--;
			} else {
				curentStatus = nextStatus;
				nextStatus = static_cast<TaskStatus>(static_cast<uint>(nextStatus) + 1);
			}
		}

		return {this->clearEmptyStatuses(updated), this->clearEmptyStatuses(untoched)};
	};

protected:
	map<string, TasksInfo> persons;

	int getAllUndoneTasks(const string& person) const {
		int cnt = 0;

		if (this->persons.count(person) != 0) {
			for(auto p : this->persons.at(person)) {
				if (p.first != TaskStatus::DONE) {
					cnt += p.second;
				}
			}
		}

		return cnt;
	}

	TasksInfo clearEmptyStatuses(TasksInfo& tt) {
		TasksInfo result = tt;
		for(auto t : tt) {
			if (t.second == 0) {
				result.erase(t.first);
			}
		}

		return result;
	}
};


void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void MyPrint(TasksInfo updated, TasksInfo untoched) {
	cout << "[{";
	if (updated.count(TaskStatus::NEW) > 0) {
		cout << "NEW: "<< updated[TaskStatus::NEW] << ',';
	}
	if (updated.count(TaskStatus::IN_PROGRESS) > 0) {
			cout << "IN_PROGRESS: "<< updated[TaskStatus::IN_PROGRESS] << ',';
		}
	if (updated.count(TaskStatus::TESTING) > 0) {
			cout << "TESTING: "<< updated[TaskStatus::TESTING] << ',';
		}
	if (updated.count(TaskStatus::DONE) > 0) {
			cout << "DONE "<< updated[TaskStatus::DONE];
		}
	cout << "}, ";
	cout << "{";
		if (untoched.count(TaskStatus::NEW) > 0) {
			cout << "NEW: "<< untoched[TaskStatus::NEW] << ',';
		}
		if (untoched.count(TaskStatus::IN_PROGRESS) > 0) {
				cout << "IN_PROGRESS: "<< untoched[TaskStatus::IN_PROGRESS] << ',';
			}
		if (untoched.count(TaskStatus::TESTING) > 0) {
				cout << "TESTING: "<< untoched[TaskStatus::TESTING] << ',';
			}
		if (untoched.count(TaskStatus::DONE) > 0) {
				cout << "DONE: "<< untoched[TaskStatus::DONE];
			}
		cout << "}]" << endl;
}

int main() {
	TeamTasks tasks;
	TasksInfo updated_tasks, untouched_tasks;

	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");
	}
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	MyPrint(updated_tasks, untouched_tasks);

	  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	  MyPrint(updated_tasks, untouched_tasks);
	  	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
	  	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	  	MyPrint(updated_tasks, untouched_tasks);
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");
	}
	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	MyPrint(updated_tasks, untouched_tasks);

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	MyPrint(updated_tasks, untouched_tasks);


  return 0;
}

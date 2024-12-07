#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

class Employee {
private:
	char _name[32];
	int _age;
	double _salary;
	int _currentProject;

public:
	Employee(char *name, int age, double salary) : _age(age), _salary(salary), _currentProject(-1) {
		strcpy(_name, name);
	}
	virtual void setName(char *name, int size) { memcpy(_name, name, size); }
	virtual char *getName() { return _name; }
	virtual void printData() { 
		printf("Name: %s, Age: %d, Salary: %lf\n", _name, _age, _salary);
	}
	virtual void assignProject(int projectId) { _currentProject = projectId; }
	virtual void deassignProject() { _currentProject = -1; }
};

class Project {
private:
	int _projectId;
	int _employeeCount;
	Employee **_workers;
	long _version;
	void (*onProjectRelease)(char *);
public:
	static int totalProjectCount;
	Project(Employee **workers) : _projectId(Project::totalProjectCount++), _workers(workers) { _version = 0; }
	void registerCallback(void (*cb)(char *)) { onProjectRelease = cb; }
	virtual void releaseProject(char *releaseMsg) {
		onProjectRelease(releaseMsg);
		_version++;
	}
	virtual ~Project() {
		for (int i = 0; _workers[i] != nullptr; i++) {
			_workers[i]->deassignProject();
		}
	}
};

int Project::totalProjectCount = 0;

void logRelease(char *msg) {
	FILE *f = fopen("./releaseLog.txt", "r");
	fputs(msg, f);
}
void announceUsers(char *msg) {
	char cmd[128];
	sprintf(cmd, "wall '%s'", msg);
	system(cmd);
}

int main() {
	Employee *e1 = new Employee("h0n3yp0t", 43, 1337);
	Employee *e2 = new Employee("sunbather", 42, 1337);
	Employee *e3 = new Employee("zenbassi", 42, 1337);

	e1->assignProject(1);
	e2->assignProject(1);
	e3->assignProject(1);

	Employee *workers[] = {e1, e2, e3, nullptr};

	Project *p = new Project(workers);
	p->registerCallback(logRelease);

	char newName[256];
	puts("Insert name for new employee:");
	int len = read(0, newName, 255);
	e1->setName(newName, len);

	delete p;
	return 0;
}

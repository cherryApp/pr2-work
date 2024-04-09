#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Worker {
	string name;
	int birth_year;
	int hours;
	int revenue;
};

void print_data(Worker* workers, int db);
int calculate_hours(Worker* workers, int db);
Worker get_oldest_worker(Worker* workers, int db);

int main() {
	string file_name = "majus.txt";
	ifstream file_reader(file_name);
	int worker_num = 0;

	while (!file_reader.eof()) {
		string name;
		file_reader >> name;
		worker_num++;
	}

	cout << "Majusban ennyi fo dolgozott: " << worker_num << endl;

	Worker* workers = new Worker[worker_num];
	file_reader.clear();
	file_reader.seekg(0, ios::beg);
	int i = 0;

	srand(time(NULL));

	for (i = 0; i < worker_num; i++) {
		file_reader >> workers[i].name;
		do {
			cout << workers[i].name << " szuletesi eve: ";
			cin >> workers[i].birth_year;
			if (workers[i].birth_year < 1957 || workers[i].birth_year > 2004) {
				cout << endl << "1957 es 2004 kozotti evet adjon meg" << endl;
			}
		} while (workers[i].birth_year < 1957 || workers[i].birth_year > 2004);
		// workers[i].birth_year = 2000;
		workers[i].hours = rand() % 160;
		workers[i].revenue = 2800 * workers[i].hours;
	}

	print_data(workers, worker_num);
	
	cout << "Ledolgozott orak szama: " << calculate_hours(workers, worker_num) << endl << endl;

	Worker oldest = get_oldest_worker(workers, worker_num);
	cout << "A legidosebb dolgozo: " << oldest.name << ", " << oldest.birth_year << endl << endl;

	return 0;
}

void print_data(Worker* workers, int db) {
	cout << setw(20) << "Name" << setw(10) << "BD" << setw(10) << "Hours" << setw(10) << "Revenue" << endl;
	for (int i = 0; i < db; i++) {
		cout << setw(20) << workers[i].name << setw(10) << workers[i].birth_year << setw(10) 
			<< workers[i].hours << setw(10) << workers[i].revenue << endl;
	}
}

int calculate_hours(Worker* workers, int db) {
	int sum_hours = 0;
	for (int i = 0; i < db; i++) {
		sum_hours += workers[i].hours;
	}

	return sum_hours;
}

Worker get_oldest_worker(Worker* workers, int db) {
	int bd = workers[0].birth_year;
	int old_index = 0;
	for (int i = 1; i < db; i++) {
		if (workers[i].birth_year < bd) {
			old_index = i;
			bd = workers[i].birth_year;
		}
	}

	return workers[old_index];
}
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

class Eredmeny {
	public: int helyezes;
	public: int fo;
	public: string kat;
	public: string sport;

	public: Eredmeny(int h, int f, string k, string s) {
		helyezes = h;
		fo = f;
		kat = k;
		sport = s;
	}

	Eredmeny() = default;
};

struct Row {
	int helyezes;
	int fo;
	string kat;
	string sport;
};

class Helsinki {
	private: int db = 0;
	private: Eredmeny* tmb[] = new Row(200);

	public: Helsinki() {
		ifstream be("helsinki.txt");
		int i = 0;
		while (!be.eof()) {
			int h;
			int f;
			string k;
			string s;
			string temp;
			getline(be, temp, ';');
			h = stoi(temp);

			getline(be, temp, ';');
			f = stoi(temp);

			getline(be, k, ';');
			getline(be, s, ';');

			tmb[i] = Eredmeny(h, f, k, s);
			i++;
			
		}
	}

	public: Eredmeny getEredmeny(int i) {
		return tmb[i];
	}
};

int main() {
	Helsinki helsinki = Helsinki();

	cout << helsinki.getEredmeny(0).helyezes << endl;

	return 0;
}
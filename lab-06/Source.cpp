#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

inline double atvalt(double fok)
{
	return fok * 3.14159 / 180;
}

int main(int ArgDb, char* ArgTmb[])
{
	char nev[80] = "";
	if (ArgDb == 2)
	{
		strcpy_s(nev, ArgTmb[1]);
	}
	else
	{
		cout << "Adja meg a allomany nevet: ";
		cin >> nev;
	}

	cout << "Az allomany neve: " << nev << endl;

	ifstream stream;
	stream.open(nev);
	if (stream)
	{
		int db = 0;
		int szam;
		while (!stream.eof())
		{
			stream >> szam;
			db++;
		}
		cout << "Ennyi szam van a listaban: " << db << endl;

		stream.clear();
		stream.seekg(0, ios::beg);
		int* p = new int[db];
		if (p)
		{
			register int i;
			for (i = 0; i < db; i++) {
				stream >> p[i];
			}
			stream.close();

			cout << endl << "A beolvasott szamok:" << endl;
			double s = 0.0;
			for (i = 0; i < db; i++) {
				cout << setw(8) << p[i];
				s += p[i];
			}

			cout << endl << endl;
			for (i = 0; i < db; i++) {
				cout << setw(12) << atvalt(p[i]);
			}

			cout << endl << "A szamok atlaga: " << s / db << endl;
			system("pause");
			delete[] p;
			return 0;
		}
		else
		{
			cerr << "A tarfoglalas sikertelen!" << endl;
			system("pause");
			exit(3);
		}
	}
	else
	{
		cerr << "Fajl megnyitasi hiba!" << endl;
		stream.close();
		system("pause");
		exit(2);
	}

	system("pause");
	return 0;
}
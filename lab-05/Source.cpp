#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct ugynok
{
	string varos;
	int tav;
};

int beolvas(char *t, ugynok *tmb);
int ossztav(ugynok *tmb, int db);
string legtavolabb(ugynok *tmb, int db);
int kozeliekszama(ugynok *tmb, int db);
void rendezvekiir(ugynok *tmb, int db);
void rendezcsokken(ugynok* tmb, int db);

int main()
{
	char file_path[] = "vartav.txt";
	ugynok A[20];
	int cityDB = beolvas(file_path, A);

	cout << endl << "A januarban megtett osszes tavolsag: " << ossztav(A, cityDB);

	cout << endl << "A legtavolabbi varos: " << legtavolabb(A, cityDB);

	cout << endl << "A kozeli varosok szama: " << kozeliekszama(A, cityDB) << endl << endl;

	rendezvekiir(A, cityDB);

	cout << endl;

	rendezcsokken(A, cityDB);
}

int beolvas(char *t, ugynok *tmb)
{
	ifstream be(t);
	if (be.fail())
	{
		cout << "Hiba, talald ki hogy mi!";
		exit(1);
	}

	int i, j, db = 0;
	for (i = 0; i < 20 && !be.eof(); i++)
	{
		be >> tmb[i].varos;
		be >> tmb[i].tav;
		db++;
		cout << tmb[i].varos << " " << tmb[i].tav << endl;
	}

	be.close();
	return db;
}

int ossztav(ugynok *tmb, int db)
{
	int max = 0;
	for (int i = 0; i < db; i++)
	{
		max += tmb[i].tav;
	}
	return max * 2;
}

string legtavolabb(ugynok *tmb, int db)
{
	int maxIndex = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[i].tav > tmb[maxIndex].tav)
		{
			maxIndex = i;
		}
	}

	return tmb[maxIndex].varos;
}

int kozeliekszama(ugynok *tmb, int db)
{
	int nearest = 0;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].tav < 80)
		{
			nearest++;
		}
	}

	return nearest;
}

void rendezvekiir(ugynok *tmb, int db)
{
	ugynok seged;
	ofstream ki("rendtav.txt");
	if (ki.fail())
	{
		cerr << "A hiba az on keszulekeben van!";
		exit(1);
	}

	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (tmb[i].tav > tmb[j].tav)
			{
				seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}

	for (int i = 0; i < db; i++)
	{
		cout << tmb[i].varos << " " << tmb[i].tav << endl;
		ki << tmb[i].varos << " " << tmb[i].tav << endl;
	}

	ki.close();
}

void rendezcsokken(ugynok* tmb, int db)
{
	ugynok seged;
	ofstream ki("rendtav.txt");
	if (ki.fail())
	{
		cerr << "A hiba az on keszulekeben van!";
		exit(1);
	}

	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (tmb[i].varos < tmb[j].varos)
			{
				seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}

	for (int i = 0; i < db; i++)
	{
		cout << tmb[i].varos << " " << tmb[i].tav << endl;
		ki << tmb[i].varos << " " << tmb[i].tav << endl;
	}

	ki.close();
}
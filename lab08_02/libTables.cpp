#include "libTables.h"
using namespace std;

int* createTable(int Tsize)
{
	int *T = nullptr;

	try
	{
		T = new int[Tsize];
	}
	catch (bad_alloc)
	{
		std::cout << "Nie udalo sie utworzyc tablicy!";
		std::cin.ignore();
		getchar();
		exit(0);
	}

	return T;
}

int ** createTable2D(int rows, int columns)
{
	int **T = nullptr;
	try
	{
		T = new int*[rows];
	}
	catch (bad_alloc)
	{
		cout << "Nie udalo sie utworzyc tablicy!";
		exit(0);
	}

	for (int i = 0; i < rows; i++) {
		try
		{
			T[i] = new int[columns];
		}
		catch (bad_alloc)
		{
			cout << "Nie udalo sie wypelnic tablicy!";
		}
	}
	return T;
}

void fillTable2DWithNulls(int ** tab, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			tab[i][j] = 0;
		}
	}
}

void showTable(int *tab, int Tsize)
{
	for (int i = 0; i < Tsize; i++)
	{
		cout << *tab << " ";
		tab++;
		//cout<<*(t+i);
	}
}

void showTable2D(int** tab, int rows, int columns, int rIterator, int cIterator)
{
	cout << "\t";
	for (int i = cIterator; i < columns; i++)
	{
		cout << i << "\t";
	}
	cout << endl << endl;

	for (int i = rIterator; i < rows; i++)
	{
		cout << i << "\t";
		for (int j = cIterator; j < columns; j++)
		{
			cout << tab[i][j] << "\t";
		}
		cout << endl;
	}
}

void fillTableRandomNumbers(int * tab, int Tsize)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(-500, 500); //dist(pow(-2, 31), pow(2, 31)-1);

	for (int i = 0; i < Tsize; i++)
	{
		tab[i] = dist(rd);
	}
}

void sortTable(int * tab, int Tsize)
{
	sort(tab, tab + Tsize);
}

void showVector2D(vector<vector<int>> vec, int rIterator, int cIterator)
{
	cout << "\t";
	for (int i = cIterator; i < vec[0].size(); i++)
	{
		cout << i << "\t";
	}
	cout << endl << endl;

	for (int i = rIterator; i < vec.size(); i++)
	{
		cout << i << "\t";
		for (int j = cIterator; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << "\t";
		}
		cout << endl;
	}
}




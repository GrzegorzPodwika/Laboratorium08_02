#include "KnapsackProblemByDynamProg.h"
using namespace std;

void computeAndShow()
{
	//wczytanie pliku z dysku
	fstream inFile = createInputFile();

	//wczytanie najwiekszej masy z pliku
	int maxMass{};
	inFile >> maxMass;

	//utworzenie pomocniczych wektorow + wstepna inicjalizacja zerowych indexow zerami
	vector <int> massOfItems(1);
	vector <int> priceOfItems(1);

	//wypelnianie vectorow pomocniczych wartosciami z pliku
	fillVectorsWithDataFromFile(inFile, massOfItems, priceOfItems);

	unsigned int numberOfRows = massOfItems.size() + 1;
	unsigned int numberOfColumns = maxMass + 1;

	vector < vector <int> > vecBestPackings{
		numberOfRows,
		vector <int>(numberOfColumns)
	};


}


void fillVectorsWithDataFromFile(fstream & inFile, vector<int>& massOfItems, vector<int>& priceOfItems)
{
	string tmpMass{}, tmpPrice{}, tmpName{};
	while (!inFile.eof())
	{
		while (true)
		{
			inFile >> tmpName;
			if (isStringANumber(tmpName))
			{
				tmpMass = tmpName;
				break;
			}
		}

		inFile >> tmpPrice;
		if (isStringANumber(tmpPrice) == false)
		{
			cout << "Blad tresci w pliku!";
			exit(0);
		}

		massOfItems.push_back(stoi(tmpMass));
		priceOfItems.push_back(stoi(tmpPrice));
	}
}

bool isStringANumber(string str)
{
	if (str != "")
	{
		if (str[0] >= '0' && str[0] <= '9')
			return true;
	}

	return false;
}
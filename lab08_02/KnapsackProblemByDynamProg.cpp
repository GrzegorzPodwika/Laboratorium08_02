#include "KnapsackProblemByDynamProg.h"
using namespace std;

void showResultsOnScreen()
{
	//wczytanie pliku z dysku
	fstream inFile = createInputFile();

	//wczytanie najwiekszej masy z pliku
	int maxMass{};
	try
	{
		inFile >> maxMass;
		if (maxMass <= 0)
			throw EXCEPTION_CODE::notNaturalNumber;
	}
	catch (EXCEPTION_CODE error)
	{
		seeExceptions(error);
		exit(0);
	}


	//utworzenie pomocniczych wektorow + wstepna inicjalizacja zerowych indexow zerami
	vector <int> massOfItems(1);
	vector <int> priceOfItems(1);

	//wypelnianie vectorow pomocniczych wartosciami z pliku
	fillVectorsWithDataFromFile(inFile, massOfItems, priceOfItems);

	//pomocnicze zmienne, aby moc zainicjalizowac vector2D
	unsigned int numberOfRows = massOfItems.size();
	unsigned int numberOfColumns = maxMass + 1;

	//utworzenie vektora najlepszych upakowan + wstepna inicjalizacja
	vector < vector <int> > vecOfBestPackings{
		numberOfRows,
		vector <int>(numberOfColumns)
	};

	//utworzenie vektora Qij- skojarzonych z Pij rzeczy + wstepna inicjalizacja
	vector < vector <int> > vecOfConnectedItems{
	numberOfRows,
	vector <int>(numberOfColumns)
	};

	//wypenienie vektora najlepszych upakowan oraz vektora skojarzonych rzeczy Qij za pomoca programowania dynamicznego
	fillVectorOfBestPackingsByDynamProg(vecOfBestPackings, vecOfConnectedItems, massOfItems, priceOfItems);

	//pokazanie wektorow na ekran
	showVector2D(vecOfBestPackings, 1, 1);
	cout << endl << endl;
	showVector2D(vecOfConnectedItems, 1, 1);

	inFile.close();
}


void fillVectorsWithDataFromFile(fstream & inFile, vector<int>& massOfItems, vector<int>& priceOfItems)
{
	//pomocnicze zmienne do wczytywania z pliku
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

void fillVectorOfBestPackingsByDynamProg(vector<vector<int>>& vecOfBestPackings, vector < vector <int> > &vecOfConnectedItems, vector<int>& massOfItems, vector<int>& priceOfItems)
{
	//pomocnicze zmienne 
	int maxMass = vecOfBestPackings[0].size() - 1;
	int maxAmountOfItemX{};
	bool flagOfNumb{};
	int indexOfPrice{};

	for (int i = 1; i < vecOfBestPackings.size(); i++)
	{
		for (int j = 1; j < vecOfBestPackings[i].size(); j++)
		{

			maxAmountOfItemX = maxMass / massOfItems[i];

			//jesli masa przedmiotu jest => od wczytanej j masy
			if ((j - massOfItems[i]) >= 0)
			{
				//I przypadek - bierzemy k razy, k = 1,2,3, ..., n tego samego wartosciowego przedmiotu, jesli k*price[i] => P[i][j]
				//ponadto Q[i][j] = i
				for (int k = maxAmountOfItemX; k >= 1; k--)
				{
					if (j >= k * massOfItems[i] && k * priceOfItems[i] >= vecOfBestPackings[i - 1][j]) {
						vecOfBestPackings[i][j] = k * priceOfItems[i];
						vecOfConnectedItems[i][j] = i;
						break;
					}
				}

				/*II przypadek - jesli poprzedni warunek nie zaszedl, P[i][j] = max(P[i-1][j], price[i] + P[i-1][ j-weight[i] ])
				ponadto jesli P[i-1][j] jest wieksze to Q[i][j] = Q[i-1][j]
				w przeciwnym wypadku Q[i][j] = indexOfNumberEqualsToPrice(priceOfItems, price[i])
				*/
				if (vecOfBestPackings[i][j] == 0)
				{
					vecOfBestPackings[i][j] = maxOfTwoNumbers(vecOfBestPackings[i - 1][j], priceOfItems[i] + vecOfBestPackings[i - 1][j - massOfItems[i]], flagOfNumb);;

					if (flagOfNumb)
					{
						vecOfConnectedItems[i][j] = vecOfConnectedItems[i-1][j];
					}
					else
					{
						indexOfPrice = indexOfNumberEqualsToPrice(priceOfItems, priceOfItems[i]);
						vecOfConnectedItems[i][j] = indexOfPrice;
					}
				}
			}
			else
			{
				/*III przypadek - jesli masa przedmiotu jest < od wczytanej j masy, P[i][j] = P[i-1][j]
				ponadto jesli o jeden wyzej P[i-1][j] != 0 to  Q[i][j] = indexOfNumberEqualsToPrice(priceOfItems, P[i - 1][j])
				*/
				vecOfBestPackings[i][j] = vecOfBestPackings[i - 1][j];

				if (vecOfBestPackings[i - 1][j] != 0) 
				{
					indexOfPrice = indexOfNumberEqualsToPrice(priceOfItems, vecOfBestPackings[i - 1][j]);
					vecOfConnectedItems[i][j] = indexOfPrice;
				}
			}
		}

	}

}

int maxOfTwoNumbers(int numA, int numB, bool &flagOfNumb)
{
	if (numA >= numB) 
	{
		flagOfNumb = true;
		return numA;
	}
	else
	{
		flagOfNumb = false;
		return numB;
	}

}

int indexOfNumberEqualsToPrice(vector<int>& priceOfItems, int number)
{
	int searchIndex{};
	
	for (int i = 1; i < priceOfItems.size(); i++)
	{
		if (number == priceOfItems[i])
			searchIndex = i;
	}

	return searchIndex;
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
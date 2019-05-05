#ifndef KNAPSACKPROBLEMBYDYNAMPROG_H
#define KNAPSACKPROBLEMBYDYNAMPROG_H

#include "libTables.h"
#include "libFiles.h"
#include "libExceptions.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/*
Glowna funkcja pokazujaca rezultat obliczen na ekran
*/
void showResultsOnScreen();

/*
Funkcja pomocnicza sprawdzajaca czy napis jest liczba lub inaczej czy da sie skonwertowac na liczbe
@param str przysylany napis do sprawdzenia
@return true jesli jest liczba, false w przeciwnym wypadku
*/
bool isStringANumber(std::string str);

/*
Funkcja wypelniajace przyslane vectory wartosciami z pliku inFile, funkcja pomocnicza
@param inFile przysylany pli k z ktorego pobieramy wartosci
@param massOfItems vector do ktorego zostaje wpisywana masa danego przedmiotu
@param priceOfItems vector do ktorego zostaje wpisywana cena danego przedmiotu
*/
void fillVectorsWithDataFromFile(std::fstream &inFile, std::vector <int> &massOfItems, std::vector <int> &priceOfItems);

/*
Glowna funkcja z algorytmem "dynamicznym" wypelniajaca vektory Pij i Qij najlepszymi wartosciami upakowania plecaka o danej masie
@param vecOfBestPackings vektor2D najlepszych upakowan Pij
@param vecOfConnectedItems vektor2D skojarzonych rzeczy Qij
@param massOfItems vektor mas poszczegolnych rzeczy
@param priceOfItems vektor cen poszczegolnych rzeczy
*/
void fillVectorOfBestPackingsByDynamProg(std::vector < std::vector <int> > &vecOfBestPackings, std::vector < std::vector <int> > &vecOfConnectedItems, std::vector <int> &massOfItems, std::vector <int> &priceOfItems);

/*
Funkcja pomocnicza sprawdzajaca ktora z liczb jest wieksza, dodatkowo za pomoca flagNumb wskazujaca czy pierwsza czy druga
@param numA pierwsza liczba do sprawdzenia
@param numbB druga liczba do sprawdzenia
@param flagOfNumb flaga boolowska, jesli numA jest wieksze to rowna sie true, w przeciwnym wypadku false
@return wieksza sposrod tych dwoch liczb
*/
int maxOfTwoNumbers(int numA, int numB, bool &flagOfNumb);

/*
Funkcja zwracajaca index i pod ktorym kryje sie cena rowna przysylanej liczbie
@param priceOfItems vektor cen poszczegolnych rzeczy
@param number przysylany numer do sprawdzenia
@return index i pod ktorym kryje sie cena rowna przysylanej liczbie
*/
int indexOfNumberEqualsToPrice(std::vector <int> &priceOfItems, int number);

#endif // !KNAPSACKPROBLEMBYDYNAMPROG_H


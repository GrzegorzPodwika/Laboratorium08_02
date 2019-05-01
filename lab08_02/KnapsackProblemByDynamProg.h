#ifndef KNAPSACKPROBLEMBYDYNAMPROG_H
#define KNAPSACKPROBLEMBYDYNAMPROG_H

#include "libFiles.h"
#include "libTables.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void computeAndShow();

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

#endif // !KNAPSACKPROBLEMBYDYNAMPROG_H


#ifndef LIBTABLES_H
#define LIBTABLES_H

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

/*
Funkcja tworzaca dynamiczna tablice jednowymiarowa
@param	Tsize rozmiar tablicy, jaka chcemy utworzyc
@return	adres utworzonej tablicy
*/
int* createTable(int Tsize);

/*
Funkcja tworzaca dynamiczna tablice dwuwymiarowa
@param	rows liczba wierszy
@param	columns liczba kolumn
@return	adres utworzonej tablicy
*/
int **createTable2D(int rows, int columns);

/*
Funkcja wypelniajaca tablice dwuwymiarowa zerami
@param	rows liczba wierszy
@param	columns liczba kolumn
*/
void fillTable2DWithNulls(int** tab, int rows, int columns);

/*
Funkcja pokazujaca na ekranie zawartosc przeslanej tablicy jednowymiarowej
@param	tab adres zerowego elementu tablicy jendowymiarowej dynamicznej
@param	Tsize rozmiar przesy³anej tablicy
*/
void showTable(int *tab, int Tsize);

/*
Funkcja pokazujaca na ekranie zawartosc przeslanej tablicy dwuwymiarowej
@param	tab adres zerowego elementu tablicy dwuwymiarowej dynamicznej
@param	rows liczba wierszy
@param	columns liczba kolumn
@param	rIterator iterator od jakiego wiersza chcemy pokazywac tablice, domyslnie 0
@param	cIterator iterator od jakiej kolumny chcemy pokazywac tablice, domylsnie 0
*/
void showTable2D(int** tab, int rows, int columns, int rIterator = 0, int cIterator = 0);

/*
Funkcja wype³niaj¹ca przes³ana tablice lodowymi wartosciami
@param	tab adres zerowego elementu tablicy jendowymiarowej dynamicznej
@param	Tsize rozmiar przesylanej tablicy
*/
void fillTableRandomNumbers(int *tab, int Tsize);

/*
Funkcja sortujaca niemalejaco przeslana tablice
@param	tab adres zerowego elementu tablicy jednowymiarowej dynamicznej
@param	Tsize rozmiar przesylanej tablicy
*/
void sortTable(int *tab, int Tsize);

/*
Funkcja pokazujaca vector2D na ekran

param vec vector2D do pokazania na ekran
@param rIterator iterator pomocniczy, od jakiego wiersza vectora chcemy pokazywac zawartosc, domyslnie 0
@param cIterator iterator pomocniczy, od jakiej kolumny vectora chcemy pokazywac zawartosc, domyslnie 0
*/
void showVector2D(std::vector< std::vector <int> > vec, int rIterator = 0, int cIterator = 0);

#endif
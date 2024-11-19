#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std;

string getFileName(const string& prompt);
double convertToUAH(double priceUSD, double exchangeRate);
bool processFile(const string& inputFile, const string& outputFile, double exchangeRate);
void showMenu();

#endif

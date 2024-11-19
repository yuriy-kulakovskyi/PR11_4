#include "../include/functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

string getFileName(const string& prompt) {
  string filename;
  cout << prompt;
  getline(cin, filename);
  return filename;
}

double convertToUAH(double priceUSD, double exchangeRate) {
  return priceUSD * exchangeRate;
}

bool processFile(const string& inputFile, const string& outputFile, double exchangeRate) {
  ifstream inFile(inputFile);
  ofstream outFile(outputFile);

  if (!inFile) {
    cerr << "Не вдалося відкрити вхідний файл: " << inputFile << endl;
    return false;
  }

  if (!outFile) {
    cerr << "Не вдалося створити вихідний файл: " << outputFile << endl;
    return false;
  }

  string line;
  while (getline(inFile, line)) {
    stringstream ss(line);
    string companyName, productName;
    double priceUSD;

    if (!(ss >> companyName >> productName >> priceUSD)) {
      cerr << "Помилка формату у рядку: " << line << endl;
      continue;
    }

    double priceUAH = convertToUAH(priceUSD, exchangeRate);

    outFile << companyName << " " << productName << " " << fixed << setprecision(2) << priceUSD
            << " USD " << priceUAH << " UAH" << endl;
  }

  cout << "Обробка завершена. Дані записано у файл: " << outputFile << endl;
  return true;
}

void showMenu() {
  cout << "=== Меню ===" << endl;
  cout << "1. Перерахувати ціни у гривні" << endl;
  cout << "2. Вихід" << endl;
  cout << "Ваш вибір: ";
}

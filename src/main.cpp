#include <iostream>
#include <fstream>
#include <string>
#include "../include/functions.h"

using namespace std;

int main() {
  string inputFile, outputFile;
  double exchangeRate;

  while (true) {
    showMenu();
    int choice;
    cin >> choice;
    cin.get();
    cin.sync();

    if (choice == 1) {
      inputFile = getFileName("Введіть ім'я вхідного файлу: ");
      outputFile = getFileName("Введіть ім'я вихідного файлу: ");
      cout << "Введіть курс гривні (UAH за 1 USD): ";
      cin >> exchangeRate;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера вводу

      if (exchangeRate <= 0) {
        cerr << "Курс має бути додатнім числом!" << endl;
        continue;
      }

      processFile(inputFile, outputFile, exchangeRate);
    } else if (choice == 2) {
      cout << "Програма завершена." << endl;
      break;
    } else {
      cerr << "Невірний вибір. Спробуйте ще раз." << endl;
    }
  }

  return 0;
}
// Section1-Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <Windows.h>
using namespace std;

void printMainMenu() {
	cout << "Please choose an option: " << endl;
	cout << "1. Kilograms and grams to pounds and ounces." << endl;
	cout << "2. Pounds and ounces to kilograms and grams." << endl;
	cout << "3. Quit." << endl;
}

void printOptionOne() {
	cout << "Please enter a weight in kilograms and grams." << endl;
}

void printOptionTwo() {
	cout << "Please enter a weight in kilograms and grams." << endl;
}

void printOptionOneMenuTwo() {
	cout << "Would you like to convert another weight, or get min, max and average?" << endl;
	cout << "1. Convert another weight" << endl;
	cout << "2. Get min, max, and average of all weights entered." << endl;
}

double convertKilosToPounds(double weight) {
	double result = weight * 2.2046;
	return result;
}

double convertPoundsToKilos(double weight) {
	double result = weight / 2.2046;
	return result;
}

double findAverage(vector<double> conversions) {
	double average = accumulate(conversions.begin(), conversions.end(), 0.00) / conversions.size();
	return average;
}

double findMin(vector<double> conversions) {
	int min = conversions[0];
	for (int i = 0; i < conversions.size(); i++) {
		if (conversions[i] < min) {
			min = conversions[i];
		}
	}
	return min;
}

double findMax(vector<double> conversions) {
	int max = conversions[0];
	for (int i = 0; i < conversions.size(); i++) {
		if (conversions[i] > max) {
			max = conversions[i];
		}
	}
	return max;
}

void minMaxAverageCalculation(vector<double> conversions) {
	cout << "The average weight is: " << findAverage(conversions) << endl;
	cout << "The minimum value is: " << findMin(conversions) << endl;
	cout << "The maximum value is: " << findMax(conversions) << endl;
}

int main()
{
	int option = -1, option2 = -1, operationCount = 0;
	vector<double> conversions; // Vector where all conversions are stored. Used to calculate min, max, and average.
	double weightToConvert, converted;

	while (option != 3)
	{
		system("CLS");
		operationCount = 0; // Reset operation count.
		conversions.clear(); // Clear all conversions in the vector.
		printMainMenu(); // Prints the main menu.
		cout << endl;
		cin >> option;

		switch (option) {
		case 1:
			cout << "You selected option 1." << endl << endl;
			printOptionOne(); // Prints the 
			cin >> weightToConvert;
			converted = convertKilosToPounds(weightToConvert); // Converts the input to pounds from kilos.
			operationCount++; // Increment operationCount.
			cout << "You converted " << weightToConvert << " to " << converted << endl << endl;
			conversions.push_back(converted); // Add the converted weight to the end of the vector.
			printOptionOneMenuTwo(); // Print the sub menu asking if the user wants to convert another number or get the min, max, and average.
			cin >> option2;

			while (option2 != 2) { // Loop until we no longer want to convert anymore numbers.
				if (operationCount >= 15) { // This is to check if we arent at the max conversions yet.
					cout << "Max conversions!" << endl;
					//minMaxAverageCalculation(conversions);
					Sleep(2000); // Add a little delay before breaking out of the loop.
					break;
				}

				printOptionOne();
				cin >> weightToConvert;
				converted = convertKilosToPounds(weightToConvert);
				operationCount++;
				cout << "You converted " << weightToConvert << " to " << converted << endl << endl;
				conversions.push_back(converted);
				printOptionOneMenuTwo();
				cin >> option2;
			}

			minMaxAverageCalculation(conversions);
			Sleep(2000);
			break;

		case 2:
			cout << "You selected option 1." << endl << endl;
			printOptionTwo();
			cin >> weightToConvert;
			converted = convertKilosToPounds(weightToConvert);
			operationCount++;
			cout << "You converted " << weightToConvert << " to " << converted << endl << endl;
			conversions.push_back(converted);
			printOptionOneMenuTwo();
			cin >> option2;

			while (option2 != 2) {
				if (operationCount >= 15) {
					cout << "Max conversions!" << endl;
					//minMaxAverageCalculation(conversions);
					Sleep(2000);
					break;
				}

				printOptionOne();
				cin >> weightToConvert;
				converted = convertKilosToPounds(weightToConvert);
				operationCount++;
				cout << "You converted " << weightToConvert << " to " << converted << endl << endl;
				conversions.push_back(converted);
				printOptionOneMenuTwo();
				cin >> option2;
			}

			minMaxAverageCalculation(conversions);
			Sleep(2000);
			break;
		case 3:
			cout << "Thanks for using!" << endl;
			return 0;
		}
	}

	system("pause");
	return 0;
}




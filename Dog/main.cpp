#include <iostream>
#include "Dogs.h"

using namespace std;

int main() {
    try {
        Dogs dogData;
        dogData.readDataFromFile("dog_data.txt");

        int choice;
        string country;

        do {
            cout << "\nMenu:\n";
            cout << "1. See total number of dogs in the world\n";
            cout << "2. Input a country name to find out how many dogs are in that country\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    dogData.displayTotalDogs();
                    break;

                case 2:
                    cout << "Enter the country name: ";
                    cin.ignore(); // Clear newline character from buffer
                    getline(cin, country);

                    try {
                        int dogsInCountry = dogData.getDogsInCountry(country);
                        cout << "Number of dogs in " << country << ": " << dogsInCountry << endl;
                    } catch (const out_of_range& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;

                case 3:
                    cout << "Exiting program.\n";
                    break;

                default:
                    cerr << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 3);
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1; // Return error code
    }

    return 0; // Return success code
}

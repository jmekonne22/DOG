#include "Dogs.h"
#include <fstream>
#include <stdexcept>

Dogs::Dogs() : totalDogs(0) {}

void Dogs::readDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error opening file.");
    }

    std::string country;
    int population;

    while (inputFile >> country >> population) {
        dogPopulation[country] = population;
        totalDogs += population;
    }

    inputFile.close();
}

void Dogs::displayTotalDogs() const {
    std::cout << "Total number of dogs in the world: " << totalDogs << std::endl;
}

int Dogs::getDogsInCountry(const std::string& country) const {
    if (dogPopulation.find(country) != dogPopulation.end()) {
        return dogPopulation.at(country);
    } else {
        throw std::out_of_range("Country not found.");
    }
}

#ifndef DOGS_H
#define DOGS_H

#include <unordered_map>
#include <string>

class Dogs {
private:
    std::unordered_map<std::string, int> dogPopulation;
    int totalDogs;

public:
    Dogs();
    void readDataFromFile(const std::string& filename);
    void displayTotalDogs() const;
    int getDogsInCountry(const std::string& country) const;
};

#endif // DOGS_H

//https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>

int main(int argc, char* argv[]) {

    // Open dataset file
    std::ifstream dataSet(argv[1]);

    // Open commands file
    std::ifstream commands(argv[2]);

    // Set and map to store data
    std::set<std::string> countries;
    std::map<std::string, std::map<std::string, int>> covidData;

    std::string line;

    // Skip the header line
    std::getline(dataSet, line);

    // Read data line by line
    while (std::getline(dataSet, line)) {
        std::stringstream ss(line);
        std::string FIPS, Admin2, Province_State, Country_Region, Last_Update, Lat, Long_, Confirmed;

        // Parse the line
        std::getline(ss, FIPS, ',');
        std::getline(ss, Admin2, ',');
        if (ss.peek() == '"') {
            ss.get();
            std::getline(ss, Province_State, '"');
            ss.ignore(1); // Skip the comma after closing quote
        } else {
            std::getline(ss, Province_State, ',');
        }
        //std::getline(ss, Province_State, ',');
        if (ss.peek() == '"') {
            ss.get();
            std::getline(ss, Country_Region, '"');
            ss.ignore(1); // Skip the comma after closing quote
        } else {
            std::getline(ss, Country_Region, ',');
        }
        std::getline(ss, Last_Update, ',');
        std::getline(ss, Lat, ',');
        std::getline(ss, Long_, ',');
        std::getline(ss, Confirmed, ',');

        // Add to the set
        countries.insert(Country_Region);
        //does not have a state/province, then use the country as the key**.
        // Add to the map
        int confirmedCases = 0;
        if (!Confirmed.empty()) {
            confirmedCases = std::stoi(Confirmed);
            if(Province_State == ""){
                Province_State = Country_Region;
                //covidData[Country_Region][Country_Region] += confirmedCases;
            }
        }
        covidData[Country_Region][Province_State] += confirmedCases;

    }

    // Close the dataset file
    dataSet.close();

    // Process commands
    while (std::getline(commands, line)) {
        std::string command;
        std::stringstream lineStream(line);
        
        // Read the command (set/map)
        lineStream >> command;

        if (command == "set") {
            std::string country;
            std::getline(lineStream, country); // Get the rest of the line after "set"
            // Delete spacing from country
            while (!country.empty() && (country[0] == ' ' || country[0] == '\t')) {
                country.erase(country.begin()); // Remove spaces
            }

            if (countries.count(country) > 0) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        } else if (command == "map") {
            std::string mapCommand;
            std::getline(lineStream, mapCommand); // Get the rest of the line after "map"
            while (!mapCommand.empty() && (mapCommand[0] == ' ' || mapCommand[0] == '\t')) {
                mapCommand.erase(mapCommand.begin()); // Remove spaces
            }

            int semicolon = mapCommand.find(';');
            if (semicolon == std::string::npos) {
                // No semicolon, map <country>
                std::string country = mapCommand;

                if (covidData.find(country) != covidData.end()) {
                    int totalCases = 0;
                    for (const auto& stateEntry : covidData[country]) {
                        totalCases += stateEntry.second;
                    }
                    std::cout << totalCases << "\n";
                } else {
                    std::cout << "-1\n";
                }
            } else {
                // map <country>;<state>
                std::string country = mapCommand.substr(0, semicolon);
                std::string state = mapCommand.substr(semicolon + 1);

                if (covidData.find(country) != covidData.end() &&
                    covidData[country].find(state) != covidData[country].end()) {
                    std::cout << covidData[country][state] << "\n";
                } else {
                    std::cout << "-1\n";
                }
            }
        } 
    }

    // Close the commands file
    commands.close();

    return 0;
}


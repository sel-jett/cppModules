#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        float value;
        std::getline(ss, date, ',');
        ss >> value;
        csv_data[date] = value;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        csv_data = other.csv_data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::printData() const {
    std::map<std::string, float>::const_iterator it = csv_data.begin();
    while (it != csv_data.end()) {
        std::cout << it->first << " | " << it->second << std::endl;
        it++;
    }
}

void BitcoinExchange::readData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open " << filename << std::endl;
        return;
    }
    std::string line;
    bool first_line = true;
    while (std::getline(file, line)) {
        if (first_line) {
            if (line.length() > 0 && line[line.length() - 1] == '\r') {
                line = line.substr(0, line.length() - 1);
                }
            if (line != "date | value") {
                std::cout << "Error: bad input => " << line << std::endl;
                return;
            }
            first_line = false;
            continue;
        }

        std::stringstream ss(line);
        std::string date;
        float value;

        if (!std::getline(ss, date, '|') || line.find('|') == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        ss >> value;
        if (date.empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (date.length() != 11 || date[4] != '-' || date[7] != '-') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        std::map<std::string, float>::const_iterator it = csv_data.begin();
        std::map<std::string, float>::const_iterator closest = csv_data.end();
        std::string closest_date = "";
        
        while (it != csv_data.end()) {
            if (date == it->first) {
                std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
                break;
            }
            
            if (it->first <= date) {
                if (closest == csv_data.end() || it->first > closest->first) {
                    closest = it;
                    closest_date = it->first;
                }
            }
            it++;
        }
        
        if (it == csv_data.end() && closest != csv_data.end()) {
            std::cout << date << " => " << value << " = " << (value * closest->second) << std::endl;
        }

    }
}
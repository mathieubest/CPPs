#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : map(copy.map), buff(copy.buff) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->map = other.map;
        this->buff = other.buff;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {};

void BitcoinExchange::readcsv(const std::string& filename) {
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        throw std::runtime_error("Error opening file: " + filename);
    }
    std::stringstream ss;
    ss << inFile.rdbuf();
    buff = ss.str();
}

void BitcoinExchange::parsecsv(std::string &buffer) {
    if (buffer.empty()) {
        throw std::runtime_error("Nothing in the buffer.");
    }
    checkHeaderCsv(buffer);
    std::string line;
    std::istringstream datacsv(buffer);
    std::getline(datacsv, line);
    while(std::getline(datacsv, line)) {
        if (line.size() < 12 || line[10] != ',' || !std::isdigit(line[11])) {
            throw std::runtime_error("Error: Invalid format in data.csv. Expected digit after comma in: " + line);
        }
        std::istringstream lineStream(line);
        std::string date;
        std::string price;
        if (std::getline(lineStream, date, ',') && std::getline(lineStream, price)) {
            if (!checkDateFormat(date)) {
                throw std::runtime_error("Error: Invalid date format in data.csv: " + date);
            }
            double btcPrice = checkPriceCsv(price);
            this->map.insert(std::pair<std::string, double>(date, btcPrice));
        }
    }
}

bool BitcoinExchange::checkInput(char* av) {
    std::ifstream inFile(av);
    if (!inFile) {
        std::cout << "Error opening the file." << std::endl;
        return false;
    }

    std::string line;
    if (!getline(inFile, line)) {
        std::cout << "Error: Empty file." << std::endl;
        inFile.close();
        return false;
    }

    while(getline(inFile, line)) {
        size_t delimPos = line.find(" | ");
        if (delimPos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimPos);
        std::string price = line.substr(delimPos + 3);

        if(!checkDate(date)) {
            continue;
        }

        double amount = checkAmountInput(price);
        if (amount < 0) {
            continue;
        }

        double btcPrice = findClosestPrice(date);
        if (btcPrice >= 0) {
            double result = amount * btcPrice;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        } else {
            std::cout << "Error: No valid price found for date " << date << std::endl;
        }
    }

    inFile.close();
    return true;
}

//# Helper functions
void BitcoinExchange::checkHeaderCsv(std::string &buffer) {
    std::string line;
    std::istringstream datacsv(buffer);
    if(std::getline(datacsv, line)) {
        if (line != "date,exchange_rate") {
            throw std::runtime_error("Error: Invalid header format. Expected 'date,exchange_rate'");
        }
    }
}

bool BitcoinExchange::checkDateFormat(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7) {
            if (!std::isdigit(date[i])) {
                return false;
            }
        }
    }
    return true;
}

double BitcoinExchange::checkPriceCsv(const std::string& price) {
    char* endptr = NULL;
    double btcPrice = std::strtod(price.c_str(), &endptr);
    if (endptr == price.c_str() || *endptr != '\0') {
        throw std::runtime_error("Error: Invalid price value: " + price);
    }
    if (btcPrice < 0) {
        throw std::runtime_error("Error: Invalid price value: " + price);
    }
    return btcPrice;
}

double BitcoinExchange::checkAmountInput(const std::string& balance) {
    char* endptr = NULL;
    double amount = std::strtod(balance.c_str(), &endptr);

    if (endptr == balance.c_str() || *endptr != '\0') {
        std::cout << "Error: Invalid amount value: " << balance << std::endl;
        return -1;
    }
    if (amount < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return -1;
    }
    if (amount > 1000) {
        std::cout << "Error: too large number." << std::endl;
        return -1;
    }
    return amount;
}

bool BitcoinExchange::checkDate(const std::string& date) {
    if (!checkDateFormat(date)) {
        std::cout << "Error: Invalid date format: " << date << std::endl;
        return false;
    }

    long year, month, day;
    try {
        year = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
        month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
        day = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
    } catch (const std::exception& e) {
        std::cout << "Error: Unable to parse date components from " << date << std::endl;
        return false;
    }

    if (!beforeMinimumDate(date, year, month, day)) {
        return false;
    }
    if (month < 1 || month > 12) {
        std::cout << "Error: Invalid month (" << month << ") in date " << date << std::endl;
        return false;
    }
    if (bisextile(year) && month == 2) {
        if (day < 1 || day > 29) {
            std::cout << "Error: Invalid day (" << day << ") in date " << date << std::endl;
            return false;
        }
    }
    if (!bisextile(year) && month == 2) {
        if (day < 1 || day > 28) {
            std::cout << "Error: Invalid day (" << day << ") in date " << date << std::endl;
            return false;
        }
    }
    if (shortMonth(month)) {
        if (day < 1 || day > 30) {
            std::cout << "Error: Invalid day (" << day << ") in date " << date << std::endl;
            return false;
        }
    }
    if (longMonth(month)) {
        if (day < 1 || day > 31) {
            std::cout << "Error: Invalid day (" << day << ") in date " << date << std::endl;
            return false;
        }
    }

    return true;
}

bool BitcoinExchange::beforeMinimumDate(const std::string& date, long year, long month, long day) {
    if (year < 2009 || (year == 2009 && (month < 1 || (month == 1 && day < 2)))) {
        std::cout << "Error: Date " << date << " is before 2009-01-02" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::bisextile(long year) {
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

bool BitcoinExchange::shortMonth(long month) {
    const long shortMonths[] = {4, 6, 9, 11};
    const int sizeArr = sizeof(shortMonths) / sizeof(shortMonths[0]);

    for (int i = 0; i < sizeArr; i++) {
        if (month == shortMonths[i]) {
            return true;
        }
    }
    return false;
}

bool BitcoinExchange::longMonth(long month) {
    const long longMonths[] = {1, 3, 5, 7, 8, 10, 12};
    const int sizeArr = sizeof(longMonths) / sizeof(longMonths[0]);

    for (int i = 0; i < sizeArr; i++) {
        if (month == longMonths[i]) {
            return true;
        }
    }
    return false;
}

double BitcoinExchange::findClosestPrice(const std::string& date) {
    // First, check if the exact date exists in the map
    std::map<std::string, double>::iterator it = map.find(date);
    if (it != map.end()) {
        return it->second;
    }

    // If not found, find the closest previous date
    it = map.lower_bound(date);
    --it;
    return it->second;
}

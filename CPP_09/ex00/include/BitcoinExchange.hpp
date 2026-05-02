#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

class BitcoinExchange {
    private:
        std::map<std::string, double> map;

        static void    checkHeaderCsv(std::string &buffer);
        static bool    checkDateFormat(const std::string& date);
        static double  checkPriceCsv(const std::string& price);
        static double  checkAmountInput(const std::string& balance);
        static bool    checkDate(const std::string& date);
        double         findClosestPrice(const std::string& date);

        static bool    beforeMinimumDate(const std::string& date, long year, long month, long day);
        static bool    bisextile(long year);
        static bool    shortMonth(long month);
        static bool    longMonth(long month);

    public:
        std::string buff;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    readcsv(const std::string& filename);
        void    parsecsv(std::string &buffer);
        bool    checkInput(char* av);
};

#endif

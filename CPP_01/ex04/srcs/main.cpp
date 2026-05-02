#include <iostream>
#include <string>
#include <fstream>

#define BOLD_RED "\033[1;31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

bool    replaceString(std::string &line, const std::string &from, const std::string &to);
int     checkInStream(std::ifstream &stream, std::string &filename);
int     checkOutStream(std::ofstream &stream, std::string &filename);

int main(int ac, char **av) {

    if (ac != 4) {
        std::cerr << BOLD_RED << "You don't have the right number of arguments..." << RESET << std::endl;
        std::cerr << BOLD << "Usage: ./main filename str1 str2" << RESET << std::endl;
        return 1;
    }

    std::string filename = av[1];
    const std::string s1 = av[2];
    const std::string s2 = av[3];

    std::ifstream inStream(filename.c_str());
    if (!checkInStream(inStream, filename)) {
        return 1;
    }
    
    std::string newfile = filename + ".replace";
    std::ofstream outStream(newfile.c_str());
    if (!checkOutStream(outStream, newfile)) {
        return 1;
    }

    std::string line;
    while(getline(inStream, line)) {
        if (!replaceString(line, s1, s2)) {
            return 1;
        }
        outStream << line << std::endl;
    }

    inStream.close();
    outStream.close();

    std::ifstream oldfile(filename.c_str());
    if (!checkInStream(oldfile, filename)) {
        return 1;
    }
    std::cout << "Printing out the old file:" << std::endl;

    while(getline(oldfile, line)) {
        std::cout << line << std::endl;
    }

    std::ifstream newfileStream((filename + ".replace").c_str());
    if (!checkInStream(newfileStream, newfile)) {
        std::cerr << BOLD_RED << "Error opening " << filename << ".replace" << RESET << std::endl;
        return 1;
    }

    std::cout << "\nPrinting out the replaced file:" << std::endl;
    while(getline(newfileStream, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}

bool    replaceString(std::string &line, const std::string &from, const std::string &to) {
    if (from.empty()) {
        std::cout << "You are trying to replace an empty string" << std::endl;
        return false;
    }
    size_t start_pos = 0;
    while ((start_pos = line.find(from, start_pos)) != std::string::npos) {
        line.erase(start_pos, from.length());
        line.insert(start_pos, to);
        start_pos += to.length();
    }
    return true;
}

int checkInStream(std::ifstream &stream, std::string &filename) {
    if (!stream) {
        std::cerr << BOLD_RED << "Error opening " << filename << RESET << std::endl;
        return 0;
    }
    return 1;
}

int checkOutStream(std::ofstream &stream, std::string &filename) {
    if (!stream) {
        std::cerr << BOLD_RED << "Error opening " << filename << RESET << std::endl;
        return 0;
    }
    return 1;
}
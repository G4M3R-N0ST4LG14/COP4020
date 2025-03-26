// Arturo Lara
// Problem 3

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


int countAlphabets(const std::string& filename) {

    std::ifstream inFile(filename);
    // If it can't open the file there will be an error message
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    char ch;
    int count = 0;
    while (inFile.get(ch)) {
        if (std::isalpha(ch)) {
            count++;
        }
    }
    
    inFile.close();
    return count;
}

int main() {
    std::string filename = "OUT.TXT";
    int alphabetCount = countAlphabets(filename);
    
    if (alphabetCount != -1) {
        std::cout << "Number of alphabets in " << filename << ": " << alphabetCount << std::endl;
    }
    
    return 0;
}

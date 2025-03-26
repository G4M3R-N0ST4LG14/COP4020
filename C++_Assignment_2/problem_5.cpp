// Arturo Lara
// Problem 5

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

int countWords(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    std::string word;
    int count = 0;
    while (inFile >> word) { // Read words using stream extraction
        count++;
    }
    
    inFile.close();
    return count;
}

int main() {
    std::string filename = "OUT.TXT";
    int wordCount = countWords(filename);
    
    if (wordCount != -1) {
        std::cout << "Number of words in " << filename << ": " << wordCount << std::endl;
    }
    
    return 0;
}
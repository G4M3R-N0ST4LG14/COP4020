// Arturo Lara
// Problem 6

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

int countThe(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    std::string word;
    int count = 0;
    while (inFile >> word) { // Read words using stream extraction
        if (word == "the" || word == "The") {
            count++;
        }
    }
    
    inFile.close();
    return count;
}

int main() {
    std::string filename = "STORY.TXT";
    int theCount = countThe(filename);

    if (theCount != -1) {
        std::cout << "Number of occurrences of 'the' in " << filename << ": " << theCount << std::endl;
    }
}
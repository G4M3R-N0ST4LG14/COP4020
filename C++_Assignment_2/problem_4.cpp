// Arturo Lara
// Problem 4

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int countBlanks(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    char ch;
    int count = 0;
    while (inFile.get(ch)) {
        if (ch == ' ') {
            count++;
        }
    }
    
    inFile.close();
    return count;
}

int main() {
    std::string filename = "OUT.TXT";
    int blankCount = countBlanks(filename);
    
    if (blankCount != -1) {
        std::cout << "Number of blanks in " << filename << ": " << blankCount << std::endl;
    }
    
    return 0;
}

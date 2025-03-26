// Arturo Lara
// Problem 7

#include <iostream>
#include <fstream>
#include <string>

int countLinesNotStartingWithA(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    
    std::string line;
    int count = 0;
    while (std::getline(inFile, line)) {
        if (line.empty() || (line[0] != 'A' && line[0] != 'a')) {
            count++;
        }
    }
    
    inFile.close();
    return count;
}

int main() {
    std::string filename = "STORY.TXT";
    int lineCount = countLinesNotStartingWithA(filename);
    
    if (lineCount != -1) {
        std::cout << "Number of lines not starting with 'A' in " << filename << ": " << lineCount << std::endl;
    }
    
    return 0;
}

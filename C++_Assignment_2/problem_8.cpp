// Arturo Lara
// Problem 8

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void copyUpper() {
    std::ifstream inFile("FIRST.TXT");
    std::ofstream outFile("SECOND.TXT");
    
    if (!inFile || !outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    std::string word;
    while (inFile >> word) {
        for (char &ch : word) {
            ch = std::toupper(ch);
        }
        outFile << word << " ";
    }
    
    inFile.close();
    outFile.close();
    std::cout << "Words copied in uppercase to SECOND.TXT successfully!" << std::endl;
}

int main() {
    copyUpper();
    return 0;
}

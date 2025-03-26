// Arturo Lara
// Problem 9

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void vowelWords() {
    std::ifstream inFile("FIRST.TXT");
    std::ofstream outFile("SECOND.TXT");
    
    if (!inFile || !outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    std::string word;
    while (inFile >> word) {
        if (!word.empty() && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) {
            outFile << word << " ";
        }
    }
    
    inFile.close();
    outFile.close();
    std::cout << "Words starting with lowercase vowels copied to SECOND.TXT successfully!" << std::endl;
}

int main() {
    vowelWords();
    return 0;
}

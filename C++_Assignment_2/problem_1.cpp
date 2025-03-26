// Arturo Lara
// Problem 1

#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("NOTES.TXT"); 
    
    // If it can't make the file there will be an error message
    if (!outFile) { 
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    for (int i = 1; i <= 100; ++i) {
        outFile << i << std::endl;
    }
    
    outFile.close();
    
    std::cout << "NOTES.TXT file successfully written" << std::endl;
    return 0;
}

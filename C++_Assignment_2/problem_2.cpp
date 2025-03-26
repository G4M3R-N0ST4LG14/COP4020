// Arturo Lara
// Problem 2


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("OUT.TXT");
    
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string text = "Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
    outFile << text << std::endl;
    
    outFile.close(); 
    
    std::cout << "OUT.TXT file successfully written" << std::endl;
    return 0;
}

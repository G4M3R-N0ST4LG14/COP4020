// Arturo Lara
// Problem 12

#include <iostream>
#include <fstream>
#include <string>

struct Computer {
    char chiptype[10];
    int speed;
};

void readFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    Computer comp;
    int count = 0;
    std::cout << "\n--- Computer Records ---\n";
    while (inFile.read(reinterpret_cast<char*>(&comp), sizeof(Computer))) {
        std::cout << "Chip: " << comp.chiptype << " | Speed: " << comp.speed << " MHz" << std::endl;
        count++;
    }
    std::cout << "-------------------------\n";
    std::cout << "Total records found: " << count << std::endl;
    inFile.close();
}

int main() {
    std::string filename = "SHIP.DAT";
    readFile(filename);
    return 0;
}

// Arturo Lara
// Problem 13

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

struct Student {
    char S_Admno[10];    
    char S_Name[30];      
    int Percentage;       
};

void readHighScorers(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    Student stu;
    bool found = false;
    std::cout << "\n--- Students with Percentage Above 75 ---\n";
    std::cout << std::setw(12) << "Adm No" << std::setw(32) << "Name" << std::setw(10) << "Percentage" << std::endl;
    while (inFile.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        if (stu.Percentage > 75) {
            std::cout << std::setw(12) << stu.S_Admno << std::setw(32) << stu.S_Name << std::setw(10) << stu.Percentage << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No students with percentage above 75 found." << std::endl;
    }
    
    std::cout << "------------------------------------------\n";
    inFile.close();
}

int main() {
    std::string filename = "STUDENT.DAT";
    readHighScorers(filename);
    return 0;
}

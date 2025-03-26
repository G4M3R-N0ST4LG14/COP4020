// Arturo lara
// Problem 10

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

struct EMPLOYEE {
    int ENO;
    char ENAME[10];
};

void writeToBinaryFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    EMPLOYEE emp;
    std::string input;

    std::cout << "Enter Employee Number: ";
    while (true) {
        std::getline(std::cin, input);
        try {
            emp.ENO = std::stoi(input); 
            break;
        } catch (...) {
            std::cout << "Invalid input! Enter a valid Employee Number: ";
        }
    }

    std::cout << "Enter Employee Name: ";
    std::getline(std::cin, input);
    strncpy(emp.ENAME, input.c_str(), sizeof(emp.ENAME) - 1);
    emp.ENAME[sizeof(emp.ENAME) - 1] = '\0';  

    outFile.write(reinterpret_cast<const char*>(&emp), sizeof(EMPLOYEE));
    outFile.close();
    std::cout << "Employee data written successfully!\n";
}

void readFromBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    EMPLOYEE emp;
    std::cout << "\n--- Employee Records ---\n";
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(EMPLOYEE))) {
        std::cout << "Employee Number: " << emp.ENO << ", Name: " << emp.ENAME << std::endl;
    }
    std::cout << "------------------------\n";
    inFile.close();
}

int main() {
    std::string filename = "EMPLOYEE.DAT";
    std::string input;
    int choice;

    do {
        std::cout << "\n1. Add Employee\n2. Display Employees\n3. Exit\nEnter choice: ";
        std::getline(std::cin, input); 

        try {
            choice = std::stoi(input); 
        } catch (...) {
            std::cout << "Invalid choice! Please enter a number.\n";
            continue; 
        }

        switch (choice) {
            case 1:
                writeToBinaryFile(filename);
                break;
            case 2:
                readFromBinaryFile(filename);
                break;
            case 3:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}

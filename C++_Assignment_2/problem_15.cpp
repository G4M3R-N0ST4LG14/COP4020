// Arturo Lara
// Problem 15

#include <iostream>
#include <fstream>
#include <string>

struct STUD {
    int Rno;
    char Name[20];
    
    void Enter() {
        std::cout << "Enter Roll Number: ";
        std::cin >> Rno;
        std::cin.ignore();
        std::cout << "Enter Name: ";
        std::cin.getline(Name, 20);
    }
    
    void Display() const {
        std::cout << "Roll Number: " << Rno << ", Name: " << Name << std::endl;
    }
};

void addStudentToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    STUD student;
    student.Enter();
    outFile.write(reinterpret_cast<const char*>(&student), sizeof(STUD));
    
    outFile.close();
    std::cout << "Student record added successfully!" << std::endl;
}

void readStudentsFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    STUD student;
    std::cout << "\n--- Student Records ---\n";
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(STUD))) {
        student.Display();
    }
    std::cout << "------------------------\n";
    
    inFile.close();
}

int main() {
    std::string filename = "STUDENT.DAT";
    addStudentToFile(filename);
    readStudentsFromFile(filename);
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}

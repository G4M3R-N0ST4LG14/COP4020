// Arturo Lara
// Problem 14

#include <fstream.h>

class Employee
{
    int Eno;
    char Ename[20];

public:
    int Countrec();
};

int Employee::Countrec()
{
    fstream File;
    File.open("EMP.DAT", ios::binary | ios::in);
    
    File.seekg(0, ios::end);  // Statement 1
    
    int Bytes = File.tellg(); // Statement 2
    
    int Count = Bytes / sizeof(Employee);
    
    File.close();
    
    return Count;
}

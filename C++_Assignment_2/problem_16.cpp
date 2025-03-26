// Arturo Lara
// Problem 16

#include <fstream.h>

class Item
{
    int Ino;
    char Item[20];

public:
    void Search(int);
    void Modify(int);
};

void Item::Search(int RecNo)
{
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in);
    
    File.seekg((RecNo - 1) * sizeof(Item), ios::beg); // Statement 1
    
    File.read((char*)this, sizeof(Item));
    cout << Ino << " ==> " << Item << endl;
    
    File.close();
}

void Item::Modify(int RecNo)
{
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in | ios::out);
    
    cin >> Ino;
    cin.getline(Item, 20);
    
    File.seekp((RecNo - 1) * sizeof(Item), ios::beg); // Statement 2
    
    File.write((char*)this, sizeof(Item));
    
    File.close();
}

#include "class_file_read.h"

file_reader::file_reader(const char * name) : file_name(name)
{
    cout << "Otwieranie pliku z danymi...\n";
    if(name == nullptr)
    {
        cout << "Nie podano nazwy pliku w argumencie";
        exit(2);
    }

    file.open(name);
    if(file.is_open() == false)
    {
        cout << "Error opening the file\n";
        exit(1);
    }
    cout << "Zakonczono otwieranie pliku\n";
}
file_reader::file_reader(string str)
{
   if(str == "")
   {
       cout << "Pusta nazwa pliku";
       exit(2);
   }
   file_name = str;
   file.open(str);
    if(file.is_open() == false)
    {
        cout << "Error opening the file\n";
        exit(1);
    }
    cout << "Zakonczono otwieranie pliku\n";

}
void file_reader::read()
{
    ull k;
    data.clear();
    cout << "Wczytywanie danych z pliku "<<file_name<<endl;
    while(file >> k)
    {
        data.push_back(k);
    }
    size = data.size();
    cout << "Zakonczono wczytywanie danych\n";
    cout << "Ilosc wczytanych liczb: " << size << endl;
}

void file_reader::print()
{
    for(auto & i : data)
    {
        cout << i <<" ";
    }
    cout << endl;
}

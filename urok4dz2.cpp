#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <algorithm>



class Address
{
private:
    std::string n_dom;
    std::string n_kv;
    std::string city;
    std::string street;   

public:
    Address() {};
    Address(std::string city, std::string street, std::string n_dom, std::string n_kv) {
        this->n_dom = n_dom;
        this->n_kv = n_kv;
        this->city = city;
        this->street = street;
    };

    std::string print_address() {
        return this->city + ", " + this->street + ", " + this->n_dom + ", " + this->n_kv;
    };

    std::string get_sity() {
        return this->city;
    }

};

int count_address = 0;




//функция для сортировки строк по возрастанию
bool comp(Address& lhs, Address& rhs)
{
    return lhs.get_sity() < rhs.get_sity();
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
   

    std::ifstream file("in.txt");
    if (!file) {
        std::cout << "Файл не найден.";
        return 0;
    }

    file >> count_address;

    Address* address_arr = new Address[count_address];

    std::string _n_dom;
    std::string _n_kv;
    std::string _city;
    std::string _street;

    std::ofstream fout("out.txt");

    for (int i = 0; i < count_address; ++i) {
        file >> _city;
        file >> _street;
        file >> _n_dom;
        file >> _n_kv;
        address_arr[i] = Address(_city, _street, _n_dom, _n_kv);
    }

    std::sort(address_arr, address_arr + count_address, comp);

    fout << count_address << std::endl;
    for (int i = 0; i <  count_address; ++i) {
        fout << address_arr[i].print_address() << std::endl;
    }
    fout.close();
    file.close();

    delete[] address_arr;
    address_arr = nullptr;
}
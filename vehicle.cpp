#include <iostream>
using namespace std;

class Vehicle
{
private:
    int year;
    int mileage;

public:
    Vehicle() {}
    Vehicle(int year, int mileage)
    {
        this->year = year;
        this->mileage = mileage;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    void setMileage(int mileage)
    {
        this->mileage = mileage;
    }

    void print()
    {
        cout << "Year: " << this->year << endl;
        cout << "Mileage: " << this->mileage << endl;
    }
};

class Sedan : public Vehicle
{
private:
    int door;
    bool hatchback;

public:
    Sedan() {}
    Sedan(int year, int mileage, int door, bool hatchback):Vehicle(year, mileage)
    {
        this->door = door;
        this->hatchback = hatchback;
    }

    void printVehicle()
    {
        cout << "Information about sedan" << endl;
        Vehicle::print();
        cout << "Doors: " << this->door << endl;
        cout << "Hatchback: " << this->hatchback << endl;
    }

};

int
main()
{
    int year, mileage, door;
    bool hatchback;
    cout << "Year =";
    cin >> year;
    cout << "Mileage = ";
    cin >> mileage;
    cout << "Door =";
    cin >> door;
    cout << "Hatchback =";
    cin >> hatchback;
    Sedan sedan(year, mileage, door, hatchback);
    sedan.printVehicle();
    return 0;
}
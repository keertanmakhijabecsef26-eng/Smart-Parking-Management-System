
#include <iostream>
using namespace std;

const int SIZE = 5;

void displaySlots(int *slots)
{
    cout << "\n----- PARKING SLOTS -----\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (*(slots + i) == 0)
        {
            cout << "Slot " << i + 1 << " : Empty\n";
        }
        else
        {
            cout << "Slot " << i + 1
                 << " : Vehicle " << *(slots + i) << "\n";
        }
    }
}

void parkVehicle(int *slots)
{
    int vehicleNumber;

    cout << "\nEnter Vehicle Number: ";
    cin >> vehicleNumber;

    for (int i = 0; i < SIZE; i++)
    {
        if (*(slots + i) == 0)
        {
            *(slots + i) = vehicleNumber;

            cout << "Vehicle Parked Successfully!\n";
            cout << "Your Parking Slot is: " << i + 1 << endl;

            return;
        }
    }

    cout << "Sorry! Parking is Full.\n";
}

void removeVehicle(int *slots)
{
    int slotNumber;

    cout << "\nEnter Slot Number to Remove Vehicle: ";
    cin >> slotNumber;

    if (slotNumber >= 1 && slotNumber <= SIZE)
    {
        if (*(slots + slotNumber - 1) != 0)
        {
            *(slots + slotNumber - 1) = 0;

            cout << "Vehicle Removed Successfully!\n";
        }
        else
        {
            cout << "This Slot is Already Empty.\n";
        }
    }
    else
    {
        cout << "Invalid Slot Number!\n";
    }
}

void availableSlots(int *slots)
{
    int count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (*(slots + i) == 0)
        {
            count++;
        }
    }

    cout << "\nAvailable Parking Slots: " << count << endl;
}

void totalVehicles(int *slots)
{
    int count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (*(slots + i) != 0)
        {
            count++;
        }
    }

    cout << "\nTotal Parked Vehicles: " << count << endl;
}

int main()
{
    int parking[SIZE] = {0};

    int choice;

    do
    {
        cout << "\n===== SMART PARKING MANAGEMENT SYSTEM =====\n";

        cout << "1. Display Parking Slots\n";
        cout << "2. Park Vehicle\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Check Available Slots\n";
        cout << "5. Total Parked Vehicles\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displaySlots(parking);
                break;

            case 2:
                parkVehicle(parking);
                break;

            case 3:
                removeVehicle(parking);
                break;

            case 4:
                availableSlots(parking);
                break;

            case 5:
                totalVehicles(parking);
                break;

            case 6:
                cout << "Thank You for Using Smart Parking System!\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

// room class
class Hotel
{
public:
    int roomNo;
    string name;
    string phone;
    int status;
};

int main()
{
    Hotel Rooms[10];

    for (int i = 0; i < 10; i++)
    {
        Rooms[i].roomNo = 101 + i;
        Rooms[i].status = 0;
    }

    int choice = 0;
    while (choice != 9)
    {
        cout << "===== HOTEL RESERVATION SYSTEM =====" << endl;
        cout << "1. Reserve Room" << endl;
        cout << "2. Check-In Customer" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Check-Out Customer" << endl;
        cout << "5. View Available Rooms" << endl;
        cout << "6. View All Bookings" << endl;
        cout << "7. Search Customer" << endl;
        cout << "8. Update Customer Details" << endl;
        cout << "9. Exit " << endl;

        cout << "------------------------------------------" << endl;
        cout << "select>";
        cin >> choice; // update choice;

        // this variable use inside switch
        bool found = false;
        string input;
        bool valid = true;

        switch (choice) // switch
        {
        case 1:
            cout << "Reserve Room Selected" << endl;

            int roomNumber;
            while (true)
            {
                cout << "Enter Room Number: ";
                getline(cin >> ws, input); // take input room number inside  input string
                valid = true;              // reset;

                for (char ch : input) // for each loop
                {
                    if (!isdigit(ch)) // check char by char that actual digit he hai ya nhi
                    {
                        valid = false; // agar condition true wo digit nhi hai
                        break;         // for each loop se bar
                    }
                }

                if (valid) // condition check
                {
                    roomNumber = stoi(input); // if true wo roomNumber ke andar assign ker do . stoi use for convert string to int
                    break;
                }
                else
                {
                    cout << "invalid roomNumber" << endl;
                }
            }

            for (int i = 0; i < 10; i++)
            {
                if (Rooms[i].roomNo == roomNumber) // check room numer is valid or not
                {
                    found = true;
                    if (Rooms[i].status == 0) // check room status
                    {
                        while (true)
                        {
                            cout << "Enter Customer Name: ";
                            getline(cin >> ws, Rooms[i].name); // ws means whitespace
                            valid = true;                      // reset

                            for (char ch : Rooms[i].name) // for each loop
                            {
                                if (!(isalpha(ch) || ch == ' ')) // check name is alpha or space allow only
                                {
                                    valid = false;
                                    break;
                                }
                            }

                            if (valid)
                            {
                                break;
                            }
                            else
                            {
                                cout << "invaild name" << endl;
                            }
                        }

                        while (true)
                        {
                            cout << "Enter Phone Number: ";
                            getline(cin >> ws, Rooms[i].phone);
                            valid = true;

                            for (char ch : Rooms[i].phone) // for each loop
                            {
                                if (!isdigit(ch)) // check char by char that actual digit he hai ya nhi
                                {
                                    valid = false; // agar condition true wo digit nhi hai
                                    break;         // for each loop se bar
                                }
                            }

                          
                            if(!valid)
                            {
                                cout << "enter number only " << endl;
                                continue;
                            }

                            if (Rooms[i].phone.length() != 10)
                            {
                                cout << "phone number must be 10 digit " << endl;
                                continue;
                            }

                            break;
                        }

                        Rooms[i].status = 1;

                        cout << "Room Reserved Successfully" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Room Not Available" << endl;
                        break;
                    }
                }
            }
            if (!found)
            {
                cout << "Room does not exist." << endl;
            }
            break;
            //-----------------------------------------------------------------------------------------------------
        case 2:
            cout << "Check-In Customer Selected" << endl;
            // input
            cout << "Enter Room Number: ";
            while (!(cin >> roomNumber))
            { // this use for handing char input on roomNumber
                cout << "invaild input ! \nEnter numbers only: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            cin.ignore();
            for (int i = 0; i < 10; i++)
            {
                if (Rooms[i].roomNo == roomNumber)
                {
                    found = true;
                    if (Rooms[i].status == 1)
                    {
                        Rooms[i].status = 2;
                        cout << "Room Number : " << Rooms[i].roomNo << endl;
                        cout << "Customer    : " << Rooms[i].name << endl;
                        cout << "Phone       : " << Rooms[i].phone << endl;
                        cout << "Status      : Checked In" << endl;
                    }
                    else if (Rooms[i].status == 2)
                    {
                        cout << "customer check in already" << endl;
                    }
                    else
                    {
                        cout << "Room is not reserved" << endl;
                    }
                }
            }
            if (!found)
            {
                cout << "Room does not exist." << endl;
            }

            break;
            //-------------------------------------------------------------------------------------------------------------
        case 3:
            cout << "Cancel Booking Selected" << endl;
            // input
            cout << "Enter Room Number: ";
            while (!(cin >> roomNumber))
            { // this use for handing char input on roomNumber
                cout << "invaild input ! \nEnter numbers only: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin.ignore();
            for (int i = 0; i < 10; i++)
            {
                if (Rooms[i].roomNo == roomNumber)
                {
                    found = true;
                    if (Rooms[i].status == 1)
                    {
                        Rooms[i].status = 0;
                        Rooms[i].name = "";
                        Rooms[i].phone = "";

                        cout << "Booking cancel successful" << endl;
                    }
                    else if (Rooms[i].status == 2)
                    {
                        cout << "customer check in the room" << endl;
                    }
                }
            }
            if (!found)
            {
                cout << "Room does not exist." << endl;
            }
            break;
            //--------------------------------------------------------------------------------------------------
        case 4:
            cout << "Check-Out Selected" << endl;
            // input
            cout << "Enter Room Number: ";
            while (!(cin >> roomNumber))
            { // this use for handing char input on roomNumber
                cout << "invaild input ! \nEnter numbers only: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin.ignore();
            for (int i = 0; i < 10; i++)
            {
                if (Rooms[i].roomNo == roomNumber)
                {
                    found = true;
                    if (Rooms[i].status == 2)
                    {
                        Rooms[i].status = 0;
                        cout << "Room Number : " << Rooms[i].roomNo << endl;
                        cout << "Customer    : " << Rooms[i].name << endl;
                        cout << "Phone       : " << Rooms[i].phone << endl;
                        cout << "Status      : Checked out" << endl;
                    }
                    else if (Rooms[i].status == 1)
                    {
                        cout << "customer not checked in" << endl;
                    }
                    else if (Rooms[i].status == 0)
                    {
                        cout << "Room is not reserved" << endl;
                    }
                }
            }
            if (!found)
            {
                cout << "Room does not exist." << endl;
            }
            break;
            //-----------------------------------------------------------------------------------------------------------
        case 5:
            cout << "View Available Rooms Selected" << endl;
            break;
            //-----------------------------------------------------------------------------------------------------------
        case 6:
            cout << "View All Bookings Selected" << endl;
            break;
            //-----------------------------------------------------------------------------------------------------------
        case 7:
            cout << "Search Customer Selected" << endl;
            break;
            //-----------------------------------------------------------------------------------------------------------
        case 8:
            cout << "Update Customer Details Selected" << endl;
            break;
            //-----------------------------------------------------------------------------------------------------------
        case 9:
            cout << "Thank You!" << endl;
            break;
            //-----------------------------------------------------------------------------------------------------------
        default:
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
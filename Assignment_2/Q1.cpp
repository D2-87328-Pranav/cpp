/*
Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options ->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.
*/

#include <iostream>
using namespace std;

class Box
{
    int l;

public:
    Box()
    {
        l=5;
        cout << "Volume =\n" << l * l * l;
    }

    Box(int l)
    {
        cout << "Volume =" << l * l * l;
    }

    Box(int l, int b, int h)
    {
        cout << "Volume =" << l * b * h;
    }
};

int main()
{
    int choice = 5;
    int l, b, h;
    // Box b1();
    // Box b2(l);
    // Box b3(l,b,h);
    while (1)
    {
        cout << "Enter your choice\n-------------------\n";
        cout << "1.Calculate volume with default values.\n";
        cout << "2.Calculate Volume with length,breadth and height with same value.\n";
        cout << "3.Calculate Volume with different length,breadth and height values.\n";
        cout << "4.Exit.\n";
        cin >> choice;

        if (choice == 4)
            break;

        switch (choice)
        {
        case 1:
        {
            Box b1();
            break;
        }

        case 2:
        {
            cout << "Enter side length\n";
            cin >> l;
            Box b2(l);
            break;
        }

        case 3:
        {
            cout << "Enter length, breadth and height.\n";
            cin >> l;
            cin >> b;
            cin >> h;
            Box b3(l, b, h);
            break;
        }
        default:
        {
            cout << "Invalid input\n";
            break;
        }
        }
    }
}
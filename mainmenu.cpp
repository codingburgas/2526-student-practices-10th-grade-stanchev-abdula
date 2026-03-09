#include <iostream>
using namespace std;
void showMainMenu()
{
    cout << "\n===== MOVIE TICKET BOOKING SYSTEM =====\n";
    cout << "1. Search Movie\n";
    cout << "2. View Showtimes\n";
    cout << "3. Book Ticket\n";
    cout << "4. Admin Panel\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}
int main()
{
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
        << "X                                                                     X\n"
        << "X XXXXXX   X   XX   X  XXXX  XX     XX      X          __/\\__         X\n"
        << "X X        X   X X  X  X     X X   X X     X X         \\    /         X\n"
        << "X X        X   X  X X  XXXX  X  X X  X    X   X        /_  _\\         X\n"
        << "X X        X   X   XX  X     X   X   X   XXXXXXX         \\/           X\n"
        << "X XXXXXX   X   X    X  XXXX  X       X  X       X                     X\n"
        << "X                                                                     X\n"
        << "X XXXX  XXXXX      X       XX     X  XXXXX  X  X  XXXX  X         X   X\n"
        << "X X       X       X X      X X    X  X      X  X  X      X       X    X\n"
        << "X X       X      X   X     X  X   X  X      XXXX  X       X     X     X\n"
        << "X XXXX    X     XXXXXXX    X   X  X  X      X  X  XXXX     X   X      X\n"
        << "X    X    X    X       X   X    X X  X      X  X  X         X X       X\n"
        << "X XXXX    X   X         X  X     XX  XXXXX  X  X  XXXX       X        X\n"
        << "X                                                                     X\n"
        << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    
    int choice;
    do
    {
        showMainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Search Movie selected.\n";
            break;
        }
        case 2:
        {
            cout << "View Showtimes selected.\n";
            break;
        }
        case 3:
        {
            cout << "Book Ticket selected.\n";
            break;
        }
        case 4:
        {
            cout << "Admin Panel selected.\n";
            break;
        }
        case 0:
        {
            cout << "Exiting system...\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Try again.\n";
            break;
        }
        }
    } while (choice != 0);
}
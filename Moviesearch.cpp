#include <iostream>
#include <string>
using namespace std;
int main()
{
    string movies[5] = {
        "Avengers: Endgame",
        "Inception",
        "Interstellar",
        "The Batman",
        "Spider-Man: No Way Home"
    };
    string halls[5] = {
        "Hall 1",
        "Hall 2",
        "Hall 3",
        "Hall 1",
        "Hall 2"
    };
    string times[5] = {
        "10:00",
        "12:30",
        "15:00",
        "18:00",
        "20:30"
    };
    double prices[5] = {
        12.50,
        10.00,
        11.50,
        13.00,
        14.00
    };
    string search;
    bool found = false;
    cout << "========================================\n";
    cout << "           MOVIE SEARCH SYSTEM          \n";
    cout << "========================================\n\n";
    cout << "Enter movie name: ";
    getline(cin, search);
    cout << "\nSearching...\n";
    for (int i = 0; i < 5; i++)
    {
        if (movies[i].find(search) != string::npos)
        {
            cout << "\n========================================\n";
            cout << "              MOVIE FOUND               \n";
            cout << "========================================\n";
            cout << " Movie: " << movies[i] << endl;
            cout << " Hall:  " << halls[i] << endl;
            cout << " Time:  " << times[i] << endl;
            cout << " Price: " << prices[i] << " BGN" << endl;
            cout << "========================================\n";
            found = true;
        }
    }
    if (!found)
    {
        cout << "\n========================================\n";
        cout << "            NOT AVAILABLE               \n";
        cout << "========================================\n";
        cout << " This movie is not in our system.\n";
        cout << "========================================\n";
    }
}
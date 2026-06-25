#include <iostream>
#include <string>

using namespace std;

void showSeats(char seats[6][6])
{
    cout << "\n     A   B   C   D   E   F\n";
    cout << "   +---+---+---+---+---+---+\n";

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << " | ";

        for (int j = 0; j < 6; j++)
        {
            cout << seats[i][j] << " | ";
        }

        cout << "\n   +---+---+---+---+---+---+\n";
    }
}

void printQRCode()
{
    cout << "█▀▀▀▀▀█ ▀▄ ▄  █▀▀▀▀▀█\n";
    cout << "█ ███ █ ▀▀▀█▀ █ ███ █\n";
    cout << "█ ▀▀▀ █ █▀ █▀ █ ▀▀▀ █\n";
    cout << "▀▀▀▀▀▀▀ ▀▄█ ▀ ▀▀▀▀▀▀▀\n";
    cout << "▀█▄▀ ▀▀ █▀▀█▄ █ ▄█▀▀▄\n";
    cout << "█▀▄▀█▄▀▄ █▀▄█ ▀▀▀▀█▀▄\n";
    cout << "▀  ▀  ▀ ▀▀  ▀ ▀▀▀  ▀▀\n";
    cout << "█▀▀▀▀▀█ ▀█▄█▀ █▀ █▀▄█\n";
    cout << "█ ███ █ █ ▀▄█ ▀▀ ▀ ██\n";
    cout << "█ ▀▀▀ █ ▀ █▀▄ ▀▀▀▀▀▀█\n";
    cout << "▀▀▀▀▀▀▀ ▀▀  ▀ ▀▀▀▀  ▀\n";
}

void printTicket(string movie, string time, string hall, string seat, double price)
{
    cout << "\n=====================================\n";
    cout << "              MOVIE TICKET\n";
    cout << "=====================================\n";
    cout << "Movie: " << movie << endl;
    cout << "Time:  " << time << endl;
    cout << "Hall:  " << hall << endl;
    cout << "Seat:  " << seat << endl;
    cout << "Price: " << price << " lv\n";
    cout << "-------------------------------------\n";
    printQRCode();
    cout << "=====================================\n";
}

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

    double prices[5] = { 10.0, 8.5, 9.0, 11.0, 12.0 };

    char seats[6][6];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            seats[i][j] = 'X';
        }
    }

    cout << "==================== MOVIE TIMETABLE ====================\n";
    cout << "| No. | Movie                     | Hall   | Time  | Price |\n";
    cout << "==========================================================\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "| ";

        if (i + 1 < 10)
        {
            cout << i + 1 << "   ";
        }
        else
        {
            cout << i + 1 << "  ";
        }

        cout << "| " << movies[i];

        for (int j = movies[i].length(); j < 25; j++)
        {
            cout << " ";
        }

        cout << " | " << halls[i] << " | " << times[i] << " | ";
        cout << prices[i];

        if (prices[i] < 10)
        {
            cout << "   |\n";
        }
        else
        {
            cout << "  |\n";
        }
    }

    cout << "==========================================================\n";

    int movieChoice;
    cout << "\nChoose movie number: ";
    cin >> movieChoice;

    while (movieChoice < 1 || movieChoice > 5)
    {
        cout << "Invalid movie. Choose again: ";
        cin >> movieChoice;
    }

    int ticketCount;
    cout << "How many tickets do you want to book? Maximum 5: ";
    cin >> ticketCount;

    while (ticketCount < 1 || ticketCount > 5)
    {
        cout << "Invalid number. Choose between 1 and 5: ";
        cin >> ticketCount;
    }

    string bookedSeats[5];

    for (int i = 0; i < ticketCount; i++)
    {
        showSeats(seats);

        int row;
        char column;

        cout << "\nChoose seat " << i + 1 << " row: ";
        cin >> row;

        cout << "Choose seat " << i + 1 << " column: ";
        cin >> column;

        if (column >= 'a' && column <= 'f')
        {
            column = column - 32;
        }

        int colIndex = column - 'A';

        while (row < 1 || row > 6 || colIndex < 0 || colIndex > 5 || seats[row - 1][colIndex] == 'O')
        {
            cout << "Invalid or already booked seat. Choose again.\n";

            cout << "Row: ";
            cin >> row;

            cout << "Column: ";
            cin >> column;

            if (column >= 'a' && column <= 'f')
            {
                column = column - 32;
            }

            colIndex = column - 'A';
        }

        seats[row - 1][colIndex] = 'O';

        bookedSeats[i] = to_string(row);
        bookedSeats[i] += column;
    }

    cout << "\nBooking confirmed!\n";
    cout << "Movie: " << movies[movieChoice - 1] << endl;
    cout << "Time: " << times[movieChoice - 1] << endl;

    for (int i = 0; i < ticketCount; i++)
    {
        cout << "Seat " << i + 1 << ": " << bookedSeats[i] << endl;
    }

    for (int i = 0; i < ticketCount; i++)
    {
        printTicket(movies[movieChoice - 1], times[movieChoice - 1], halls[movieChoice - 1], bookedSeats[i], prices[movieChoice - 1]);
    }

    return 0;
}

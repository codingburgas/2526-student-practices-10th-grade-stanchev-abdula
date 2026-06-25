#include <iostream>
#include <string>
#include "moviesystem.h"
using namespace std;

// ─── Shared Data ─────────────────────────────────────────────────────────────

string movies[MAX_MOVIES] = {
    "Avengers: Endgame",
    "Inception",
    "Interstellar",
    "The Batman",
    "Spider-Man: No Way Home"
};

string halls[MAX_MOVIES] = {
    "Hall 1",
    "Hall 2",
    "Hall 3",
    "Hall 1",
    "Hall 2"
};

string times[MAX_MOVIES] = {
    "10:00",
    "12:30",
    "15:00",
    "18:00",
    "20:30"
};

double prices[MAX_MOVIES] = { 10.0, 8.5, 9.0, 11.0, 12.0 };

char seats[MAX_MOVIES][6][6];

int movieCount = 5;

// ─── Helper Functions ─────────────────────────────────────────────────────────

void showSeats(char s[6][6])
{
    cout << "\n     A   B   C   D   E   F\n";
    cout << "   +---+---+---+---+---+---+\n";
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < 6; j++)
            cout << s[i][j] << " | ";
        cout << "\n   +---+---+---+---+---+---+\n";
    }
    cout << "  X = Available   O = Booked\n";
}

void printQRCode()
{
    cout << "\u2588\u2580\u2580\u2580\u2580\u2580\u2588 \u2580\u2584 \u2584  \u2588\u2580\u2580\u2580\u2580\u2580\u2588\n";
    cout << "\u2588 \u2588\u2588\u2588 \u2588 \u2580\u2580\u2580\u2588\u2580 \u2588 \u2588\u2588\u2588 \u2588\n";
    cout << "\u2588 \u2580\u2580\u2580 \u2588 \u2588\u2580 \u2588\u2580 \u2588 \u2580\u2580\u2580 \u2588\n";
    cout << "\u2580\u2580\u2580\u2580\u2580\u2580\u2580 \u2580\u2584\u2588 \u2580 \u2580\u2580\u2580\u2580\u2580\u2580\u2580\n";
    cout << "\u2580\u2588\u2584\u2580 \u2580\u2580 \u2588\u2580\u2580\u2588\u2584 \u2588 \u2584\u2588\u2580\u2580\u2584\n";
    cout << "\u2588\u2580\u2584\u2580\u2588\u2584\u2580\u2584 \u2588\u2580\u2584\u2588 \u2580\u2580\u2580\u2580\u2588\u2580\u2584\n";
    cout << "\u2580  \u2580  \u2580 \u2580\u2580  \u2580 \u2580\u2580\u2580  \u2580\u2580\n";
    cout << "\u2588\u2580\u2580\u2580\u2580\u2580\u2588 \u2580\u2588\u2584\u2588\u2580 \u2588\u2580 \u2588\u2580\u2584\u2588\n";
    cout << "\u2588 \u2588\u2588\u2588 \u2588 \u2588 \u2580\u2584\u2588 \u2580\u2580 \u2580 \u2588\u2588\n";
    cout << "\u2588 \u2580\u2580\u2580 \u2588 \u2580 \u2588\u2580\u2584 \u2580\u2580\u2580\u2580\u2580\u2580\u2588\n";
    cout << "\u2580\u2580\u2580\u2580\u2580\u2580\u2580 \u2580\u2580  \u2580 \u2580\u2580\u2580\u2580  \u2580\n";
}

void printTicket(string movie, string time, string hall, string seat, double price)
{
    cout << "\n=====================================\n";
    cout << "           MOVIE TICKET\n";
    cout << "=====================================\n";
    cout << "Movie: " << movie << "\n";
    cout << "Time:  " << time << "\n";
    cout << "Hall:  " << hall << "\n";
    cout << "Seat:  " << seat << "\n";
    cout << "Price: " << price << " lv\n";
    cout << "-------------------------------------\n";
    printQRCode();
    cout << "=====================================\n";
}

// ─── Feature: Search Movie ────────────────────────────────────────────────────

void searchMovie()
{
    if (movieCount == 0)
    {
        cout << "\nNo movies in the system.\n";
        return;
    }

    string search;
    bool found = false;

    cout << "\n========================================\n";
    cout << "         MOVIE SEARCH SYSTEM            \n";
    cout << "========================================\n";
    cout << "Enter movie name to search: ";
    cin.ignore();
    getline(cin, search);
    cout << "\nSearching...\n";

    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].find(search) != string::npos)
        {
            cout << "\n========================================\n";
            cout << "             MOVIE FOUND                \n";
            cout << "========================================\n";
            cout << " No.:   " << i + 1 << "\n";
            cout << " Movie: " << movies[i] << "\n";
            cout << " Hall:  " << halls[i] << "\n";
            cout << " Time:  " << times[i] << "\n";
            cout << " Price: " << prices[i] << " lv\n";
            cout << "========================================\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "\n========================================\n";
        cout << "           NOT AVAILABLE                \n";
        cout << "========================================\n";
        cout << " This movie is not in our system.\n";
        cout << "========================================\n";
    }
}

// ─── Feature: View Showtimes ──────────────────────────────────────────────────

void viewShowtimes()
{
    if (movieCount == 0)
    {
        cout << "\nNo movies currently showing.\n";
        return;
    }

    cout << "\n==================== MOVIE TIMETABLE ====================\n";
    cout << "| No. | Movie                     | Hall   | Time  | Price |\n";
    cout << "==========================================================\n";

    for (int i = 0; i < movieCount; i++)
    {
        cout << "| ";
        if (i + 1 < 10)
            cout << i + 1 << "   ";
        else
            cout << i + 1 << "  ";

        cout << "| " << movies[i];
        for (int j = movies[i].length(); j < 25; j++)
            cout << " ";

        cout << " | " << halls[i] << " | " << times[i] << " | ";
        cout << prices[i];

        if (prices[i] < 10)
            cout << "   |\n";
        else
            cout << "  |\n";
    }

    cout << "==========================================================\n";
}

// ─── Feature: Book Ticket ─────────────────────────────────────────────────────

void bookTicket()
{
    if (movieCount == 0)
    {
        cout << "\nNo movies available to book.\n";
        return;
    }

    viewShowtimes();

    int movieChoice;
    cout << "\nChoose movie number (1-" << movieCount << "): ";
    cin >> movieChoice;

    while (movieChoice < 1 || movieChoice > movieCount)
    {
        cout << "Invalid movie. Choose again (1-" << movieCount << "): ";
        cin >> movieChoice;
    }

    int ticketCount;
    cout << "How many tickets do you want to book? (1-5): ";
    cin >> ticketCount;

    while (ticketCount < 1 || ticketCount > 5)
    {
        cout << "Invalid number. Choose between 1 and 5: ";
        cin >> ticketCount;
    }

    string bookedSeats[5];

    for (int i = 0; i < ticketCount; i++)
    {
        showSeats(seats[movieChoice - 1]);

        int row;
        char column;

        cout << "\nChoose seat " << i + 1 << " - Row (1-6): ";
        cin >> row;
        cout << "Choose seat " << i + 1 << " - Column (A-F): ";
        cin >> column;

        if (column >= 'a' && column <= 'f')
            column = column - 32;

        int colIndex = column - 'A';

        while (row < 1 || row > 6 || colIndex < 0 || colIndex > 5 || seats[movieChoice - 1][row - 1][colIndex] == 'O')
        {
            cout << "Invalid or already booked seat. Try again.\n";
            cout << "Row (1-6): ";
            cin >> row;
            cout << "Column (A-F): ";
            cin >> column;

            if (column >= 'a' && column <= 'f')
                column = column - 32;

            colIndex = column - 'A';
        }

        seats[movieChoice - 1][row - 1][colIndex] = 'O';
        bookedSeats[i] = to_string(row);
        bookedSeats[i] += column;
    }

    cout << "\n========== BOOKING CONFIRMED ==========\n";
    cout << "Movie: " << movies[movieChoice - 1] << "\n";
    cout << "Time:  " << times[movieChoice - 1] << "\n";
    cout << "Hall:  " << halls[movieChoice - 1] << "\n";

    for (int i = 0; i < ticketCount; i++)
        cout << "Seat " << i + 1 << ": " << bookedSeats[i] << "\n";

    cout << "=======================================\n";

    for (int i = 0; i < ticketCount; i++)
        printTicket(movies[movieChoice - 1], times[movieChoice - 1], halls[movieChoice - 1], bookedSeats[i], prices[movieChoice - 1]);
}

// ─── Admin: Add Movie ─────────────────────────────────────────────────────────

void addMovie()
{
    if (movieCount >= MAX_MOVIES)
    {
        cout << "\nCannot add more movies. Maximum of " << MAX_MOVIES << " reached.\n";
        cout << "Remove a movie first to make space.\n";
        return;
    }

    string newMovie, newHall, newTime;
    double newPrice;

    cin.ignore();

    cout << "\nEnter movie name: ";
    getline(cin, newMovie);

    cout << "Enter hall (e.g. Hall 1): ";
    getline(cin, newHall);

    cout << "Enter showtime (e.g. 14:00): ";
    getline(cin, newTime);

    cout << "Enter ticket price: ";
    cin >> newPrice;

    movies[movieCount] = newMovie;
    halls[movieCount] = newHall;
    times[movieCount] = newTime;
    prices[movieCount] = newPrice;

    // Clear seats for the new movie slot
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            seats[movieCount][i][j] = 'X';

    movieCount++;

    cout << "\n\"" << newMovie << "\" has been added successfully!\n";
    cout << "Total movies: " << movieCount << "/" << MAX_MOVIES << "\n";
}

// ─── Admin: Remove Movie ──────────────────────────────────────────────────────

void removeMovie()
{
    if (movieCount == 0)
    {
        cout << "\nNo movies to remove.\n";
        return;
    }

    viewShowtimes();

    int choice;
    cout << "\nEnter movie number to remove (1-" << movieCount << "): ";
    cin >> choice;

    while (choice < 1 || choice > movieCount)
    {
        cout << "Invalid. Try again (1-" << movieCount << "): ";
        cin >> choice;
    }

    cout << "\nRemoving \"" << movies[choice - 1] << "\"...\n";

    // Shift all movies down to fill the gap
    for (int i = choice - 1; i < movieCount - 1; i++)
    {
        movies[i] = movies[i + 1];
        halls[i] = halls[i + 1];
        times[i] = times[i + 1];
        prices[i] = prices[i + 1];

        for (int r = 0; r < 6; r++)
            for (int c = 0; c < 6; c++)
                seats[i][r][c] = seats[i + 1][r][c];
    }

    // Clear the last slot
    movies[movieCount - 1] = "";
    halls[movieCount - 1] = "";
    times[movieCount - 1] = "";
    prices[movieCount - 1] = 0.0;

    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 6; c++)
            seats[movieCount - 1][r][c] = 'X';

    movieCount--;

    cout << "Movie removed successfully!\n";
    cout << "Total movies: " << movieCount << "/" << MAX_MOVIES << "\n";
}

// ─── Feature: Admin Panel ─────────────────────────────────────────────────────

void adminPanel()
{
    string password;
    cout << "\nEnter admin password: ";
    cin >> password;

    if (password != "admin123")
    {
        cout << "Incorrect password. Access denied.\n";
        return;
    }

    int adminChoice;
    do
    {
        cout << "\n===== ADMIN PANEL (" << movieCount << "/" << MAX_MOVIES << " movies) =====\n";
        cout << "1. View seat map\n";
        cout << "2. Reset all seats\n";
        cout << "3. Change movie price\n";
        cout << "4. Add a movie\n";
        cout << "5. Remove a movie\n";
        cout << "0. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> adminChoice;

        switch (adminChoice)
        {
        case 1:
        {
            if (movieCount == 0)
            {
                cout << "No movies in system.\n";
                break;
            }
            viewShowtimes();
            int pick;
            cout << "View seats for movie number (1-" << movieCount << "): ";
            cin >> pick;
            while (pick < 1 || pick > movieCount)
            {
                cout << "Invalid. Try again: ";
                cin >> pick;
            }
            cout << "\nSeats for \"" << movies[pick - 1] << "\":\n";
            showSeats(seats[pick - 1]);
            break;
        }
        case 2:
        {
            for (int i = 0; i < MAX_MOVIES; i++)
                for (int r = 0; r < 6; r++)
                    for (int c = 0; c < 6; c++)
                        seats[i][r][c] = 'X';
            cout << "All seats have been reset.\n";
            break;
        }
        case 3:
        {
            if (movieCount == 0) { cout << "No movies to update.\n"; break; }
            viewShowtimes();
            int movieNum;
            double newPrice;
            cout << "Enter movie number to update: ";
            cin >> movieNum;
            while (movieNum < 1 || movieNum > movieCount)
            {
                cout << "Invalid. Try again: ";
                cin >> movieNum;
            }
            cout << "Enter new price: ";
            cin >> newPrice;
            prices[movieNum - 1] = newPrice;
            cout << "Price updated for \"" << movies[movieNum - 1] << "\".\n";
            break;
        }
        case 4: addMovie();    break;
        case 5: removeMovie(); break;
        case 0: cout << "Returning to main menu...\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }

    } while (adminChoice != 0);
}

// ─── Menu ─────────────────────────────────────────────────────────────────────

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

void runMenu()
{
    // Initialize all seat grids
    for (int m = 0; m < MAX_MOVIES; m++)
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                seats[m][i][j] = 'X';

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
        case 1: searchMovie();   break;
        case 2: viewShowtimes(); break;
        case 3: bookTicket();    break;
        case 4: adminPanel();    break;
        case 0: cout << "Exiting system. Goodbye!\n"; break;
        default: cout << "Invalid choice. Try again.\n"; break;
        }

    } while (choice != 0);
}

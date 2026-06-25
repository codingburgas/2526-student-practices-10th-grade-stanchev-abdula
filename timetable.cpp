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

    double prices[5] = { 10.0, 8.5, 9.0, 11.0, 12.0 };

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

    return 0;

}

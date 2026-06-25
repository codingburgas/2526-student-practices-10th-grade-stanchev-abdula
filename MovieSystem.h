#pragma once
#include <string>
using namespace std;

const int MAX_MOVIES = 5;

extern string movies[MAX_MOVIES];
extern string halls[MAX_MOVIES];
extern string times[MAX_MOVIES];
extern double prices[MAX_MOVIES];
extern char seats[MAX_MOVIES][6][6];
extern int movieCount;

void showMainMenu();
void runMenu();

void searchMovie();
void viewShowtimes();
void bookTicket();
void adminPanel();

void addMovie();
void removeMovie();

void showSeats(char seats[6][6]);
void printQRCode();
void printTicket(string movie, string time, string hall, string seat, double price);

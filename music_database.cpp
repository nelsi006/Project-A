// This program displays a menu to the user and allows them to interact with a music database.
// This menu displays options of adding songs, viewing all songs, getting recommendations,
// updating the users preferences, and exiting the program.
// Nelsi Valdovinos-Lemus
#include <iostream>
#include <string>
#include "music.h"
using namespace std;

const int MAX_SONGS = 50;

void displayMenu()
{
    cout << "\nChoose your option!\n";
    cout << "1. Add Song to Playlist\n";
    cout << "2. View All Songs\n";
    cout << "3. Get Recommendations\n";
    cout << "4. Update Preference\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

void addSong(Song songDatabase[], int &numSongs)
{
    string title = "";
    string artist = "";
    string genre = "";
    int popularity = 0;
    if (numSongs >= MAX_SONGS)
    {
        cout << "Playlist is full!\n";
        return;
    }
    cout << "Lets Add a New song to your Playlist!\n";
    cout << "Enter song title: ";
    getline(cin, title);
    cout << "Enter artist: ";
    getline(cin, artist);
    cout << "Enter genre: ";
    getline(cin, genre);

    do
    {
        cout << "Enter popularity (1-100): ";
        cin >> popularity;
    } while (popularity < 1 || popularity > 100);

    songDatabase[numSongs++] = Song(title, artist, genre, popularity);
    cout << "Song added successfully!\n";
}

int main()
{
    int numSongs = 0;      //  Initialize numSongs to 0 to keep track of the number of songs in the database
    string userGenre = ""; // Empty string to store user genre
    char choice = '0';     // Initialize choice to 0 for switch statement
    Song songDatabase[MAX_SONGS] = {};
    Song::loadSongsFromFile(songDatabase, numSongs);
    // First thing the user will seee when they open the program
    cout << "Welcome to your Music Database!\n";
    cout << "Set up your genre preference to begin.\n";
    cout << "Enter your favorite genre (Hip Hop, Pop, Rap, ";
    cout << "Corridos tumbados, Rock, Indi Pop, Regional Mexican)" << endl;
    getline(cin, userGenre);

    UserProfile user(userGenre);
    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            addSong(songDatabase, numSongs);
            break;
        case '2':
            Song::displaySongs(songDatabase, numSongs);
            break;
        case '3':
            user.getRecommendations(songDatabase, numSongs);
            break;
        case '4':
            user.updatePreferences();
            break;
        case '5':
            Song::saveSongsToFile(songDatabase, numSongs);
            cout << "Until Next Time, Goodbye!\n";
            break;
        default:
            cout << "Error. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
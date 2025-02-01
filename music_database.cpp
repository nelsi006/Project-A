// This program displays a menu to the user and allows them to interact with a music database.
// This menu displays options of adding songs, viewing all songs, getting recommendations,
// updating the users preferences, and exiting the program.
// Nelsi Valdovinos-Lemus
//CSCI-41 Spring 2025
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
    cout << "5. Remove Song\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}
void addSong(Song *&songDatabase, int &numSongs)
{
    Song *newData = new Song[numSongs + 1];

    for (int i = 0; i < numSongs; i++)
    {
        newData[i] = songDatabase[i];
    }

    string title = "";
    string artist = "";
    string genre = "";
    int popularity = 0;

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

    newData[numSongs] = Song(title, artist, genre, popularity);
    cout << "Song added successfully!\n";

    // Delete old array and update pointer
    delete[] songDatabase;
    songDatabase = newData;
    numSongs++;
}
int main()
{
    Song *songDatabase = nullptr;
    int numSongs = 0;      //  Initialize numSongs to 0 to keep track of the number of songs in the database
    int genreChoice;       // Initialize genreChoice store user genre choice
    string userGenre = ""; // Empty string to store user genre
    char choice = '0';     // Initialize choice to 0 for switch statement
    songDatabase = new Song[MAX_SONGS];
    Song::loadSongsFromFile(songDatabase, numSongs);
    // First thing the user will see when they open the program
    cout << "Welcome to your Music Database!\n";
    cout << "Set up your genre preference to begin.\n";
    cout << "Choose a genre (1-7):\n";
    cout << "1. Hip Hop\n";
    cout << "2. Pop\n";
    cout << "3. Rap\n";
    cout << "4. Corridos tumbados\n";
    cout << "5. Rock\n";
    cout << "6. Indi Pop\n";
    cout << "7. Regional Mexican\n";
    cout << "Enter your choice: ";
    cin >> genreChoice;
    cin.ignore();

    switch (genreChoice)
    {
    case 1:
        userGenre = "Hip Hop";
        break;
    case 2:
        userGenre = "Pop";
        break;
    case 3:
        userGenre = "Rap";
        break;
    case 4:
        userGenre = "Corridos tumbados";
        break;
    case 5:
        userGenre = "Rock";
        break;
    case 6:
        userGenre = "Indi Pop";
        break;
    case 7:
        userGenre = "Regional Mexican";
        break;
    default:
        cout << "Invalid choice. Setting to Hip Hop by default.\n";
        userGenre = "Hip Hop";
    }

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
            Song::removeSong(songDatabase, numSongs);
            break;
        case '6':
            Song::saveSongsToFile(songDatabase, numSongs);
            cout << "Until Next Time, Goodbye!\n";
            break;
        default:
            cout << "Error. Please try again.\n";
        }
    } while (choice != '6');
    delete[] songDatabase;
    return 0;
}

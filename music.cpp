// Implementation file for the Song and UserProfile classes
// Nelsi Valdovinos-Lemus
#include "music.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//***********************************************************
// The Song constructor createss a Song object.
// Parameters are title, artist, genre, and popularity
//***********************************************************
Song::Song(string t, string a, string g, int p)
{
    title = t;
    artist = a;
    genre = g;
    setPopularity(p);
}
//***********************************************************
// setTitle sets the value of the member variable title (mutulator)
//***********************************************************
void Song::setTitle(string t)
{
    title = t;
}

//***********************************************************
// setGenre sets the value of the member variable genre
//***********************************************************
void Song::setGenre(string g)
{
    genre = g;
}

//***********************************************************
// setPopularity sets the value of popularity and make sure it is between 0 and 100
//***********************************************************
void Song::setPopularity(int p)
{
    if (p >= 0 && p <= 100)
    {
        popularity = p;
    }
    else
    {
        cout << "Error. Popularity needs to be between 0 and 100\n";
    }
}

//***********************************************************
// UserProfile constructor innitializes preferredGenre
//***********************************************************
UserProfile::UserProfile(string g)
{
    preferredGenre = g;
}

//***********************************************************
// setPreferredGenre sets the updated value of preferredGenre
//***********************************************************
void UserProfile::setPreferredGenre(string g)
{
    preferredGenre = g;
}

//***********************************************************
// Reads songs.txt file and creates song objects
//***********************************************************
void Song::loadSongsFromFile(Song songDatabase[], int &numSongs)
{
    string title, artist, genre;
    int popularity;
    ifstream dataIn;
    dataIn.open("songs.txt");
    // Handle errors
    if (!dataIn)
    {
        cout << "No songs in your playlist.\n";
        return;
    }
    // Reads songs.txt file and creates song objects until max 50 songs
    while (getline(dataIn, title) && numSongs < 50)
    {
        getline(dataIn, artist);
        getline(dataIn, genre);
        dataIn >> popularity;
        dataIn.ignore();
        // Creates song objects and stores them in songDatabase array
        songDatabase[numSongs++] = Song(title, artist, genre, popularity);
    }
    dataIn.close();
}

//***********************************************************
// Saves songs to songs.txt file
//***********************************************************

void Song::saveSongsToFile(const Song songDatabase[], int numSongs)
{
    ofstream dataOut;
    dataOut.open("songs.txt");
    // Handle errors
    if (!dataOut)
    {
        cout << "Error. Couldn't save song to file.\n";
        return;
    }
    // Saves songs data to songs.txt file
    for (int i = 0; i < numSongs; i++)
    {
        dataOut << songDatabase[i].getTitle() << endl;
        dataOut << songDatabase[i].getArtist() << endl;
        dataOut << songDatabase[i].getGenre() << endl;
        dataOut << songDatabase[i].getPopularity() << endl;
    }
    dataOut.close();
    cout << "Songs saved successfully!\n";
}
//***********************************************************
// Displays songs in playlist in nice format
//***********************************************************
void Song::displaySongs(const Song songDatabase[], int numSongs)
{
    cout << "\nCurrent Playlist:\n";
    cout << setw(30) << left << "Title"
         << setw(25) << "Artist"
         << setw(35) << "Genre"
         << "Popularity\n";
    cout << string(100, '*') << endl;
    // all songs data alignled nicley in columns
    for (int i = 0; i < numSongs; i++)
    {
        cout << setw(30) << left << songDatabase[i].getTitle()
             << setw(25) << songDatabase[i].getArtist()
             << setw(35) << songDatabase[i].getGenre()
             << songDatabase[i].getPopularity() << endl;
    }
}

// ***********************************************************
// Gathers "song reccomendations" based on user's preferred genre
//***********************************************************
void UserProfile::getRecommendations(const Song songDatabase[], int numSongs) const
{ // Check if there are any songs in the database
    if (numSongs == 0)
    {
        cout << "\nNo songs in database for recommendations.\n";
        return;
    }

    cout << "\nRecommended songs based on your preferences:\n";
    bool found = false;
    // Search for genre matches then will displays songs with the preferred genre
    for (int i = 0; i < numSongs; i++)
    {
        if (songDatabase[i].getGenre() == preferredGenre)
        {
            cout << "  " << songDatabase[i].getTitle() << " - " << songDatabase[i].getArtist() << endl;
            found = true;
        }
    }
}
//***********************************************************
// Have the user update their preferred genre
//***********************************************************
void UserProfile::updatePreferences()
{
    string genre;
    cout << "Enter new favorite genre: ";
    getline(cin, genre);

    setPreferredGenre(genre); // call function to update preferred genre
    cout << "Preference updated successfully!\n";
}
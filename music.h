// This program calls the music class constructor.
// Nelsi Valdovinos-Lemus
#ifndef MUSIC_H
#define MUSIC_H
#include <string>
using namespace std;

class Song // Manages everything about a song. Title, artist, genre, and popularity.
{
private:
    string title, artist, genre;
    int popularity;

public:
    // Default constructor
    Song()
    {
        title = "";
        artist = "";
        genre = "";
        popularity = 0;
    }
    // Constructor with parameters
    Song(string, string, string, int);

    void setTitle(string);
    void setArtist(string);
    void setGenre(string);
    void setPopularity(int);

    string getTitle() const
    {
        return title;
    }
    // accessor
    string getArtist() const
    {
        return artist;
    }

    string getGenre() const
    {
        return genre;
    }

    int getPopularity() const
    {
        return popularity;
    }

    static void loadSongsFromFile(Song songDatabase[], int &numSongs);
    static void saveSongsToFile(const Song songDatabase[], int numSongs);
    static void displaySongs(const Song songDatabase[], int numSongs);
};

class UserProfile
{
private:
    string preferredGenre;

public:
    UserProfile(string); // constructor that will initialize users preferred genre

    void setPreferredGenre(string);

    string getPreferredGenre() const
    {
        return preferredGenre;
    }

    void updatePreferences(); // can hace the user update their preferred genre
    void getRecommendations(const Song songDatabase[], int numSongs) const;
    // will find matching songs based on the users preferred genre
};

#endif
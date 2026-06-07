/*
Write Album's PrintSongsShorterThan() member function to print all the songs from the album whose duration is shorter than the value of the parameter songDuration. Use Song's PrintSong() member function to print a song.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song {
   public:
      void SetDurationAndName(int songDuration, string songName) {
         duration = songDuration;
         name = songName;
      }
      void PrintSong() const {
         cout << duration << " - " << name << endl;
      }
      int GetDuration() const { return duration; }
      string GetName() const { return name; }

   private:
      int duration;
      string name;
};

class Album {
   public:
      void SetName(string albumName) { name = albumName; }
      void InputSongs();
      void PrintName() const { cout << name << endl; }
      void PrintSongsShorterThan(int songDuration) const;

   private:
      string name;
      vector<Song> albumSongs;
};

void Album::InputSongs() {
   Song currSong;
   int currDuration;
   string currName;

   cin >> currDuration;
   while (currDuration >=  0) {
      cin >> currName;
      currSong.SetDurationAndName(currDuration, currName);
      albumSongs.push_back(currSong);
      cin >> currDuration;
   }
}

void Album::PrintSongsShorterThan(int songDuration) const {
   unsigned int i;
   Song currSong;

   cout << "Songs shorter than " << songDuration << " seconds:" << endl;

   for (i = 0; i < albumSongs.size(); ++i){
      currSong = albumSongs.at(i);
      
      if(currSong.GetDuration() < songDuration){
         currSong.PrintSong();
      }
   }

}

int main() {
   Album musicAlbum;
   string albumName;

   getline(cin, albumName);
   musicAlbum.SetName(albumName);
   musicAlbum.InputSongs();
   musicAlbum.PrintName();
   musicAlbum.PrintSongsShorterThan(150);

   return 0;
}
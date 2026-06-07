/*
Write code to read a list of song durations and song names from input. For each line of input, set the duration and name of newSong. Then add newSong to myPlaylist. Input first receives a song duration, then the name of that song (which you can assume is only one word long). Input example:
424 Time
383 Money
-1
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

int main() {
   vector<Song> myPlaylist;
   Song newSong;
   int songDuration;
   string songName;
   unsigned int i;

   cin >> songDuration;
   while (songDuration >= 0) {
      
      cin >> songName;
      newSong.SetDurationAndName(songDuration, songName);
      
      myPlaylist.push_back(newSong);

      cin >> songDuration;
   }

   for (i = 0; i < myPlaylist.size(); ++i) {
      newSong = myPlaylist.at(i);
      newSong.PrintSong();
   }

   return 0;
}
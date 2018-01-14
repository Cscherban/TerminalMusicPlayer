

#include"MusicPlayer.h"

using namespace boost::filesystem;




int main() {

    MusicPlayer m("/Users/scherban/Desktop/Music");
    m.playArtist(m.artists[0]);
    return 0;
}
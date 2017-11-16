//
// Created by Christopher Scherban on 11/3/17.
//

#include "MusicPlayer.h"
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
std::string MusicDirectory = "/Users/scherban/Desktop";




MusicPlayer::MusicPlayer(std::string Dir){
  /*Write Code to fill the Artist vector using path iterator. */

}





void MusicPlayer::playArtist(Artist a){
    for(int i = 0; i < a.albums.size(); i++){
        playAlbum(a.albums[i]);
    }
}
void MusicPlayer::playAlbum(Album a){
    for(int i = 0; i < a.songs.size(); i++){
        playSong(a.songs[i]);
    }
}
void MusicPlayer::playSong(Song s){
    system(("afplay " + s.path).c_str());
}





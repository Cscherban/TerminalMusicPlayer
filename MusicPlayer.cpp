//
// Created by Christopher Scherban on 11/3/17.
//
#include<iostream>
#include <algorithm>    // std::sort
#include "MusicPlayer.h"
using namespace boost::filesystem;


/**
 *
 * @param p is the path of the current directory
 */
void MusicPlayer::iterate_through_directory(path &p){
    path _temp;
    for(directory_iterator dir(p); dir!=directory_iterator(); dir++){
        _temp = path(*dir);
        if(is_directory(_temp)){
            iterate_through_directory(_temp);
        }
        else if(extension(_temp) == ".js"){ //checks for a specific extension
            struct Song s;
            s.name = _temp.stem().string();
            s.path = _temp.string();
            songs.push_back(s);
        }

    }

}

/**
 *  Constructor for MusicPlayer
 * @param Dir
 */
MusicPlayer::MusicPlayer(std::string Dir){
    path p(Dir.c_str());
    iterate_through_directory(p);

    //std::sort(songs.begin(),songs.end(),[](Song a,Song b){ return a.path.compare(b.path); }); //soring lambda if needed
    for(int i = 0; i < songs.size(); i++){
        std::cout<<songs[i].path<<std::endl;
    }

}




/**
 *  Plays all of an artist
 * @param a
 */
void MusicPlayer::playArtist(Artist a){
    for(int i = 0; i < a.albums.size(); i++){
        playAlbum(a.albums[i]);
    }
}

/**
 *
 * @param Album a, which is to be played
 */
void MusicPlayer::playAlbum(Album a){
    for(int i = 0; i < a.songs.size(); i++){
        playSong(a.songs[i]);
    }
}


/**
 * Plays a song
 * @param s
 */
void MusicPlayer::playSong(Song s){
    system(("afplay " + s.path).c_str());
}





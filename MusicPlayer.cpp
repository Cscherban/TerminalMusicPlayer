//
// Created by Christopher Scherban on 11/3/17.
//
#include<iostream>
#include <algorithm>    // std::sort
#include <boost/algorithm/string.hpp> //to split some strings
#include "MusicPlayer.h"
using namespace boost::filesystem;

#include <boost/algorithm/string.hpp>
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
        else if(extension(_temp) == ".mp3"){ //checks for a specific extension
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
 *
 *
 * WHEN YOU GET HOME IMPLEMENT THE THINGY WHERE YOU USE SPLIT TO GET ALBUM NAME AND ARTIST NAME FROM SONG;
 */
MusicPlayer::MusicPlayer(std::string Dir){
    path p(Dir.c_str());
    iterate_through_directory(p);

    std::sort(songs.begin(),songs.end(),[](Song a,Song b){ return a.path.compare(b.path); }); //soring lambda

    int i = 0;
    std::string next_album, next_artist;
    while(i<songs.size()){
        struct Artist artist;
        artist.name = extract_artist(songs[i].path);
        next_artist = artist.name;
        while(i<songs.size() && artist.name == next_artist ){

            struct Album album;
            album.name = extract_album(songs[i].path);
            next_album = album.name;
            while(i < songs.size() && (album.name == next_album && artist.name == next_artist)){

                album.songs.push_back(songs[i]);
                if(++i < songs.size()){
                    next_album = extract_album(songs[i].path);
                    next_artist = extract_artist(songs[i].path);
                }
            }
            artist.albums.push_back(album);

        }
        artists.push_back(artist);
    }


    /**

     If Stuff isnt working, try looking at the output.
     Make sure the file structure is Artist/Album/Song for all members of the dirrectory
     This will only look at the innermost two subdirrectories contained in the dirrectory
     And treat them as Artist and Album.

    for(Artist a: artists){
        for(Album b: a.albums){
            for(Song s : b.songs){
                std::cout<<a.name<<"\t "<<b.name<<"\t"<<s.name<<std::endl;
            }
        }
    }

    */









}

/**
 * does exacly as advertised
 * Stops all the playing of music.
 */
void MusicPlayer::stop(){
    system("killall afplay");
}



std::string MusicPlayer::extract_artist(std::string path){
    //std::cout<<"Hello: "<<path<<std::endl;
    std::vector<std::string> result;
    boost::split(result, path,boost::is_any_of("/") );
    return result[result.size() - 3];

    //return " ";
}

std::string MusicPlayer::extract_album(std::string path){
    std::vector<std::string> result;
    boost::split(result, path,boost::is_any_of("/") );
    return result[result.size() - 2];
}


/**
 *  Plays all of an artist
 * @param a
 */
void MusicPlayer::playArtist(Artist a){
    std::cout<<std::endl<<"Hey";

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
 * this will only work on a Mac
 *
 * @param s pretty obvious isn't it?
 */
void MusicPlayer::playSong(Song s){
   // system(("afplay " + s.path).c_str());
}


/**
 *
 * @param querry : The name of the song you are looking for
 * @return The song desired or null if nothign is found
 */
Song findSong(std::string querry){
    for(Song s: songs){
        if(querry == s.name){
            return s;
        }
    }

    return null;
}

/**
 *
 * @param querry , the name of the album you are searching for
 * @return the album you wanted, or null if nothign is found
 */
Album findAlbum(std::string querry){
    for(Album a: albums){
        if(querry == a.name){
            return a;
        }
    }
    return null;
}


/**
 *
 * @param querry the name of the artist you are wishing to find
 * @return the Artist that you want to find, or null if nothign is found
 */
Artist findArtist(std::string querry){
    for(Artist a: artists){
        if(querry == a.name){
            return a;
        }
    }
    return null;
}





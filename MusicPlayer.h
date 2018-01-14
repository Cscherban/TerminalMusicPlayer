//
// Created by Christopher Scherban on 11/3/17.
//

#ifndef UNTITLED5_MUSICPLAYER_H
#define UNTITLED5_MUSICPLAYER_H
#include<string>
#include<vector>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
class MusicPlayer {


public:
    struct Song{
        std::string name;
        std::string path;
    };
    struct Album{
        std::string name;
        std::vector<Song> songs;
    };
    struct Artist{
        std::string name;
        std::vector<Album> albums;
    };
    std::vector<Artist> artists;
    MusicPlayer(std::string Dir);
    void stop();
    void playArtist(Artist a );
    void playAlbum(Album a );
    void playSong(Song s);

    Song findSong(std::string querry);
    Album findAlbum(std::string name);
    Artist findArtist(std::string name);



private:

    bool isPlaying = false;


    std::vector<Album> albums;
    std::vector<Song> songs;

    void iterate_through_directory(path &p);
    std::string extract_artist(std::string);
    std::string extract_album(std::string);

};


#endif //UNTITLED5_MUSICPLAYER_H

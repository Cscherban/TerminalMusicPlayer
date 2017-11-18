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
private:
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
    bool isPlaying = false;
    std::string MODE = "";
    std::string current_song = "";
    std::string current_album = "";
    std::string current_artist = "";
    std::vector<Artist> artists;
    std::vector<Album> albums;
    std::vector<Song> songs;
    void iterate_through_directory(path &p);
public:
    MusicPlayer(std::string Dir);
    void skip();
    void replay();
    void previous();
    void playArtist(Artist a );
    void playAlbum(Album a );
    void playSong(Song s);
    Song findsong(std::string name);
    Album findAlbum(std::string name);
    Artist findArtist(std::string name);



};


#endif //UNTITLED5_MUSICPLAYER_H

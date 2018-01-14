cmake_minimum_required(VERSION 3.7)
project(TerminalMusicPlayer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MusicPlayer.cpp MusicPlayer.h InvalidSearchException.cpp InvalidSearchException.h)
add_executable(TerminalMusicPlayer ${SOURCE_FILES})

find_package(Boost COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(TerminalMusicPlayer ${Boost_FILESYSTEM_LIBRARY}
            ${Boost_SYSTEM_LIBRARY})

endif()
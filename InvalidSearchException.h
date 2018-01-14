//
// Created by Christopher Scherban on 1/14/18.
//


#ifndef TERMINALMUSICPLAYER_INVALIDSEARCHEXCEPTION_H
#define TERMINALMUSICPLAYER_INVALIDSEARCHEXCEPTION_H


#include <stdexcept>


class InvalidSearchException : public std::runtime_error {
public:
    InvalidSearchException(const char *);
    InvalidSearchException(const char *, const char *);
    const char *getMessage();
    const char *getQuerry();
    const char *what() const throw();


private:
    const char *querry;
    const char *msg;

};


#endif //TERMINALMUSICPLAYER_INVALIDSEARCHEXCEPTION_H

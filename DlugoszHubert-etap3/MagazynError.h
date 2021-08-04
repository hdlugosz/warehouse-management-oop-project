#ifndef MAGAZYNERROR_H_
#define MAGAZYNERROR_H_

#include <iostream>

struct MagazynError : std::exception {
    std::string message;

    explicit MagazynError(std::string msg) : message(std::move(msg)) {}

    virtual const char* what() const noexcept {
        return message.c_str();
    }
};

struct MagazynInvalidPosition: public MagazynError {
    explicit MagazynInvalidPosition(std::string msg) : MagazynError(std::move(msg)) {}
};

struct MagazynInvalidAmount : public MagazynError {
    explicit MagazynInvalidAmount(std::string msg) : MagazynError(std::move(msg)) {}
};

struct MagazynInvalidInput : public MagazynError {
    explicit MagazynInvalidInput(std::string msg) : MagazynError(std::move(msg)) {}
};


#endif
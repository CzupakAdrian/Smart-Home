#pragma once

#include <exception>
#include <string>

struct NoSuchItemException : public std::exception
{
    const char * what() const throw() { return "No such item"; }
};
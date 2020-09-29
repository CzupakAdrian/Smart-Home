#pragma once
#include <exception>
#include <string>
#include <vector>

using Message = std::string;

using Name = std::string;
using NamesList = std::vector<Name>;

struct NoSuchItemException : public std::exception
{
    const char * what() const throw() { return "No such item"; }
};
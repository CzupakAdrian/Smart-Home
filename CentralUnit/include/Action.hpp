#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

namespace SH
{
    using action_output = string_view; // TODO change it to sth else??
    using action_input = const string &; // it shouldn't be non const reference

    class Action
    {
    private:
        string name;

    public:
        string getDescription();
        virtual auto act(action_input params) -> action_output;
    };
} // namespace SH
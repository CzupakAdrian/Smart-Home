#include "SH_Action.hpp"

using SH::Action;

string Action::getDescription()
{
    unique_ptr<fstream> file;
    string description;
    {
        string filename = name + ".txt";
        file = make_unique<fstream>(filename.c_str());
        if (not file->is_open())
        {
            description = "\"" + filename + "\" not found";
            return move(description);
        }
    }
    while (*file >> description)
    {
    }
    file->close();
    return move(description);
}
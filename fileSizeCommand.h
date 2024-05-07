#ifndef FILE_SIZE_COMMAND_H
#define FILE_SIZE_COMMAND_H

#include "command.h"
#include <iostream>
#include <fstream>

class FileSizeCommand : public Command
{
public:
    virtual void execute(const std::string &params) override
    {
        std::ifstream file(params, std::ios::binary | std::ios::ate);
        if (file)
        {
            std::streamsize size = file.tellg();
            std::cout << "Size of file '" << params << "' in bytes: " << size << "\n";
        }
        else
        {
            std::cerr << "File with name '" << params << "' not found.\n";
        }
    }
};

#endif

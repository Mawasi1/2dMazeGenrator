#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const std::string& params) = 0;
};

#endif

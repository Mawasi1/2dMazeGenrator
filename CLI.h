#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include "command.h"
#include "generateMazeCommand.h"
#include "displayCommand.h"
#include "saveMazeCommand.h"
#include "loadMazeCommand.h"
#include "mazeSizeCommand.h"
#include "fileSizeCommand.h"
#include "solveCommand.h"

class CLI
{
private:
    std::unordered_map<std::string, Command *> commands;
    MazeManager mazeManager;

public:
    CLI()
    {
        // Register commands
        commands["generate maze"] = new GenerateMazeCommand(mazeManager);
        commands["display"] = new DisplayCommand(mazeManager);
        commands["save maze"] = new SaveMazeCommand(mazeManager);
        commands["load maze"] = new LoadMazeCommand(mazeManager);
        commands["maze size"] = new MazeSizeCommand(mazeManager);
        commands["file size"] = new FileSizeCommand();
        commands["solve"] = new SolveCommand(mazeManager);

        // Add more commands as needed
    }

    ~CLI()
    {
        // Clean up command objects
        for (auto &pair : commands)
        {
            delete pair.second;
        }
    }

    void start()
    {
        std::string line;
        std::cout << "Welcome to the Maze Generator CLI!\n";
        std::cout << "Available commands:\n";
        std::cout << "  generate maze <name> <rows> <cols> <simple or my or prim>\n";
        std::cout << "  display <name>\n"; 
        std::cout << "  save maze <name> <file name>\n";
        std::cout << "  load maze <file name> <name>\n";
        std::cout << "  maze size <name>\n";
        std::cout << "  file size <name>\n";
        std::cout << "  solve <name> <algoithm>\n";

        std::cout << "Type 'exit' to quit.\n";

        while (true)
        {
            std::cout << "> ";
            std::getline(std::cin, line);

            if (line == "exit")
            {
                break;
            }

            std::istringstream iss(line);
            std::string command;
            std::getline(iss, command, ' ');

            if (command == "generate")
            {
                std::string subcommand;
                std::getline(iss, subcommand, ' ');
                if (subcommand == "maze")
                {
                    std::string params;
                    std::getline(iss, params); // Get the rest of the line
                    commands["generate maze"]->execute(params);
                    continue;
                }
            }
            else if (command == "display") 
            {
                std::string params;
                std::getline(iss, params);                                             // Get the rest of the line
                params = params.substr(params.find_first_not_of(" \t\n\r\f\v"));       // Trim leading whitespace
                params = params.substr(0, params.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing whitespace
                commands["display"]->execute(params);
                continue;
            }
            else if (command == "save") 
            {
                std::string subcommand;
                std::getline(iss, subcommand, ' ');
                if (subcommand == "maze")
                {
                    std::string params;
                    std::getline(iss, params); // Get the rest of the line
                    commands["save maze"]->execute(params);
                    continue;
                }
            }
            else if (command == "load") 
            {
                std::string subcommand;
                std::getline(iss, subcommand, ' ');
                if (subcommand == "maze")
                {
                    std::string params;
                    std::getline(iss, params); // Get the rest of the line
                    commands["load maze"]->execute(params);
                    continue;
                }
            }
            else if (command == "maze") 
            {
                std::string subcommand;
                std::getline(iss, subcommand, ' ');
                if (subcommand == "size")
                {
                    std::string params;
                    std::getline(iss, params);                                             // Get the rest of the line
                    params = params.substr(params.find_first_not_of(" \t\n\r\f\v"));       // Trim leading whitespace
                    params = params.substr(0, params.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing whitespace
                    commands["maze size"]->execute(params);
                    continue;
                }
            }
            else if (command == "file") 
            {
                std::string subcommand;
                std::getline(iss, subcommand, ' ');
                if (subcommand == "size")
                {
                    std::string params;
                    std::getline(iss, params);                                             // Get the rest of the line
                    params = params.substr(params.find_first_not_of(" \t\n\r\f\v"));       // Trim leading whitespace
                    params = params.substr(0, params.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing whitespace
                    commands["file size"]->execute(params);
                    continue;
                }
            }
            else if (command == "solve") 
            {
                std::string params;
                std::getline(iss, params); // Get the rest of the line
                commands["solve"]->execute(params);
                continue;
            }

            std::cerr << "Unknown command: " << line << "\n";
        }

        std::cout << "Goodbye!\n";
    }
};

#endif

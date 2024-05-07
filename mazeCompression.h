#ifndef MAZE_COMPRESSION_H
#define MAZE_COMPRESSION_H

#include <vector>
#include <fstream>
#include "maze2d.h"

class MazeCompression {
public:
    // Method to compress and save a maze to a file
    void saveMaze(const Maze2D& maze, const std::string& filename) {
        std::vector<char> data = maze.getData();
        std::vector<char> compressedData;

        // Compress the data using run-length encoding
        char currentChar = data[0];
        int count = 1;
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] == currentChar) {
                ++count;
            } else {
                compressedData.push_back(currentChar);
                compressedData.push_back(count);
                currentChar = data[i];
                count = 1;
            }
        }
        compressedData.push_back(currentChar);
        compressedData.push_back(count);

        // Write the compressed data to the file
        std::ofstream file(filename, std::ios::binary);
        file.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size());
        file.close();
    }

    // Method to load and decompress a maze from a file
    Maze2D loadMaze(const std::string& filename) {
        // Read the compressed data from the file
        std::ifstream file(filename, std::ios::binary);
        std::vector<char> compressedData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        // Decompress the data using run-length encoding
        std::vector<char> data;
        for (size_t i = 0; i < compressedData.size(); i += 2) {
            char value = compressedData[i];
            int count = compressedData[i + 1];
            for (int j = 0; j < count; ++j) {
                data.push_back(value);
            }
        }

        // Create and return a Maze2D object using the decompressed data
        return Maze2D(data);
    }
};


#endif
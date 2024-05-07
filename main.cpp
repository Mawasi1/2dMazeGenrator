
#include "CLI.h"

int main()
{
    // Instantiate a SimpleMaze2DGenerator
    // SimpleMaze2DGenerator generator;

    // // Generate a maze with a given name, rows, and columns
    // Maze2D maze = generator.generate("MyMaze", 10, 10);

    // // Display the maze
    // std::cout << "Generated maze:\n";
    // maze.display();

    // double timeTaken = generator.measureAlgorithmTime("MyMaze",10, 10);
    // std::cout << "Time taken to generate the maze: " << timeTaken << " seconds\n";

  //     MyMaze2DGenerator mazeGenerator;
  //   //SimpleMaze2DGenerator mazeGenerator;

  //  // Generate a maze with a given name, number of rows, and number of columns
  //   std::string mazeName = "MyMaze";
  //   int rows = 10;
  //   int cols = 10;
  //   Maze2D maze = mazeGenerator.generate(mazeName, rows, cols);

  //   Maze2DSearchable maze_s(&maze);
  //   BFS bfs;
  //   AStar astar;

  //  Solution s = bfs.search(maze_s);

    // Solution astr = astar.search(maze_s);

    // Display the maze

    // std::pair<int, int> startPosition = maze.getStartPosition();
    // std::pair<int, int> goalPosition = maze.getGoalPosition();
    // int startRow = startPosition.first;
    // int startCol = startPosition.second;
    // int goalRow = goalPosition.first;
    // int goalCol = goalPosition.second;
    // std::cout << "Start position: (" << startRow << ", " << startCol << ")\n";
    // std::cout << "Goal position: (" << goalRow << ", " << goalCol << ")\n";

    // TestMazeGenerator t;
    // SimpleMaze2DGenerator simpleGenerator;
    // MyMaze2DGenerator myGenerator;
    // t.testMazeGenerator(simpleGenerator);
    // t.testMazeGenerator(myGenerator);

    // Demo demo;
    // demo.run();
    // MyMaze2DGenerator mazeGenerator;
    // // Generate a maze with a given name, number of rows, and number of columns
    // std::string mazeName = "MyMaze";
    // int rows = 10;
    // int cols = 12;
    // Maze2D maze = mazeGenerator.generate(mazeName, rows, cols);

    // std::cout << "created maze:" << std::endl;
    //  maze.display();


    // // Compress and save the maze
    // MazeCompression compressor;
    // compressor.saveMaze(maze.getData(), "MyMaze.mz");

    // // Load and decompress the maze
    // auto loadedData = compressor.loadMaze("MyMaze.mz");

    // // Reconstruct the maze from the loaded data
    // Maze2D loadedMaze(loadedData);

    // // Display the loaded maze
    // std::cout << "\nLoaded Maze:\n";
    // loadedMaze.display();

    CLI cli;
    cli.start();


    return 0;
}

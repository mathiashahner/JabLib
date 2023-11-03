#include <dfs.h>

DFS::DFS(Maze *maze)
{
  this->maze = maze;
}

void DFS::depthFirstSearch(MazePoint *point)
{
  point->isVisited = true;

  MazePoint *neighbour = getUnvisitedNeighbour(point);

  while (neighbour)
  {
    maze->removeWall(point, neighbour);

    if (maze->delay > 0)
      SDL_Delay(maze->delay);

    depthFirstSearch(neighbour);
    neighbour = getUnvisitedNeighbour(point);
  }
}

MazePoint *DFS::getUnvisitedNeighbour(MazePoint *point)
{
  int numEnumValues = sizeof(enum Direction);
  int selectedValues[numEnumValues];

  for (int i = 0; i < numEnumValues; i++)
    selectedValues[i] = 0;

  for (int i = 0; i < numEnumValues; i++)
  {
    Direction direction = getRandomDirection(selectedValues, numEnumValues);

    int x = point->point->x;
    int y = point->point->y;

    switch (direction)
    {
    case UP:
      y = point->point->y - maze->pointDistance;
      break;
    case DOWN:
      y = point->point->y + maze->pointDistance;
      break;
    case LEFT:
      x = point->point->x - maze->pointDistance;
      break;
    case RIGHT:
      x = point->point->x + maze->pointDistance;
      break;
    }

    if (x >= 0 && x < ((maze->columns - 1) * maze->pointDistance) &&
        y >= 0 && y < ((maze->rows - 1) * maze->pointDistance))
    {
      MazePoint *neighbour = &maze->mazePoints[y / maze->pointDistance][x / maze->pointDistance];

      if (!neighbour->isVisited)
        return neighbour;
    }
  }

  return NULL;
}

Direction DFS::getRandomDirection(int *selectedValues, int numEnumValues)
{
  int randomIndex;

  do
    randomIndex = rand() % numEnumValues;
  while (selectedValues[randomIndex]);

  selectedValues[randomIndex] = 1;

  return (enum Direction)randomIndex;
}
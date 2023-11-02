#include <time.h>
#include <maze.h>

Maze::Maze(SDL_Renderer *renderer, int rows, int columns)
{
  this->rows = rows + 1;
  this->columns = columns + 1;
  this->renderer = renderer;
  this->isGenerating = false;
  this->pointDistance = 20;
  this->delay = 50;

  srand(time(NULL));

  initPoints();
  initLines();
}

Maze::~Maze()
{
  deleteMazePoints();
}

void Maze::initPoints()
{
  mazePoints = new MazePoint *[rows];

  for (int row = 0; row < rows; row++)
  {
    mazePoints[row] = new MazePoint[columns];
  }

  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      mazePoints[row][column].isVisited = false;
      mazePoints[row][column].point = new Point(renderer, (column * pointDistance),
                                                (row * pointDistance), pointColor);
    }
  }
}

void Maze::initLines()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      Point *origin = mazePoints[row][column].point;

      if (column < columns - 1)
      {
        Point *xDestiny = mazePoints[row][column + 1].point;

        mazePoints[row][column].xLine = new Line(renderer, origin->x, origin->y,
                                                 xDestiny->x, xDestiny->y, lineColor);
      }
      else
      {
        mazePoints[row][column].xLine = NULL;
      }

      if (row < rows - 1)
      {
        Point *yDestiny = mazePoints[row + 1][column].point;

        mazePoints[row][column].yLine = new Line(renderer, origin->x, origin->y,
                                                 yDestiny->x, yDestiny->y, lineColor);
      }
      else
      {
        mazePoints[row][column].yLine = NULL;
      }
    }
  }
}

void Maze::generate()
{
  isGenerating = true;
  depthFirstSearch(&mazePoints[0][0]);
  isGenerating = false;
}

void Maze::depthFirstSearch(MazePoint *point)
{
  point->isVisited = true;

  MazePoint *neighbour = getUnvisitedNeighbour(point);

  while (neighbour)
  {
    removeWall(point, neighbour);

    if (delay > 0)
      SDL_Delay(delay);

    depthFirstSearch(neighbour);
    neighbour = getUnvisitedNeighbour(point);
  }
}

MazePoint *Maze::getUnvisitedNeighbour(MazePoint *point)
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
      y = point->point->y - pointDistance;
      break;
    case DOWN:
      y = point->point->y + pointDistance;
      break;
    case LEFT:
      x = point->point->x - pointDistance;
      break;
    case RIGHT:
      x = point->point->x + pointDistance;
      break;
    }

    if (x >= 0 && x < ((columns - 1) * pointDistance) && y >= 0 && y < ((rows - 1) * pointDistance))
    {
      MazePoint *neighbour = &mazePoints[y / pointDistance][x / pointDistance];

      if (!neighbour->isVisited)
        return neighbour;
    }
  }

  return NULL;
}

void Maze::removeWall(MazePoint *point, MazePoint *neighbour)
{
  int x = point->point->x;
  int y = point->point->y;

  Direction direction;

  if (x == neighbour->point->x)
  {
    if (y > neighbour->point->y)
      direction = UP;
    else
      direction = DOWN;
  }
  else
  {
    if (x > neighbour->point->x)
      direction = LEFT;
    else
      direction = RIGHT;
  }

  switch (direction)
  {
  case UP:
    delete point->xLine;
    point->xLine = NULL;
    break;
  case DOWN:
    delete neighbour->xLine;
    neighbour->xLine = NULL;
    break;
  case LEFT:
    delete point->yLine;
    point->yLine = NULL;
    break;
  case RIGHT:
    delete neighbour->yLine;
    neighbour->yLine = NULL;
    break;
  }
}

Direction Maze::getRandomDirection(int *selectedValues, int numEnumValues)
{
  int randomIndex;

  do
    randomIndex = rand() % numEnumValues;
  while (selectedValues[randomIndex]);

  selectedValues[randomIndex] = 1;

  return (enum Direction)randomIndex;
}

void Maze::render(int screenWidth, int screenHeight)
{
  int xInitial = ((screenWidth / 2) - (((columns - 1) * pointDistance) / 2)) + (xOffset / 2);
  int yInitial = ((screenHeight / 2) - (((rows - 1) * pointDistance) / 2)) + (yOffset / 2);

  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      MazePoint point = mazePoints[row][column];

      point.point->render(xInitial, yInitial);

      if (point.xLine != NULL)
        point.xLine->render(xInitial, yInitial);

      if (point.yLine != NULL)
        point.yLine->render(xInitial, yInitial);
    }
  }
}

void Maze::deleteMazePoints()
{
  for (int row = 0; row < rows; row++)
  {
    delete[] mazePoints[row];
  }

  delete[] mazePoints;
}

void Maze::reset()
{
  deleteMazePoints();
  initPoints();
  initLines();
}

void Maze::decreaseDelay()
{
  if (delay > 0)
    delay -= 10;
}

void Maze::increaseDelay()
{
  if (delay < 100)
    delay += 10;
}

void Maze::decreasePointDistance()
{
  if (pointDistance > 10)
  {
    pointDistance -= 1;
    reset();
  }
}

void Maze::increasePointDistance()
{
  if (pointDistance < 50)
  {
    pointDistance += 1;
    reset();
  }
}

void Maze::resizeMaze(ResizeOption option)
{
  deleteMazePoints();

  switch (option)
  {
  case ADD_ROW:
    rows++;
    break;
  case ADD_COLUMN:
    columns++;
    break;
  case REMOVE_ROW:
    if (rows > 2)
      rows--;
    break;
  case REMOVE_COLUMN:
    if (columns > 2)
      columns--;
    break;
  }

  initPoints();
  initLines();
}

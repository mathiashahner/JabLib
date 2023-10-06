#include <maze.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

Maze::Maze(SDL_Renderer *renderer, int rows, int columns)
{
  this->rows = rows;
  this->columns = columns;
  this->renderer = renderer;
  this->hasConflicts = true;

  srand(time(NULL));

  initPoints();
  initLines();
}

Maze::~Maze()
{
  for (int row = 0; row < rows; row++)
  {
    delete[] mazePoints[row];
  }

  delete[] mazePoints;
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
      mazePoints[row][column].rect = new Rect(renderer, (column * rectDistance) + rectWidth,
                                              (row * rectDistance) + rectHeight,
                                              rectWidth, rectHeight, rectColor);
    }
  }
}

void Maze::initLines()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      int randomRow = getRandomNumber(rows - 1);
      int randomColumn = getRandomNumber(columns - 1);

      mazePoints[row][column].line = new Line(renderer,
                                              mazePoints[row][column].rect->x,
                                              mazePoints[row][column].rect->y,
                                              mazePoints[randomRow][randomColumn].rect->x,
                                              mazePoints[randomRow][randomColumn].rect->y,
                                              lineColor);
    }
  }
}

void Maze::update()
{
  if (hasConflicts)
  {
    for (int row = 0; row < rows; row++)
    {
      for (int column = 0; column < columns; column++)
      {
        MazePoint mazePoint = mazePoints[row][column];

        if (verifyConflicts(mazePoint.line))
        {
          int newRow = getRandomNumber(rows - 1);
          int newColumn = getRandomNumber(columns - 1);

          // if (row == 0)
          // {
          //   newRow = row + 1;
          //   newColumn = column;
          // }

          // if (row == rows - 1)
          // {
          //   newRow = row - 1;
          //   newColumn = column;
          // }

          mazePoint.line->update(mazePoint.rect->x,
                                 mazePoint.rect->y,
                                 mazePoints[newRow][newColumn].rect->x,
                                 mazePoints[newRow][newColumn].rect->y);

          mazePoint.line->render();
        }
      }
    }
  }
}

bool Maze::verifyConflicts(Line *line)
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      Line *currentLine = mazePoints[row][column].line;

      Point A = {line->x1, line->y1};
      Point B = {line->x2, line->y2};
      Point C = {currentLine->x1, currentLine->y1};
      Point D = {currentLine->x2, currentLine->y2};

      return doIntersect(A, B, C, D);
    }
  }
}

bool Maze::doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
    return true;

  if (o1 == 0 && onSegment(p1, p2, q1))
    return true;

  if (o2 == 0 && onSegment(p1, q2, q1))
    return true;

  if (o3 == 0 && onSegment(p2, p1, q2))
    return true;

  if (o4 == 0 && onSegment(p2, q1, q2))
    return true;

  return false;
}

int Maze::orientation(Point p, Point q, Point r)
{
  int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0;

  return (val > 0) ? 1 : 2;
}

bool Maze::onSegment(Point p, Point q, Point r)
{
  if (q.x <= MAX(p.x, r.x) && q.x >= MIN(p.x, r.x) &&
      q.y <= MAX(p.y, r.y) && q.y >= MIN(p.y, r.y))
    return true;

  return false;
}

void Maze::render()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      mazePoints[row][column].rect->render();
      mazePoints[row][column].line->render();
    }
  }
}

int Maze::getRandomNumber(int max)
{
  return rand() % max;
}
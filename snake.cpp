#include "snake.h"
#include <iostream>

Snake::Snake(int x, int y, int growToSize): numQueuedSegments(growToSize)
{
  QImage image;
  image.load("C:\\Users\\Adel\\QTProjects\\Snake\\snake.png");
  QRect head;
  head = image.rect();
  head.moveTo(x, y);
  putSegmentAt(image, head, x, y);
}

void Snake::putSegmentAt(QImage image, QRect rect, int x, int y)
{
  segments.push_front(Segment(image, rect, x, y));

  if (numQueuedSegments > 0)
  {
     --numQueuedSegments;
  }
  else
  {
     segments.pop_back();
  }
}

void Snake::growBy(unsigned int numSegments)
{
  numQueuedSegments += numSegments;
}

Snake::~Snake()
{
 std::cout << ("Snake deleted\n");
}

void Snake::moveBottom()
{
    QImage image;
    image.load("C:\\Users\\Adel\\QTProjects\\Snake\\snake.png");
    QRect rect2;
    rect2 = image.rect();
    int x = head().x;
    int y = head().y;
    rect2.moveTo(x, y+7);
    putSegmentAt(image, rect2, x, y+7);
}

void Snake::moveTop()
{
    QImage image;
    image.load("C:\\Users\\Adel\\QTProjects\\Snake\\snake.png");
    QRect rect2;
    rect2 = image.rect();
    int x = head().x;
    int y = head().y;
    rect2.moveTo(x, y-7);
    putSegmentAt(image, rect2, x, y-7);
}

void Snake::moveLeft()
{
    QImage image;
    image.load("C:\\Users\\Adel\\QTProjects\\Snake\\snake.png");
    QRect rect2;
    rect2 = image.rect();
    int x = head().x;
    int y = head().y;
    rect2.moveTo(x-7, y);
    putSegmentAt(image, rect2, x-7, y);
}

void Snake::moveRight()
{
    QImage image;
    image.load("C:\\Users\\Adel\\QTProjects\\Snake\\snake.png");
    QRect rect2;
    rect2 = image.rect();
    int x = head().x;
    int y = head().y;
    rect2.moveTo(x+7, y);
    putSegmentAt(image, rect2, x+7, y);
}



#include "printformat.h"

PrintFormat::PrintFormat()
{
    up=0;
    down=0;
    left=0;
    right=0;
    fontSize=0;
    singleSpace=0;
    lineSpace=0;
}

int PrintFormat::getId()
{
    return id;
}

void PrintFormat::setId(int id)
{
    this->id = id;
}

float PrintFormat::getUp()
{
    return up;
}

void PrintFormat::setUp(float up)
{
    this->up = up;
}

float PrintFormat::getDown()
{
    return down;
}

void PrintFormat::setDown(float down)
{
    this->down = down;
}

float PrintFormat::getLeft()
{
    return left;
}

void PrintFormat::setLeft(float left)
{
    this->left = left;
}

float PrintFormat::getRight()
{
    return right;
}

void PrintFormat::setRight(float right)
{
    this->right = right;
}

int PrintFormat::getFontSize()
{
    return fontSize;
}

void PrintFormat::setFontSize(int fontSize)
{
    this->fontSize = fontSize;
}

float PrintFormat::getSingleSpace()
{
    return singleSpace;
}

void PrintFormat::setSingleSpace(float singleSpace)
{
    this->singleSpace = singleSpace;
}

float PrintFormat::getLineSpace()
{
    return lineSpace;
}

void PrintFormat::setLineSpace(float lineSpace)
{
    this->lineSpace = lineSpace;
}

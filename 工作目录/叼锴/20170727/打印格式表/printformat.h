#ifndef PRINTFORMAT_H
#define PRINTFORMAT_H

class PrintFormat
{
public:
    PrintFormat();

    int getId();
    void setId(int id);
    float getUp();
    void setUp(float up);
    float getDown();
    void setDown(float down);
    float getLeft();
    void setLeft(float left);
    float getRight();
    void setRight(float right);
    int getFontSize();
    void setFontSize(int fontSize);
    float getSingleSpace();
    void setSingleSpace(float singleSpace);
    float getLineSpace();
    void setLineSpace(float lineSpace);
private:
    int id;
    float up;//上边距
    float down;//下边距
    float left;//左边距
    float right;//右边距
    int fontSize;//字体大小
    float singleSpace;//联单间距
    float lineSpace;//行距
};

#endif // PRINTFORMAT_H

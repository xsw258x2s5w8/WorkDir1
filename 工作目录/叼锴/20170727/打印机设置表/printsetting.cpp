#include "printsetting.h"

PrintSetting::PrintSetting()
{
    isAuto=-1;
    bkZero=-1;
    minWeight=0;
    singleNum=0;
    singleSpace=0;
    printerType=-1;
    title="";
    micrType=-1;
    QRCode=-1;
}
int PrintSetting::getPrintSetId()
{
    return printSetId;
}
void PrintSetting::setPrintSetId(int printSetId)
{
    this->printSetId = printSetId;
}
int PrintSetting::getIsAuto()
{
    return isAuto;
}
void PrintSetting::setIsAuto(int isAuto)
{
    this->isAuto = isAuto;
}
float PrintSetting::getbkZero()
{
    return bkZero;
}
void PrintSetting::setbkZero(float bkZero)
{
    this->bkZero = bkZero;
}
float PrintSetting::getMinWeight()
{
    return minWeight;
}
void PrintSetting::setMinWeight(float minWeight)
{
    this->minWeight = minWeight;
}
int PrintSetting::getSingleNum()
{
    return singleNum;
}
void PrintSetting::setSingleNum(int singleNum)
{
     this->singleNum = singleNum;
}
float PrintSetting::getSingleSpace()
{
    return singleSpace;
}
void PrintSetting::setSingleSpace(float singleSpace)
{
    this->singleSpace = singleSpace;
}
int PrintSetting::getPrinterType()
{
    return printerType;
}
void PrintSetting::setPrinterType(int printerType)
{
    this->printerType = printerType;
}
QString PrintSetting::getTitle()
{
    return title;
}
void PrintSetting::setTitle(QString title)
{
    this->title = title;
}
int PrintSetting::getMicrType()
{
    return micrType;
}
void PrintSetting::setMicrType(int micrType)
{
    this->micrType = micrType;
}
int PrintSetting::getQRCode()
{
    return QRCode;
}
void PrintSetting::setQRCode(int QRCode)
{
    this->QRCode = QRCode;
}

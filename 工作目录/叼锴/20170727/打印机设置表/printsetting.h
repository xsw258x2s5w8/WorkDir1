#ifndef PRINTSETTING_H
#define PRINTSETTING_H
#include <QString>
class PrintSetting
{
public:
    PrintSetting();
    int getPrintSetId();
    void setPrintSetId(int printSetId);
    int getIsAuto();
    void setIsAuto(int isAuto);
    float getbkZero();
    void setbkZero(float bkZero);
    float getMinWeight();
    void setMinWeight(float minWeight);
    int getSingleNum();
    void setSingleNum(int singleNum);
    float getSingleSpace();
    void setSingleSpace(float singleSpace);
    int getPrinterType();
    void setPrinterType(int printerType);
    QString getTitle();
    void setTitle(QString title);
    int getMicrType();
    void setMicrType(int micrType);
    int getQRCode();
    void setQRCode(int QRCode);
private:
    int printSetId;//打印设置id
    int isAuto;//自动打印
    float bkZero;//回零限制
    float minWeight;//最小打印重量
    int singleNum;//联单数量
    float singleSpace;//联单间距
    int printerType;//打印机类型
    QString title;//磅单标题
    int micrType;//微打类型
    int QRCode;//二维码
};

#endif // PRINTSETTING_H

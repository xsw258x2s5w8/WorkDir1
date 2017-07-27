#ifndef PRINTFORMATIMPL_H
#define PRINTFORMATIMPL_H
#include <QtSql>
#include "printformat.h"
class PrintFormatImpl
{
public:
    PrintFormatImpl();
    PrintFormat selectPrintFormat();//查询打印格式表
    int deletePrintFormat();//删除打印格式表
    int insertPrintFormat(PrintFormat printFormat);//插入到打印格式表
private:
    QSqlDatabase database;
};

#endif // PRINTFORMATIMPL_H

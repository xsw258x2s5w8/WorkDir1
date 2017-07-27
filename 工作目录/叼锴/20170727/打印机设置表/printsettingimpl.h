#ifndef PRINTSETTINGIMPL_H
#define PRINTSETTINGIMPL_H
#include <QtSql>
#include "printsetting.h"
class PrintSettingImpl
{
public:
    PrintSettingImpl();
    int deletePrintSettingById(int printSetId);//根据id删除PrintSetting表记录
    int deletePrintSetting();//删除表中的所有记录
    PrintSetting selectPrintSettingById(int printSetId);//根据id查询
    PrintSetting selectPrintSetting();//查询所有记录
    int insertPrintSetting(PrintSetting printSetting);//把数据插入到表中
    int updatePrintSetting(PrintSetting printSetting);//根据id更新表中数据

private:
    QSqlDatabase database;
};

#endif // PRINTSETTINGIMPL_H

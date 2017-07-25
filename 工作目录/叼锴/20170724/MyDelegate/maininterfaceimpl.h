#ifndef MAININTERFACEIMPL_H
#define MAININTERFACEIMPL_H
#include "maininterface.h"
#include <QtSql>
class MainInterfaceImpl
{
public:
    MainInterfaceImpl();
    int deleteInterface();//删除表中数据
    int  insertInterface(MainInterface interface);//向表中添加数据
    QList<MainInterface> selectInterface();//获得表中所有数据
private:
    QSqlDatabase database;
};

#endif // MAININTERFACEIMPL_H

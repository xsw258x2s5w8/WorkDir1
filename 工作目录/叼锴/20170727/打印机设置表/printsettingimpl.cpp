#include "printsettingimpl.h"
#include <QDebug>
PrintSettingImpl::PrintSettingImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      database = QSqlDatabase::database("qt_sql_default_connection");
    else
      database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    database.setDatabaseName("/opt/sqlite/D28QT.db");
    //打开连接
    if( !database.open())
    {
       qDebug() << database.lastError();
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery query;
        QString createTable_sql = "create table if not exists PrintSetting(printSetId INTEGER PRIMARY KEY AUTOINCREMENT,isAuto int,bkZero REAL,minWeight REAL,singleNum int,singleSpace REAL,printerType int,title varchar(40),micrType int,QRCode int);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int PrintSettingImpl::deletePrintSettingById(int printSetId)//根据id删除PrintSetting表记录
{
    if(database.open())
    {
        QSqlQuery query;
        //把int类型转化为QString类型
        QString id = QString::number(printSetId, 10);
        QString delete_sql = "delete from PrintSetting where printSetId="+id;//进行字符串拼接
        query.prepare(delete_sql);
        if(!query.exec())
        {
            qDebug()<<query.lastError();
            database.close();
            return -1;
        }
        else
        {
            qDebug()<<"delete success";
            database.close();
            return 1;
        }
    }
    database.close();
    return -1;
}

int PrintSettingImpl::deletePrintSetting()//删除表中的所有记录
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from PrintSetting";
        query.prepare(delete_sql);
        if(!query.exec())
        {
            qDebug()<<query.lastError();
            database.close();
            return -1;
        }
        else
        {
            qDebug()<<"delete success";
            database.close();
            return 1;
        }
    }
    database.close();
    return -1;
}

PrintSetting PrintSettingImpl::selectPrintSettingById(int printSetId)//根据id查询
{
    PrintSetting printSetting;
    //把int类型转化为QString类型
    QString id = QString::number(printSetId, 10);
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from PrintSetting where printSetId = "+id;
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                printSetting.setPrintSetId(query.value(0).toInt());
                printSetting.setIsAuto(query.value(1).toInt());
                printSetting.setbkZero(query.value(2).toFloat());
                printSetting.setMinWeight(query.value(3).toFloat());
                printSetting.setSingleNum(query.value(4).toInt());
                printSetting.setSingleSpace(query.value(5).toFloat());
                printSetting.setPrinterType(query.value(6).toInt());
                printSetting.setTitle(query.value(7).toString());
                printSetting.setMicrType(query.value(8).toInt());
                printSetting.setQRCode(query.value(9).toInt());
            }


        }
    }
    database.close();
    return printSetting;
}

PrintSetting PrintSettingImpl::selectPrintSetting()//查询所有记录
{
    PrintSetting printSetting;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from PrintSetting";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                printSetting.setPrintSetId(query.value(0).toInt());
                printSetting.setIsAuto(query.value(1).toInt());
                printSetting.setbkZero(query.value(2).toFloat());
                printSetting.setMinWeight(query.value(3).toFloat());
                printSetting.setSingleNum(query.value(4).toInt());
                printSetting.setSingleSpace(query.value(5).toFloat());
                printSetting.setPrinterType(query.value(6).toInt());
                printSetting.setTitle(query.value(7).toString());
                printSetting.setMicrType(query.value(8).toInt());
                printSetting.setQRCode(query.value(9).toInt());
            }


        }
    }
    database.close();
    return printSetting;
}

int PrintSettingImpl::insertPrintSetting(PrintSetting printSetting)//把数据插入到表中
{
    if(database.open())
    {
        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into PrintSetting(isAuto,bkZero,minWeight,singleNum,singleSpace,printerType,title,micrType,QRCode) values(?,?,?,?,?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupIsAuto;
        GroupIsAuto.append(printSetting.getIsAuto());
        QVariantList GroupbkZero;
        GroupbkZero.append(printSetting.getbkZero());
        QVariantList GroupMInWeight;
        GroupMInWeight.append(printSetting.getMinWeight());
        QVariantList GroupSingleNum;
        GroupSingleNum.append(printSetting.getSingleNum());
        QVariantList GroupSingleSpace;
        GroupSingleSpace.append(printSetting.getSingleSpace());
        QVariantList GroupPrinterType;
        GroupPrinterType.append(printSetting.getPrinterType());
        QVariantList GroupTitle;
        GroupTitle.append(printSetting.getTitle());
        QVariantList GroupMicrType;
        GroupMicrType.append(printSetting.getMicrType());
        QVariantList GroupQRCode;
        GroupQRCode.append(printSetting.getQRCode());
        //插入到sql语句中
        query.addBindValue(GroupIsAuto);
        query.addBindValue(GroupbkZero);
        query.addBindValue(GroupMInWeight);
        query.addBindValue(GroupSingleNum);
        query.addBindValue(GroupSingleSpace);
        query.addBindValue(GroupPrinterType);
        query.addBindValue(GroupTitle);
        query.addBindValue(GroupMicrType);
        query.addBindValue(GroupQRCode);

        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"插入记录成功";
             database.close();
             return 1;
         }

    }
}

int PrintSettingImpl::updatePrintSetting(PrintSetting printSetting)//根据id更新表中数据
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = printSetting.getPrintSetId();
        QString id = QString::number(intId,10);
        //QString insert_sql = "insert into PrintSetting(isAuto,bkZero,minWeight,singleNum,singleSpace,printerType,title,micrType,QRCode) values(?,?,?,?,?,?,?,?,?)";
        QString update_sql = "update PrintSetting set isAuto=?,bkZero=?,minWeight=?,singleNum=?,singleSpace=?,printerType=?,title=?,micrType=?,QRCode=? where printSetId="+id;
        query.prepare(update_sql);

        //给数据赋值
        QVariantList GroupIsAuto;
        GroupIsAuto.append(printSetting.getIsAuto());
        QVariantList GroupbkZero;
        GroupbkZero.append(printSetting.getbkZero());
        QVariantList GroupMInWeight;
        GroupMInWeight.append(printSetting.getMinWeight());
        QVariantList GroupSingleNum;
        GroupSingleNum.append(printSetting.getSingleNum());
        QVariantList GroupSingleSpace;
        GroupSingleSpace.append(printSetting.getSingleSpace());
        QVariantList GroupPrinterType;
        GroupPrinterType.append(printSetting.getPrinterType());
        QVariantList GroupTitle;
        GroupTitle.append(printSetting.getTitle());
        QVariantList GroupMicrType;
        GroupMicrType.append(printSetting.getMicrType());
        QVariantList GroupQRCode;
        GroupQRCode.append(printSetting.getQRCode());
        //插入到sql语句中
        query.addBindValue(GroupIsAuto);
        query.addBindValue(GroupbkZero);
        query.addBindValue(GroupMInWeight);
        query.addBindValue(GroupSingleNum);
        query.addBindValue(GroupSingleSpace);
        query.addBindValue(GroupPrinterType);
        query.addBindValue(GroupTitle);
        query.addBindValue(GroupMicrType);
        query.addBindValue(GroupQRCode);
        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"update success";
             database.close();
             return 1;
         }
    }
    database.close();
    return -1;
}

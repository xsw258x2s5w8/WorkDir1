#include "printformatimpl.h"
#include <QDebug>
PrintFormatImpl::PrintFormatImpl()
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
        QString createTable_sql = "create table if not exists PrintFormat(id INTEGER PRIMARY KEY AUTOINCREMENT,up REAL,down REAL,left REAL,right REAL,fontSize int,singleSpace REAL,lineSpace REAL);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
PrintFormat PrintFormatImpl::selectPrintFormat()//查询打印格式表
{
    PrintFormat printFormat;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from PrintFormat";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                printFormat.setId(query.value(0).toInt());
                printFormat.setUp(query.value(1).toFloat());
                printFormat.setDown(query.value(2).toFloat());
                printFormat.setLeft(query.value(3).toFloat());
                printFormat.setRight(query.value(4).toFloat());
                printFormat.setFontSize(query.value(5).toInt());
                printFormat.setSingleSpace(query.value(6).toFloat());
                printFormat.setLineSpace(query.value(7).toFloat());
            }


        }
    }
    database.close();
    return printFormat;
}

int PrintFormatImpl::deletePrintFormat()//删除打印格式表
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from PrintFormat";
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

int PrintFormatImpl::insertPrintFormat(PrintFormat printFormat)//插入到打印格式表
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into PrintFormat(up,down,left,right,fontSize,singleSpace,lineSpace) values(?,?,?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupUp;
        GroupUp.append(printFormat.getUp());
        QVariantList GroupDown;
        GroupDown.append(printFormat.getDown());
        QVariantList GroupLeft;
        GroupLeft.append(printFormat.getLeft());
        QVariantList GroupRight;
        GroupRight.append(printFormat.getRight());
        QVariantList GroupFontSize;
        GroupFontSize.append(printFormat.getFontSize());
        QVariantList GroupSingleSpace;
        GroupSingleSpace.append(printFormat.getSingleSpace());
        QVariantList GroupLineSpace;
        GroupLineSpace.append(printFormat.getLineSpace());
        //插入到sql语句中
        query.addBindValue(GroupUp);
        query.addBindValue(GroupDown);
        query.addBindValue(GroupLeft);
        query.addBindValue(GroupRight);
        query.addBindValue(GroupFontSize);
        query.addBindValue(GroupSingleSpace);
        query.addBindValue(GroupLineSpace);

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

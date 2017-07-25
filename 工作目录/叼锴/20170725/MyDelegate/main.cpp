#include <QApplication>
#include <QTextCodec>
#include "mytableview.h"
#include "mydelegate.h"
#include "mydelegateedit.h"
#include "maininterfaceimpl.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTableView mytableview;
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    mytableview.setSelectionBehavior(QAbstractItemView::SelectRows);
    mytableview.setSelectionMode ( QAbstractItemView::SingleSelection);//选中单行
    //mytableview.setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    MyDelegate *mydelegate = new MyDelegate;
    mytableview.setItemDelegate(mydelegate);

    MainInterfaceImpl impl;

    QList<MainInterface> list = impl.selectInterface();

    for(int i=0;i<list.length();i++)
    {
       MainInterface main;
       main = list.at(i);
       mytableview.setModelData(main);
    }


//    MainInterface main;
//    main.setIsMust(1);
//    main.setIsSelected(1);
//    main.setOtherName("车号");
//    main.setPara("carId");
//    main.setParaName("车号");
//    mytableview.setModelData(main);


    mytableview.show();

    return a.exec();
}

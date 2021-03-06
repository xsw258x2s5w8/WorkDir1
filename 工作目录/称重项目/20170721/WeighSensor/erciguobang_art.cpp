#include "erciguobang_art.h"

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

Erciguobang_art::Erciguobang_art(QWidget *parent) :
    QWidget(parent)
{
    //10个button
    QString buttontext = "苹果,面粉,油条,豆皮,奶油,花椒,水桶,铁桶,麻花,绿豆";
    QStringList texts = buttontext.split(",");
    signalMapper = new QSignalMapper(this);
    QGridLayout *gridLayout = new QGridLayout;
    for (int i = 0; i < texts.size(); ++i)
    {
       QPushButton *button = new QPushButton(texts[i], this);
       button->setObjectName(texts[i]);
       //原始信号传递给signalmapper
       connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(button, texts[i]);
       //设置signalmapper的转发规则, 转发为参数为QString类型的信号， 并把texts[i]的内容作为实参传递。
       gridLayout->addWidget(button, i / 3, i % 3);
    }
    //将转发的信号连接到最终的槽函数
    connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));
    setLayout(gridLayout);
}

void Erciguobang_art::doClicked(const QString &btnname)
{
    //显示被按下的btn名称。
    //  QMessageBox::information(this, "Clicked", btnname + " is clicked!");

    emit sendArtid(btnname);

    this->close();
}

#include "mydelegateedit.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
QString AllContent="";
int isOK=-1;
MyDelegateEdit::MyDelegateEdit(QString content,QWidget *parent)
            :QWidget(parent)
{

    edit=new QLineEdit;
    ok=new QPushButton;
    cancel=new QPushButton;
    //向edit编辑框内填写内容
     this->edit->setText(content);
     ok->setText("确定");
     cancel->setText("取消");
     QHBoxLayout *topLeftLayout1 = new QHBoxLayout;
     topLeftLayout1->addWidget(edit);
     QHBoxLayout *topLeftLayout2 = new QHBoxLayout;
     topLeftLayout2->addWidget(ok);
     topLeftLayout2->addWidget(cancel);


     QVBoxLayout *mainlayout = new QVBoxLayout;
     mainlayout->addLayout(topLeftLayout1);
     mainlayout->addLayout(topLeftLayout2);

     this->setLayout(mainlayout);

     connect(this->ok,SIGNAL(clicked()),this,SLOT(push_ok_button()));
     connect(this->cancel,SIGNAL(clicked()),this,SLOT(push_cancel_button()));

     setWindowTitle(tr("Edit"));
     //setFixedHeight(sizeHint().height());
     this->setGeometry(100,100,100,100);
     setVisible(true);

}

void MyDelegateEdit::push_ok_button()
{
    AllContent=edit->text();
    isOK=1;
    //emit clicked1();
    this->close();
}
void MyDelegateEdit::push_cancel_button()
{
    isOK=0;
    //emit clicked1();
    this->close();
}


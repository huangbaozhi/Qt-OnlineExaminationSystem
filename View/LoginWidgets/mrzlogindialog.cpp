#include "mrzlogindialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>

MrzLoginDialog::MrzLoginDialog(QWidget *parent)
    : QDialog{parent}
{
    initUi();
    connectFun();
}

void MrzLoginDialog::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedSize(500, 448);
    //pMainWgt->setStyleSheet("QWidget{background-color: rgba(206,189,219,1);}");
    pMainWgt->setWindowFlags(Qt::FramelessWindowHint); // 设置窗口无边框
    pMainWgt->setAttribute(Qt::WA_TranslucentBackground); // 设置窗口背景透明
    //(void)new MovebleWindow(this);
    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pCloseLyt = new QHBoxLayout();
    pCloseLyt->setContentsMargins(0, 0, 0, 0);
    m_pCloseBtn = new QPushButton(this);
    m_pCloseBtn->setFixedSize(20, 20);
    m_pCloseBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/clear_1x.png); border: 0px;}");
    pCloseLyt->addStretch();
    pCloseLyt->addWidget(m_pCloseBtn);

    QHBoxLayout *pLogoLyt = new QHBoxLayout();
    pLogoLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pLogoLbl = new QLabel(this);
    pLogoLbl->setFixedSize(110, 110);
    //pLogoLbl->setStyleSheet("QLabel{background-image: url(:/image/LOGO.png); border: 0px;}");
    pLogoLbl->setStyleSheet("QLabel{border-image: url(:/image/LOGO.png);}");
    pLogoLyt->addStretch();
    pLogoLyt->addWidget(pLogoLbl);
    pLogoLyt->addStretch();

    QString style = QString("QLineEdit{"
                            "line-height: 28px;"
                            "border-radius: 10px;"
                            "background-color: rgba(255,255,255,1);"
                            "color: rgba(16,16,16,1);"
                            "font-size: 20px;"
                            "text-align: center;"
                            "font-family: PingFangSC-regular;"
                            "border: 1px solid rgba(187,187,187,1);"
                            "}");

    QWidget *pUserWgt = new QWidget(this);
    pUserWgt->setFixedSize(250, 172);
    QVBoxLayout *pUserLyt = new QVBoxLayout(pUserWgt);
    pUserLyt->setContentsMargins(0, 0, 0, 0);
    m_pAccountEdit = new QLineEdit(this);
    m_pAccountEdit->setFixedSize(250, 42);
    m_pAccountEdit->setStyleSheet(style);

    m_pPasswordEdit = new QLineEdit(this);
    m_pPasswordEdit->setFixedSize(250, 42);
    m_pPasswordEdit->setStyleSheet(style);


    // 已阅读并同意m_pLoginB
    QHBoxLayout *pReadAlreadyLyt = new QHBoxLayout();
    pReadAlreadyLyt->setContentsMargins(0, 0, 0, 0);
    m_pReadAlreadyBtn = new QPushButton(this);
    m_pReadAlreadyBtn->setFixedSize(18, 18);
    m_pReadAlreadyBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/ze-checked_1x.png); border: 0px;}");

    QLabel *pReadAlreadyLbl = new QLabel(this);
    pReadAlreadyLbl->setFixedSize(228, 17);
    pReadAlreadyLbl->setText("已阅读并同意服务协议和木知隐私保护指引");
    pReadAlreadyLbl->setStyleSheet("QLabel{"
                                   "line-height: 17px;"
                                   "color: rgba(0,0,0,1);"
                                   "font-size: 12px;"
                                   "text-align: left;"
                                   "font-family: PingFangSC-regular; border: 0px;"
                                   "}");

    pReadAlreadyLyt->addStretch();
    pReadAlreadyLyt->addWidget(m_pReadAlreadyBtn);
    pReadAlreadyLyt->addWidget(pReadAlreadyLbl);
    pReadAlreadyLyt->addStretch();

    m_pLoginBtn = new QPushButton(this);
    m_pLoginBtn->setFixedSize(250, 42);
    m_pLoginBtn->setText("登录");
    m_pLoginBtn->setStyleSheet("QPushButton{"
                               "line-height: 28px;"
                               "border-radius: 10px;"
                               "background-color: rgba(57,126,253,1);"
                               "color: rgba(255,255,255,1);"
                               "font-size: 20px;"
                               "text-align: center;"
                               "font-family: PingFangSC-regular;"
                               "border: 1px solid rgba(187,187,187,1);"
                               "}"
                               "QPushButton:hover {"
                               "background-color: rgba(57,126,253,1);"
                               "color: rgba(255,255,255,1);"
                               "font-size: 20px;"
                               "text-align: center;"
                               "font-family: PingFangSC-regular;"
                               "border: 1px solid rgba(187,187,187,1);"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: rgba(57,126,253,1);"
                               "color: rgba(255,255,255,1);"
                               "font-size: 20px;"
                               "text-align: center;"
                               "font-family: PingFangSC-regular;"
                               "border: 1px solid rgba(187,187,187,1);"
                               "}");

    pUserLyt->addWidget(m_pAccountEdit);
    pUserLyt->addWidget(m_pPasswordEdit);
    pUserLyt->addLayout(pReadAlreadyLyt);
    pUserLyt->addWidget(m_pLoginBtn);


    QHBoxLayout *phUserLyt = new QHBoxLayout();
    phUserLyt->setContentsMargins(0, 0 ,0 ,0);
    phUserLyt->addStretch();
    phUserLyt->addWidget(pUserWgt);
    phUserLyt->addStretch();

    QString styleBottom = QString("QPushButton{"
                                  "line-height: 17px;"
                                  "color: rgba(140,102,172,1);"
                                  "font-size: 12px;"
                                  "text-align: left;"
                                  "font-family: PingFangSC-regular;"
                                  "border:0px;"
                                  "}");

    QHBoxLayout *pBottomLyt = new QHBoxLayout();
    m_pScanCodeLoginBtn = new QPushButton(this);
    m_pScanCodeLoginBtn->setText("扫码登录");
    m_pScanCodeLoginBtn->setStyleSheet(styleBottom);

    QLabel *pLineLbl = new QLabel(this);
    pLineLbl->setFixedSize(1, 20);
    pLineLbl->setStyleSheet("QLabel{background-color: rgba(255,255,255,1);border: 1px solid rgba(187,187,187,1);}");

    m_pMoreOptionsBtn = new QPushButton(this);
    m_pMoreOptionsBtn->setText("更多选项");
    m_pMoreOptionsBtn->setStyleSheet(styleBottom);

    pBottomLyt->addStretch();
    pBottomLyt->addWidget(m_pScanCodeLoginBtn);
    pBottomLyt->addWidget(pLineLbl);
    pBottomLyt->addWidget(m_pMoreOptionsBtn);
    pBottomLyt->addStretch();

    pMainLyt->addLayout(pCloseLyt);
    pMainLyt->addLayout(pLogoLyt);
    pMainLyt->addLayout(phUserLyt);
    pMainLyt->addSpacing(25);
    pMainLyt->addLayout(pBottomLyt);
}

void MrzLoginDialog::connectFun()
{
    connect(m_pLoginBtn, &QPushButton::clicked, this, &MrzLoginDialog::slotLogin);
    connect(m_pCloseBtn, &QPushButton::clicked, this, &MrzLoginDialog::slotCancel);
}

void MrzLoginDialog::slotLogin()
{
    //QMessageBox::information(this,"提示","进入教育软件主界面！");
    done(Accepted);// 关闭当前窗体，以指定方式返还
    //return;

    // 正则验证邮地址 用户名@域名
    // 表示符解释：^表示规则字符串的开始，$表示规则字符串的结束
    // +表示匹配次数>=1次 *表示匹配任意次数（可为0次）{n,m}表示匹配次数至少n次，至多m次

    // 验证邮箱地址，验证邮箱
    // QRegularExpression rx("^[A-Za-z0-9]+([_\.][A-Za-z0-9]+)*@([A-Za-z0-9\-]+\.)+[A-Za-z]{2,6}$");
    // bool res = rx.match(m_pAccountEdit->text()).hasMatch();

    // if (!res)
    // {
    //     QMessageBox::information(this, "提示", "非法的邮箱地址，请你重新输入！");
    //     m_pAccountEdit->clear();
    //     m_pPasswordEdit->clear();
    //     m_pAccountEdit->setFocus();
    // }
    // else
    // {
    //     QString filename;           // 账号密码数据文件
    //     QString strAccInput;        // 用户输入的账号
    //     QString strPwd;            // 用户输入的密码
    //     QString strLine;            // 每次读取的一行数据
    //     QStringList strList;        // 保存分割读取的一行数据

    //     filename = "account.txt";
    //     strAccInput = m_pAccountEdit->text();
    //     strPwd = m_pPasswordEdit->text();
    //     strList = strLine.split(",");

    //     QFile file(filename);
    //     QTextStream stream(&file);

    //     if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    //     {
    //         while(!stream.atEnd())
    //         {
    //             strLine = stream.readLine();
    //             strList = strLine.split(",");

    //             if (strAccInput == strList.at(0))
    //             {
    //                 if(strPwd == strList.at(1))
    //                 {
    //                     QMessageBox::information(this,"提示","进入教育软件主界面！");
    //                     file.close();
    //                     done(Accepted);// 关闭当前窗体，以指定方式返还
    //                     return;
    //                 }
    //                 else
    //                 {
    //                     QMessageBox::information(this,"提示","您输入的密码有误，请重新输入！");
    //                     m_pPasswordEdit->clear();
    //                     m_pPasswordEdit->setFocus();
    //                     file.close();
    //                     return;
    //                 }
    //             }
    //         }
    //         QMessageBox::information(this,"提示","您输入的账号有误，请重新输入！");
    //         m_pAccountEdit->clear();
    //         m_pPasswordEdit->clear();
    //         m_pAccountEdit->setFocus();
    //         file.close();
    //         return;
    //     }
    //     else
    //     {
    //         QMessageBox::information(this,"提示","读取账号数据文件失败！");
    //         return;
    //     }
    // }

}

void MrzLoginDialog::slotCancel()
{
    done(Rejected);
}

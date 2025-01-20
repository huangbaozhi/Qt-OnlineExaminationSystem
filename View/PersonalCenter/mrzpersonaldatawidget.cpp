#include "mrzpersonaldatawidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

const QString styleLineEdit = QString("QLineEdit{"
                                   "line-height: 20px;"
                                   "border-radius: 3px;"
                                   "background-color: rgba(255,255,255,1);"
                                   "color: rgba(193, 194, 197, 1);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "border: 1px solid rgba(220,224,231,1);"
                                   "font-family: SourceHanSansSC-regular;}");

const QString styleLabel = QString("QLabel{line-height: 20px;"
                                   "color: rgb(16,16,16);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border: none;}");

const QString styleRadion = QString("QRadioButton{line-height: 20px;"
                                   "color: rgb(16,16,16);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border: none;}");

const QString styleTipLabel = QString("QLabel{line-height: 20px;"
                                   "color: rgba(255,0,0,1);"
                                   "font-size: 14px;"
                                   "text-align: left;"
                                   "font-family: SourceHanSansSC-regular;"
                                   "border: none;}");

const QString styleButton = QString("QPushButton{line-height: 17px;"
                                      "color: rgb(255,255,255);"
                                      "font-size: 14px;"
                                      "text-align: center;"
                                      "font-family: SourceHanSansSC-regular;"
                                      "border-radius: 2px 2px 2px 2px;"
                                      "background-color: rgba(86,119,252,1);"
                                      "border: 0px solid rgba(255,0,0,0);}");

MrzPersonalDataWidget::MrzPersonalDataWidget(QWidget *parent)
    : QWidget{parent}
{
    initUi();

    connectFun();

    // create the database connection
    createDatabase();

    // Load data from database
    loadDataFromDatabase();
}

void MrzPersonalDataWidget::initUi()
{
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *pPersonLyt = new QHBoxLayout;
    pPersonLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pPersonLbl = new QLabel;
    pPersonLbl->setText("个人资料");
    pPersonLbl->setStyleSheet("QLabel{line-height: 29px;"
                              "color: rgb(16,16,16);"
                              "font-size: 20px;"
                              "text-align: left;"
                              "font-family: SourceHanSansSC-regular;}");
    pPersonLyt->addSpacing(25);
    pPersonLyt->addWidget(pPersonLbl);
    pPersonLyt->addStretch();

    // 真实姓名
    QHBoxLayout *pRealNameLyt = new QHBoxLayout;
    pRealNameLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipRealNameLbl = new QLabel;
    pTipRealNameLbl->setText("*");
    pTipRealNameLbl->setStyleSheet(styleTipLabel);
    QLabel *pRealNameLbl = new QLabel;
    pRealNameLbl->setText("真实姓名");
    pRealNameLbl->setStyleSheet(styleLabel);
    pRealNameLbl->setAlignment(Qt::AlignCenter);
    m_pRealNameEdit = new QLineEdit;
    m_pRealNameEdit->setFixedSize(380, 40);
    m_pRealNameEdit->setStyleSheet(styleLineEdit);
    pRealNameLyt->addSpacing(158);
    pRealNameLyt->addWidget(pTipRealNameLbl);
    pRealNameLyt->addSpacing(5);
    pRealNameLyt->addWidget(pRealNameLbl);
    pRealNameLyt->addSpacing(13);
    pRealNameLyt->addWidget(m_pRealNameEdit);
    pRealNameLyt->addStretch();

    // 姓别
    QHBoxLayout *pSexLyt = new QHBoxLayout;
    pSexLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipSexLbl = new QLabel;
    pTipSexLbl->setText("*");
    pTipSexLbl->setStyleSheet(styleTipLabel);
    QLabel *pSexLbl = new QLabel;
    pSexLbl->setText("性别");
    pSexLbl->setStyleSheet(styleLabel);
    pSexLbl->setAlignment(Qt::AlignCenter);
    pSexLyt->addSpacing(158);
    pSexLyt->addWidget(pTipSexLbl);
    pSexLyt->addSpacing(5);
    pSexLyt->addWidget(pSexLbl);
    pSexLyt->addSpacing(41);

    // Gender radio buttons
    m_pSexButtonGroup = new QButtonGroup;
    QStringList sexOptions;
    sexOptions << "男" << "女" <<"未知";
    int sexbutton = 0;
    for (const QString &option : sexOptions)
    {
        qDebug()<<"[option]= " <<option << "[button]= "<<  sexbutton;
        m_pSexRadioButton = new QRadioButton(option, this);
        m_pSexRadioButton->setStyleSheet(styleRadion);
        m_pSexButtonGroup->addButton(m_pSexRadioButton, sexbutton);
        pSexLyt->addWidget(m_pSexRadioButton);
        pSexLyt->addSpacing(30);
        sexbutton++;
    }
    pSexLyt->addStretch();


    // 手机
    QHBoxLayout *pPhoneLyt = new QHBoxLayout;
    pPhoneLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pPhoneLbl = new QLabel;
    pPhoneLbl->setText("手机");
    pPhoneLbl->setStyleSheet(styleLabel);
    //pPhoneLbl->setAlignment(Qt::AlignLeft);
    pPhoneLbl->setAlignment(Qt::AlignCenter);
    m_pPhoneEdit = new QLineEdit;
    m_pPhoneEdit->setFixedSize(380, 40);
    m_pPhoneEdit->setStyleSheet(styleLineEdit);
    pPhoneLyt->addSpacing(177);
    pPhoneLyt->addWidget(pPhoneLbl);
    pPhoneLyt->addSpacing(41);
    pPhoneLyt->addWidget(m_pPhoneEdit);
    pPhoneLyt->addStretch();

    // 邮箱
    QHBoxLayout *pMailLyt = new QHBoxLayout;
    pMailLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pMailLbl = new QLabel;
    pMailLbl->setText("邮箱");
    pMailLbl->setStyleSheet(styleLabel);
    pMailLbl->setAlignment(Qt::AlignCenter);
    m_pEmailEdit = new QLineEdit;
    m_pEmailEdit->setFixedSize(380, 40);
    m_pEmailEdit->setStyleSheet(styleLineEdit);
    pMailLyt->addSpacing(177);
    pMailLyt->addWidget(pMailLbl);
    pMailLyt->addSpacing(41);
    pMailLyt->addWidget(m_pEmailEdit);
    pMailLyt->addStretch();

    // 身份证号
    QHBoxLayout *pIDNumberLyt = new QHBoxLayout;
    pIDNumberLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipIDNumberLbl = new QLabel;
    pTipIDNumberLbl->setText("*");
    pTipIDNumberLbl->setStyleSheet(styleTipLabel);
    QLabel *pIDNumberLbl = new QLabel;
    pIDNumberLbl->setText("身份证号");
    pIDNumberLbl->setStyleSheet(styleLabel);
    pIDNumberLbl->setAlignment(Qt::AlignCenter);
    m_pIDNumberEdit = new QLineEdit;
    m_pIDNumberEdit->setFixedSize(380, 40);
    m_pIDNumberEdit->setStyleSheet(styleLineEdit);
    pIDNumberLyt->addSpacing(158);
    pIDNumberLyt->addWidget(pTipIDNumberLbl);
    pIDNumberLyt->addSpacing(5);
    pIDNumberLyt->addWidget(pIDNumberLbl);
    pIDNumberLyt->addSpacing(13);
    pIDNumberLyt->addWidget(m_pIDNumberEdit);
    pIDNumberLyt->addStretch();

    // 学校
    QHBoxLayout *pSchoolLyt = new QHBoxLayout;
    pSchoolLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipSchoolLbl = new QLabel;
    pTipSchoolLbl->setText("*");
    pTipSchoolLbl->setStyleSheet(styleTipLabel);
    QLabel *pSchoolLbl = new QLabel;
    pSchoolLbl->setText("学校");
    pSchoolLbl->setStyleSheet(styleLabel);
    pSchoolLbl->setAlignment(Qt::AlignCenter);
    m_pSchoolEdit = new QLineEdit;
    m_pSchoolEdit->setFixedSize(380, 40);
    m_pSchoolEdit->setStyleSheet(styleLineEdit);
    pSchoolLyt->addSpacing(158);
    pSchoolLyt->addWidget(pTipSchoolLbl);
    pSchoolLyt->addSpacing(5);
    pSchoolLyt->addWidget(pSchoolLbl);
    pSchoolLyt->addSpacing(41);
    pSchoolLyt->addWidget(m_pSchoolEdit);
    pSchoolLyt->addStretch();

    // 组别
    QHBoxLayout *pGroupLyt = new QHBoxLayout;
    pGroupLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pGroupLbl = new QLabel;
    pGroupLbl->setText("组别");
    pGroupLbl->setStyleSheet(styleLabel);
    pGroupLbl->setAlignment(Qt::AlignCenter);
    pGroupLyt->addSpacing(177);
    pGroupLyt->addWidget(pGroupLbl);
    pGroupLyt->addSpacing(41);

    m_pGroupButtonGroup = new QButtonGroup;
    QStringList groupOptions;
    groupOptions << "本科组" << "专科组";
    int groupbutton = 0;
    for (const QString &group : groupOptions)
    {
        m_pGroupRadioButton = new QRadioButton(group, this);
        m_pGroupRadioButton->setStyleSheet(styleRadion);
        m_pGroupButtonGroup->addButton(m_pGroupRadioButton, groupbutton);
        pGroupLyt->addWidget(m_pGroupRadioButton);
        pGroupLyt->addSpacing(20);
        groupbutton++;
    }
    pGroupLyt->addStretch();

    // 注意事项
    QHBoxLayout *pPrecautionsLyt = new QHBoxLayout;
    pPrecautionsLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pTipPrecautionsLbl = new QLabel;
    pTipPrecautionsLbl->setText("*");
    pTipPrecautionsLbl->setStyleSheet(styleTipLabel);
    QLabel *pPrecautionsLbl = new QLabel;
    pPrecautionsLbl->setText("注意事项");
    pPrecautionsLbl->setStyleSheet(styleLabel);
    pPrecautionsLbl->setAlignment(Qt::AlignCenter);
    QLabel *pPrecautionsRemarkLbl = new QLabel;
    pPrecautionsRemarkLbl->setText("请依次上传本人学生证、正面免冠照，缺一不可，如非本人\n照片将导致人脸验证无法通过，影响正常考试。");
    pPrecautionsRemarkLbl->setStyleSheet("QLabel{line-height: 20px;"
                              "color: rgba(255,22,0,1);"
                              "font-size: 14px;"
                              "text-align: left;"
                              "font-family: SourceHanSansSC-regular;}");
    pPrecautionsLyt->addSpacing(158);
    pPrecautionsLyt->addWidget(pTipPrecautionsLbl);
    pPrecautionsLyt->addSpacing(5);
    pPrecautionsLyt->addWidget(pPrecautionsLbl);
    pPrecautionsLyt->addSpacing(13);
    pPrecautionsLyt->addWidget(pPrecautionsRemarkLbl);
    pPrecautionsLyt->addStretch();

    // 学生证
    QHBoxLayout *pStudentIDcardLyt = new QHBoxLayout;
    pStudentIDcardLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pStudentIDcardLbl = new QLabel;
    pStudentIDcardLbl->setText("学生证");
    pStudentIDcardLbl->setStyleSheet(styleLabel);
    pStudentIDcardLbl->setAlignment(Qt::AlignCenter);
    QLabel *pStudentIDcardRemarkLbl = new QLabel;
    pStudentIDcardRemarkLbl->setText("请依次上传本人学生证、正面免冠照，缺一不可，如非本人\n照片将导致人脸验证无法通过，影响正常考试。");
    pStudentIDcardLyt->addSpacing(177);
    pStudentIDcardLyt->addWidget(pStudentIDcardLbl);
    pStudentIDcardLyt->addSpacing(25);
    pStudentIDcardLyt->addWidget(pStudentIDcardRemarkLbl);
    pStudentIDcardLyt->addStretch();

    // 人脸采集
    QHBoxLayout *pFaceCollectionLyt = new QHBoxLayout;
    pFaceCollectionLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pFaceCollectionLbl = new QLabel;
    pFaceCollectionLbl->setText("人脸采集");
    pFaceCollectionLbl->setStyleSheet(styleLabel);
    pFaceCollectionLbl->setAlignment(Qt::AlignCenter);
    pFaceCollectionLyt->addSpacing(175);
    pFaceCollectionLyt->addWidget(pFaceCollectionLbl);
    pFaceCollectionLyt->addSpacing(13);

    m_pCollectionLyt = new QHBoxLayout;
    m_pCollectionLyt->setContentsMargins(0, 0, 0, 0);
    pFaceCollectionLyt->addLayout(m_pCollectionLyt);

    m_pCollectionButtonGroup = new QButtonGroup;
    QStringList collectionOptions;
    collectionOptions << "采集" << "不采集";
    int icollectionbutton = 0;
    for (const QString &collection : collectionOptions)
    {
        qDebug() << "collectionOptions= " << collection << "button= " << icollectionbutton;
        m_pRadioButtonButton = new QRadioButton(collection, this);
        m_pRadioButtonButton->setStyleSheet(styleRadion);
        m_pCollectionButtonGroup->addButton(m_pRadioButtonButton, icollectionbutton);
        m_pCollectionLyt->addWidget(m_pRadioButtonButton);
        m_pCollectionLyt->addSpacing(48);
        icollectionbutton++;
    }
    m_pCollectionLyt->addStretch();

    // 选手类型
    QHBoxLayout *pPlayerTypeLyt = new QHBoxLayout;
    pPlayerTypeLyt->setContentsMargins(0, 0, 0, 0);
    QLabel *pPlayerTypeLbl = new QLabel;
    pPlayerTypeLbl->setText("选手类型");
    pPlayerTypeLbl->setStyleSheet(styleLabel);
    pPlayerTypeLbl->setAlignment(Qt::AlignCenter);
    pPlayerTypeLyt->addSpacing(175);
    pPlayerTypeLyt->addWidget(pPlayerTypeLbl);
    pPlayerTypeLyt->addSpacing(13);

    m_pPlayerTypeButtonGroup = new QButtonGroup;
    QStringList playerTypeOptions;
    playerTypeOptions << "替补选手" << "正式选手";
    int playerTypebutton = 0;
    for (const QString &playerType : playerTypeOptions)
    {
        m_pPlayerTypeRadioButton = new QRadioButton(playerType, this);
        m_pPlayerTypeRadioButton->setStyleSheet(styleRadion);
        m_pPlayerTypeButtonGroup->addButton(m_pPlayerTypeRadioButton, playerTypebutton);
        pPlayerTypeLyt->addWidget(m_pPlayerTypeRadioButton);
        pPlayerTypeLyt->addSpacing(23);
        playerTypebutton++;
    }
    pPlayerTypeLyt->addStretch();

    QHBoxLayout *pSaveLyt = new QHBoxLayout;
    m_pSaveBtn = new QPushButton;
    m_pSaveBtn->setFixedSize(94, 36);
    m_pSaveBtn->setText("保存");
    m_pSaveBtn->setStyleSheet(styleButton);
    pSaveLyt->addStretch();
    pSaveLyt->addWidget(m_pSaveBtn);
    pSaveLyt->addStretch();

    pMainLyt->addSpacing(20);
    pMainLyt->addLayout(pPersonLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pRealNameLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pSexLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pPhoneLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pMailLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pIDNumberLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pSchoolLyt);
    pMainLyt->addSpacing(20);
    pMainLyt->addLayout(pGroupLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pPrecautionsLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pStudentIDcardLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pFaceCollectionLyt);
    pMainLyt->addSpacing(22);
    pMainLyt->addLayout(pPlayerTypeLyt);
    pMainLyt->addSpacing(60);
    pMainLyt->addLayout(pSaveLyt);
    pMainLyt->addSpacing(70);
    pMainLyt->addStretch();
}

void MrzPersonalDataWidget::connectFun()
{
   connect(m_pSaveBtn, &QPushButton::clicked, this, &MrzPersonalDataWidget::saveDataInfo);
}

void MrzPersonalDataWidget::createDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("registration.db");

    if (!db.open())
    {
        QMessageBox::critical(this, "数据库错误", "无法连接数据库");
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS registration ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "phone TEXT, "
               "email TEXT, "
               "id_card TEXT, "
               "school TEXT, "
               "gender TEXT, "
               "group_type TEXT, "
               "face_collection TEXT, "
               "player_type TEXT)");
}

void MrzPersonalDataWidget::loadDataFromDatabase()
{
    QSqlQuery query("SELECT * FROM registration ORDER BY id DESC LIMIT 1");
    if (query.next()) {
        m_pRealNameEdit->setText(query.value("name").toString());
        m_pPhoneEdit->setText(query.value("phone").toString());
        m_pEmailEdit->setText(query.value("email").toString());
        m_pIDNumberEdit->setText(query.value("id_card").toString());
        m_pSchoolEdit->setText(query.value("school").toString());

        // 读取性别
        QString gender = query.value("gender").toString();
        if (gender == "男")
        {
            m_pSexButtonGroup->button(0)->setChecked(true);
        } else if (gender == "女")
        {
            m_pSexButtonGroup->button(1)->setChecked(true);
        } else if (gender == "未知")
        {
            m_pSexButtonGroup->button(2)->setChecked(true);
        }

        // 读取组别
        QString groupType = query.value("group_type").toString();
        if (groupType == "本科组")
        {
            m_pGroupButtonGroup->button(0)->setChecked(true); // 假设第一个按钮是本科生
        } else if (groupType == "专科")
        {
            m_pGroupButtonGroup->button(1)->setChecked(true);
        }

        // 读取人脸采集
        QString faceCollection = query.value("face_collection").toString();
        if (faceCollection == "采集")
        {
            m_pCollectionButtonGroup->button(0)->setChecked(true);
        }
        else if (faceCollection == "不采集")
        {
            m_pCollectionButtonGroup->button(1)->setChecked(true);
        }

        // 读取选手类型
        QString playerType = query.value("player_type").toString();
        if (playerType == "替补选手")
        {
            m_pPlayerTypeButtonGroup->button(0)->setChecked(true);
        } else if (playerType == "正式选手")
        {
            m_pPlayerTypeButtonGroup->button(1)->setChecked(true);
        }
    }
    else
    {
        m_pRealNameEdit->clear();
        m_pPhoneEdit->clear();
        m_pEmailEdit->clear();
        m_pIDNumberEdit->clear();
        m_pSchoolEdit->clear();
        m_pSexButtonGroup->button(0)->setChecked(false);
        m_pSexButtonGroup->button(1)->setChecked(false);
        m_pSexButtonGroup->button(2)->setChecked(false);
        m_pGroupButtonGroup->button(0)->setChecked(false);
        m_pGroupButtonGroup->button(1)->setChecked(false);
        m_pCollectionButtonGroup->button(0)->setChecked(false);
        m_pCollectionButtonGroup->button(1)->setChecked(false);
        m_pPlayerTypeButtonGroup->button(0)->setChecked(false);
        m_pPlayerTypeButtonGroup->button(1)->setChecked(false);
    }
}

QString MrzPersonalDataWidget::getSelectedButtonText(QButtonGroup *group)
{
    QAbstractButton *button = group->checkedButton();
    return button ? button->text() : QString();
}

void MrzPersonalDataWidget::saveDataInfo()
{
    // Retrieve input data
    QString name = m_pRealNameEdit->text();
    QString phone = m_pPhoneEdit->text();
    QString email = m_pEmailEdit->text();
    QString idCard = m_pIDNumberEdit->text();
    QString school = m_pSchoolEdit->text();
    QString gender = getSelectedButtonText(m_pSexButtonGroup);
    QString group = getSelectedButtonText(m_pGroupButtonGroup);
    QString face = getSelectedButtonText(m_pCollectionButtonGroup);
    QString playerType = getSelectedButtonText(m_pPlayerTypeButtonGroup);

    // Check if all fields are filled
    if (name.isEmpty() || phone.isEmpty() || email.isEmpty() || idCard.isEmpty() || school.isEmpty())
    {
        QMessageBox::warning(this, "输入错误", "所有信息都必须填写!");
        return;
    }

    // Insert data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO registration (name, phone, email, id_card, school, gender, group_type, face_collection, player_type) "
                  "VALUES (:name, :phone, :email, :id_card, :school, :gender, :group, :face, :player)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    query.bindValue(":id_card", idCard);
    query.bindValue(":school", school);
    query.bindValue(":gender", gender);
    query.bindValue(":group", group);
    query.bindValue(":face", face);
    query.bindValue(":player", playerType);

    // QSqlQuery query;
    // query.prepare("INSERT INTO registration (name, phone, email, id_card, school, gender, group_type, face_collection, player_type) "
    //               "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
    // query.addBindValue(name);
    // query.addBindValue(phone);
    // query.addBindValue(email);
    // query.addBindValue(idCard);
    // query.addBindValue(school);
    // query.addBindValue(gender);
    // query.addBindValue(group);
    // query.addBindValue(face);
    // query.addBindValue(playerType);

    if (query.exec())
    {
        QMessageBox::information(this, "成功", "数据保存成功!");
    }
    else
    {
        QMessageBox::critical(this, "错误", "保存数据失败!" );
    }
}

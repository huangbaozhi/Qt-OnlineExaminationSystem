#include "mrzglobalclass.h"
#include <QDebug>

MrzGlobalClass::MrzGlobalClass(QObject *parent)
    : QObject{parent}
{}

static MrzGlobalClass* G_MrzGlobalClass = nullptr;
MrzGlobalClass *MrzGlobalClass::instance()
{
    if (!G_MrzGlobalClass)
    {
        G_MrzGlobalClass = new MrzGlobalClass;
    }
    return G_MrzGlobalClass;
}

void MrzGlobalClass::setUserName(QString user)
{
    m_strUserName = user;
}

QString MrzGlobalClass::getUserName()
{
    return m_strUserName;
}

void MrzGlobalClass::setPassWord(QString password)
{
    m_strPassWord = password;
}

QString MrzGlobalClass::getPassWord()
{
    return m_strPassWord;
}

void MrzGlobalClass::setName(QString name)
{
    m_strName = name;
}

QString MrzGlobalClass::getName()
{
    return m_strName;
}

void MrzGlobalClass::setSex(QString sex)
{
    m_strSex = sex;
}

QString MrzGlobalClass::getSex()
{
    return m_strSex;
}

void MrzGlobalClass::setPhone(QString phone)
{
    m_strPhone = phone;
}

QString MrzGlobalClass::getPhone()
{
    return m_strPhone;
}

void MrzGlobalClass::setMail(QString mail)
{
    m_strMail = mail;
}

QString MrzGlobalClass::getMail()
{
    return m_strMail;
}

void MrzGlobalClass::setIDNumber(QString id)
{
    m_strIDNumber = id;
}

QString MrzGlobalClass::getIDNumber()
{
    return m_strIDNumber;
}

void MrzGlobalClass::setSchool(QString school)
{
    m_strSchool = school;
}

QString MrzGlobalClass::getSchool()
{
    return m_strSchool;
}

void MrzGlobalClass::setGroup(QString group)
{
    m_strGroup = group;
}

QString MrzGlobalClass::getGroup()
{
    return m_strGroup;
}

void MrzGlobalClass::setStudentIDcard(QString studentid)
{
    m_strStudentIDcard = studentid;
}

QString MrzGlobalClass::getStudenIDcard()
{
    return m_strStudentIDcard;
}

void MrzGlobalClass::setFaceCollection(QString face)
{
    m_strFaceCollection = face;
}

QString MrzGlobalClass::getFaceCollection()
{
    return m_strFaceCollection;
}

void MrzGlobalClass::setPlayerType(QString player)
{
    m_strPlayerType = player;
}

QString MrzGlobalClass::getPlayerType()
{
    return m_strPlayerType;
}

void MrzGlobalClass::setFaceData(QByteArray &byteArray)
{
    m_byteArray = byteArray;
}

QByteArray MrzGlobalClass::getFaceData()
{
    return m_byteArray;
}

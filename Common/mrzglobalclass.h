#ifndef MRZGLOBALCLASS_H
#define MRZGLOBALCLASS_H

#include <QObject>

class MrzGlobalClass : public QObject
{
    Q_OBJECT
public:
    explicit MrzGlobalClass(QObject *parent = nullptr);

    static MrzGlobalClass *instance();

signals:

public:
    void setUserName(QString user);
    QString getUserName();

    void setPassWord(QString password);
    QString getPassWord();

    void setName(QString name);
    QString getName();

    void setSex(QString sex);
    QString getSex();

    void setPhone(QString phone);
    QString getPhone();

    void setMail(QString mail);
    QString getMail();

    void setIDNumber(QString id);
    QString getIDNumber();

    void setSchool(QString school);
    QString getSchool();

    void setGroup(QString group);
    QString getGroup();

    void setStudentIDcard(QString studentid);
    QString getStudenIDcard();

    void setFaceCollection(QString face);
    QString getFaceCollection();

    void setPlayerType(QString player);
    QString getPlayerType();

    void setFaceData(QByteArray &byteArray);
    QByteArray getFaceData();

private:
    QString m_strUserName;
    QString m_strPassWord;
    QString m_strName;
    QString m_strSex;
    QString m_strPhone;
    QString m_strMail;
    QString m_strIDNumber;
    QString m_strSchool;
    QString m_strGroup;
    QString m_strStudentIDcard;
    QString m_strFaceCollection;
    QString m_strPlayerType;

    QByteArray m_byteArray;
};

#endif // MRZGLOBALCLASS_H

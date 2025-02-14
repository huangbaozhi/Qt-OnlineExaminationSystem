#include "mrzsqldatastorage.h"
#include "Common/mrzglobalclass.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

MrzSqlDataStorage::MrzSqlDataStorage(QObject *parent)
    : QObject{parent}
{}

static MrzSqlDataStorage *G_MrzSqlDataStorage = nullptr;
MrzSqlDataStorage *MrzSqlDataStorage::instance()
{
    if (!G_MrzSqlDataStorage)
    {
        G_MrzSqlDataStorage = new MrzSqlDataStorage;
    }
    return G_MrzSqlDataStorage;
}

void MrzSqlDataStorage::createDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("registration.db");

    if (!db.open())
    {
        //QMessageBox::critical(this, "数据库错误", "无法连接数据库");
        qDebug() << "数据库错误, 无法连接数据库!!!";
    }

    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL
        )
    )";

    if (!query.exec(createTableQuery))
    {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return;
    }

    QString insertQuery = "INSERT INTO Users (username, password) VALUES (?, ?)";
    // 准备查询并绑定参数
    query.prepare(insertQuery);
    // query.addBindValue(MrzGlobalClass::instance()->getUserName());  // 绑定用户名
    // query.addBindValue(MrzGlobalClass::instance()->getPassWord());  // 绑定密码
    query.addBindValue("123456@qq.com");  // 绑定用户名
    query.addBindValue("123456");  // 绑定密码

    // 执行查询
    if (query.exec()) {
        qDebug() << "User inserted successfully.";
    } else {
        qDebug() << "Error inserting user: " << query.lastError().text();
    }

    //QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS registration ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "phone TEXT, "
               "email TEXT, "
               "id_card TEXT, "
               "school TEXT, "
               "gender TEXT, "
               "group_type TEXT, "
               "collection_face TEXT, "
               "player_type TEXT, "
               "face_data BLOB)");
}

void MrzSqlDataStorage::writeDatebase()
{
    // Insert data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO registration (name, phone, email, id_card, school, gender, group_type, collection_face, player_type, face_data) "
                  "VALUES (:name, :phone, :email, :id_card, :school, :gender, :group, :collection, :player, :face)");

    query.bindValue(":name", MrzGlobalClass::instance()->getName());
    query.bindValue(":phone", MrzGlobalClass::instance()->getPhone());
    query.bindValue(":email", MrzGlobalClass::instance()->getMail());
    query.bindValue(":id_card", MrzGlobalClass::instance()->getIDNumber());
    query.bindValue(":school", MrzGlobalClass::instance()->getSchool());
    query.bindValue(":gender", MrzGlobalClass::instance()->getSex());
    query.bindValue(":group", MrzGlobalClass::instance()->getGroup());
    query.bindValue(":collection", MrzGlobalClass::instance()->getFaceCollection());
    query.bindValue(":player", MrzGlobalClass::instance()->getPlayerType());
    query.bindValue(":face", MrzGlobalClass::instance()->getFaceData());

    if (!query.exec())
    {
        qDebug() << "Error saving face to database!";
    }
    else
    {
        qDebug() << "Face saved to database!";
    }
}

void MrzSqlDataStorage::writeUserInfo()
{
    QSqlQuery query;

    // 插入数据的 SQL 语句
    QString insertQuery = "INSERT INTO Users (username, password) VALUES (?, ?)";
    // 准备查询并绑定参数
    query.prepare(insertQuery);
    query.addBindValue(MrzGlobalClass::instance()->getUserName());  // 绑定用户名
    query.addBindValue(MrzGlobalClass::instance()->getPassWord());  // 绑定密码

    // 执行查询
    if (query.exec()) {
        qDebug() << "User inserted successfully.";
    } else {
        qDebug() << "Error inserting user: " << query.lastError().text();
    }
}

void MrzSqlDataStorage::readDatebase()
{

}

void MrzSqlDataStorage::updateDatebase()
{

}

void MrzSqlDataStorage::deleteDatebase()
{

}

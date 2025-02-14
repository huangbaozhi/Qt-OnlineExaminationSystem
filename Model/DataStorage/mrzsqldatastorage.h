#ifndef MRZSQLDATASTORAGE_H
#define MRZSQLDATASTORAGE_H

#include <QObject>

class MrzSqlDataStorage : public QObject
{
    Q_OBJECT
public:
    explicit MrzSqlDataStorage(QObject *parent = nullptr);

    static MrzSqlDataStorage *instance();

signals:

public:
    void createDatabase();

    // 插入、增加
    void writeDatebase();
    void writeUserInfo();

    // 查
    void readDatebase();

    // 更新、修改
    void updateDatebase();

    // 删除
    void deleteDatebase();
};

#endif // MRZSQLDATASTORAGE_H

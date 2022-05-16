#ifndef RESULT_H
#define RESULT_H
#include <QJsonObject>
#include <QString>

class Result
{
private:
    bool error;
    QString message;

public:
    Result();
    Result(const bool &error, const QString &message);
    void setResult(const bool &error, const QString &message);
    bool getError();
    QString getMessage();
    Result operator()(const bool &error, const QString &message);
};

#endif // RESULT_H

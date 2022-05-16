#include "result.h"

Result::Result(const bool &error, const QString &message)
    : error(error), message(message) {}

Result Result::operator()(const bool &error, const QString &message)
{
    this->error = error;
    this->message = message;
    return *this;
}

void Result::setResult(const bool &error, const QString &message)
{
    this->error = error;
    this->message = message;
}

bool Result::getError()
{
    return this->error;
}

QString Result::getMessage()
{
    return this->message;
}

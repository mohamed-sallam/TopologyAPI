#ifndef DEVICE_H
#define DEVICE_H
#include <QVector>
#include <QJsonObject>

class Device
{
protected:
    QString type;
    QString id;
    QJsonObject netlist;

public:
    Device() {}
    virtual ~Device() {}
    virtual void createDeviceFromJSON(const QJsonObject &json) = 0;
    virtual QJsonObject getDeviceJSON() const = 0;
    virtual const QString &getType() const;
    virtual void setType(const QString &newType);
    virtual const QString &getId() const;
    virtual void setId(const QString &newId);
    virtual const QJsonObject &getNetlist() const;
    virtual void setNetlist(const QJsonObject &newNetlist);
    virtual bool operator==(const Device &rhs);
};

#endif // DEVICE_H

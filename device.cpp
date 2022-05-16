#include "device.h"

const QString &Device::getId() const
{
    return id;
}

void Device::setId(const QString &newId)
{
    id = newId;
}

const QJsonObject &Device::getNetlist() const
{
    return netlist;
}

void Device::setNetlist(const QJsonObject &newNetlist)
{
    netlist = newNetlist;
}

bool Device::operator==(const Device &rhs)
{
    return this->getDeviceJSON() == rhs.getDeviceJSON();
}

const QString &Device::getType() const
{
    return type;
}

void Device::setType(const QString &newType)
{
    type = newType;
}

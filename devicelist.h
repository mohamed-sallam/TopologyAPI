#ifndef DEVICELIST_H
#define DEVICELIST_H

#include <memory>
#include <QJsonArray>
#include <device.h>

class DeviceList : public QVector<std::shared_ptr<Device>>
{
public:
    DeviceList();
    QJsonArray getDevicesJSON() const;
    bool operator==(const DeviceList &rhs) const;
};

#endif // DEVICELIST_H

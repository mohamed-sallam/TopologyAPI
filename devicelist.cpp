#include "devicelist.h"

DeviceList::DeviceList()
{
}

QJsonArray DeviceList::getDevicesJSON() const
{
    QJsonArray devicesList{};
    for (const auto &device : this->toStdVector())
        devicesList.push_back(device->getDeviceJSON());
    return devicesList;
}
bool DeviceList::operator==(const DeviceList &rhs) const
{
    return rhs.getDevicesJSON() == this->getDevicesJSON();
}

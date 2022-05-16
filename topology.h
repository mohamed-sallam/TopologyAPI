#ifndef TOPOLOGY_H
#define TOPOLOGY_H
#include "device.h"
#include <QString>
#include <QVector>
#include <QJsonArray>
#include "devicesfactory.h"
#include "devicelist.h"

class Topology
{
private:
    QString id;
    DeviceList components;

public:
    Topology() {}
    Topology(const QString &id, const DeviceList &components);
    const QString &getId() const;
    void setId(const QString &newId);
    const DeviceList &getComponents() const;
    void setComponents(const DeviceList &newComponents);
    QJsonObject getTopologyJSON() const;
    void createTopologyFromJSON(const QJsonObject &json);
    bool operator==(const Topology &rhs) const;
};

typedef std::shared_ptr<QHash<QString, Topology>> TopologyList;
#endif // TOPOLOGY_H

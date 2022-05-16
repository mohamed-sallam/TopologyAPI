#include "topology.h"

Topology::Topology(const QString &id, const DeviceList &components)
    : id(id), components(components) {}

const QString &Topology::getId() const
{
    return id;
}

void Topology::setId(const QString &newId)
{
    id = newId;
}

const DeviceList &Topology::getComponents() const
{
    return components;
}

void Topology::setComponents(const DeviceList &newComponents)
{
    components = newComponents;
}

QJsonObject Topology::getTopologyJSON() const
{
    QJsonArray componentsJSON;
    for (const auto &component : components)
        componentsJSON.push_back(component->getDeviceJSON());
    return {{"id", id},
            {"components", componentsJSON}};
}

void Topology::createTopologyFromJSON(const QJsonObject &json)
{
    DeviceList deviceList;
    for (const auto &component : json.value("components").toArray())
    {
        deviceList.push_back(DevicesFactory::devices.value(component.toObject().value("type").toString())());
        deviceList.last()->createDeviceFromJSON(component.toObject());
    }
    this->components = deviceList;
    this->id = json.value("id").toString();
}

bool Topology::operator==(const Topology &rhs) const
{
    return rhs.getTopologyJSON() == this->getTopologyJSON();
}

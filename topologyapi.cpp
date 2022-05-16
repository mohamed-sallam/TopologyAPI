#include "topologyapi.h"

TopologyAPI::TopologyAPI(TopologyList topologies)
    : topologies(topologies) {}

Result TopologyAPI::deleteTopology(const QString &topologyID)
{
    if (topologies->remove(topologyID))
        return Result(false, "Deleted Successfully!");
    else
        return Result(true, "There are no topology by this ID!");
}

const TopologyList &TopologyAPI::queryTopologies()
{
    return topologies;
}

Result TopologyAPI::readJSON(const QString &fileName)
{
    QFile file{fileName};
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return Result(true, "Failed to open " + fileName);
    QTextStream in(&file);
    QString jsonText{in.readAll()};
    file.close();

    QJsonDocument json_doc{QJsonDocument::fromJson(jsonText.toUtf8())};
    if (json_doc.isNull())
        return Result(true, "Failed to create JSON doc.");
    if (!json_doc.isObject())
        return Result(true, "JSON is not an object.");

    QJsonObject json_obj = json_doc.object();
    if (json_obj.isEmpty())
        return Result(true, "JSON object is empty.");

    Topology topology{Topology()};
    topology.createTopologyFromJSON(json_obj);

    topologies->insert(topology.getId(), topology);
    return Result(false, "success");
}

Result TopologyAPI::writeJSON(const QString &topologyID, const QString &fileName)
{
    if (!fileName.isEmpty())
    {
        QJsonObject topologyJSON_obj;
        if (TopologyAPI::topologies->contains(topologyID))
            topologyJSON_obj = TopologyAPI::topologies->value(topologyID).getTopologyJSON();
        else
            return Result(true, "There is no topology by this ID " + topologyID);

        QString topologyJSON_str{QJsonDocument(topologyJSON_obj).toJson()};

        QFile file(QFileInfo(fileName).absoluteFilePath());
        if (!file.open(QIODevice::WriteOnly))
            return Result(true, "Failed to save file");

        //All ok - save data
        QTextStream out(&file);
        out << topologyJSON_str;
        file.close();
        return Result(false, "success");
    }

    return Result(true, "Error, file name is empty.\n"
                        "Please, choose file name and file path to be saved!");
}

DeviceList TopologyAPI::queryDevices(const QString &topologyID)
{
    return topologies->value(topologyID).getComponents();
}

DeviceList TopologyAPI::queryDevicesWithNetlistNode(const QString &topologyID, const QString &netlistNode)
{
    DeviceList devices;
    for (const auto &device : topologies->value(topologyID).getComponents())
        if (device->getNetlist().toVariantHash().keys(netlistNode).length() > 0)
            devices.push_back(device);
    return devices;
}

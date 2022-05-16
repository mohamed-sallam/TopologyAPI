#ifndef TOPOLOGYAPI_H
#define TOPOLOGYAPI_H
#include "result.h"
#include "devicesfactory.h"
#include "topology.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFileInfo>
#include <algorithm>
#include "TopologyAPI_global.h"
#include "devicelist.h"
class TOPOLOGYAPI_EXPORT TopologyAPI
{
public:
    TopologyAPI(TopologyList topologies);
    Result readJSON(const QString &fileName);
    const TopologyList &queryTopologies();
    Result deleteTopology(const QString &topologyID);
    Result writeJSON(const QString &topologyID, const QString &fileName);
    DeviceList queryDevices(const QString &topologyID);
    DeviceList queryDevicesWithNetlistNode(const QString &topologyID, const QString &netlistNode);

private:
    TopologyList topologies;
};

#endif // TOPOLOGYAPI_H

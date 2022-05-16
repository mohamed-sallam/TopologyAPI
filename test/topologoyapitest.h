#ifndef TOPOLOGOYAPITEST_H
#define TOPOLOGOYAPITEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QTest>
#include "topology.h"
#include "topologyapi.h"

class TopologoyAPITest : public QObject
{
    Q_OBJECT
public:
    explicit TopologoyAPITest(QObject *parent = nullptr);

private:
    TopologyList topologies{new QHash<QString, Topology>};
    TopologyAPI underTest{TopologyAPI(topologies)};
    DeviceList createDevicesForTop(char topologyNumber);

signals:

private slots:
    void cleanup();
    void readTopologyShouldEqualGivenOne();
    void shouldSaveJsonFileWithSameTopologyOfProvidedOne();
    void queriedDevicesShouldEqualGivenOne();
    void deletedTopologyShouldBeUnfound();
    void queriedTopologiesShouldEqualGivenOne();
    void queriedDevicesWithNetlistNodeShouldEqualGivenOne_data();
    void queriedDevicesWithNetlistNodeShouldEqualGivenOne();
};

#endif // TOPOLOGOYAPITEST_H

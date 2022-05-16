#include "topologoyapitest.h"
#include "topologyapi.h"

TopologoyAPITest::TopologoyAPITest(QObject *parent)
    : QObject{parent}
{
}

DeviceList TopologoyAPITest::createDevicesForTop(char topologyNumber)
{
    DeviceList devices;
    std::shared_ptr<Resistor> resistor{new Resistor()};
    std::shared_ptr<N_MOSFET> nmos{new N_MOSFET()};
    switch (topologyNumber)
    {
    case 2:
        resistor->setId("res2");
        resistor->setType("resistor");
        resistor->setNetlist({{"t1", "vcc"},
                            {"t2", "n2"}});
        resistor->setResistance({{"default", 150},
                                {"min", 10},
                                {"max", 1000}});

        nmos->setId("m2");
        nmos->setType("nmos");
        nmos->setNetlist({{"drain", "n2"},
                        {"gate", "vout"},
                        {"source", "vcc"}});
        nmos->setMl({{"default", 1.7},
                    {"min", 1},
                    {"max", 2}});
        break;
    case 1:
    default:
        resistor->setId("res1");
        resistor->setType("resistor");
        resistor->setNetlist({{"t1", "vdd"},
                            {"t2", "n1"}});
        resistor->setResistance({{"default", 100},
                                {"min", 10},
                                {"max", 1000}});

        nmos->setId("m1");
        nmos->setType("nmos");
        nmos->setNetlist({{"drain", "n1"},
                        {"gate", "vin"},
                        {"source", "vss"}});
        nmos->setMl({{"default", 1.5},
                    {"min", 1},
                    {"max", 2}});
        break;
    }
    devices.push_back(resistor);
    devices.push_back(nmos);
    return devices;
}

void TopologoyAPITest::readTopologyShouldEqualGivenOne()
{
    //given
    Topology topology_expected{Topology("top1", createDevicesForTop(1))};

    //when
    Result result{underTest.readJSON("./topology.json")};
    Topology topology_actual{topologies->value("top1")};

    //then
    QCOMPARE(topology_actual, topology_expected);
}

void TopologoyAPITest::shouldSaveJsonFileWithSameTopologyOfProvidedOne()
{
    //given
    Topology topology_expected{Topology("top1", createDevicesForTop(1))};
    topologies->insert("top1", topology_expected);
    
    //when
    underTest.writeJSON("top1", "./top1.json");
    topologies->clear();
    underTest.readJSON("./top1.json");
    Topology topology_actual{underTest.queryTopologies()->value("top1")};

    //then
    QCOMPARE(topology_actual, topology_expected);
}

void TopologoyAPITest::queriedDevicesShouldEqualGivenOne()
{
    //given
    DeviceList devices_expected = createDevicesForTop(1);
    topologies->insert("top1", Topology("top1", devices_expected));

    //when
    DeviceList devices_actual = underTest.queryDevices("top1");

    //then
    QCOMPARE(devices_actual, devices_expected);
}

void TopologoyAPITest::deletedTopologyShouldBeUnfound()
{
    //given
    topologies->insert("top1", Topology("top1", createDevicesForTop(1)));
    bool wasTopologyAdded{topologies->contains("top1")};

    //when
    underTest.deleteTopology("top1");
    bool isTopologyDeleted{!topologies->contains("top1")};

    //then
    if (!(wasTopologyAdded && isTopologyDeleted))
        QFAIL("The topology was NOT added or still isn't deleted.");
}

void TopologoyAPITest::queriedTopologiesShouldEqualGivenOne()
{
    //given
    topologies->insert("top1", Topology("top1", createDevicesForTop(1)));
    topologies->insert("top2", Topology("top2", createDevicesForTop(2)));

    //when
    TopologyList topologies_actual = underTest.queryTopologies();

    //then
    QCOMPARE(topologies, topologies_actual);
}

void TopologoyAPITest::queriedDevicesWithNetlistNodeShouldEqualGivenOne_data()
{
    QJsonArray devicesOfTopology_json[2] = {createDevicesForTop(1).getDevicesJSON(),
                                            createDevicesForTop(2).getDevicesJSON()};

    QTest::addColumn<QString>("topologyID");
    QTest::addColumn<QString>("netlist");
    QTest::addColumn<QJsonArray>("devices_expected");

    QTest::addRow("retrun_both") << "top1"
                                 << "n1" << devicesOfTopology_json[0];
    QTest::addRow("return_empty_list") << "top1"
                                       << "vcc" << QJsonArray();
    QTest::addRow("return_res1") << "top1"
                                 << "vdd" << QJsonArray({devicesOfTopology_json[0].at(0)});
    QTest::addRow("return_m1") << "top1"
                               << "vin" << QJsonArray({devicesOfTopology_json[0].at(1)});
    QTest::addRow("return_m1") << "top1"
                               << "vss" << QJsonArray({devicesOfTopology_json[0].at(1)});

    QTest::addRow("retrun_both") << "top2"
                                 << "vcc" << devicesOfTopology_json[1];
    QTest::addRow("retrun_both") << "top2"
                                 << "n2" << devicesOfTopology_json[1];
    QTest::addRow("return_m2") << "top2"
                               << "vout" << QJsonArray({devicesOfTopology_json[1].at(1)});
    QTest::addRow("return_empty_list") << "top2"
                                       << "vss" << QJsonArray();
}

void TopologoyAPITest::queriedDevicesWithNetlistNodeShouldEqualGivenOne()
{
    //given
    topologies->insert("top1", Topology("top1", createDevicesForTop(1)));
    topologies->insert("top2", Topology("top2", createDevicesForTop(2)));
    QFETCH(QString, topologyID);
    QFETCH(QString, netlist);
    QFETCH(QJsonArray, devices_expected);

    //when
    QJsonArray devices_actual = underTest.queryDevicesWithNetlistNode(topologyID, netlist).getDevicesJSON();

    //then
    QCOMPARE(devices_actual, devices_expected);
}

void TopologoyAPITest::cleanup()
{
    topologies->clear();
}

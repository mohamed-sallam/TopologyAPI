QT -= gui
QT += testlib

TEMPLATE = lib
DEFINES += TOPOLOGYAPI_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated API.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the API deprecated before Qt 6.0.0

SOURCES += \
    device.cpp \
    devicelist.cpp \
    n_mosfet.cpp \
    resistor.cpp \
    result.cpp \
    test/topologoyapitest.cpp \
    topology.cpp \
    topologyapi.cpp

HEADERS += \
    TopologyAPI_global.h \
    device.h \
    devicelist.h \
    devicesfactory.h \
    n_mosfet.h \
    resistor.h \
    result.h \
    test/topologoyapitest.h \
    topology.h \
    topologyapi.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

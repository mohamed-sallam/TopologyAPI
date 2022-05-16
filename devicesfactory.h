#ifndef DEVICESFACTORY_H
#define DEVICESFACTORY_H
#include "n_mosfet.h"
#include "resistor.h"
#include <QHash>
#include <memory>
namespace DevicesFactory {
    template <typename T>
    std::shared_ptr<Device> makeDevice() { return std::shared_ptr<Device>(new T{}); }

    using DeviceMaker = std::shared_ptr<Device> (*)();

    const QHash<QString, std::shared_ptr<Device> (*)()> devices = {{"resistor", makeDevice<Resistor>},
                                                                {"nmos", makeDevice<N_MOSFET>}};
};
#endif // DEVICESFACTORY_H

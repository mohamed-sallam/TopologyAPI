#ifndef RESISTOR_H
#define RESISTOR_H

#include "device.h"

class Resistor : public Device
{
protected:
    QJsonObject resistance;
    static int i;

public:
    Resistor();
    ~Resistor() {}
    void createDeviceFromJSON(const QJsonObject &json) override;
    QJsonObject getDeviceJSON() const override;
    const QJsonObject &getResistance() const;
    void setResistance(const QJsonObject &newResistance);
};

#endif // RESISTOR_H

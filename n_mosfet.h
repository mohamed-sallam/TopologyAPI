#ifndef N_MOSFET_H
#define N_MOSFET_H

#include "device.h"

class N_MOSFET : public Device
{
protected:
    QJsonObject ml;
    static int i;

public:
    N_MOSFET();
    ~N_MOSFET() {}
    void createDeviceFromJSON(const QJsonObject &json) override;
    QJsonObject getDeviceJSON() const override;
    const QJsonObject &getMl() const;
    void setMl(const QJsonObject &newMl);
};

#endif // N_MOSFET_H

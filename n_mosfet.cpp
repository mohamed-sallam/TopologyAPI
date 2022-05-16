#include "n_mosfet.h"

int N_MOSFET::i{0};

const QJsonObject &N_MOSFET::getMl() const
{
    return ml;
}

void N_MOSFET::setMl(const QJsonObject &newMl)
{
    ml = newMl;
}

N_MOSFET::N_MOSFET()
{
    type = "nmos";
    id = "m" + QString::number(i++);
    ml = {{"default", ""},
          {"min", ""},
          {"max", ""}};
    netlist = {{"drain", ""},
               {"gate", ""},
               {"source", ""}};
}

void N_MOSFET::createDeviceFromJSON(const QJsonObject &json)
{
    id = json.value("id").toString();
    QJsonObject ml_obj{json.value("m(l)").toObject()};
    ml = {{"default", ml_obj.value("default").toDouble()},
          {"min", ml_obj.value("min").toDouble()},
          {"max", ml_obj.value("max").toDouble()}};
    QJsonObject netlist_obj{json.value("netlist").toObject()};
    netlist = {{"drain", netlist_obj.value("drain").toString()},
               {"gate", netlist_obj.value("gate").toString()},
               {"source", netlist_obj.value("source").toString()}};
}

QJsonObject N_MOSFET::getDeviceJSON() const
{
    return {{"type", type},
            {"id", id},
            {"m(l)", ml},
            {"netlist", netlist}};
}

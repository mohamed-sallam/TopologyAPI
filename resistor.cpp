#include "resistor.h"

int Resistor::i{0};

const QJsonObject &Resistor::getResistance() const
{
    return resistance;
}

void Resistor::setResistance(const QJsonObject &newResistance)
{
    resistance = newResistance;
}

Resistor::Resistor()
{
    type = "resistor";
    id = "res" + QString::number(i++);
    resistance = {{"default", ""},
                  {"min", ""},
                  {"max", ""}};
    netlist = {{"t1", ""},
               {"t2", ""}};
}

void Resistor::createDeviceFromJSON(const QJsonObject &json)
{
    id = json.value("id").toString();
    QJsonObject resistance_obj{json.value("resistance").toObject()};
    resistance = {{"default", resistance_obj.value("default").toDouble()},
                  {"min", resistance_obj.value("min").toDouble()},
                  {"max", resistance_obj.value("max").toDouble()}};
    QJsonObject netlist_obj{json.value("netlist").toObject()};
    netlist = {{"t1", netlist_obj.value("t1").toString()},
               {"t2", netlist_obj.value("t2").toString()}};
}

QJsonObject Resistor::getDeviceJSON() const
{
    return {{"type", type},
            {"id", id},
            {"resistance", resistance},
            {"netlist", netlist}};
}

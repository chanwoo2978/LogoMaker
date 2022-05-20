//
// Created by Chan Lee on 3/24/22.
//

#include "Snapshot.h"

Snapshot::Snapshot()
{
    data = "";
}

Snapshot::Snapshot(std::string letter)
{
    data = letter;
}

void Snapshot::setString(std::string string)
{
    data = string;
}

std::string Snapshot::getString() const
{
    return data;
}

Snapshot &Snapshot::getSnapshot()
{
}

void Snapshot::applySnapshot(const Snapshot &snapshot)
{
}

//
// Created by eliran on 19/12/17.
//

#include "Soldiers.h"
Soldiers::Soldiers(int _id,int _life,int _speed)
        : id(_id),life(_life),speed(_speed),armors{nullptr, nullptr} {}


int Soldiers::getLife() const {
    return life;
}

Armors *const *Soldiers::getArmors() const {
    return armors;
}

void Soldiers::setLife(int life) {
    Soldiers::life = life;
}

const Point2d &Soldiers::getSoldierLocation() const {
    return soldierLocation;
}

void Soldiers::setSoldierLocation(const Point2d &soldierLocation) {
    Soldiers::soldierLocation = soldierLocation;

}

const int Soldiers::getSpeed() const {
    return speed;
}

const int Soldiers::getId() const {
    return id;
}
void Soldiers::toString(std::ostream &os)const {
    os << "SoldierId: " << id << ", Life: " << life << ", Speed: " << speed << ", SoldierLocation: "
       << soldierLocation<<", ";
}

std::ostream &operator<<(std::ostream &os, const Soldiers &soldiers) {
    soldiers.toString(os);

    return os;
}

Soldiers::~Soldiers() {
    if(armors[0])
        delete(armors[0]);
    if(armors[1])
        delete(armors[1]);

}



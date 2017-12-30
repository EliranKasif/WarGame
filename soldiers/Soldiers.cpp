//
// Created by eliran on 19/12/17.
//

#include <random>
#include "Soldiers.h"
Soldiers::Soldiers(int _id,int _life,int _speed)
        : id(_id),life(_life),speed(_speed),armors{nullptr, nullptr} {}

Soldiers::Soldiers()
        : id(ZERO),life(ZERO),speed(ZERO),armors{nullptr, nullptr} {}


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

Point2d Soldiers::checkifcanstep(const Point2d& point) {
    Point2d can;
    if (getSoldierLocation().getX() < point.getX()) {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setX(getSoldierLocation().getX() - getSpeed());
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() - getSpeed());
        } else {
            can.setX(getSoldierLocation().getX() - getSpeed());
            can.setY(getSoldierLocation().getY() + getSpeed());
        }
    } else if (getSoldierLocation().getX() == point.getX()) {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
        } else {
            can.setY(getSoldierLocation().getY() + getSpeed());
        }
    } else {
        if (getSoldierLocation().getY() < point.getY()) {
            can.setX(getSoldierLocation().getX() + getSpeed());
            can.setY(getSoldierLocation().getY() - getSpeed());

        } else if (getSoldierLocation().getY() == point.getY()) {
            can.setX(getSoldierLocation().getX() + getSpeed());
        } else {
            can.setX(getSoldierLocation().getX() + getSpeed());
            can.setY(getSoldierLocation().getY() + getSpeed());
        }

    }
    return can;
}

int Soldiers::random() {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(1,10); // guaranteed unbiased
    return uni(rng);

}

Soldiers::~Soldiers() {
    if(armors[0])
        delete(armors[0]);
    if(armors[1])
        delete(armors[1]);

}



#ifndef POWERUP_H
#define POWERUP_H

#include "constants.h"

class Ship;
class PowerUp {
public:
    PowerUp();

    // bool update(Ship& player, Object::Command command = Command::NA) override;

private:
    static const float PI;
};

#endif // POWERUP_H

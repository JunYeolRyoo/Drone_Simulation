#include "Package.h"

Package::Package(JsonObject &obj) : details(obj) {
JsonArray pos(obj["position"]);position = {pos[0], pos[1], pos[2]};
JsonArray
 dir(obj["direction"]);
direction = {dir[0], dir[1], dir[2]};
speed = obj["speed"];available = true;
}

JsonObject Package::GetDetails() const { return details; }




void Package::SetAvailability(bool choice) { available =choice; }
void Package::Rotate(double angle) {direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);}
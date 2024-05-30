#ifndef PACKAGE_H
#define PACKAGE_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

class Package : public IEntity {
 public:
  Package(JsonObject& obj);

  ~Package() override = default;

  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; };

  Vector3 GetDestination() const { return destination; }

  bool GetAvailability() const { return available; }

  JsonObject GetDetails() const override;

  float GetSpeed() const { return speed; }

  void SetAvailability(bool choice);

  void SetPosition(Vector3 pos_) { position= pos_; }

  void SetDirection(Vector3 dir_) { direction = dir_; };

  void SetDestination(Vector3 des_) { destination =des_; }

  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // PACKAGE_H

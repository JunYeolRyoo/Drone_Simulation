#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

Drone::Drone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Drone::~Drone() {
  // Delete dynamically allocated variables
  delete graph;
  delete nearestEntity;
}

void Drone::GetNearestEntity(std::vector<IEntity*> scheduler) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }

  if(nearestEntity){
    nearestEntity->SetAvailability(false);  // set availability to the nearest entity
    available =   false; pickedUp = false;
    destination   = nearestEntity->GetPosition();
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler) {
  if ( available    ) {
        GetNearestEntity(scheduler);
  }
}

void    Drone::Rotate(double angle) {
  Vector3 dirTmp= direction;
  direction.x = dirTmp.x 
  *
  std::cos(angle)
  -
  dirTmp.z
  *
  std::sin(angle);
  direction.z= dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Drone::Jump(double height) {
  if(goUp){
    position.y +=height;
    jumpHeight 
    += height;
    if(jumpHeight > 5){
  goUp = false;
    }
  } else {
    position.y -=height;
  jumpHeight -= height;
  if(jumpHeight < 0){
goUp = true;
  }
  }
}

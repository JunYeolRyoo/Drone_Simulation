#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "Drone.h"
#include "IController.h"
#include "IEntity.h"
#include "Package.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
class SimulationModel {
 public:
  SimulationModel(IController& controller);

  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  void CreateEntity(JsonObject& entity);

  /// Schedules a trip for an object in the scene
  void ScheduleTrip(JsonObject& details);

  /// Updates the simulation
  void Update(double dt);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
};

#endif

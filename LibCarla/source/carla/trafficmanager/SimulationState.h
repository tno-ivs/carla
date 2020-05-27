
#pragma once

#include <unordered_set>

#include "carla/geom/Vector3D.h"
#include "carla/rpc/ActorId.h"
#include "carla/trafficmanager/DataStructures.h"

namespace carla {
namespace traffic_manager {

namespace cg = carla::geom;

using ActorId = carla::rpc::ActorId;

/// This class holds the state of all the vehicles in the simlation.
class SimulationState {

private:
  // Structure to hold ids of all actors in the simulation.
  std::unordered_set<ActorId> actor_set;
  // Structure containing dynamic motion related state of actors.
  KinematicStateMap kinematic_state_map;
  // Structure containing static attributes of actors.
  StaticAttributeMap static_attribute_map;
  // Structure containing dynamic traffic light related state of actors.
  TrafficLightStateMap tl_state_map;
  // Structure containing dynamic vehicle light related state of actors.
  TrafficLightStateMap vl_state_map;


public :
  SimulationState(/* args */);

  // Method to add an actor to the simulation state.
  void AddActor(ActorId actor_id,
                KinematicState kinematic_state,
                StaticAttributes attributes,
                TrafficLightState tl_state,
                VLS vl_state);

  // Method to verify if an actor is present currently present in the simulation state.
  bool ContainsActor(ActorId actor_id) const;

  // Method to remove an actor from simulation state.
  void RemoveActor(ActorId actor_id);

  // Method to flush all states and actors.
  void Reset();

  void UpdateKinematicState(ActorId actorid, KinematicState state);

  void UpdateTrafficLightState(ActorId actor_id, TrafficLightState state);

  cg::Location GetLocation(const ActorId actor_id) const;

  cg::Rotation GetRotation(const ActorId actor_id) const;

  cg::Vector3D GetHeading(const ActorId actor_id) const;

  cg::Vector3D GetVelocity(const ActorId actor_id) const;

  float GetSpeedLimit(const ActorId actor_id) const;

  bool IsPhysicsEnabled(const ActorId actor_id) const;

  TrafficLightState GetTLS(const ActorId actor_id) const;

  VLS GetVLS(const ActorId actor_id) const;

  ActorType GetType(const ActorId actor_id) const;

  cg::Vector3D GetDimensions(const ActorId actor_id) const;

};

} // namespace traffic_manager
} // namespace carla
/*****************************************************************************************************************
 * ReelRobotix Inc. - Software License Agreement      Copyright (c) 2018
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <smacc/client_bases/smacc_action_client.h>
#include <smacc/component.h>

#include <rclcpp/rclcpp.hpp>

namespace cl_move_base_z
{
// this component is used to switch the current planner and controller interacting
// with the remote navigation2 stack nodes (bt_navigator, planner_server, controller_server)
class PlannerSwitcher : public smacc::ISmaccComponent
{
public:
  PlannerSwitcher();
  void setBackwardPlanner();
  void setUndoPathBackwardPlanner();

  void setForwardPlanner();
  void setPureSpinningPlanner();

  virtual void onInitialize() override;

  // sets ROS defaults local and global planners
  void setDefaultPlanners();

private:
  std::string desired_global_planner_;
  std::string desired_local_planner_;
  bool set_planners_mode_flag_;

  void updatePlanners(bool subscribecallback = true);
};
}  // namespace cl_move_base_z
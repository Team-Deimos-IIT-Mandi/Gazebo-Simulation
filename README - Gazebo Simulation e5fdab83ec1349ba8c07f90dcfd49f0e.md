# README

This repository is maintained by IIT Mandi Mars Rover Team: Team Deimos. The goal is to simulate all the missions of the University Rover Challenge. The team has started this on Gazebo and might move to IssacSim in the future.

## File Structure

---

The workspace has 4 packages as of now.

- **full_rover_assembly_urdf**: Simulation of Rover assembly, contains URDF of the rover with gazebo plugins, launch files, and relevant configurations.
- **realsense_gazebo_plugin:** Plugin provided by Pal-Robotics to simulate intel realsense
- **realsense2_description:** Example files by pal-robotics on how to use plugins
- **rviz_satelite:** Package to visualize GPS data in rviz.
    
    Reference: 
    
    [ROS Index](https://index.ros.org/p/rviz_satellite/#noetic)
    

## Instructions for ROS installations

---

1. ROS noetic is being used with Gazebo 9, Ubuntu 20.04 LTS
2. ROS installation: [http://wiki.ros.org/noetic/Installation/Ubuntu](http://wiki.ros.org/noetic/Installation/Ubuntu) 
    
    **Desktop-Full Install: (Recommended):** Installs Gazebo as well
    
3. **Official** ******************************Gazebo tutorials:****************************** [https://classic.gazebosim.org/tutorials](https://classic.gazebosim.org/tutorials)

## How to build the packages?

---

```xml
mkdir -p catkin_ws/src
cd catkin_ws/src
git clone https://github.com/Team-Deimos-IIT-Mandi/Gazebo-Simulation.git
cd ..
catkin build
```

- For any errors related to the path, make sure the paths are corresponding to your workspace.
    
    Example: Replace the path of mesh files in world files corresponding to your workspace.
    

## Gazebo simulations

---

For spawning the robot along with GPS visualization and rqt_robot_steering

```bash
roslaunch full_rover_assembly_urdf diff_drive.launch
```

For spawning the robot in a Mars-like environment( taken from IITBMartian/ gazebo-simulation)

```bash
roslaunch full_rover_assembly_urdf gazebo.launch
```

********************************************Examples of Simulation********************************************

![Screenshot from 2023-01-22 12-40-12.png](README%20-%20Gazebo%20Simulation%20e5fdab83ec1349ba8c07f90dcfd49f0e/Screenshot_from_2023-01-22_12-40-12.png)

## Packages utilized

---

- **gazebo_ros_control:** `http://gazebosim.org/tutorials?tut=ros_control`
 Implement differential control on the rover.
- **rqt_robot_steering:** `http://wiki.ros.org/rqt_robot_steering`
 Gives a pre-made User Interface for publishing cmd_vel
- **rviz_satelite:**`https://index.ros.org/p/rviz_satellite/#noetic`
 for UI to control rover movement
- ********************************************************Realsense_Gazebo_Plugin:******************************************************** For simulating Realsense on the rover

## Citations

---

**Realsense Simulations**

[https://github.com/issaiass/realsense2_description](https://github.com/issaiass/realsense2_description)

IITB Martian/Gazebo-Simulation:

[https://github.com/iitbmartian/Gazebo_simulation](https://github.com/iitbmartian/Gazebo_simulation)

## Further work

---

1. Use Navsat_transform node and robot_localization for GPS-based localization
2. Implement RTAB-MAP for mapping and localization.
3. Simulate Aruco- detection and Spiral Search algorithm for autonomous navigation of Rover 

## Contributors:

---

Anurag Maurya

## How to contribute?

---

Create an issue or comment on an existing issue giving details of your approach to fix the issue.

You will be assigned to the issue by a maintainer.

Make the best use of GitHub Conversations. 

For any queries, you can also reach out to the email ID: robotronics@iitmandi.ac.in

---

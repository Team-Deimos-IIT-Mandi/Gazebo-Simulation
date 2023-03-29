# code to publish FK computed x.y,z of the arm, RPY of the end effector
import math
def FK_rover_arm(self,joint_states):
    L1=0.3
    L2=0.4
    # return x,y,z and r,p,y of the end effector frame
    # End effector frame is just at the end of elbow link
    z=L1*math.sin(joint_states[1])-L2*math.cos(joint_states[2]+joint_states[1]-math.pi/2)
    r=L1*math.cos(joint_states[1])+L2*math.sin(joint_states[2]+joint_states[1]-math.pi/2)
    theta=joint_states[0]
    x=r*math.sin(theta)
    y=r*math.cos(theta)
    roll=joint_states[3]
    pitch=joint_states[4]
    yaw=joint_states[5]
    return [x,y,z,roll,pitch,yaw]



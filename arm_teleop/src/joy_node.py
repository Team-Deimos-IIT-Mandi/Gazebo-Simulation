#!/usr/bin/env python
import rospy
from sensor_msgs.msg import JointState
from sensor_msgs.msg import Joy
from std_msgs.msg import UInt16

class joy_teleop:
    def joy_callback(self,data):
        # rospy.loginfo(data.buttons)
        if rospy.get_param('switch')==1:
            joint_5=-1*(data.axes[2]-1)/4
            joint_6=-1*(data.axes[5]-1)/4
            if data.buttons[0]==1:
                self.gripper=0
            if data.buttons[3]==1:
                self.gripper=2
            if data.buttons[2]==1:
                self.gripper=1
            if data.buttons[4]==1:
                joint_5=-joint_5
            if data.buttons[5]==1:
                joint_6=-joint_6
            # self.joint=[int(data.axes[1]*255/2),int(data.axes[0]*255/2),int(data.axes[4]*255/2),int(data.axes[3]*255/2),int(joint_5*255),int(joint_6*255)]
            self.joint0=int(data.axes[1]*255/2)+255
            self.joint1=int(data.axes[0]*255/2)+255
            self.joint2=int(data.axes[4]*255)+255
            self.joint3=int(data.axes[3]*255/2)+255
            self.joint4=int(joint_5*255)+255
            self.joint5=int(joint_6*255)+255
        else:
            self.joint0=255
            self.joint1=255
            self.joint2=255
            self.joint3=255
            self.joint4=255
            self.joint5=255
            self.gripper=0

        

    def __init__(self):
        self.joint=None
        self.joint0=255
        self.joint1=255
        self.joint2=255
        self.joint3=255
        self.joint4=255
        self.joint5=255
        self.gripper=0
        rospy.init_node('arm_teleop_joy', anonymous=True)
        pub0 = rospy.Publisher('joint_state0', UInt16, queue_size=10)
        pub1 = rospy.Publisher('joint_state1', UInt16, queue_size=10)
        pub2 = rospy.Publisher('joint_state2', UInt16, queue_size=10)
        pub3 = rospy.Publisher('joint_state3', UInt16, queue_size=10)
        pub4 = rospy.Publisher('joint_state4', UInt16, queue_size=10)
        pub5 = rospy.Publisher('joint_state5', UInt16, queue_size=10)
        pub6 = rospy.Publisher('joint_state6', UInt16, queue_size=10)        
        rate = rospy.Rate(5) # 10hz
        rospy.Subscriber("joy", Joy, self.joy_callback)
        
        while not rospy.is_shutdown():
            pub0.publish(self.joint0)
            pub1.publish(self.joint1)
            pub2.publish(self.joint2)
            pub3.publish(self.joint3)
            pub4.publish(self.joint4)
            pub5.publish(self.joint5)
            pub6.publish(self.gripper)
            rospy.loginfo(self.gripper)
            # rospy.loginfo(self.joint5)
            rate.sleep()





if __name__ == '__main__':
    try:
        joy_teleop()
    except rospy.ROSInterruptException:
        pass
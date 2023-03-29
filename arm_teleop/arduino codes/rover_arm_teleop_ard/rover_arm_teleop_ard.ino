
#include<ros.h>
#include <std_msgs/UInt16.h>
#include <Servo.h>
Servo servo;
int angle=50;

bool _connected = false;
bool rosConnected();
ros::NodeHandle node;
void onJointStates0(const std_msgs::UInt16 &StateMsg);
void onJointStates1(const std_msgs::UInt16 &StateMsg);
void onJointStates2(const std_msgs::UInt16 &StateMsg);
void onJointStates3(const std_msgs::UInt16 &StateMsg);
void onJointStates4(const std_msgs::UInt16 &StateMsg);
void onJointStates5(const std_msgs::UInt16 &StateMsg);
void onJointStates6(const std_msgs::UInt16 &StateMsg);
ros::Subscriber<std_msgs::UInt16> sub0("joint_state0", onJointStates0);
ros::Subscriber<std_msgs::UInt16> sub1("joint_state1", onJointStates1);
ros::Subscriber<std_msgs::UInt16> sub2("joint_state2", onJointStates2);
ros::Subscriber<std_msgs::UInt16> sub3("joint_state3", onJointStates3);
ros::Subscriber<std_msgs::UInt16> sub4("joint_state4", onJointStates4);
ros::Subscriber<std_msgs::UInt16> sub5("joint_state5", onJointStates5);
ros::Subscriber<std_msgs::UInt16> sub6("joint_state6", onJointStates6);

#include "CytronMotorDriver.h"
CytronMD motor0(PWM_DIR, 8, 30);   // PWM 1A = Pin 3, PWM 1B = Pin 9.
CytronMD motor1(PWM_DIR, 9, 32);   // PWM 2A = Pin 10, PWM 2B = Pin 11.
CytronMD motor2(PWM_DIR, 7, 34);
CytronMD motor3(PWM_DIR, 11, 36);
CytronMD motor4(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 9.
CytronMD motor5(PWM_PWM, 5, 6); // PWM 2A = Pin 10, PWM 2B = Pin 11.
//CytronMD motor4(PWM_DIR, 6, 7);
//CytronMD motor5(PWM_DIR, 6, 7);


void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  servo.attach(12);
  servo.write(0);
  node.initNode();
//  node.getHardware()->setBaud(115200);
  node.subscribe(sub0);
  node.subscribe(sub1);
  node.subscribe(sub2);
  node.subscribe(sub3);
  node.subscribe(sub4);
  node.subscribe(sub5);
  node.subscribe(sub6);
  // put your setup code here, to run once:

}

void onJointStates0(const std_msgs::UInt16 &StateMsg){
int t0=StateMsg.data;
motor0.setSpeed(t0-255);
delay(10);
}

void onJointStates1(const std_msgs::UInt16 &StateMsg){
int t1=StateMsg.data;
motor1.setSpeed(t1-255);
delay(10);
}

void onJointStates2(const std_msgs::UInt16 &StateMsg){
int t2=StateMsg.data;
motor2.setSpeed(t2-255);
delay(10);
}

void onJointStates3(const std_msgs::UInt16 &StateMsg){
int t3=StateMsg.data;
motor3.setSpeed(t3-255);
delay(10);
}


void onJointStates4(const std_msgs::UInt16 &StateMsg){
int t4=StateMsg.data;
motor4.setSpeed(t4-255);
delay(10);
}


void onJointStates5(const std_msgs::UInt16 &StateMsg){
int t5=StateMsg.data;
motor5.setSpeed(t5-255);
delay(10);
}

void onJointStates6(const std_msgs::UInt16 &StateMsg){
int gripper=StateMsg.data-1;
angle=angle+gripper;
servo.write(angle);
delay(10);
}

void loop() {
  if (!rosConnected())
  {
     Serial.println("Stopped");
  }
  node.spinOnce();
  // put your main code here, to run repeatedly:

}

bool rosConnected()
{
  // If value changes, notify via LED and console.
  bool connected = node.connected();
  if (_connected != connected)
  {
    _connected = connected;
    digitalWrite(LED_BUILTIN, !connected); // false -> on, true -> off
    Serial.println(connected ? "ROS connected" : "ROS disconnected");
  }
  return connected;
}

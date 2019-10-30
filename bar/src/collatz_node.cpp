#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <sequences/sequences.h>

int main(int argc, char** argv) {
  using sequences::collatz;
  ros::init(argc, argv, "collatz");
  ros::NodeHandle nh;
  std_msgs::Int32 msg;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("collatz", 1);

  unsigned int n=1, m=1;
  ros::Rate r(2);
  while(ros::ok()) {
    msg.data = m;
    pub.publish(msg);
    if(m == 1) {
      m = (n++);
    }
    else {
      m = collatz(m);
    }
    r.sleep();
  }
  return 0;
}

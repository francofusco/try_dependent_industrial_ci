#include <ros/ros.h>
#include <std_msgs/String.h>
#include <foo/footils.h>


class Bar {
public:
  Bar() : pnh("~") {
    pub = pnh.advertise<std_msgs::String>("foofied_message", 1);
    sub = nh.subscribe("message", 1, &Bar::foofyMsg, this);
  }

  void foofyMsg(const std_msgs::String& in) {
    pub.publish(foo::foofy(in));
  }

private:
  ros::NodeHandle nh, pnh;
  std_msgs::String msg;
  ros::Publisher pub;
  ros::Subscriber sub;
};


int main(int argc, char** argv) {
  ros::init(argc, argv, "bar_node");
  Bar bar;
  ros::spin();
  return 0;
}

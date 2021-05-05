#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "twistetry_publisher");

    ros::NodeHandle n;
    ros::Publisher twist_pub = n.advertise<geometry_msgs::Twist>("/controllers/diff_drive/cmd_vel", 50);
    tf::TransformBroadcaster twist_broadcaster;

    double x = 0.0;
    double y = 0.0;
    double th = 0.0;

    double vx = 0.2;
    double vy = 0;
    double vth = 0;

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    ros::Rate r(1.0);
    while (n.ok())
    {

        ros::spinOnce(); // check for incoming messages
        current_time = ros::Time::now();

        //next, we'll publish the twistetry message over ROS
        geometry_msgs::Twist twist;


        //set the velocity
        twist.linear.x = vx;
        twist.linear.y = vy;
        twist.angular.z = vth;

        //publish the message
        twist_pub.publish(twist);

        last_time = current_time;
        r.sleep();
    }
}

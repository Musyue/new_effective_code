#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc,char **argv)
{
    // 初始化该节点和名称
    // initialize the node and set the name
    ros::init(argc,argv,"example_advertise");
    // 设置进程处理函数与ROS环境进行交互
    // allows our node to interact with the ROS environment
    ros::NodeHandle n;
    // 将节点实例化成发布者，使用ROS命名空间下的模板类实例化消息发布函数，消息名为Message,设置缓冲区大小
    // instantiate a publisher and tell the master the name of the topic and the type,and set the buff size
    ros::Publisher chatter_pub=n.advertise<std_msgs::String>("message",1000);
    // 设置发送频率，这里设置的是10hz
    //  set the data sending frequency,which in this case is 10HZ
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        // 创建一个字符串类型的消息
        // create a variable for the message 
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"I am the advertise node";
        msg.data=ss.str();
        chatter_pub.publish(msg);
        // 使用spinOnce处理该节点相关的ROS事件和操作，如订阅消息和发布
        // spinOnce takes care of handling all of ROS's internal events and actions in this node
        ros::spinOnce();
        // 执行休眠程序，让数据按照需要的10HZ发布
        // sleep for the required time to get a 10HZ frequency
        loop_rate.sleep();
    }
}
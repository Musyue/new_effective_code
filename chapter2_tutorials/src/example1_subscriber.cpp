#include "ros/ros.h"
#include "std_msgs/String.h"
// 设置回调函数，每次该节点收到新消息都会调用该函数
// following type of function is a callback and happens in response to an action
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard:[%s]",msg->data.c_str());
}
int main(int argc,char **argv)
{
    // 初始化该节点和名称
    // initialize the node and set the name
    ros::init(argc,argv,"example_subscriber");
    // 设置进程处理函数与ROS环境进行交互
    // allows our node to interact with the ROS environment
    ros::NodeHandle n;
    ros::Subscriber chatter_sub=n.subscribe("message",1000,chatterCallback);
    // 将节点实例化成接受者，使用ROS命名空间下的接受函数，消息名为Message,设置缓冲区大小，回调函数名为chatterCallback
    //  create a subscriber and start to listen to the topic with the name message. The buffer will be of 
    // 1000, and the function to handle the message will be messageCallback
    //节点开始读取主题，在消息到达时回调函数chatterCallback被调用。当用户按下Ctrl+c时程序退出主循环
    //This line is the main loop where the node starts to read the topic and when a message arrives,chatterCallback is called.
    // While user presses Ctrl+C,the node exits the loop and ends. 
    ros::spin();
    return 0;
}
#include "rclcpp/rclcpp.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"

class Talker : public rclcpp::Node
{
public:
  Talker() : Node("talker")
  {
    publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive", 10);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(100),
      std::bind(&Talker::timer_callback, this));

    this->declare_parameter("v", 0.0);
    this->declare_parameter("d", 0.0);
  }

private:
  void timer_callback()
  {
    auto message = ackermann_msgs::msg::AckermannDriveStamped();
    message.drive.speed = this->get_parameter("v").as_double();
    message.drive.steering_angle = this->get_parameter("d").as_double();
    publisher_->publish(message);
  }

  rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}

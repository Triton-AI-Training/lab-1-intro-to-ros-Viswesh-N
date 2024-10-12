import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped

class Talker(Node):
    def __init__(self):
        super().__init__('talker')
        self.publisher_ = self.create_publisher(AckermannDriveStamped, 'drive', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.declare_parameter('v', 0.0)
        self.declare_parameter('d', 0.0)

    def timer_callback(self):
        msg = AckermannDriveStamped()
        msg.drive.speed = self.get_parameter('v').value
        msg.drive.steering_angle = self.get_parameter('d').value
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    talker = Talker()
    rclpy.spin(talker)
    talker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

import rclpy
from rclpy.node import Node

class Publisher(Node):
    def __init__(self):
        super().__init__('Publisher')
        self.publisher_ = self.create_publisher(
            bool,
            'amazing_bool',
            10
        )
        publish_period = 0.5
        self.timer = self.create_timer(publish_period,self.timer_callback)
        
    def timer_callback(self):
        msg = 1
        self.publisher_.publish(msg)
        
def main():
    rclpy.init(args=None)
    
    # Instantiate the node and spin it
    publish_node = Publisher()
    rclpy.spin(publish_node)
    
    # Stop the node
    publish_node.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()
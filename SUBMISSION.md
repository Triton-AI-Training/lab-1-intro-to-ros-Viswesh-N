# Lab 1: Intro to ROS 2

## Written Questions

### Q1: During this assignment, you've probably ran these two following commands at some point: ```source /opt/ros/foxy/setup.bash``` and ```source install/local_setup.bash```. Functionally what is the difference between the two?

Answer: The first command sets up the environment for the base ROS 2 Foxy installation, giving access to all core ROS 2 functionalities. The second command is specific to your local workspace, adding only your custom packages to the environment.

### Q2: What does the ```queue_size``` argument control when creating a subscriber or a publisher? How does different ```queue_size``` affect how messages are handled?

Answer: The queue_size determines how many messages can be buffered for a publisher or subscriber. For publishers, it sets how many messages to keep if they're being published faster than sent. For subscribers, it's how many incoming messages to hold if they arrive faster than they're processed. A larger queue_size helps prevent message loss during processing delays but may increase latency. A smaller queue_size promotes real-time behavior but risks losing messages if the system can't keep up

### Q3: Do you have to call ```colcon build``` again after you've changed a launch file in your package? (Hint: consider two cases: calling ```ros2 launch``` in the directory where the launch file is, and calling it when the launch file is installed with the package.)

Answer: f you're running the launch file directly from its source location, you don't need to rebuild. The changes take effect immediately. However, if you're running an installed version of the launch file, you need to run colcon build --symlink-install to update the installed copy. 

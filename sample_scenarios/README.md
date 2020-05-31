# yrn-eavat-zrff - Sample Scenarios

Here you'll find a collection of example scenarios that contain settings for different kinds of subject behaviours.

Brief descriptions of each sample scenario:
- **axis_wise_following**: Subjects scatter from your current position, and then attempt to stick around, but not too close. Their movement is separated into axis-wise movement (one input for x-axis, another for y-axis). Takes a few generations for the scenario to exhibit said behaviour.
- **counter_clockwise**: Subjects scatter from your current position, and then attempt to circle around your ship counter-clockwise. Moving ahead of them makes them try to avoid collisions (still trying to move counter-clockwise), but not always. Despite the name of the scenario, some subjects may eventually try to move clockwise.
- **gaussian_bias**: A simple scenario that uses a Gaussian activation function and some initial bias to guide
subjects to your ship.
- **slow_circular_congregation**: Subjects move in large circles, slowly towards your ship.
- **stay_inside** (\*): Subjects are limited to horizontal/vertical movement and are encouraged to stay inside the visible 2D space. Subjects ignore your ship. Twitchy behaviour is a common sight here due to their restricted movement.
- **swarm_of_mosquitoes** (\*): Subjects come to "buzz" around you, effectively demonstrating the wacky stuff that the application could create.
- **too_fast_too_furious** (\*): subjects approach you... with weak brakes. They try their best to get close to you, but often times they simply have too much speed to see it through. Staying close to the mouse point and increasing offspring count seems to help the training.
- **unreal_angular_velocity**: Using extremely high angular velocity, the subjects somehow make their way to your ship. What could cause this?

(\*): Subjects appear from a "mouse point". This is created by right-clicking the visible space. Default location of the mouse point is in top-left corner, outside the visible area.

Here are some other notes relating to scenarios:
- Editing scenarios outside the application may cause a crash (due to invalid keys/values, out-of-range values etc.).
- The application directs you to your desktop folder once you attempt to load/save a scenario. Relocating/Copying this folder there could save some time.

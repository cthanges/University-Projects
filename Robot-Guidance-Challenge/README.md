# Robot Guidance Challenge (Group Project)
## Introduction
The purpose of this project is to program an eebot (mobile robot that uses an HCS12 microcontroller) to navigate a maze autonomously. The eebot should be able to explore different paths, detect and make decisions at intersections, and learn the correct path through trial and error. This code in particular causes the eebot to prioritize right turns over left turns. If the robot reaches a dead end, it executes a 180-degree turn and retraces it steps to find a better path.

## Problems Encountered & Solved
**Problem #1**: The eebot was not following the black path on the S-turn.
- **Reasoning**: The guider readings were inconsistent, and the eebot failed to detect the black path accurately. This discrepancy led to deviations in the robot's trajectory, particularly on S-turns, affecting its ability to navigate the maze effectively.
- **Solution**: Revised the guider routine to enhance the sensitivity and accuracy of the sensor readings. Adjusted the threshold values to ensure reliable detection of the black path. Additionally, implemented a real-time feedback mechanism to monitor and fine-tune the guider control during navigation continuously.

**Problem #2**: The eebot was not turning right at the intersections.
- **Reasoning**: The logic responsible for making decisions at intersections was flawed, causing the eebot to consistently choose the wrong direction, especially when a right turn was required. This led to incorrect maze traversal and hindered the learning process.
- **Solution**: Refactored the intersection decision-making algorithm to correctly interpret the current direction and choose the appropriate turn. Implemented conditional statements to map the robot's path and the desired turn direction accurately. Conducted rigorous testing to validate the decision-making logic at various intersections, ensuring appropriate path selection.

##
This project was developed as part of COE538: Microprocessor Systems at Toronto Metropolitan University.


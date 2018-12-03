# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

As suggested, two PID controllers were used in this project. One for the steering, and the other for the throttle. The cross-track error was used as the basis signal for both. Steering aimed to keep it down around zero, and in throttle it was used to suppress speed when off the track-center to help the recovery.

### The effect of parameters on steering 

#### P
The proportional control coefficient helps to govern the car back to the middle of the road. The further it gets, the stronger this "force" becomes. The analogy is a spring which shows its problem too: it does not stop the car in the middle, as it only starts counteracting the original direction when it gets to the other side.

#### D
The differential control coefficient helps with stopping the car near the middle, as it only reacts to the change rate in error. It is effective in sharp turns where the error grows at a high rate and when the car has swerved towards the middle when the error decreases at a high rate.

#### I
The integrating control coefficient helps to fight the remainder of the error as it increases with its cumulation. The difficulties regarding the I term is to mitigate its saturation and to prevent the overshooting effect.

### The effect of parameters on throttle

#### P
The throttle can be set based on the cross-track error as well, a bit similar to the human intuition in driving: the further you get from the middle of the road -for example in turns-, the slower you need to drive in order to be able to recover.

#### D
The decreasing of the throttle can also incorporate the D term. For the differential part, it is okay to drive parallel to the trajectory, but moving away from the center at a quick rate needs a counter-measure. It is crucial to react quickly when arriving to turns.

#### I
The integrating term plays a secondary role in the throttle control. It was used to handle a specific problem. When the car gets too far from the center, the P and D control can slow down the car to a halt. Using a negative coefficient, the I term can be used to achieve an extra boost over time to accelerate the stuck car, at a rate it can find the way back to the center.

### The tuning process
Due to the specific nature of the application, I chose manual parameter tuning, as there were many cues that would have been difficult to extract of each run numerically. First, only with P, the best possible behavior was tuned, then I added and tuned D to achieve success in sharper turns. Trying the I term did not yield a clear advantage but complicated the tuning process, so I omitted it in the final version. Adding the throttle control made the system more stable and robust against situational differences, namely arriving to turns in an awkward angle or too fast.
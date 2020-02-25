# UCSDIEEE_team_6_WI_2020

## Software
- Travis Davis
- Ethan Spraggon

The software should consider the user's ability manipulate the time to dispense and save multiple combinations to desposit the medication. For this purpose use the default Arduino timer to measure the time elapsed from start up to measure against real time. There is the option to track the actual global time but for this project we shall use the in-built time for simplification. Most importantly is for the Arduino to call on specific trays at the correct time without invoking a cascading error, make sure that there are try catch statements that prevent errors from user input. 

The software must consider the motor's on and off times so it doesn't over dispense. This part can the written in the from of an if not gate with a specified timer. The motor must also not burn out in case of jamming so the timing must be tested repeatedly during weeks 7 and 8. An option is for an user input to ask how big the pill is for set timers for different sizes. To note the motor must not be spinning at full speed, an option to use pulse width modulation to control the output voltage although it is unideal for motors. 

Linking software to hardware in terms of user input is the user's ability to interact with the "calendar" of the medicine. For this project we shall constrain the limit of time to one day instead of week for convenience. With this we have LCD displays that demonstrate the time and what medication is dispensed. In consideration the project will be targeted to old and infirmed, externals must be simple with user interaction at maximum be with simple buttons and switches.

## Hardware
- Mon Morera
- Mike Liu

The hardware should consider the ease of use, internal tray, and wheel design. The exterior box, since is a prototype at best, should be simply laser cut from plastic or wood. No need to be fancy, but clear plastic is preferable since we can see what happen on the inside.

Ease of use should consider the exterior simplicity of using simple buttons and switches that allow users to interact with the LCD display. At most it should simply connect with the available pins inside the Arduino with appropriate wiring. Switches for one use could turn on and off the machine which will be considered as a reset for the machine that wipes the previous memory of the schedule for the prototype.

The internal tray and wheel design should consider the size of the pills. It is best if we have a uniform size of tray (input) and disposit tray (output). How the size and layout of the device is designed is in the discretion of the hardware team, just make sure there is sufficient space for everything including wirings (don't make it too messy please). 

For the wiring it is suggested to have a few excess breadboards at the beginning. Whether we shall improve it to PCBs should be in consideration if we have the time to execute it. The main goal of the project is to get it to work not appearace.


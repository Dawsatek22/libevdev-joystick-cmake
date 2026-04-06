#include <fcntl.h>
#include <libevdev/libevdev.h>
#include <stdio.h>
#include <cstdlib>
#include <errno.h>
#include <error.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

int main() {
   struct libevdev *dev = NULL;
int fd;
int rc = 1;
// button values for  xbox one game pad
 
 int a_btn = BTN_SOUTH; // A button
 int b_btn = BTN_EAST; // B button
 int x_btn = BTN_NORTH; // X button 
 int y_btn = BTN_WEST; // Y button 
 int lb_Btn = BTN_TL ; // LB button 
 int lt_btn = ABS_BRAKE; // LT button
 int rb_btn = BTN_TR; // RB button
 int rt_btn = ABS_GAS; // RT button
 int select_btn = BTN_SELECT; // select button
 int start_btn = BTN_START; // start button
 int lstick_btn = BTN_THUMBL; // left joystick button 
 int rstick_btn = BTN_THUMBR; // right joystick button 
int y_arrow = ABS_HAT0Y; // up and down arrow button
int x_arrow = ABS_HAT0X; // left and right arrow button
fd = open("/dev/input/event17", O_RDONLY|O_NONBLOCK); 
rc = libevdev_new_from_fd(fd, &dev);
if (rc < 0) {
        fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
        exit(1);
}
printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
printf("Input device ID: bus %#x vendor %#x product %#x\n",
       libevdev_get_id_bustype(dev),
       libevdev_get_id_vendor(dev),
       libevdev_get_id_product(dev));
// checks if gamepad is available
if (!libevdev_has_event_type(dev, EV_SYN) ||
    !libevdev_has_event_code(dev, EV_KEY,a_btn)) {
        printf("This device does not look like a gamepad\n");
        exit(1);
}
 
while (true) {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

        if (rc == 0)
                printf("Event: %s %s %d\n",
                       libevdev_event_type_get_name(ev.type),
                       libevdev_event_code_get_name(ev.type, ev.code),
                       ev.value);
                
              // here are the button presses printed 
              if (ev.code == x_btn)  {
                 
                  printf("X was pressed.");
              }
            
                  if (ev.code == a_btn)  {
                 
                  printf("A was pressed.");
                 
                  }
                     if (ev.code == b_btn)  {
                
                  printf("B was pressed.");
                 
                  }
                     if (ev.code == y_btn)  {
                 
                  printf("Y was pressed.");
            
                  }
                        if (ev.code == lb_Btn)  {
                  
                  printf("LB was pressed.");
                 
                  }

                        if (ev.code == lt_btn)  {
                  
                  printf("LT was pressed.");
                  
                  }



                        if (ev.code == rt_btn)  {
                  
                  printf("RT was pressed.");
                  
                  }


                           if (ev.code == rb_btn)  {
                  
                  printf("RB was pressed.");
                  
                  }


                          if (ev.code == select_btn)  {
                  
                  printf("select button was pressed.");
                  
                  }

                          if (ev.code == start_btn)  {
                  
                  printf("start button was pressed.");
                  
                  }


                            if (ev.code == y_arrow )  {
                  
                  printf("arrow button y touched .");
                  std::cout << "y arrow value is" << ev.value<< "currently" << '\n';
            
                }
              if (ev.code == x_arrow )  {
                  
                  printf("arrow button y touched .");
                  std::cout << "x arrow value is" << ev.value<< "currently" << '\n';
            
                }


          

            }}
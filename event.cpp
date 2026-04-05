
// this is a code trying to  print events by pressing button or joystick getting a certain value

// the pass
#include <fcntl.h>
#include <libevdev/libevdev.h>
#include <stdio.h>
#include <cstdlib>
#include <errno.h>
#include <error.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
 struct libevdev *dev = NULL;
int fd;
int rc = 1;
 
fd = open("/dev/input/event17", O_RDONLY|O_NONBLOCK); // device adress
rc = libevdev_new_from_fd(fd, &dev);
// checks if libevdev is initialized
if (rc < -0) {
        fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
        exit(1);
}
printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
printf("Input device ID: bus %#x vendor %#x product %#x\n",
       libevdev_get_id_bustype(dev),
       libevdev_get_id_vendor(dev),
       libevdev_get_id_product(dev));

       // checks if it is a gamepad
if (
    !libevdev_has_event_code(dev, EV_KEY, BTN_NORTH)) {
        printf("This device does not look like a gamepad\n");
        exit(1);
}
 // print event type
do {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
        if (rc == 0)
                printf("Event: %s %s %d\n",
                       libevdev_event_type_get_name(ev.type),
                       libevdev_event_code_get_name(ev.type, ev.code),
                       ev.value);
} while (rc == 1 || rc == 0 || rc == -EAGAIN);
// should print a message by pressing x
if (libevdev_has_event_code(dev, EV_KEY,BTN_NORTH) == 0){

    printf(" x is press");
 }
}
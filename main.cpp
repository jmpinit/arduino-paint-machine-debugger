#include <thread>
#include <unistd.h>
#include "ArduinoEmu.h"

void s1up();

#include "sketch.cpp"

void timeout() {
  usleep(10000);
  exit(0);
}

int main(int argc, char **argv) {
  std::thread timeoutThread(timeout);

  setup();

  for (int i = 0; i < 1; i++) {
    loop();
  }
}

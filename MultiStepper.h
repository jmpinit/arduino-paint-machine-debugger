#ifndef H_MULTISTEPPER
#define H_MULTISTEPPER

#include <stdio.h>

class MultiStepper {
  public:
    MultiStepper();
    void addStepper(AccelStepper stepper);
    void moveTo(long *positions);
    void runSpeedToPosition();
};

MultiStepper::MultiStepper() {
  printf("x,y\n");
}

void MultiStepper::addStepper(AccelStepper stepper) { }
void MultiStepper::runSpeedToPosition() { }
void MultiStepper::moveTo(long *positions) {
  //printf("%ld, %ld, %ld\n", positions[0], positions[1], positions[2]);
  printf("%ld,%ld\n", positions[0], positions[1]);
}

#endif

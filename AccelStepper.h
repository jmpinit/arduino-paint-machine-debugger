#ifndef H_ACCELSTEPPER
#define H_ACCELSTEPPER

class AccelStepper {
  public:
    AccelStepper(int a, int b, int c);
    void setMaxSpeed(int speed);
    void setAcceleration(int accel);
    void move(long pos);
    void moveTo(long pos);
    void setCurrentPosition(long pos);
    void runToPosition();
    void run();
};

AccelStepper::AccelStepper(int a, int b, int c) {
}


void AccelStepper::setMaxSpeed(int speed) { }
void AccelStepper::setAcceleration(int speed) { }
void AccelStepper::setCurrentPosition(long pos) { }
void AccelStepper::move(long pos) { }
void AccelStepper::moveTo(long pos) { }
void AccelStepper::runToPosition() { }
void AccelStepper::run() { }

#endif

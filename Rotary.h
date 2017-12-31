// The library this emulates is https://github.com/brianlow/Rotary

#ifndef H_ROTARY
#define H_ROTARY

#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Counter-clockwise step.
#define DIR_CCW 0x20

class Rotary {
  public:
    Rotary(int, int);
    unsigned char process();
};

Rotary::Rotary(int pinA, int pinB) { }

unsigned char Rotary::process() {
  return 0; // FIXME
}

#endif


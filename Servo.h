#ifndef H_SERVO
#define H_SERVO

class Servo {
  public:
    void attach(int);
    void detach();
    void write(int);
};

void Servo::attach(int position) { }
void Servo::detach() { }
void Servo::write(int position) { }

#endif

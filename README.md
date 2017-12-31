# Arduino Paint Machine Debugger

Disclaimer: this is probably not super useful for you because it is meant for use in a really specific context.

The basic idea is that there is a CNC machine controlled by an Arduino Mega. Artwork is produced on the machine by writing Arduino sketches which control the stepper motors that actuate the axes of the CNC.

A ton of sketches have been written but not documented super well so it's hard to know at a glance what each sketch "looks" like (the sort of visual output it produces on the machine).

This code is a hack meant to take Arduino sketches meant for the painting machine as input and generate as output thumbnails approximating the result of running each sketch on the painting machine. It does that by stubbing out the Arduino API and the libraries used for controlling the CNC machine's stepper motors, compiling a given sketch, saving a CSV file of stepper motion targets, and then generating images based on those motion targets.

# Usage

You'll need Python (using 2.7.10) and Ruby (using 2.3.0p0), a C++ compiler (using clang-900.0.39.2), the colors gem, the Pillow Python library, and a bunch of Arduino sketches that use the AccelStepper library. `runOnSketchFolder.rb` is the main script. Do something like `ruby runOnSketchFolder.rb /Users/YourCoolName/Documents/Arduino` and it will start working its dirty work, compiling each sketch it finds in that directory and generating a corresponding thumbnail in the script's directory.


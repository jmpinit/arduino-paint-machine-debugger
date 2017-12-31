#!/bin/bash

set -o errexit

SKETCH_DIR="$1"
SCRIPT_DIR="$( cd "$(dirname "$0")" || exit 1; pwd -P )"

if [ -z "$SKETCH_DIR" ]; then
  echo "Usage: thumbnail.sh <path to a sketch folder>"
  exit 1
fi

SKETCH_PATH="$SKETCH_DIR/"$(basename "$SKETCH_DIR").ino

if [ ! -f "$SKETCH_PATH" ]; then
  echo "Sketch \"$SKETCH_PATH\" not found"
  exit 1
fi

THUMBNAIL_NAME=$(basename "$SKETCH_PATH" .ino).png

# Get the sketch source
SKETCH_COPY="$SCRIPT_DIR"/sketch.cpp
cp "$SKETCH_PATH" "$SKETCH_COPY"

# Handle utilities.ino
if [ -f "$SKETCH_DIR/utilities.ino" ]; then
  echo "Found utilities.ino - including in build"
  UTILITIES_COPY="$SCRIPT_DIR/utilities.cpp"
  cp "$SKETCH_DIR/utilities.ino" "$UTILITIES_COPY"
  
  # Add the utilities file in the right place
python - <<EOF sketch.cpp
import sys
fp = sys.argv[1]
with open(fp, 'r+') as f:
  d = f.read().replace('void setup', '#include "utilities.cpp"\n\nvoid setup')
  f.seek(0)
  f.write(d)
  f.truncate()
EOF
fi

CSV_PATH="$SCRIPT_DIR/output.csv"
g++ main.cpp -o sim -I./ && ./sim > "$CSV_PATH"
python path-to-image.py "$CSV_PATH" "$THUMBNAIL_NAME"
rm "$CSV_PATH" "$SKETCH_COPY" "$UTILITIES_COPY"

echo "OK, done. Data in $CSV_PATH, image named $THUMBNAIL_NAME generated"

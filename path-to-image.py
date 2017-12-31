import sys
import csv
from PIL import Image, ImageDraw

if len(sys.argv) != 3:
    print("Usage: {} <CSV file> <image file>".format(sys.argv[0]))
    sys.exit(1)

dataFilePath = sys.argv[1]
imageFilePath = sys.argv[2]

imageWidth = 400
imageHeight = 400
thumbnail = Image.new('RGB', (imageWidth, imageHeight), (255, 255, 255)) 
draw = ImageDraw.Draw(thumbnail) 

def getBoundingBox(points):
    if len(points) == 0:
        return None

    x1, y1 = points[0]
    
    minX = x1
    minY = y1
    maxX = x1
    maxY = y1

    for pt in points:
        x, y = pt

        if x < minX:
            minX = x
        if x > maxX:
            maxX = x
        if y < minY:
            minY = y
        if y > maxY:
            maxY = y

    return (minX, maxX, minY, maxY)

with open(dataFilePath, 'rb') as dataFile:
    dataReader = csv.DictReader(dataFile)

    points = []

    for row in dataReader:
        x = int(row['x'])
        y = int(row['y'])

        points += [(x, y)]

    minX, maxX, minY, maxY = getBoundingBox(points)

    width = maxX - minX
    height = maxY - minY

    last = None
    for pt in points:
        rawX, rawY = pt

        x = imageWidth * (rawX - minX) / width
        y = imageHeight * (rawY - minY) / height

        if not last is None:
            draw.line((last[0], last[1], x, y), fill=128, width=3)

        last = (x, y)

thumbnail.save(imageFilePath)


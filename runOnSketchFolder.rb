require 'pp'
require 'colorize'

if ARGV.length != 1
  puts "Usage: runOnSketchFolder.rb <folder containing sketches>"
  exit
end

sketchFolder = ARGV[0]
sketches = `ls #{sketchFolder}`.split("\n").map { |sketchDir| File.join(sketchFolder, sketchDir) }

thumbnailResults = Hash.new

for sketchFolder in sketches do
  succeeded = system("./thumbnail.sh #{sketchFolder}", { :out => File::NULL, :err => File::NULL })

  if succeeded
    puts "(✔) #{sketchFolder}".green
  else
    puts "(X) #{sketchFolder}".red
  end
end


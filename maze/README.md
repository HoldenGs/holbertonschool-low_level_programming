# Maze Prototype (WIP)

## Controls

W - forward
S - backward
A - turn left
D - turn right
Q - strafe left
E - strafe right

## Create a map

Make a text file and use the following characters for the map:

'W' - Wall
' ' or '0' - Space
'P' - Player

Make sure to enclose the player in spaces and enclose spaces with walls.

## Run the game

To compile the game, you must have SDL2.0 installed.

Run `make` on your CLI to compile the program, then run:

```
./maze_binary ./maps/map_1.txt
```

If you have a custom map, replace the `./map_1.txt` with the location of your map.
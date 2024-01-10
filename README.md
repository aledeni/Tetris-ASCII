The rules of the game follow those of classic Tetris: the aim is complete horizontal lines in the playing field. When one line is completed, disappears and the player earns points.
The ncurses.h library is used for the game graphics.
The playing field is made up of a 20x25 char matrix.

How to run:
A makefile is provided, and to compile the application just type ```make``` in the terminal and then ```./tetris``` to run.

If you want to make the application even fancier you can download some retro video game fonts and add them to your terminal. To do that you can type:
```sudo cp font_file_name.ttf /usr/share/fonts/truetype/```
```sudo fc-cache -f -v```

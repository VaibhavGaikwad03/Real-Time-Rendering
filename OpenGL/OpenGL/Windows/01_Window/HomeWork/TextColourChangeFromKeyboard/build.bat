del *.obj
del *.exe

cl Window.c user32.lib gdi32.lib
Window.exe
del *.obj
del *.exe

cl /c /EHsc Window.c
link Window.obj user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
Window.exe
del *.obj
del *.exe

cl /c /EHsc Window.c
rc Window.rc
link Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
Window.exe

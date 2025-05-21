del *.obj
del *.exe
del *.res

cl /c /EHsc Window.c
rc Window.rc
link Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
Window.exe

del *.obj
del *.exe
del *.res
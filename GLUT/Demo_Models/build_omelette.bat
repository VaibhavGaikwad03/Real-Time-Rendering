cl /c /EHsc /I C:\freeglut\include Omelette.c
link Omelette.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
Omelette.exe
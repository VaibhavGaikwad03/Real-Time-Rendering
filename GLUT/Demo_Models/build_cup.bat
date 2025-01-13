cl /c /EHsc /I C:\freeglut\include Cup.c
link Cup.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
Cup.exe
cl /c /EHsc /I C:\freeglut\include test.c
link test.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
test.exe
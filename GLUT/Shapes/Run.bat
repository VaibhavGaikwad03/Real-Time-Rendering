cl /c /EHsc /I C:\freeglut\include test.cpp
link test.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
test.exe



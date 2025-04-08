all:
	main
	start

main: main.c app.c
	gcc main.c app.c -o main

start:
	./main.exe

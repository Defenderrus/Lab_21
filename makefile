all:
	main
	start

main: main.c app.c
	gcc main.c app.c tests/test.c tests/unity.c -o main

start:
	./main.exe

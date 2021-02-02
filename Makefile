all:
	gcc shell.c -o shell
	gcc date.c -o date
	gcc mkdir.c -o mkdir
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc cat.c -o cat
	./shell
all: clean
	gcc program.c -Wl,-z,relro,-z,now -o program_recompiled

clean:
	rm -f program_recompiled


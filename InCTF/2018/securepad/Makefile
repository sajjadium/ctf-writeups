all: clean
	gcc program.c -fpie -pie -Wl,-z,relro,-z,now -o program_recompiled

clean:
	rm -f program_recompiled


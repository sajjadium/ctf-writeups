all: clean
	gcc program.c -fpie -pie -fno-stack-protector -z execstack -o program_recompiled

clean:
	rm -f program_recompiled


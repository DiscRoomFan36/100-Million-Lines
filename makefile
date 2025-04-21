

thing: thing.c
	clang -Wall -Wextra -Werror -pedantic -O0 -o thing thing.c

thing.c: main
	./main thing.c

main: main.c
	clang -Wall -Wextra -O2 -o main main.c

clean:
	rm main thing.c thing

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


char new() {
	// функция лепит новый файл с нулём
	FILE * file = fopen("/tmp/iota.number", "wb");
	if (file == NULL) return FALSE;
	int i=1;
    fwrite(&i, sizeof(int), 1, file);
    fclose(file);
	return TRUE;
}

void put_help() {
	puts("Usage: iota [options]");
	puts("    help; --help      help massage");
	puts("    null              set null number");
	puts("    get               get number");
}

int main(int argc, char **argv) {
	if (argc>2) {
		fputs("iota: too many arguments", stderr);
		put_help();
		return 1;
	}
	if (argc==2) {
		// проверка арнументов командной строки
		if (!strcmp(argv[1], "help") || !strcmp(argv[1], "--help")) {
			put_help();
			return 0;
		}
		if (!strcmp(argv[1], "null")) {
			if (new() != TRUE) { // лепим файл с нулём
 	          	fputs("iota: i/o error", stderr);
 	          	return 2;
 	      	}
			return 0;
		}
		if (!strcmp(argv[1], "get")) {
			FILE *file = fopen("/tmp/iota.number", "rb");
	    	if (file == NULL) {
				fputs("iota: file does not exist\n", stderr);
				return 1;
	        }
			int number;
			fread(&number, sizeof(int), 1, file);
			fclose(file);
			printf("%d", number);
			return 0;
		}
		// если был аргумент, но невеный
		puts("iota: invalid argument\n");
		put_help();
        return 1;
	}

	// с опциями покончено, далее нормальная работа проги

	// чтение первой строки файла с числом, или создание файла с нулём при отсутствии оного
	FILE *file = fopen("/tmp/iota.number", "rb");
	if (file == NULL) {
		if (new() != TRUE) { // лепим файл с нулём
			fputs("iota: i/o error", stderr);
			return 2;
		}
		return 0;
	}
	// number - само число
	int number;
	fread(&number, sizeof(int), 1, file);
	fclose(file);

	// а теперь записываем number++
	file = fopen("/tmp/iota.number", "wb");
	if (file == NULL) {
		fputs("iota: i/o error", stderr);
		return 2;
	}
	number++;
	fwrite(&number, sizeof(int), 1, file);
	fclose(file);

	return 0;
}

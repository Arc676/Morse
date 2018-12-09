//Copyright (C) 2018  Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3).

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdio.h>

#include "morse.h"

void usage() {
	fprintf(stderr, "Usage: morse {-m morse code | -t normal text}\n");
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		usage();
		return 1;
	}
	char* message = argv[2];
	int len = strlen(message);
	if (!strcmp(argv[1], "-t")) {
		char* output = textToMorse(message, len);
		printf("%s\n", output);
		free(output);
	} else if (!strcmp(argv[1], "-m")) {
		char* output = morseToText(message, len);
		printf("%s\n", output);
		free(output);
	} else {
		usage();
		return 1;
	}
	return 0;
}

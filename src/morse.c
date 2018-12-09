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

#include "morse.h"

const char* morse[36] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....", "..", ".---", "-.-", ".-..", "--", "-.",
	"---", ".--.", "--.-", ".-.", "...", "-", "..-",
	"...-", ".--", "-..-", "-.--", "--..",
	"-----", ".----", "..---", "...--", "....-", ".....",
	"-....", "--...", "---..", "----.",
};

char* textToMorse(const char* message, int len) {
	char output[7 * len];
	memset(output, 0, sizeof(output));
	int pos = 0;
	for (int i = 0; i < len; i++) {
		char c = message[i];
		if ('a' <= c && c <= 'z') {
			c += 'A' - 'a';
		}
		if (c == ' ') {
			sprintf(output + pos, "       ");
			pos += 7;
		} else if ('A' <= c && c <= 'Z') {
			const char* m = morse[c - 'A'];
			sprintf(output + pos, "%s   ", m);
			pos += strlen(m) + 3;
		} else if ('0' <= c && c <= '9') {
			const char* m = morse[c - '0' + 26];
			sprintf(output + pos, "%s   ", m);
			pos += strlen(m) + 3;
		}
	}
	char* ret = malloc(strlen(output));
	memcpy(ret, output, strlen(output));
	return ret;
}

char* morseToText(const char* message, int len) {
}

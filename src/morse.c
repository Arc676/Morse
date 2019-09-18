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

const char chars[63] = {
	0, 0, 'E', 'T', 'I', 'N', 'A', 'M',
	'S', 'D', 'R', 'G', 'U', 'K', 'W', 'O',
	'H', 'B', 'L', 'Z', 'F', 'C', 'P', 0,
	'V', 'X', 0, 'Q', 0, 'Y', 'J', 0,
	'5', '6', 0, '7', 0, 0, 0, '8',
	0, 0, 0, 0, 0, 0, 0, '9',
	'4', 0, 0, 0, 0, 0, 0, 0,
	'3', 0, 0, 0, '2', 0, '1'
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
			sprintf(output + pos, "    ");
			pos += 4;
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
	char* ret = malloc(strlen(output) + 1);
	memcpy(ret, output, strlen(output));
	ret[strlen(output)] = 0;
	return ret;
}

char* morseToText(const char* message, int len) {
	char output[len];
	memset(output, 0, sizeof(output));
	int mpos = 0;
	int pos = 0;
	int bit = 1;
	for (int i = 0; i <= len; i++) {
		char c = i < len ? message[i] : ' ';
		switch (c) {
		case '-':
			pos |= bit;
			break;
		case '.':
			break;
		case ' ':
			pos |= bit;
			if (bit != 1) {
				output[mpos++] = chars[pos];
				int spaces = 1;
				// count number of spaces
				for (i++; message[i] == ' '; i++, spaces++);
				i--;
				if (spaces == 7) {
					output[mpos++] = ' ';
				}
			}
			pos = 0;
			bit = 1;
			continue;
		default:
			return NULL;
		}
		bit <<= 1;
	}
	char* ret = malloc(strlen(output));
	memcpy(ret, output, strlen(output));
	return ret;
}

void stdfree(char* str) {
	free(str);
}

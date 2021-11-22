//Copyright (C) 2018-21 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3).

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef MORSE_H
#define MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code translations of alphanumeric characters
extern const char* morse[36];

// Lookup table for alphanumeric translations of Morse code
extern const char chars[63];

/**
 * Converts a message to morse code
 * @param message Message text
 * @param len Length of message
 * @return Morse code version of the message (allocated on heap)
 */
char* textToMorse(const char* message, int len);

/**
 * Converts a message from morse code to text
 * @param message Message text
 * @param len Length of message
 * @return Text version of the message (allocated on heap)
 */
char* morseToText(const char* message, int len);

/**
 * Alias for standard memory deallocation for Python frontend
 * @str String to deallocate
 */
void stdfree(char* str);

#endif

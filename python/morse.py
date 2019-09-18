# Copyright (C) 2019  Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation (version 3).

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import ctypes

libmorse = ctypes.cdll.LoadLibrary("../libmorse.so")

textToMorse = libmorse.textToMorse
textToMorse.argtypes = [ctypes.c_char_p, ctypes.c_int]
textToMorse.restype = ctypes.POINTER(ctypes.c_char)

morseToText = libmorse.morseToText
morseToText.argtypes = [ctypes.c_char_p, ctypes.c_int]
morseToText.restype = ctypes.POINTER(ctypes.c_char)

free = libmorse.stdfree
free.argtypes = [ctypes.c_char_p]

while True:
	mode = input("To morse (default) or to text (nonempty)? ")
	msg = input("Enter message: ")
	length = len(msg)
	if length == 0:
		break
	cout = None
	msg = ctypes.c_char_p(msg.encode("utf-8"))
	if len(mode) > 0:
		cout = morseToText(msg, length)
	else:
		cout = textToMorse(msg, length)
	output = None
	try:
		output = ctypes.cast(cout, ctypes.c_char_p).value.decode("utf-8")
		print(f"Output: {output}")
	except UnicodeDecodeError:
		print("Unicode decoding failed. Raw bytes:")
		print(ctypes.cast(cout, ctypes.c_char_p).value)
	free(cout)

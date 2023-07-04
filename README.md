# Sorting methods in C
This program runs various sorting methods and outputs their required moves and compares:
- insert sort
- quick sort
- shell sort
- heap sort
## Installation (make commands)
use the included makefile and run ```make``` to make the executable. The options are as follows:
| flag | description |
| --------- | -------|
| all | create all files |
| sorting | create sorting binary (identical to "all" or no flag) |
| tidy | remove object (.o) files |
| clean | remove object (.o) and executable binary files |
| format | formats all code using clang-format |

## Usage
run ./sorting and add whatever flags you would like:

| Flag | Description |
| --- | --------------|
| -a | run all sorting methods |
|-p | lets you change the amount of printed elements after sorting |
| -r | lets you choose the seed |
| -n | lets you choose the number of elements |
| -h | prints out help |
| -i | runs insertion sort |
| -q | runs quick sort |
| -e | runs heap sort |
| -s | runs shell sort |
## CREDITS
My professor, Darrell Long, has included this in "set.h", which presumably applies to all the .h files (I've since forgotten which, if any, that I created). He also gave us pseudocode for all the sorting methods:
```
BSD 2-Clause License
Copyright (c) 2021, Darrell Long
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```
## Known Errors
There are none.

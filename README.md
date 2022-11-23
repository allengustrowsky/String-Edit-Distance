# Minimum String Edit Distance Calculator
## Overview
Console application that takes two strings as input and uses dynamic programming to calculate the minimum number of edits to transform the first string into the second. Also provides a string representing the edits needed. Below are the edit operations and their associated symbols:
- `insert`: `+`
- `delete`: `-`
- `replace`: `/`
- `keep`: `^`

For `insert` and `replace` the new character will be appended after the symbol: `+u` means "insert u" and `/w` means "replace the character in the original string with w."

## Usage
After compiling and running, enter two separate strings on separate lines:

`algorithms are essential`\
`antimony is an element`

The resulting minimum number of edits and edit string will be output:

`17:  ^+n/t/i/m/o/n/y/ /i^^^-/n^^+l/e/m^^^---`

After this, two more strings can be entered, and the process will repeat. To break out of the loop and end the program, just enter an empty line for the first string.

## Limitations
Do not put `+`, `-`, `/`, or `^` into the input strings since those are like keywords in this program.  Also, do not entering an empty string for the second input and do not enter only spaces for either input string.
<!-- don't use special chars for ops-->
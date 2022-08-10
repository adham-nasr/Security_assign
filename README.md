# Security_assign

Approach:

find Characters in text by  xoring bytes in same column ( if 7th bit is not '1' and bytes are not equal then both are characters )

Use found characters to find spaces by  xoring bytes in same column ( if 7th bit is equal to '1'  then second byte is a space )

use found spaces to retrive characters in same column

guess 4th sentence

use guessed characters to deduce all characters in the same column using XOR property  (  m1 ^ m2 = c1 ^ c2  >>  m2 = m1 ^ (c1^c2) )

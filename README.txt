HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h

ToggleBit
(0, 31) -2147483648
(5, 0) 4
(5, 2) 1
(0, 0) 1
(-1, 31) 2147483647
(0, 15) 32768
(1, 0) 0

Get MSB
(2) 1
(0x80000000) 31
(0x0) -1
(1) 0
(0xFFFFFFFF) 31
(-1) 31

ClearBitRange
(73, 1, 3) 65
(0,0,31) 0
(-2147483647,31,31) 1
(2147483647,31,0) 2147483647
(2147483647,0,31) 0

RotateLeft
(5, 1) 10
(5, 2) 20
(0x80000000,1) 1
(1,31) 2147483648
(0,31) 0

SwapOddEvenBits
(23) 43
(0) 0
(0xFFFFFFFF) -1
(1) 2
(0x80000000) -1073741824

├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c

Positive cases
(0x00, 0x7F, 0x000000)
1.0
(0x00, 0x7F, 0x200000)
1.25
(0x00, 0x7F, 0x400000)
1.5
(0x00, 0x7E, 0x000000)
0.5
(0x00, 0x7E, 0x200000)
0.625

Negative cases
(0x01, 0x7F, 0x000000)
-1.0
(0x01, 0x7F, 0x200000)
-1.25
(0x01, 0x7F, 0x400000)
-1.5
(0x01, 0x7E, 0x000000)
-0.5
(0x01, 0x7E, 0x200000)
-0.625



├── MyIntegers.h
├── MyIntegers.c

('S', '2', 0x80000000) 00000000
('2','S',0) 00000000
('2','S',5) 00000005
('2','S',-5) fffffffb
('S','2',5) 00000005
('S','2',-5) 80000005
('2','S',0x80000000) undefined
('2','2',0x80000000) 80000000
('S','S',0x80000000) 80000000
('X','S',0x80000000) error
('S','4',0x80000000) error
└── README.txt  


1- write your name and SBU ID in each of the file.

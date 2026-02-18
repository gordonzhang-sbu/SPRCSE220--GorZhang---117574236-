CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
CRIT = -lcriterion

OBJS = MyBitManipulation.o Myfloat.o MyIntegers.o
TARGET = hw3
TEST_TARGET = test_hw3

all: $(TARGET)

$(TARGET): HW3_main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) HW3_main.o $(OBJS)

HW3_main.o: HW3_main.c
	$(CC) $(CFLAGS) -c HW3_main.c

MyBitManipulation.o: MyBitManipulation.c MyBitManipulation.h
	$(CC) $(CFLAGS) -c MyBitManipulation.c

Myfloat.o: Myfloat.c Myfloat.h
	$(CC) $(CFLAGS) -c Myfloat.c

MyIntegers.o: MyIntegers.c MyIntegers.h
	$(CC) $(CFLAGS) -c MyIntegers.c

# -------------------------
# Criterion Tests
# -------------------------
test: $(TEST_TARGET)

$(TEST_TARGET): test_hw3.c $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) test_hw3.c $(OBJS) $(CRIT)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

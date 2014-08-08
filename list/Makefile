SRC_FILES=test.cpp linkList2.cpp
OBJ_FILES=$(patsubst %.cpp, %.o, ${SRC_FILES})
#VPATH = src

CFLAGS = -c -o
LDFLAGS = -o

linkListTest: $(OBJ_FILES)
	g++ -o linkListTest ${OBJ_FILES}

#%.o:%.c
#	g++ ${CFLAGS} -o $@ $
MAIN_HDRS = test.h linkList2.h list.h
LINKLIST_HDRS = linkList2.h list.h

test.o : ${MAIN_HDRS} test.cpp
	g++ -c test.cpp
linkList.o : ${LINKLIST_HDRS} linkList2.cpp
	g++ -c linkList2.cpp

.PHONY:clean
clean:
	rm *.o linkListTest



#
# Specifiy the target
all:	FB

FB:	CA3.o	FBLUser.o	FBLUserLL.o	FBLPost.o	FBLPostLL.o	FBLComment.o	FBLCommentLL.o
	g++ -g CA3.o FBLUser.o FBLUserLL.o FBLPost.o FBLPostLL.o FBLComment.o FBLCommentLL.o -o FB	


# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
CA3.o:	CA3.cpp	FBLUser.h FBLUserLL.h	FBLPost.h	FBLPostLL.h	FBLComment.o	FBLCommentLL.o
	g++ -c -g CA3.cpp -o CA3.o

# Specify how the object files should be created from source files
FBLUser.o:	FBLUser.cpp	FBLUser.h	FBLUserLL.h	FBLPost.h	FBLPostLL.h	FBLComment.h	FBLCommentLL.h
	g++ -c -g FBLUser.cpp -o FBLUser.o

FBLUserLL.o:	FBLUserLL.cpp	FBLUserLL.h	FBLUser.h	FBLPost.h	FBLPostLL.h	FBLComment.h	FBLCommentLL.h
	g++ -c -g FBLUserLL.cpp -o FBLUserLL.o

FBLPost.o:	FBLPost.cpp	FBLPost.h	FBLUser.h	FBLUserLL.h	FBLPostLL.h	FBLComment.h	FBLCommentLL.h
	g++ -c -g FBLPost.cpp -o FBLPost.o

FBLPostLL.o:	FBLPostLL.cpp	FBLPostLL.h	FBLUser.h	FBLUserLL.h	FBLPost.h	FBLComment.h	FBLCommentLL.h
	g++ -c -g FBLPostLL.cpp -o FBLPostLL.o

FBLComment.o:	FBLComment.cpp	FBLComment.h	FBLUser.h	FBLUserLL.h	FBLPost.h	FBLPostLL.h	FBLCommentLL.h
	g++ -c -g FBLComment.cpp -o FBLComment.o

FBLCommentLL.o:	FBLCommentLL.cpp	FBLCommentLL.h	FBLUser.h	FBLUserLL.h	FBLPost.h	FBLPostLL.h	FBLComment.h
	g++ -c -g FBLCommentLL.cpp -o FBLCommentLL.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o FB	


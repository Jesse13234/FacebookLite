#ifndef FBLCOMMENTLL_H
#define FBLCOMMENTLL_H
#include <iostream>
#include <stdio.h>
#include "FBLComment.h"

using namespace std;

class CommentNode
{
	public:
		FBLComment * data;
		CommentNode * next;
		CommentNode * previous;
		CommentNode(FBLComment * a);
			
};

class FBLCommentLL
{
	public:	
		CommentNode * head;
		CommentNode * current;
		CommentNode * tail;
		FBLCommentLL();
		~FBLCommentLL();
		void insert(FBLComment * a);
		void forward();
		void backward();
					
};
		

#endif

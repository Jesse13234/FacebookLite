#ifndef FBLPOST_H
#define FBLPOST_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include "FBLCommentLL.h" 

using namespace std;

class FBLPost {
	public:
		int likes;
		string post;
		FBLCommentLL * comment;
		FBLPost * wallPost;
		//vector<string> comments;
		FBLPost();
		FBLPost(string post, int likes, FBLPost * wallPost);
		void increaseLikes();
		void commentPost(string comment);
		void printFoward();
		void printBackward();
};

#endif

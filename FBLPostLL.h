#ifndef FBLPOSTLL_H
#define FBLPOSTLL_H
#include "FBLPost.h"


using namespace std;

class PostNode
{
	public:
		FBLPost * data;
		PostNode * next;
		PostNode(FBLPost * a);
			
};

class FBLPostLL
{
	public:	
		PostNode * head;
		PostNode * current;
		FBLPostLL();
		~FBLPostLL();
		void insert(FBLPost * a);
		void printLast();
		void deleteLast();
		void print();
		void wallPrint();
		void like();
		void comment(string userComment);
		void readFoward();
		void readBackward();
					
};
		

#endif

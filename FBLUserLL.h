#ifndef FBLUSERLL_H
#define FBLUSERLL_H
#include "FBLUser.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Node
{
	public:
		FBLUser * data;
		Node * next;
		Node * previous;
		Node(FBLUser * a);
			
};

class FBLUserLL
{
	public:	
		Node * head;
		Node * current;
		FBLUserLL();
		~FBLUserLL();
		void insert(FBLUser * a);
		FBLUser* doesUserExist(string userID, string password);
		FBLUser* doesFriendExist(string userID);
		void print();
		void printUserList();
		FBLUserLL sortUsers();
		vector<FBLUser *> sorting(vector<FBLUser *> left, vector<FBLUser *> right);
		vector<FBLUser *> mergeSort(vector<FBLUser *> unsorted);
		
	private:
		//FBLUserLL(const FBLUserLL &c);
					
};
		

#endif

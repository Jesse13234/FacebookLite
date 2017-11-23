#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include "FBLCommentLL.h"

using namespace std;

CommentNode :: CommentNode (FBLComment * a)
{
	data = a;
	next = nullptr;
	previous = nullptr;

}

FBLCommentLL :: FBLCommentLL()
{
	head = nullptr;
	current = nullptr;
	tail = nullptr;
}

FBLCommentLL::~FBLCommentLL()
{
	CommentNode * temp;
	while(temp != nullptr) {
		temp = head -> next;
		delete head->data;
		delete head;
		head = temp;
	}
}

void FBLCommentLL::insert(FBLComment * a) 
{
	CommentNode * newNode = new CommentNode(a);
	CommentNode * temp = head;
	
	if(head == nullptr){
		head = newNode;
		newNode->next = nullptr;
		cout << head->data->comment << endl;
	}
	else{
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->previous = temp;
		newNode->next = nullptr;
		tail = newNode;
				
	}
}

void FBLCommentLL::forward(){
	CommentNode * temp = head;

	if(temp == nullptr){
		cout << "No comment to read" << endl;
	}
	else{
		while(temp != nullptr){
			cout << temp->data->comment << endl;
			temp = temp->next;
		}
	}
}

void FBLCommentLL::backward(){
	CommentNode * temp = tail;

	if(temp == nullptr){
		cout << "No comment to read" << endl;
	}
	else{
		while(temp != nullptr){
			cout << temp->data->comment << endl;
			temp = temp->previous;
		}
	}
}










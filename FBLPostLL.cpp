#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include "FBLPostLL.h"

using namespace std;

PostNode :: PostNode (FBLPost * a)
{
	data = a;
	next = nullptr;

}

FBLPostLL :: FBLPostLL()
{
	head = nullptr;
	current = nullptr;
}

FBLPostLL::~FBLPostLL()
{
	PostNode * temp;
	while(temp != nullptr) {
		temp = head -> next;
		delete head->data;
		delete head;
		head = temp;
	}
}

void FBLPostLL::insert(FBLPost * a) 
{
	PostNode * newNode = new PostNode(a);
	PostNode * temp = head;
	if(head == nullptr){
		head = newNode;
		newNode->next = nullptr;
	}
	else{
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = nullptr;		
	}
}

void FBLPostLL::deleteLast(){
	PostNode * temp = head;

	if(temp == nullptr){
		cout << "Nothing to read." << endl;
	}
	else{
		//cout << temp->data->post << endl;
		temp = head -> next;
		delete head;
		head = temp;
	}
}

void FBLPostLL::print(){ //prints out entire list
	PostNode * temp = head;

	if(temp == nullptr){
		cout << "Nothing on your wall/feed." << endl;
	}
	else{
		while(temp != nullptr){
			cout << temp->data->post << endl;
			temp = temp->next;
		}
	}
}

void FBLPostLL::wallPrint(){
	PostNode * temp = head;

	if(temp == nullptr){
		cout << "Nothing on your wall/feed." << endl;
	}
	else{
		while(temp != nullptr){
			cout << temp->data->likes << " " << temp->data->post << endl;
			temp = temp->next;
		}
	}
}

void FBLPostLL::printLast(){
	PostNode * temp = head;

	if(temp == nullptr){
		cout << "Nothing to read." << endl;
	}
	else{
		cout << temp->data->post << endl;
	}
}	

void FBLPostLL::like(){
	PostNode * temp = head;

	if(temp==nullptr){
		cout << "Nothing to like." << endl;
	}
	else{
		temp->data->increaseLikes();
	}
}
	
void FBLPostLL::comment(string userComment){
	PostNode * temp = head;

	if(temp==nullptr){
		cout << "Nothing to comment." << endl;
	}
	else{
		temp->data->commentPost(userComment);
	}
}

void FBLPostLL::readFoward(){
	PostNode * temp = head;
	
	if(temp==nullptr){
		cout << "No post to read comments from." << endl;
	}
	else{
		temp->data->printFoward();
	}
}

void FBLPostLL::readBackward(){
	PostNode * temp = head;

	if(temp==nullptr){
		cout << "No post to read comments from." << endl;
	}
	else{
		temp->data->printBackward();
	}
}
		


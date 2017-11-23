#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include "FBLUserLL.h"

using namespace std;

Node :: Node (FBLUser * a)
{
	data = a;
	next = nullptr;
	//previous = nullptr;

}

FBLUserLL :: FBLUserLL()
{
	head = nullptr;
	current = nullptr;

}

//Creates a hardcopy/deep copy of the linked list
/*FBLUserLL::FBLUserLL(const FBLUserLL &c)
{
	if(head == NULL) {
		return;
	}
	
	Node * chead = new Node (head -> data);
	Node * curr = chead;

	for(Node * temp = c.head; temp != NULL; temp = temp -> next){
		curr -> next = current -> next;
		curr = curr -> next;
	}
}*/

FBLUserLL::~FBLUserLL()
{
	Node * temp;
	while(temp != nullptr) {
		temp = head -> next;
		delete head->data->wall;
		delete head->data->feedList;
		delete head->data;
		delete head;
		head = temp;
	}
}

void FBLUserLL::insert(FBLUser * a) 
{
	Node * newNode = new Node(a);
	Node * temp = head;
	
	if(head == nullptr){
		head = newNode;
		newNode->next = nullptr;
	}
	else{
		while(temp->next != nullptr){
			temp = temp->next;
		}
		//newNode->previous = temp;
		temp->next = newNode;
		newNode->next = nullptr;		
	}
}

void FBLUserLL::print(){
	Node * temp = head;

	if(temp == nullptr){
		cout << "Head is null" << endl;
	}
	else{
		while(temp != nullptr){
			cout << head->data->userID << " THIS IS THE USERID" << endl;
			cout << head->data->password << " THIS IS THE PASSWORD" << endl;
			temp = temp->next;
		}
	}
}

FBLUser* FBLUserLL::doesUserExist(string userID, string password){
	Node * temp = head;
	
	while(temp != nullptr){
		if(temp->data->userID == userID && temp->data->password == password){
			return temp->data;
		}
		else{
			temp = temp->next;
		}
	}
	return nullptr;
}

FBLUser* FBLUserLL::doesFriendExist(string userID){
	Node * temp = head;
	
	while(temp != nullptr){
		if(temp->data->userID == userID){
			return temp->data;
		}
		else{
			temp = temp->next;
		}
	}
	return nullptr;
}

void FBLUserLL::printUserList(){
	Node * temp = head;

	if(temp == nullptr){
		cout << "No users exist." << endl;
	}
	else{
		while(temp != nullptr){
			cout << temp->data->lastName << ", " << temp->data->firstName << " <" << temp->data->userID << ">" << endl;
			temp = temp->next;
		}
	}
}

FBLUserLL FBLUserLL::sortUsers(){
	vector<FBLUser *> userList;
	Node * temp = head;
	FBLUserLL newList;
	
	if(temp == nullptr){
		cout << "No users to user." << endl;
	}
	else{
		while(temp != nullptr){
			userList.push_back(temp->data);
			temp = temp->next;
		}
		userList = mergeSort(userList);
		for(int i=0; i < userList.size(); i++){
			cout << userList[i]->lastName << endl;
		}
		for(int i=0; i < userList.size(); i++){
			Node * newNode = new Node(userList[i]);
			if(i == 0){
				newList.head = newNode;
				newNode->next = nullptr;
			}
			else /*if(i < userList.size() -1)*/{
				newNode->next = newList.head;
				newList.head = newNode;
			}
		}
	}
	return newList;
}

vector<FBLUser *> FBLUserLL::sorting(vector<FBLUser *> left, vector<FBLUser *> right){

	vector<FBLUser *> sorted;
	
	while(left.size() != 0 && right.size() != 0){
		if((*left.begin())->lastName > (*right.begin())->lastName){
			sorted.push_back(left[0]);
			left.erase(left.begin());
		}
		else{
			sorted.push_back(right[0]);
			right.erase(right.begin());
		}		
	}
	if(left.size() != 0){
		for(int i = 0; i < left.size(); i++){
			sorted.push_back(left[i]);
		}
	}
	else{
		for(int i = 0; i < right.size(); i++){
			sorted.push_back(right[i]);
		}
	}
	return sorted;
}

vector<FBLUser *> FBLUserLL::mergeSort(vector<FBLUser *> unsorted){

	vector<FBLUser *> left;
	vector<FBLUser *> right;
		
	if(unsorted.size() <= 1){
		return unsorted;
	}
	else{
		for(int i=0; i<unsorted.size(); i++){
			if(i%2 == 0){
				left.push_back(unsorted[i]);
			}
			else{
				right.push_back(unsorted[i]);
			}
		}
		
		left = mergeSort(left);
		right = mergeSort(right);	
	
		return sorting(left, right);
	}		
}









		
		


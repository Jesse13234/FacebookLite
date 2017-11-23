#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "FBLUser.h"

using namespace std;

FBLUser :: FBLUser () {
	userID = " ";
	password = " ";
	firstName = " ";
	lastName = " ";
	vector<FBLUser *> friendList;
	wall = new FBLPostLL();
	feedList = new FBLPostLL();
}

FBLUser :: FBLUser(string userID, string password, string firstName, string lastName){
	this->userID = userID;
	this->password = password;
	this->firstName = firstName;
	this->lastName = lastName;
	wall = new FBLPostLL();
	feedList = new FBLPostLL();
}

/*oid FBLUser :: insertPost(string post){
	FBLPostLL postList;
	wall->insert(new FBLPost(post));
}*/

void FBLUser :: addFriendList(FBLUser * aFriend){
	friendList.push_back(aFriend);
}

void FBLUser :: printFriendList(){
	if(friendList.size() == 0){
		cout << "You have no friends." << endl;
	}
	else{
		for (unsigned int i =0; i < friendList.size();i++){
			cout << friendList[i]->userID;
			cout << endl;
		}	
	}
}

bool FBLUser :: checkFriendList(FBLUser * aFriend){
	if(userID == aFriend->userID){
		cout << "You can't friend yourself." << endl;
		return false;
	}
	for (vector<FBLUser *>::iterator i = friendList.begin(); i != friendList.end(); ++i){
		if(*i == aFriend){
			cout << "You already have this friend in your friend list." << endl;
			return false;
		}
	}
	return true;
}

void FBLUser :: printWall(){
	wall->wallPrint();
}

void FBLUser :: printFeed(){
	feedList->print();
}





#ifndef FBLUSER_H
#define FBLUSER_H
#include <vector>
#include "FBLPostLL.h"
using namespace std;

class FBLUser {

	public:
		FBLUser();
		string userID;
		string password;
		string firstName;
		string lastName;
		vector<FBLUser *> friendList; 		
		FBLPostLL * wall;
		FBLPostLL * feedList;
		FBLUser(string userID, string password, string firstName, string lastName);
		void insertPost(string post);
		void addFriendList(FBLUser * aFriend);
		bool checkFriendList(FBLUser * aFriend);
		void printFriendList();
		void printWall();
		void printFeed();
		
};

#endif

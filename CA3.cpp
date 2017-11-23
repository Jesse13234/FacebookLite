#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include "FBLUserLL.h"

using namespace std;

bool isFirstMenu = false;
bool isSecondMenu = false;
bool isThirdMenu = false;

FBLUser * checkUserExist(FBLUserLL &list, string userID){
	if(list.doesFriendExist(userID) == nullptr){
		cout << "This user does not exist" << endl;
		return nullptr;
	}
	return list.doesFriendExist(userID);
}


void firstMenu(bool isFirstMenu, FBLUserLL &list);
void secondMenu(FBLUser * user, FBLUserLL &list);

void thirdMenu(FBLUser * user, FBLUserLL &list, FBLPostLL * feed){
	
	string firstWord;
	string input;

	while(isThirdMenu == false){ 
		cout << "Choose one of the 5 following options: " << endl;
		cout << "LIKE" << endl;
		cout << "COMMENT <text>" << endl;
		cout << "READ_AZ" << endl;
		cout << "READ_ZA" << endl;
		cout << "DONE" << endl;
		cout << "--------------------------------------------------" << endl;	

		getline(cin, input);
		istringstream iss(input);
		iss >> firstWord;
		
		if(firstWord == "LIKE" || firstWord == "COMMENT" || firstWord == "READ_AZ" || firstWord == "READ_ZA" || firstWord == "DONE"){
			isThirdMenu = true;
		}
		else{
			isThirdMenu = false;
			cout << "The command enter was invalid." << endl;
		}
	}
	
	if(firstWord == "LIKE"){ // only likes the first orginal post on user wall but never moves increases the likes on the second one
		feed->like();
		//feed->head->data->increaseLikes();
		isThirdMenu = false;
		thirdMenu(user, list, feed);
	}
		
	else if(firstWord == "COMMENT"){
		int pos = input.find("COMMENT");
		string userComment = input.substr(pos+8);
		feed->comment(userComment);
		isThirdMenu = false;
		thirdMenu(user, list, feed);
	}

	else if(firstWord == "READ_AZ"){
		feed->readFoward();
		isThirdMenu = false;
		thirdMenu(user, list, feed);
	}

	else if(firstWord == "READ_ZA"){
		feed->readBackward();
		isThirdMenu = false;
		thirdMenu(user, list, feed);
	}

	else{
		user->feedList->deleteLast();
		isThirdMenu = false;
		secondMenu(user, list);
	}
}
		

void secondMenu(FBLUser * user, FBLUserLL &list){
	
	FBLUser * userFriend;
	string userID;	
	string firstWord;
	string input;
	string post;
	
	while(isSecondMenu == false){ 
		cout << "Choose one of the 7 following options: " << endl;
		cout << "POST <text>" << endl;
		cout << "READ" << endl;
		cout << "FRIEND" << endl;
		cout << "MYFRIENDS" << endl;
		cout << "MYWALL" << endl;
		cout << "MYFEED" << endl;
		cout << "LOGOUT" << endl;
		cout << "--------------------------------------------------" << endl;		

		getline(cin, input);
		istringstream iss(input);
		iss >> firstWord;
		
		if(firstWord == "POST" || firstWord == "LOGOUT" || firstWord == "READ" || firstWord == "FRIEND" || firstWord == "MYFRIENDS" || firstWord == "MYWALL" || firstWord == "MYFEED"){
			isSecondMenu = true;
		}
		else{
			isSecondMenu = false;
			cout << "The command enter was invalid." << endl;
		}
	}
	
	if(firstWord == "POST"){
		int pos = input.find("POST");
		string postInput = input.substr(pos+5);
		FBLPost * wallP = new FBLPost(postInput, 0, nullptr);
		user->wall->insert(wallP);
		//user->feedList->insert(new FBLPost(postInput, 0, user->wall->head->data));
		for (unsigned int i =0; i < user->friendList.size();i++){
			user->friendList[i]->feedList->insert(new FBLPost(postInput, 0, wallP));
		}
		isSecondMenu = false;
		secondMenu(user, list);
		
	}
	
	else if(firstWord == "READ"){
		user->feedList->printLast();
		isSecondMenu = false;
		thirdMenu(user, list, user->feedList);
	}
	
	else if(firstWord == "FRIEND"){
		istringstream iss(input);
		iss >> firstWord;
		iss >> userID;
		userFriend = checkUserExist(list, userID);
		if(userFriend != nullptr){
			if(user->checkFriendList(userFriend)){;
				user->addFriendList(userFriend);
				userFriend->addFriendList(user);
				
			}
		}
		isSecondMenu = false;
		secondMenu(user, list);
	}

	else if(firstWord == "MYFRIENDS"){
		user->printFriendList();
		isSecondMenu = false;
		secondMenu(user, list);
	}

	else if(firstWord == "MYWALL"){
		user->printWall();
		isSecondMenu = false;
		secondMenu(user, list);
	}

	else if(firstWord == "MYFEED"){
		user->printFeed();
		isSecondMenu = false;
		secondMenu(user, list);
	}
	
	else{
		isSecondMenu = false;
		isFirstMenu = false;
		firstMenu(isFirstMenu, list);
	}
}

void firstMenu(bool isFirstMenu, FBLUserLL &list){

	string input;
	string firstWord;
	string userID;
	string password;
	string firstName;
	string lastName;

	while(isFirstMenu == false){
		cout << "Choose one of the 3 following options: " << endl;
		cout << "CREATE <Userid> <Password> <First> <Last>" << endl;
		cout << "LOGIN <Userid> <Password>" << endl;
		cout << "USERS" << endl;
		cout << "SORTUSERS" << endl;
		cout << "QUIT" << endl;
		cout << "--------------------------------------------------" << endl;	
	
		getline(cin, input);
		istringstream iss(input);
		iss >> firstWord;
		
		if(firstWord == "CREATE" || firstWord == "LOGIN" || firstWord == "QUIT" || firstWord == "USERS" || firstWord == "SORTUSERS"){
			isFirstMenu = true;
		}
		else{
			isFirstMenu = false;
			cout << "The command enter was invalid." << endl;
		}
	}

	if(firstWord == "CREATE"){
			istringstream iss(input);
			iss >> firstWord;
			iss >> userID;
			iss >> password; 
			iss >> firstName;		
			iss >> lastName; //prompt if no first name or last or user or pass
			if(firstName == "" || lastName == ""){
				cout << "You did not enter a first or last name." << endl;
				isFirstMenu = false;
				firstMenu(isFirstMenu, list);
			}
			else{
				FBLUser * tempUser = new FBLUser(userID, password, firstName, lastName);
				list.insert(tempUser);
				isFirstMenu = false;
				firstMenu(isFirstMenu, list);	
			}
	}

	else if(firstWord == "LOGIN"){
			istringstream iss(input);
			iss >> firstWord;
			iss >> userID;
			iss >> password;
			if(list.doesUserExist(userID, password) == nullptr){
				cout << "UserID or password was entered was incorrect." << endl;
				isFirstMenu = false;
				firstMenu(isFirstMenu, list);
			}
			else{
				secondMenu(list.doesUserExist(userID, password), list);
			}
	}
	
	else if(firstWord == "USERS"){
		list.printUserList();
		isFirstMenu = false;
		firstMenu(isFirstMenu, list);	
	}

	else if(firstWord == "SORTUSERS"){
		list = list.sortUsers();
		isFirstMenu = false;
		firstMenu(isFirstMenu, list);	
	}

	else{
		cout << "Goodbye." << endl;
	}

}

int main(int argc, char *argv[]){

	FBLUserLL list;

	firstMenu(isFirstMenu, list);
	return 0;
}	



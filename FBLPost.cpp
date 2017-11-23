#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include "FBLPost.h"

using namespace std;

FBLPost :: FBLPost (){
	post = " ";
	likes = 0;
	comment = new FBLCommentLL();
	
}

FBLPost :: FBLPost(string post, int likes, FBLPost * wallPost){
	this->post = post;
	this->likes = likes;
	this->wallPost = wallPost;
	comment = new FBLCommentLL();
}

void FBLPost :: increaseLikes(){
	wallPost->likes++;
}

void FBLPost :: commentPost(string comment){
	FBLComment * newComment = new FBLComment(comment);
	wallPost->comment->insert(newComment);
}

void FBLPost :: printFoward(){
	wallPost->comment->forward();
	/*
	if(wallPost->comments.size() == 0){
		cout << "You have no comments." << endl;
	}
	else{
		for (unsigned int i =0; i < wallPost->comments.size();i++){
			cout << wallPost->comments[i];
			cout << endl;
		}	
	}*/
}

void FBLPost :: printBackward(){
	wallPost->comment->backward();
	/*
	if(wallPost->comments.size() == 0){
		cout << "You have no comments." << endl;
	}
	else{
		for(unsigned int i = comments.size()-1; i > 0; i--){
			cout << comments[i];
			cout << endl;
		}
		reverse(wallPost->comments.begin(), wallPost->comments.end());
		for (unsigned int i =0; i < wallPost->comments.size();i++){
			cout << wallPost->comments[i];
			cout << endl;
		}
		reverse(wallPost->comments.begin(), wallPost->comments.end());	
	}*/
}

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "FBLComment.h"

using namespace std;

FBLComment :: FBLComment (){
	comment = " ";
	
}

FBLComment :: FBLComment(string comment){
	this->comment = comment;
}



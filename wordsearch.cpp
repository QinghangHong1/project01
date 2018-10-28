#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "wordsearch.h"


using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}
void word_search(string word,Word word_array[],int length){
	  int word_exist=false;
	  for(int a=0;a<length;a++){
		  if(word==word_array[a].get_word()){
			  word_array[a].printing();
			  word_exist=true;
			  break;
			  
		  }
	  }
  
	  if(!word_exist){
		  cout<<"The word does not exist."<<endl;
	  }
  }


int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();
  Word word_array[1000];
  int used=0;

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }

	
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    while(true){
      fin>>word;
      if(fin.eof()) { break;}
      else {
		  bool exist=false;
		  for(int j=0;j<used;j++){//if the word exist in the array,update the bag
			  if(word==word_array[j].get_word()){
				  word_array[j].addition(files[i]);
				  exist=true;
				  
			  }
		  }
		  if(!exist){//if the word does not exist in the array, create a word object for it and initialize
			  word_array[used].set_word(word);
			  word_array[used].addition(files[i]);
			  used++;
		  }
			  

	// Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
	// Use these two strings to search/insert in your array/list of words.
      }
    }
    fin.close();
  }
  string user_word;
  cout<<"Enter word: ";
  cin>>user_word;
  word_search(user_word,word_array,used);
  
  return 0;

}




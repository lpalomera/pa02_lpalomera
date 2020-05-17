#include <iostream>
#include <vector>
#include "heap.h"
#include <sstream> 
#include <fstream>
#include <string>
#include <iterator>
using namespace std;


int main(int argc, char *argv[]){
    minMaxHeap h1;
  /*  
    h1.insert(1);
    h1.insert(4);
    h1.insert(8);
    h1.insert(15);
    h1.insert(21);
    h1.insert(41);
    h1.insert(83);
    h1.insert(165);
    h1.insert(331);
    cout<<"----------------"<<endl; 
*/

    ifstream myfile;
    ///autograder/submission/PA2_dataset.txt
    
    myfile.open("autograder/submission/PA2_dataset.txt");       
    char output[100];
    int convert;
    int z=0;
    if (myfile.is_open()) {
        while (!myfile.eof() && z<9999) {
            z++;
            myfile >> output;
            convert=stoi(output);
            h1.insert2(convert);
            }
    }
    myfile.close();


 string parse = argv[1];
 vector<string> phrase;
 string word="";
 string::iterator it = parse.begin();
 bool statement=false;
 string x; 
 
 
 for (it; it != parse.end()+1; it++) {
   
   if(statement==true){
     if (phrase[0]=="printHeap"){
       h1.printHeap();
       //cout<<"printHeap"<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="getMin"){
       h1.getMin();
       //cout<<"getMin"<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="getMax"){
       h1.getMax();
       //cout<<"getMax"<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="deleteMin"){
       h1.deleteMin();
       //cout<<"deleteMin"<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="deleteMax"){
       h1.deleteMax();
       //cout<<"deleteMax"<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="insert"){
       h1.insert(stoi(phrase[1]));
       //cout<<"insert: "<<phrase[1]<<endl;
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     
     }
  
  if(*it==' ' || *it==',' || it==parse.end() ){ //if it has reached a space or comma,
    if(word!=" " && word!=""){
    x=word;
    phrase.push_back(x); //pushback the word and reset word
    }
    if(*it==','){          //if comma statement is complete* need to add end of statement
      statement=true;
      }
      word="";
    }
    if((*it!=' ') && (*it !=',')){
  word=word+*it;
    }
  }

  if (phrase[0]=="printHeap"){
      //cout<<"printHeap"<<endl;
      h1.printHeap();
      }
  else if(phrase[0]=="getMin"){
      //cout<<"getMin"<<phrase[1]<<endl;
      h1.getMin();
      }
  else if(phrase[0]=="getMax"){
      //cout<<"getMax"<<endl;
      h1.getMax();
      }
  else if(phrase[0]=="deleteMin"){
      //cout<<"deleteMin"<<endl;
      h1.deleteMin();
      }
  else if(phrase[0]=="deleteMax"){
      //cout<<"deleteMax"<<endl;
      h1.deleteMax();
      }
  else if(phrase[0]=="insert"){
      //cout<<"insert: "<<phrase[1]<<endl;
      h1.insert(stoi(phrase[1]));
      }













  /*
    hi.insert(5);
    hi.insert(65);
    hi.insert(80);
    hi.insert(25);
    hi.insert(37);
    hi.insert(8);
    hi.insert(15);
    hi.insert(57);
    hi.insert(36);
    hi.insert(45);
    hi.insert(59);
    hi.insert(20);
    hi.insert(14);
    hi.insert(32);
    hi.insert(18);
    hi.insert(28);
    hi.insert(30);
    hi.insert(34);
    hi.insert(27);
    hi.insert(39);
    hi.insert(38);
    hi.insert(45);
    hi.insert(50);
    hi.insert(15);
    hi.insert(12);
    hi.insert(13);
    hi.insert(10);
    hi.insert(30);
    hi.insert(31);
    hi.insert(16);
    hi.insert(17);
    hi.insert(2);
    hi.printHeap();
*/



    return 0;
    }

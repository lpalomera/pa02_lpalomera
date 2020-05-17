//heap.cpp

#include "heap.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>

using namespace std;
int minMaxHeap::GP(int i){
    return ((i-3)/4);
    }

int minMaxHeap::PARENT(int i){
    return ((i-1)/2);
    }



//Given index, will find left child's index
int minMaxHeap::LEFT(int i) {
    return (2 * i + 1);
}

//Given index, will find right child's index
int minMaxHeap::RIGHT(int i) {
    return (2 * i + 2);
}

void minMaxHeap::swap(int &ind1,int &ind2){
    //cout<<"index 1: "<<ind1<<" index 2: "<<ind2<<endl;
    int temp= ind1;
    ind1=ind2;
    ind2=temp;
    //cout<<"index 1: "<<ind1<<" index 2: "<<ind2<<endl;
    }

//gets minimum element
void minMaxHeap::getMin(){
    if(vdata.empty()==true){
        cout<<"min = 0"<<endl;
        return;
    }else{
        cout<<"min = "<<vdata[0]<<endl;
        return;
    }
        }


//gets maximum element
void minMaxHeap::getMax(){
    if(vdata.empty()==true){
        cout<<"max = 0"<<endl;
        return;
    }
    else if(vdata.size()>=3){
        if(vdata[1]>vdata[2]){
            cout<<"max = "<<vdata[1]<<endl;
            return;
        }else {
            cout<<"max = "<<vdata[2]<<endl;
            return;
            }
        }
    else if(vdata.size()==2){
        cout<<"max = "<<vdata[1]<<endl;
        return;
        }
    else if(vdata.size()==1){
        cout<<"max = "<<vdata[0]<<endl;
        return;
        }
    cout<<"max = 0"<<endl;
    return;
}

//should percolate the new index up if need be
//Min Level: should be smaller than parent and greater than grand
//Max Level: should be greater than parent and smaller than grand
void minMaxHeap::percUP(int i){
    if(i==0 || i==1 || i==2){
        return;
        }

    int currInd=i;
    int height= log2(i+1);
    if((height%2)== 1){//max levels
        //max level and may switch with parent
        if(vdata[currInd] < vdata[PARENT(currInd)]){
            //while(vdata[currInd] < vdata[PARENT(currInd)]){
                swap(vdata[currInd] , vdata[PARENT(currInd)] );
                currInd=PARENT(currInd);
                //PARENT=PARENT(currInd);
                /////cout<<"Going in with "<< vdata[currInd]<<endl;
                percUP(currInd);
                //return;
                //}
             return;
            }
        //max level and may switch with grandparent
        if(vdata[currInd] > vdata[GP(currInd)]){
            //while(vdata[currInd] > vdata[GP(currInd)]){
                swap(vdata[currInd] , vdata[GP(currInd)]);
                currInd=GP(currInd);
                percUP(currInd);
                //return;
                //}
             return;
            }
        //Meets requirements, no need for swap
        return;
        }
    else{//min level
        //min level and may switch with parent
        if(vdata[currInd] > vdata[PARENT(currInd)]){
            //while(vdata[currInd] > vdata[PARENT(currInd)]){
                swap(vdata[currInd] , vdata[PARENT(currInd)]);
                currInd=PARENT(currInd);
                percUP(currInd);
                //return;
                //}
            return;
            }
        //min level and may switch with grandparent
        //cout<<"In the min level"<<endl;
        if(vdata[currInd] < vdata[GP(currInd)]){
            //while(vdata[currInd] < vdata[GP(currInd)]){
                swap(vdata[currInd] , vdata[GP(currInd)]);
                currInd=GP(currInd);
                //cout<<"Going in with "<<vdata[currInd]<<endl;
                percUP(currInd);
                //return;
                //}
            return;
            }
        //Meets requirements, no need for swap
        return;
        }
    //Should never reach here
    return;
    }



//inserts element
void minMaxHeap::insert(int value){
    //insert value
    vdata.push_back(value);
    cout<<"inserted "<<value<<endl;
    
    //return after inserting the only element if prev empty
    if(vdata.size()==0 || vdata.size()==1){
        return;
        }
    int height= log2(vdata.size());
    int currInd=vdata.size()-1;
    //new element was placed on a max level
    if( (height%2)== 1){//max levels
        //if no grandparent i.e. the 1st and 2nd index
        //check if its smaller than root(min), switch if yes
        if(vdata.size()==2 || vdata.size()==3){
            if(vdata[vdata.size()-1]< vdata[0]){
                swap(vdata[vdata.size()-1],vdata[0]);
                //cout<<vdata[0]<<" then "<<vdata[1]<<endl;
                return;
                }
            //Valid as is, no swap
            return;
            }
         //has grandparent and parent, so check
         //Have to be greater than parent and smaller than grandparent
         //if not switch, may need percUP/
         if( vdata[currInd] < vdata[PARENT(currInd)] or vdata[currInd] > vdata[GP(currInd)]){
             percUP(currInd);
             return;
             }
         //Meets requiremets should stay at current index
         return;
    }else{//min levels
        //if on the the next possible min level beside root
        //i.e. the 3rd, 4th, 5th, or 6th index. has to be
        //smaller than parent but greater than grandparent
        if(vdata.size()==4 || vdata.size()==5 ||vdata.size()==6 || vdata.size()==7){
            //switches with parent if greater than it
            if(vdata[currInd]> vdata[PARENT( currInd) ]){
                swap(vdata[currInd], vdata[ PARENT(currInd) ] );
                return;
                   }
            //switches with grand if lesser than it
            else if( vdata[currInd]< vdata[ GP(currInd) ] ){
                swap( vdata[currInd], vdata[ GP(currInd) ] );
                return;
                }
            //valid as is
            return;
            }
        //has grandparent and parent and is not
        //the first(root) nor second min level
        //has to be smaller than parent, greater
        //than grandparent, may have to use percUp/
        if(vdata[currInd] > vdata[PARENT(currInd)] or vdata[currInd] < vdata[GP(currInd)]){
            percUP(currInd);
            return;
            }
        //Meets requirements and should stay at current index
        return;
        }
    //bool minLev=false;

    //should never reach here since it will be max or min level
    return;
    }




//deletes minimum element
void minMaxHeap::deleteMin(){
    cout<<"deleted min"<<endl;
    }

//deletes maximum element
void minMaxHeap::deleteMax(){
    cout<<"deleted max"<<endl;
    }

//prints heap from left to right
void minMaxHeap::printHeap(){
    cout<<"heap = ";
    for(int i=0; i< vdata.size();i++){
        if(i==vdata.size()-1){
            cout<<vdata[i];
            }else{
            cout<<vdata[i]<<" ";
             }
        }
        cout<<endl;
    }

void minMaxHeap::insert2(int value){
    //insert value
    vdata.push_back(value);
    //cout<<"inserted "<<value<<endl;
    
    //return after inserting the only element if prev empty
    if(vdata.size()==0 || vdata.size()==1){
        return;
        }
    int height= log2(vdata.size());
    int currInd=vdata.size()-1;
    //new element was placed on a max level
    if( (height%2)== 1){//max levels
        //if no grandparent i.e. the 1st and 2nd index
        //check if its smaller than root(min), switch if yes
        if(vdata.size()==2 || vdata.size()==3){
            if(vdata[vdata.size()-1]< vdata[0]){
                swap(vdata[vdata.size()-1],vdata[0]);
                //cout<<vdata[0]<<" then "<<vdata[1]<<endl;
                return;
                }
            //Valid as is, no swap
            return;
            }
         //has grandparent and parent, so check
         //Have to be greater than parent and smaller than grandparent
         //if not switch, may need percUP/
         if( vdata[currInd] < vdata[PARENT(currInd)] or vdata[currInd] > vdata[GP(currInd)]){
             percUP(currInd);
             return;
             }
         //Meets requiremets should stay at current index
         return;
    }else{//min levels
        //if on the the next possible min level beside root
        //i.e. the 3rd, 4th, 5th, or 6th index. has to be
        //smaller than parent but greater than grandparent
        if(vdata.size()==4 || vdata.size()==5 ||vdata.size()==6 || vdata.size()==7){
            //switches with parent if greater than it
            if(vdata[currInd]> vdata[PARENT( currInd) ]){
                swap(vdata[currInd], vdata[ PARENT(currInd) ] );
                return;
                   }
            //switches with grand if lesser than it
            else if( vdata[currInd]< vdata[ GP(currInd) ] ){
                swap( vdata[currInd], vdata[ GP(currInd) ] );
                return;
                }
            //valid as is
            return;
            }
        //has grandparent and parent and is not
        //the first(root) nor second min level
        //has to be smaller than parent, greater
        //than grandparent, may have to use percUp/
        if(vdata[currInd] > vdata[PARENT(currInd)] or vdata[currInd] < vdata[GP(currInd)]){
            percUP(currInd);
            return;
            }
        //Meets requirements and should stay at current index
        return;
        }
    //bool minLev=false;

    //should never reach here since it will be max or min level
    return;
    }





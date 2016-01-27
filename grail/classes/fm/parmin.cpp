/*#include<iostream>
#include<string>
#include<fstream>
//using namespace std;
#include<stdio.h>

#include<stdlib.h>

//#include"dynarray.h"

#define S_DEBUG 1


*/
#include<math.h>
  
template <class dataType>class mNode
{
 public:
 dataType data;
 mNode *next; // pointer to next element in the list
 mNode *prev;
};

template <class dataType>class mList
{
public:
 mNode<dataType> *base;  // base node of the list
			 // does not contain any data
			 // only serves as a start marker
 mNode<dataType> *latest; //reference to recently modefied or accessed list item
 mNode<dataType> *endFlag;//end marker of list

 long latest_index;
                 	//current size of the list
			 //this is a expandable number
public:
long size;
	//contructor
	mList();
	//destructor
	~mList();

long memory_used();
			 //overload the "=" operator to use this linked list
			 //as if it is a simple array . here we are hiding the implementation from user
dataType &operator[](int index);  //only operator that is visible to user
};

//implimentation of the member functions start here
template <class dataType> mList<dataType>::mList()
{

	   size=0;
	   base = new mNode<dataType>;
	   latest =  new mNode<dataType>;
	   endFlag = new mNode<dataType>;
	   //cout<<"base"<<base;
	   if(base==NULL)
		cout<<"memry Error";
		
	   base->next=NULL;
	   base->prev=NULL;
		latest->next=NULL;
		latest->prev=NULL;
	  // base->data=-1;
}
template <class dataType> mList<dataType>::~mList()
{
		//DEBUG0
		//	cout<<"freeing up memory of "<<this;
		// free all the memory allocated for the object
		//start
		long i;
		mNode<dataType> *temp;   // serves as location pointer in the list while looping
		mNode<dataType> *temp2;
		temp=base;
		//serch for that element from begining
		 for(i=0;i<=size;i++)
		 {
	//		 cout<<"deallocation i="<<i<<"\t";
			 temp2=temp;
			temp=temp->next;
			 delete temp2;

		 }
		 //are we at the end of the list ? did we properly deallocated every thing of the list
		 //if so last node's next will be next
		 if(temp!=NULL)
			cout<<"OH error with memory free ";
}


template <class dataType> long mList<dataType>::memory_used()
			//function for calculating memory used by our dynamic array object in total (this instance only)
{
	return (size+3)*sizeof(dataType)+2*sizeof(long); 
}



template <class dataType> dataType &mList<dataType>::operator[](int index)
			 //overload the "=" operator to use this linked list
			 //as if it is a simple array . here we are hiding the implementation from user

{
	   mNode<dataType> *temp;   // serves as location pointer in the list while looping
	   mNode<dataType> *temp2;  //very unstable buffer for memory allcation for each
			 //if index is < size okay we are aking for a existing element in the liked list
	   temp= new mNode<dataType>;
	   
	   if(index<size)
	   {
			 long distance_from_start=index;
			 long distance_from_end=abs(size-1-index);
			 long distance_from_latest=abs(latest_index-index);
			 long i=0;

			 if(  (distance_from_start<=distance_from_end)  && (distance_from_start<=distance_from_latest) )
			 {	//normal sequential search from start
					 temp=base->next;
					//serch for that element from begining
					for(i=0;i<index;i++)
					 temp=temp->next;
					 
			 }else if((distance_from_latest<=distance_from_start)  && (distance_from_latest<=distance_from_end) )
			 {	 //is latest operation's  index is nearest to our search index?
				 if((index-latest_index)>=0)
				 {
					temp=latest;
					//serch for that element from index of latest operation
					 for(i=latest_index;i<index;i++)
					 temp=temp->next;
				 }
				 else
				 {	
				 	temp=latest;
				  //serch for that element back ward from latest index
					 for(i=latest_index;i>index;i--)
					 temp=temp->prev;
				  }
			 
			 }else
			 {
				// it is closer to the end point
				// do a backward search from end
				temp=endFlag;
				for(i=size-1;i>index;i--)
					 temp=temp->prev;
			 }
			 //return a reference to the element
			 latest=temp;
			 latest_index=index;
			 return temp->data;
	   }
	  else //if index is greater than size
	  {
			 
		  if(size>0)
			 temp=endFlag;
			 
		  else
		  {	 temp=base;
				//initalize latest operation index
			latest_index=0;
		  }
			//okay its a over flow ! expand the memory
			//use previous operation index as start point to reduce sequential search time
			 for(long j=size;j<index+1;j++)
			 {
					 //get new node
					 temp2=new mNode<dataType>;
					 //append that to existing list
					 temp2->prev=temp;
					 temp->next=temp2;
					 temp2->next=NULL;

					 temp=temp2;
					if(size==0 && j==0)
						latest=temp;
			 }
			 size=index+1;
			 //store index to last element for future access
					 endFlag=temp2;
					 endFlag->prev=temp2->prev;
					 endFlag->next=NULL;
			 //return the reference to last element
			  return temp->data;
	  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                        specialized implementation for mNode for a string array                     ////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> class mNode <char *>
{
 public:
 char * data;
 mNode *next; // pointer to next element in the list
 mNode *prev;
 //we are using constructors and destructors because we are using dynamic memory allocation in this instead of 
 //simple data types as in generic case 
 mNode()
 {	data= (char *) malloc(10*sizeof(char));  }
 ~mNode()
 { 	free(data); }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//															NOTE																////
//	add any more specialized implementations for node if you need special functionality like above one ; usually classes 
//	structures will work fine with out special implementation. 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










class _su_parFm{
public:
  int calcNP(char *filename ) //calculates the number of processes required 
{
                        mList<int> _su_states;
			mList<char *> buf2; char buf[500];
			int countx,k,i;
			int p,q;
			int indexx;
			  
			countx=0;
			k=0;
			i=0;
			//lets 
			for(int bbb=0;bbb<20000;bbb++)
			{
				_su_states[bbb]=-1;
			}  
			ifstream inFile(filename);
			while(inFile)
			{       inFile.getline(buf,500,'\n');
				// If reading the file is over, then it calculates the block numbers of the 	
				// _su_states, the total number of _su_states, and their transitions and the input 	
				// symbols etc.
					if((bool)!inFile||buf[0]==' '||buf[0]==NULL||buf==NULL)
		   			{
             				p=(int)ceil((double)log((double)countx)/(double)log((double)2));
					q=(int)ceil(float(countx)/float(p));
					}	
	     	  			else//If reading the file is not over
						{
					
		    for(indexx=k;indexx<k+3;indexx++)
		    {
			     
				if(indexx==k)//reading the first token
			     {
				strcpy(buf2[indexx],strtok(buf," "));
				if(strcmp(buf2[indexx],"(START)")!=0)
				{
				    if(_su_states[atoi(buf2[indexx])]==-1)
				    {
				       //storing the _su_states in an array
					_su_states[atoi(buf2[indexx])]=atoi(buf2[indexx]);
				       	countx++;
					
				    }
						

				}
			       }
				
				else//Reading the third token
				{
				     strcpy(buf2[indexx],strtok(NULL," "));
				     if(strcmp(buf2[indexx],"(FINAL)")!=0)
				     {
					 if(_su_states[atoi(buf2[indexx])]==-1)
					 {
					    //storing the _su_states in the array
					    _su_states[atoi(buf2[indexx])]=atoi(buf2[indexx]);
					    countx++;
					 } 
							
				     }
				     
				}
		 			 

			}//end for
		}//end elsei
		  i++;
		  k=k+3;	
		}
			inFile.close();	
			
				

//cout<<"number of processors required="<<q+1;
return q+1;

}
int call_MPI(int q,char * filename) //invokes parallel MPI executable for a given input file and given number of processes(virtual processors)
{
char Q[10]; //
char command0[100];
sprintf(Q,"%d",q);
strcpy(command0,"mpirun -np ");
strcat(command0,Q); //specify  number of proceeses
strcat(command0," parmin.out ");
strcat(command0,filename); //give the 
//cout<<"Generated MPI command"<<command0;
system(command0);
return 1;  //**********************************************
} 
bool parmin(char *filename ) //actual paralle minimisation function that we are going to call
{
call_MPI(calcNP(filename),filename);
return true;
}

};

/*
int main()
{
_su_parFm su;
su.parmin("bigdfa.txt");
return 0;
}*/

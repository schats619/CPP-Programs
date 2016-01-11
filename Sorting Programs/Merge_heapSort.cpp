#include<iostream>
#include <stdlib.h>
#include <sys/time.h>
#include<iomanip>
#include<ctime>
#include <cstdlib>
#include<conio.h>
using namespace std;


class NArray {  				//defining a class
	public:
		int arr[100000];  		// fixing the max array size
		int size;	 			// size of integer type
		static int swapCount;	// swap count varibale for merge sort
	public:
		NArray(){   			// constructor for initializing the size variable to zero
			size=0;
			}
		~NArray(){  			// destructor
			cout<<"\nthe array Object is deleted"<<endl;
			}

	void setArrSize(int sizeOfAr);  	// to set the array size
	void setDataInArr();			// to set the data in array a[i] =i
	void  heap_sort();		// heap sort  for the array.
	void makeheap(int i); 	//utility function for the merge sort
	void merge_sort(int low, int high);		// Merge sort  for the array.
	void merge(int low, int high, int mid);  // merge function to merge the elements
	void diaplayElementsOfList();	// display the elements in the array
	void getSwapCount();
	};

int NArray::swapCount =0; // initialising the static variable swapCount = 0

//funtion to print the swapcount of the Mergesort
void NArray :: getSwapCount() {
	cout<<"\n\nthe swap count :: "<<swapCount<< " for Merge Sort\n"<<endl;
	}

// to set the array size
void NArray :: setArrSize(int sizeOfAr)	{
		size = sizeOfAr;
	}
// to set the random data in array
void NArray :: setDataInArr()	{
	srand((unsigned)time(0));
	cout<< size << " elements are inserted initially in an array "<<endl;
	if (size >0)	{
		for(int i=0;i<size;i++)	   // generates random numberrs for the given size
			arr[i] = (rand()%size)+1;
	}
	else
		cout<<"enter size greater than 0"<<endl;
}
//Makeheap function to sor the elements
void NArray :: makeheap(int c)   //// A utility function to make a max heap of given capacity
{
	for ( int i = 1 ; i < c ; i++ )   // heapify till the count is reached up to c
	{
		int val = arr[i] ; 	//	value is made equal to the array element
		int s = i ;
		int f = ( s - 1 ) / 2 ; 		// evaluating the f to make the  max heap
		while ( s > 0 && arr[f] < val )
		{
			arr[s] = arr[f] ;      // if conditions satifies then arr[s] is equted to the arr[f] where f = (s-1)/2
			s = f ;
			f = ( s - 1 ) / 2 ;
		}
		arr[s] = val ;   // equating the current array element value to the arr[s]
	}
}

// heap sort function to sort the elements of the array
void NArray :: heap_sort( )
{
	int swap_count =0;  	// initializing the swapcount to 0
	for ( int i = size - 1 ; i > 0 ; i-- )    // for everyelement in the array
	{
		swap_count++;   // swap count increments for each swap
		int ivalue = arr[i] ;  // swapping takes place
		arr[i] = arr[0] ;	// using temporary variable
		arr[0]=ivalue;
		makeheap(i); 		// then we will make the heap for every element index
	}
cout<<"\n\nthe swap count :: "<<swap_count<< " for Heap Sort\n"<<endl;    // display the swapcount in the console
}


// merge sort function to sort elements of an array using recursion
void NArray ::  merge_sort(int low, int high)    // given the low and the higher index
{
    int mid;     // declaring the mid variable
    if (low < high)
    {
        mid=(low+high)/2;   // getting the mid value
        merge_sort(low,mid);  // sorting the upper half from the low array index to the mid array index
        merge_sort(mid+1,high); // sorting the lower half to the upper array index from the mid+1 array index
        merge(low,high,mid);  // merging the two halfs at one place to get the sorted list
    }
    return;
}

// utility function to merge the elements of a list in a sorted manner
void NArray ::  merge(int low, int high, int mid)   //   low, high and mid indexof the array are passed
{
    int i, j, k, c[500000];   // c should be taken value more than the initial array declaration which is 100000
    i = low;    // assigning the low, mid values to variables so as merge the elements
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)   // checking the condition if low < mid and the index after mid is lower than high
    {
        if (arr[i] < arr[j])    // checking condition if array lesser than mid < array after mid
        {
            c[k] = arr[i];     // respective swapping taking place
            k++;// incrementing the positions
            i++;
	swapCount++;  //incrementing the static swapcount variable to get the swapcount
        }
        else
        {
            c[k] = arr[j]; // respective swapping taking place
            k++; // incrementing the positions
            j++;
	swapCount++;	//incrementing the static swapcount variable to get the swapcount
        }
    }
    while (i <= mid) //while loop til low <= mid
    {
        c[k] = arr[i]; // respective swapping taking place
        k++;	// incrementing the positions
        i++;
	swapCount++;	//incrementing the static swapcount variable to get the swapcount
    }
    while (j <= high)  // while loop til low <= high
    {
        c[k] = arr[j]; // respective swapping taking place
        k++;	// incrementing the positions
        j++;
	swapCount++;	//incrementing the static swapcount variable to get the swapcount
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}


//##############################################//##############################################


// display the elements in the array linked list
void NArray :: diaplayElementsOfList()	{
		for (int i =0;i<size;i++) // looping through all the elements
			cout<<arr[i]<<" ";
	}


int main() {
	NArray arr1;  					// creating an object arr1 for class NArray
	timeval t1, t2;
	int size1,size2;			// sizes for both sorting
	double elapsedTime ;
		cout << "\n\n <<---------------------------------Merge Sort ----------------------------------->>" <<endl;
	cout<<"\nenter the size for the Merge Sort \n";
	cin>> size2;  					// input size2
	arr1.setArrSize(size2);  			// setting the array size to size 2
	arr1.setDataInArr();				// generating the random elements for the array
	int top =0,bottom =size2-1;
	cout<<"\nElements of Array list are ------> "<<"\t";   // display the elements of a array list
	arr1.diaplayElementsOfList();  		// display the elements int he memberr variable arr[]
	gettimeofday(&t1, NULL);  		// start timer
	arr1.merge_sort(top,bottom); 			//  Merge sort for different array size
	gettimeofday(&t2, NULL);			// stop timer
	arr1.getSwapCount();  // display the swapcount in the console
	elapsedTime = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0); // converting to nanoseconds
	cout << "Elapsed time  ----------> "<<elapsedTime << " ns. for Merge sort "<<size2<< " Elements"<<endl;
	cout<<"\nElements of Array list after Merge Sort ------> "<<"\t";   // display the sorted elements of an array
	arr1.diaplayElementsOfList();
	
	cout << "\n<<---------------------------------Heap Sort ------------------------------------>>" <<endl;
	cout<<"\nenter the size for the array for  Heap sort \n";
	cin>> size1; 					// input size1
	arr1.setArrSize(size1);  			// setting the array size to size 1
	arr1.setDataInArr();  			// generating the random elements for the array
	arr1.makeheap(size1);
	cout<<"\nElements of Array list are ------> "<<"\t";   // display the elements of a array list
	arr1.diaplayElementsOfList();  		// display the elements int he memberr variable arr[]
	gettimeofday(&t1, NULL);			// start timer
	arr1.heap_sort();			// Heap sort  for the array.
	gettimeofday(&t2, NULL);			// stop timer
	elapsedTime = (t2.tv_sec - t1.tv_sec) +((t2.tv_usec - t1.tv_usec)/1000000.0);  // converting to nanoseconds
	cout << "Elapsed time -----------> "<< elapsedTime << " ns. for Heap sort "<<size1<< " Elements"<<endl;
	cout<<"\nElements of Array list after Heap Sort ------> "<<"\t";   // display the sorted elements of an array
	arr1.diaplayElementsOfList();	 	// display the sorted elements int he memberr variable arr[]
	
	

	getch(); 		// display the sorted elements int he memberr variable arr[]
	return 0;
	}

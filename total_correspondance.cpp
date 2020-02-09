/* Program to implement total correspondance method in Binary Heap


    Authors :-
    1)Shreya Kulkarni(2018BTECS00217)
    2)Poonam Katale(2018BTECS0209)
    3)Vaishnavi Bharambe(2018BTECS00214)

*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int buffer=0;
struct com
{
    int x;
    int *cor;

};

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void minheapify(com arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].x < arr[largest].x)
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].x < arr[largest].x)
        largest = r;

    // If largest is not root
    if (largest != i){
        swap(arr[i].x, arr[largest].x);
        swap(arr[i].cor , arr[largest].cor);

        // Recursively heapify the affected sub-tree
        minheapify(arr, n, largest);
    }
}

void maxheapify(com arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].x > arr[largest].x)
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].x > arr[largest].x)
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i].x, arr[largest].x);
        swap(arr[i].cor , arr[largest].cor);
        // Recursively heapify the affected sub-tree
        maxheapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array
void minbuildHeap(com arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        minheapify(arr, n, i);
    }
}



void maxbuildHeap(com arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
}

void deleteCorrMax(com max[],int n,int j)
{
    int index;
    for(int i=0;i<=j;i++)
    {
        if(max[i].x==n)
        {
            index=i;
        }
    }
    for(int k=index;k<=j-1;k++)
    {
        max[k]=max[k+1];
    }
    maxbuildHeap(max,j);
}

void deleteCorrMin(com min[],int n,int j)
{
    int index;
    for(int i=0;i<=j;i++)
    {
        if(min[i].x==n)
        {
            index=i;
        }
    }
    for(int k=index;k<=j-1;k++)
    {
        min[k]=min[k+1];
    }
    minbuildHeap(min,j);
}
// A utility function to print the array
// representation of Heap
void printHeap(com arr[], int n)
{

    if(n==0)
            cout<<"\n Heap is Empty..";
    for (int i = 0; i < n; ++i)
    {

        cout << arr[i].x<<"  ";

    cout << "\n";
    }

}
int getMin(com arr[])
{
    if(buffer!=0)
    {
        if(arr[0].x<buffer)
		return arr[0].x;
	else
		return buffer;
    }
    return arr[0].x;

}

int getMax(com arr[])
{
    if(buffer!=0)
    {
        	if(arr[0].x>buffer)
	return arr[0].x;
	else
	 	return buffer;
    }
    return arr[0].x;

}
void deleteRootmin(com arr[],com arr2[], int& n)
{
    // Get the last element

    if(arr[0].x>buffer && buffer!=0){

        cout<<" \nMinimum Element in the buffer will be deleted = "<<buffer;
        buffer=0;
    }

    else
    {


    int lastElement = arr[n - 1].x;
    int d=*(arr[n-1].cor);

    int maxtodel=*(arr[0].cor);
	buffer=maxtodel;
    cout<<" Element "<<arr[0].x<<" is Deleted "<<endl;
    cout<<" Corresponding Max element will be deleted = ";
    cout<<maxtodel;
    // Replace root with first element
    arr[0].x = lastElement;
    arr[0].cor=&d;
    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    minheapify(arr, n, 0);
    deleteCorrMax(arr2,maxtodel,n);
    }
}

void deleteRootmax(com arr[],com arr2[], int& n)
{
    // Get the last element


     if(arr[0].x<buffer && buffer!=0){
        //buffer=0;
         cout<<"\nMaximum Element in the buffer will be deleted="<<buffer;
         buffer=0;

    }



    int lastElement = arr[n - 1].x;
    int d=*(arr[n-1].cor);
    int mintodel=*(arr[0].cor);
		buffer=mintodel;
    cout<<" Element "<<arr[0].x<<" is Deleted"<<endl;
    cout<<"Corresponding Min element will be deleted:";
    cout<<mintodel;
    // Replace root with first element
    arr[0].x = lastElement;
    arr[0].cor=&d;
    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    maxheapify(arr, n, 0);
    deleteCorrMin(arr2,mintodel,n);

}

int main ()
{
     cout<<"\n\n\t\t\t****************Total Correspondence method in Binary Heap*****************\t\t\t\n\n";
         int n;

         struct com min[n/2];
         struct com max[n/2];
         int a[n];
          int j=0;int i=0;
    int mi,mx;

    int k=0;  int ch;



    do
        {

      cout<<" \n 1.Insert \n 2.Delete \n 3.Display \n 4.Get Minimum Element \n 5.Get Maximum Element \n 6.Exit";
     cout<<" \n\n Enter your choice = ";
     cin>>ch;

       switch(ch)
       {
           case 1:

                   cout<<"\n Enter number of elements = ";
                    cin>>n;


                    cout<<"\n Enter Elements = " ;
                      for(int i=0;i<n;i++)
                          cin>>a[i];
                      if(n%2!=0)
                        buffer=a[n-1];
                       for(int i=0;i<n-1;)
    {
        //cout<<i<<endl;
        if(a[i]>a[i+1])
        {
            mi=a[i+1];
            mx=a[i];
            min[j].x=mi;
            min[j].cor=&a[i];
            max[j].x=mx;
            max[j].cor=&a[i+1];
        }
        else
        {
            mi=a[i];
            mx=a[i+1];
             min[j].x=mi;
            min[j].cor=&a[i+1];
            max[j].x=mx;
            max[j].cor=&a[i];
        }
        j++;
        i=i+2;
    }

      minbuildHeap(min,j);
      maxbuildHeap(max,j);
     cout<<"Min and Max Heaps are built...!";


      break;
           case 2:

                     cout<<" What do you want to Delete?\n1.Min\n2.Max\n3.Exit\n ";
                     int ch;
                     cout<<" Enter choice = ";
                     cin>>ch;
                     switch(ch)
                     {
                         case 1: deleteRootmin(min,max,j);
                                 break;
                         case 2: deleteRootmax(max,min,j);
                                 break;

                     }

                   break;
          case 3:

              cout<<"\n Heap Elements are = \n";
                  cout<<"\n Min Heap = \n";
                  printHeap(min,j);
                  cout<<"\n Max Heap = \n";
                  printHeap(max,j);
                  break;

          case 4:  cout<<getMin(min)<<" is Minimum Element\n";
                   break;
          case 5:  cout<<getMax(max)<<" is Maximum Element\n";
                   break;
           case 6:exit(0);


       }

    }while(ch<=6);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

    /**

        Random no generation using hardware
    */

    random_device rd;   //obtain random no from hardware
    mt19937 eng(rd());  //seed the generator

int genrandom(int l,int r)
{
    uniform_int_distribution<>distr(l,r);
    return distr(eng);
}

int partition(int arr[],int l,int r){
    int random=genrandom(l,r);

    if(random!=l)
    {
        int t=arr[l];
        arr[l]=arr[random];
        arr[random]=t;
    }

   int p=arr[l];           //make first element pivot element

    int i=l+1;
    for(int j=i;j<=r;j++)   //loop through l+1 to rth element
    {
        if(arr[j]<p)        //if jth element is <p then swap arr[i] and arr[j] element
        {
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
            i++;
        }
    }

    int t=arr[i-1];         //on loop completion we have to swap arr[i-1] and arr[l]
    arr[i-1]=arr[l];        //so that pivot element reaches its rightfull place`
    arr[l]=t;


    return i-1;

}
int rselect(int arr[],int l,int r,int min)
{
    if(l==r)
     return arr[l];

        int p=partition(arr,l,r);

        if(min==p)
            return arr[p];
        else if(p>min)
            rselect(arr,l,p-1,min);
        else if(p<min)
            rselect(arr,p+1,r,min);


}
int main()
{
    int arr[]={3,8,2,5,1,4,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("\nEnter the value of n for nth min element selection (1 to %d) :  ",n);
    int selectmin;
    scanf("%d",&selectmin);
    if(selectmin > n || selectmin<=1)
        {
            printf("\nInvalid entry !!! \n");
            return 1;
        }
    int val=rselect(arr,0,n-1,selectmin-1); //quicksort function 0 is for first index and n-1 is the last index in array;

    printf("\n%d",selectmin);
    switch(selectmin%10)
    {
        case 1: printf("st");break;
        case 2: printf("nd");break;
        case 3: printf("rd");break;
        default : printf("th");break;
    }
    printf(" min element is  : %d \n",val);


}

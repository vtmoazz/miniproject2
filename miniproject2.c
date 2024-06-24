/*Write a program in C language to input a one dimensional array of marks (>=0 and <=100) and do following tasks:
0. Print out the list;
1. Find maximum marks and print to screen;
2. Find marks that are greater than or equal to average of all the marks;
3. Insert a mark into the array;
4. Delete a mark from the array;
5. Sort the array (Ascending Order)
6. Input two float numbers a and b (a<b). Show marks that are greater than or equal to a and less than or equal to b.

Demo output:

Suppose that I have an array of marks, such that: 35 67 50 67
1. (1, 67), (3, 67). 1 is index of 67 in the array, is the same with (3, 67)
2. (1, 67), (3, 67). 
…
6. Let a=45 and b=55, so the output is (50, 2).*/
#include<stdio.h>
void Input(int *p, int *m ){
	printf("Enter n element: ");
	printf("\a[%d]= ");
	scanf("%d",m);
	int i;
	for(i=0;i<*m;i++){
		scanf("%d",&p[i]);
	}
}
void Print(int a[], int n){
	int i;
    for(i=0;i<n;i++){
    	printf("%d ",a[i]);
	}	
}
int Max(int a[], int n){
	int i,max=a[0];
	for(i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		} 		
	}
	printf("\nMax:%d\n",max);
	return max;
}
float AVG(int a[], int n){
	float f,sum=0;
    int i;
    for (i=0;i<n;i++){
        sum+=a[i];	
	}
    f=sum/n;
	return f;
}
void  Compare(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		if (a[i] >= AVG(a,n)){
			printf("%d ",a[i] ); 
		}
	}
}
void Insert(int a[], int n, int position, int value){
	int i;
    for (i = n-1; i > position; --i){
        a[i] = a[i - 1];
        a[position] = value;
        (n)++;
	}
}
void swap(int* x,int *y){
   int temp = *x;
   *x= *y;
   *y= temp;	
}
void BubbleSort(int a[], int size){
    int i,j; 
    for ( i = 0; i < size-1; i++){
		for ( j = i + 1; j < size; j++){
			if ((a[j])> (a[j+1])){
             swap(&a[j],&a[j+1]);      
			}
		}
	}
}
void menu(){ 
printf("3.Insert a mark into the array\n4.Delete a mark from the array\n5.Sort the array (Ascending Order)\n6.Input two float numbers a and b (a<b)\n");
	
}
int main(){
	int a[100],n,position,value;
	menu();
    Input(a,&n);
	Print(a,n);
	Max(a,n);
	Compare(a,n);
//	printf("\nEnter the position you want to insert into the array: ");
//	scanf("%d\n",&position);
//	printf("Enter a value in this new element: ");
//	scanf("%d\n",&value);
//	Insert(a,n,position,value);
	BubbleSort(a, size);
	printf("\n");
    Print(a,n);	
    
}

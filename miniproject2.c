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
void swap(int &x,int &y){
   int temp = x;
   x=y;
   y=temp;	
}
void BubbleSort(int a[], int n){
    int temp,i,j; 
    for ( i = 0; i < n; i++){
	for ( j = i + 1; j < n; j++){
		if ((a[j])> (a[j+1])){
             swap(a[i],a[j]);      
			}
		}
	}
}
int main(){
	int a[100],n,position,value;
	printf("3.Insert a mark into the array\n4.Delete a mark from the array\n5.Sort the array (Ascending Order)\n6.Input two float numbers a and b (a<b)\n");
    Input(a,&n);
	Print(a,n);
	Max(a,n);
	Compare(a,n);
//	printf("\nEnter the position you want to insert into the array: ");
//	scanf("%d\n",&position);
//	printf("Enter a value in this new element: ");
//	scanf("%d\n",&value);
//	Insert(a,n,position,value);
	BubbleSort(a,n);
	printf("\n");
    Print(a,n);	
    
}

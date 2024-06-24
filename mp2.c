#include<stdio.h>
// xu li loi input, insert tiep tuc cho toi khi user dừng lại, 
// xu li loi delete
// xu li loi khoang trang
/* Demo output:

Suppose that I have an array of marks, such that: 35 67 50 67
1. (1, 67), (3, 67). 1 is index of 67 in the array, is the same with (3, 67)
2. (1, 67), (3, 67). 
…
6. Let a=45 and b=55, so the output is (50, 2).
*/
// after deleting:, deleting array emty thong bao empty quay ve menu, cho delete nhieu vi tri


//Write a program in C language to input a one dimensional array of marks (>=0 and <=100) and do following tasks:
//0. Print out the list;
//1. Find maximum marks and print to screen;
//2. Find marks that are greater than or equal to average of all the marks;
//3. Insert a mark into the array;
//4. Delete a mark from the array;
//5. Sort the array (Ascending Order)
//6. Input two float numbers a and b (a<b). Show marks that are greater than or equal to a and less than or equal to b. [a;b]

void Check(int *a, char *b){
	scanf("%d",a);
	scanf("%c",b);
	fflush(stdin);
}
void Input(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
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
    for (i = n-1; i >= position; i--){
        a[i+1] = a[i];    
	}
	(n)++;
	a[position] = value;
	Print(a,n);
}
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;  
}
void BubbleSort(int a[], int n){
    int i,j; 
    for ( i = 0; i < n-1; i++){
	    for ( j = i + 1; j < n; j++){
		    if (a[i]> a[j]){
			    swap(&a[i],&a[j]);   
			}
		}
	}
	Print(a,n);
}
void Delete(int a[], int n, int position){
	int i;
	if(n<=0){
		return;
    }
	if(position<0) position=0;
	else if(position>=n) position=n-1;
	for(i=position;i<n-1;i++){
		a[i]=a[i+1];
	}
	n--;
	Print(a,n);
}
void Floatab(int a[], int n, int a1, int b1){
	int i;
	for(i=0;i<n;i++){
		if(a[i]>=a1 && a[i]<=b1){
			printf("a[%d]=%d ",i,a[i]);
		}
	}
}
int main(){
	printf("0.Print out the list\n1.Find maximum marks and print to screen\n2.Find marks that are greater than or equal to average of all the marks\n3.Insert a mark into the array\n4.Delete a mark from the array\n5.Sort the array (Ascending Order)\n6.Input two float numbers a and b (a<b)\n");
	int a[100],n=0,position,value,module;
	char m,p;
	do{
        printf("Enter n element: ");
	    scanf("%d",&n);
	    scanf("%c",&p);
	    fflush(stdin);
	    if (n<0 || n>100 || p!=10) {
		    printf(" Error! Please check again!\n");	
		}
	}
    while(n<0 || n>100|| p!=10) ;
    Input(a,n);
    Print(a,n);
	while(1){
		do{
    		printf("\nPlease choose a module (1 - 6): ");
    		scanf("%d", &module);
    		scanf("%c", &m);
    		fflush(stdin);
    		if(m != 10 || module>6 || module==0) printf("Invalid choice!\n");
    	}
		while(m != 10);
    switch(module){
		case 1:{
			int maxi=Max(a,n);
			printf("%d",maxi);
			break;
		} 
		case 2:{
			Compare(a,n);
			break;
		}
		case 3:{
			char x,y;
			printf("\nEnter the position you want to insert into the array: ");
			do{
		        Check(&position,&x);
	            if (x!=10 || position>n || position<0) printf("Error! Please check input!: ");
	        }
	        while(x!=10 || position>n || position<0);
	        printf("\nEnter a value in this new element: ");
	        do{
	            Check(&value,&y);
	            if (y!=10) printf("\nError! Please check input!: ");
			}
			while(y!=10);
	        Insert(a,n,position,value);	
			break;
		}
		case 4:{
			int pos;
			char z;
			printf("\nEnter the position you want to delete: ");
			do{
		        Check(&pos,&z);
	            if (z!=10 || pos>n || pos<0) printf("Error! Please check input!: ");
	        }
	        while(z!=10 || pos>n || pos<0);
			Delete(a,n,pos);
			break;
		} 
        case 5:{
        	BubbleSort(a,n);
	        printf("\n");	
			break;
		}
		case 6:{
			int i; 
			float a1,b1;
			char g,h;
			printf("Enter two float numbers a,b\n");
			printf("a= ");
			do{
				scanf("%f",&a1);
				scanf("%c",&g);
				fflush(stdin);
				if(g!=10) printf("Error! Please check input!: ");
			}
			while(g!=10);
			printf("b= ");
			do{
				scanf("%f",&b1);
				scanf("%c",&h);
				fflush(stdin);
				if(h!=10) printf("Error! Please check input!: ");
			}
			while(h!=10);
		    Floatab(a,n,a1,b1);
			break;
		}
}
}
}

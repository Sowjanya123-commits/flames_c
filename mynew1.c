#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char data;
	struct node* next;
};
struct node* create(char x){
	struct node *l;
	l=(struct node*)malloc(sizeof(struct node));
	l->data=x;
	l->next=NULL;
}
struct node* insert(struct node *l,char d){
	struct node *l2=l,*in=create(d);
	if(l==NULL){
		in->next=in;
		return in;
	}
	while(l->next!=l2)
	    l=l->next;
	if(l->next==l2){
		l->next=in;
		in->next=l2;
	}
	return l2;
}
char checkalpha(struct node *l,int c){
	int i;
	if(c==1)
	    return 's';
	while(1){
		for(i=1;i<c-1;i++)
		     l=l->next;
	    l->next=l->next->next;
	    l=l->next;
	    if(l->next->next==l){
	    	if(c%2==0)
	    	     return l->data;
	        return l->next->data;
		}
	}
}
int main(){
	struct node *l=NULL,*l2;
	int m,t,k,p,i,c=0,n1=0,n2=0,j;
	char s1[10],s2[10],sf[]="flames\0";
	char ch;
	printf("enter first name:\n");
	gets(s1);
	printf("enter second name:\n");
	gets(s2);
	for(i=0;s1[i]!='\0';i++)
	      n1++;
	for(j=0;s2[j]!='\0';j++)
	      n2++;
	m=n1+n2;
	for(i=0;i<n1;i++)
	    for(j=0;j<n2;j++)
	         if(s1[i]==s2[j]){
	         	m=m-2;
	         	s1[i]='*';
	         	s2[j]='+';
			 }
	for(i=0;sf[i]!='\0';i++)
	    l=insert(l,sf[i]);
	l2=l;
	printf("---------------------\n");
	ch=checkalpha(l2,m);
	switch(ch){
		case 'f':
			printf("f\n");
			break;
		case 'l':
			printf("l\n");
			break;
		case 'a':
			printf("a\n");
			break;
		case 'm':
			printf("m\n");
			break;
		case 'e':
		    printf("e\n");
			break;
		case 's':
		    printf("s\n");
			break;
	}
}

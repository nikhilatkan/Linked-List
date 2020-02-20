#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};




void insertathead(node*&head,int data)
{
	node*n=new node(data);
	n->next=head;
	head=n;
}

void insertatend(node*head,int data)
{
	if(head==NULL)
	{
		insertathead(head,data);
	}

	node*tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
}

int lenght(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len=len+1;
	}
	return len;
}

void insertatmiddle(node*&head,int data,int p)
{
	if(head==NULL)
	{
		insertathead(head,data);
	}
	if(p>lenght(head))
	{
		insertatend(head,data);
	}

	int jump=1;
	node*prev=NULL;
	node*cur=head;
	while(jump<=p-1)
	{
		prev=cur;
		cur=cur->next;
		jump++;
	}
	node*n=new node(data);
	n->next=prev->next;
	prev->next=n;
}


void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}

int main()
{
	node*head=NULL;
	insertathead(head,5);
	insertathead(head,6);
	insertathead(head,7);
	insertathead(head,2);
	insertatend(head,9);
	insertatmiddle(head,4,2);
	print(head);

	return 0;


}
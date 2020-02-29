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

void insertatend(node*&head,int data)
{
	if(head==NULL)
	{
		insertathead(head,data);
	}
	else
	{
		node*tail=head;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next=new node(data);
	}
}

void buildlist(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertatend(head,data);
		cin>>data;
		
	}
}
void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}

istream& operator>>(istream &is,node*&head)
{
	buildlist(head);
	return is;
}

ostream& operator<<(ostream &os,node*head)
{
	print(head);
	return os;
}

node*midpoint(node*head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

node*merge(node*a,node*b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}

	node*c;
	//compare a and b for smaller element
	if(a->data < b->data)
	{
		c=a;
		c->next=merge(a->next,b);
	}

	else if(b->data < a->data)
	{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}

node*mergesort(node*head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	//1. Midpoint
	node*mid=midpoint(head);

	node*a=head;
	node*b=mid->next;
	mid->next=NULL;

	//2. Recursively Sort
	a=mergesort(a);
	b=mergesort(b);

	//3.Merge a and b
	node*c=merge(a,b);
	return c;


}

int main()
{
	node*head=NULL;
	cin>>head;
	cout<<head<<endl;
	head=mergesort(head);
	cout<<head;

	
	

	return 0;


}

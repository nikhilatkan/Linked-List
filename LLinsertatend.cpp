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
	print(head);

	return 0;


}
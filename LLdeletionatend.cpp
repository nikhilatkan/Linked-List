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

void deletionatend(node*head)
{
	if(head==NULL)
	{
		return;
	}
	node*prev=NULL;
	node*temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	delete temp;
	prev->next=NULL;
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
	insertathead(head,8);
	insertathead(head,17);
	insertathead(head,5);
	insertathead(head,3);
	deletionatend(head);
	print(head);

	return 0;


}
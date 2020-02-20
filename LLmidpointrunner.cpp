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

node* midpoint(node*head)
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
	insertathead(head,3);
	print(head);
	cout<<endl;
	node*mid=midpoint(head);
	cout<<mid->data;

	return 0;


}

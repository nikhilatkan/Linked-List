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

void deletionatmiddle(node*&head,int key)
{
	if(head==NULL)
	{
		return;
	}

	//node*temp=NULL;
	node*prev=NULL;
	node*cur=head;
	while(cur->data!=key)
	{
		prev=cur;
		cur=cur->next;
	}
	prev->next=cur->next;
	delete cur;
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
	deletionatmiddle(head,5);
	print(head);

	return 0;


}
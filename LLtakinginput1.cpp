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

void buildlist(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertathead(head,data);
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

int main()
{
	node*head=NULL;
	buildlist(head);
	print(head);

	return 0;


}

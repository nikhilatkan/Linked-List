#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node*next;

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
		node*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		node*tail=new node(data);
		temp->next=tail;
	}
}

void Buildlist(node*&head)
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
	cout<<endl;
}




node* rearrange(node*&head)
{	
	//Initialize first node of odd and even lists
	node*odd=head;
	node*even=head->next;

	//remember the first node of even list
	node*evenfirst=even;
	node*head1=new node(0);
	

	while(1)
	{
		if(odd==NULL || even==NULL || even->next==NULL)
		{
			odd->next=evenfirst;
			break;
		}
		//Jump to next odd node and update the odd node
		odd->next=even->next;
		odd=even->next;

		//if the nodes are over than point the next of odd 
		//to the first node of even list
		if(odd->next==NULL)
		{
			even->next=NULL;
			odd->next=evenfirst;
			break;
		}

		//Jump to next even node and update the even node
		even->next=odd->next;
		even=odd->next;
	}

	return head;

}







int main()
{
	node*head=NULL;
	Buildlist(head);

	print(head);
	
	head=rearrange(head);
	print(head);
	return 0;


}
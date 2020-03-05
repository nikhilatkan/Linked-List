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

void reverselist(node*&head) 
{ 
    // Initialize prev and current pointers 
    node *c = head;
    node*p = NULL;
    node*n;
  
    while (c!=NULL) 
    { 
    	n=c->next;
    	c->next=p;
    	p=c;
    	c=n;
    } 
    head=p;
  
    
} 

void rearrange(node*&head)
{
	node*mid=midpoint(head);
	node*head1=head;
	node*head2=mid->next;
	mid->next=NULL;


node*temp1=head1;


	reverselist(head2);
	node*temp2=head2;


	node*curr=new node(0);

	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1!=NULL)
		{
			curr->next=temp1;
			curr=curr->next;
			cout<<temp1->data<<"==>";
			temp1=temp1->next;
		}

		if(temp2!=NULL)
		{
			curr->next=temp2;
			curr=curr->next;
			cout<<temp2->data<<"==>";
			temp2=temp2->next;
		}
		
	}
}
	

int main()
{
	node*head=NULL;
	Buildlist(head);

	print(head);
	
	rearrange(head);

	return 0;


}
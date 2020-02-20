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

bool searchrec(node*head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	if(head->data==key)
	{
		return true;
	}
	else 
	{
		return searchrec(head->next,key);
	}
}

bool searchiterative(node*head,int key)
{
	while(head!=NULL)
	{
		if(head->data==key)
			return true;
		head=head->next;
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
	insertathead(head,8);
	insertathead(head,17);
	insertathead(head,5);
	insertathead(head,6);
	insertathead(head,3);
	insertathead(head,7);
	insertathead(head,1);
	print(head);
	cout<<endl;
	if(searchrec(head,5))
	{
		cout<<"element found through recursive";
	}
	else
	{
		cout<<"element not found";
	}
	cout<<endl;

	if(searchiterative(head,2))
	{
		cout<<"element found through iteration";
	}
	else
	{
		cout<<"element not found";
	}

	return 0;


}
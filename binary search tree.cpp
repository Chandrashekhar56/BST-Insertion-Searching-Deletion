#include <bits/stdc++.h>
using namespace std;
struct create_node {
	int data_part;
	struct create_node *left_part, *right_part;
};
create_node* new_node(int value)
{
	create_node* temporary_pointer = new create_node;
	temporary_pointer->data_part = value;
	temporary_pointer->left_part = temporary_pointer->right_part = NULL;
	return temporary_pointer;
}
void inorder_traversal(create_node* root_node)
{
	if (root_node != NULL)
    {
		inorder_traversal(root_node->left_part);
		printf("%d ", root_node->data_part);
		inorder_traversal(root_node->right_part);
	}
}
create_node* data_insert(create_node* ptr, int data_part)
{
	if (ptr == NULL)
		return new_node(data_part);
	if (data_part < ptr->data_part)
		ptr->left_part = data_insert(ptr->left_part, data_part);
	else
		ptr->right_part = data_insert(ptr->right_part, data_part);
	return ptr;
}
create_node* delete_node(create_node* root_node, int value)
{
	if (root_node == NULL)
		return root_node;
	if (root_node->data_part > value)
    {
		root_node->left_part = delete_node(root_node->left_part, value);
		return root_node;
	}
	else if (root_node->data_part < value)
    {
		root_node->right_part = delete_node(root_node->right_part, value);
		return root_node;
	}
	if (root_node->left_part == NULL)
	{
		create_node* temporary_pointer = root_node->right_part;
		delete root_node;
		return temporary_pointer;
	}
	else if (root_node->right_part == NULL)
	{
		create_node* temporary_pointer = root_node->left_part;
		delete root_node;
		return temporary_pointer;
	}
	else
	{

		create_node* successorParent = root_node;
		create_node* successor = root_node->right_part;
		while (successor->left_part != NULL)
        {
			successorParent = successor;
			successor = successor->left_part;
		}
		if (successorParent != root_node)
			successorParent->left_part = successor->right_part;
		else
			successorParent->right_part = successor->right_part;
		root_node->data_part = successor->data_part;
		delete successor;
		return root_node;
	}
}
bool search(create_node* root_node,int search_element)
{
	if(root_node == NULL)
	{
		return false;
	}
	else if(root_node->data_part == search_element)
	{
		return true;
	}
	else if(search_element<= root_node->data_part)
	{
		return search(root_node->left_part,search_element);
	}
	else
	{
		return search(root_node->right_part,search_element);
	}
}
int main()
{
	create_node* root_node = NULL;
	root_node = data_insert(root_node, 10);
	root_node = data_insert(root_node, 5);
	root_node = data_insert(root_node, 20);
	root_node = data_insert(root_node, 35);
	root_node = data_insert(root_node, 7);
	root_node = data_insert(root_node, 61);
	root_node = data_insert(root_node, 8);

    if(search(root_node,10) == true)
	cout<<"\n Element Found: "<<10<<"\n";
	else
	cout<<"\n Element Not Found: "<<10<<"\n";

	printf(" inorder_traversal : \n");
	inorder_traversal(root_node);

	printf("\nDelete 7\n");
	root_node = delete_node(root_node, 7);
	printf(" inorder_traversal : \n");
	inorder_traversal(root_node);

	printf("\nDelete 10\n");
	root_node = delete_node(root_node, 10);
	printf(" inorder_traversal : \n");
	inorder_traversal(root_node);


    if(search(root_node,10) == true)
	cout<<"\n Element Found: "<<10<<"\n";
	else
	cout<<"\n Element Not Found: "<<10<<"\n";

	return 0;
}

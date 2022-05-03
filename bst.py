class create_node:
	def __init__(self, value):
		self.value = value
		self.left_part= None
		self.right_part = None
		
def inorder_traversal(root_node):
	if root_node is not None:
		inorder_traversal(root_node.left_part)
		print(root_node.value, end=" ")
		inorder_traversal(root_node.right_part)
		
def data_insert(ptr, value):
	if ptr is None:
		return create_node(value)
	if value < ptr.value:
		ptr.left_part= data_insert(ptr.left_part, value)
	else:
		ptr.right_part = data_insert(ptr.right_part, value)
	return ptr
    
def delete_node(root_node, value):
	if root_node is None:
		return root_node
	    
	if value < root_node.value:
		root_node.left_part = delete_node(root_node.left_part, value)
		return root_node
	elif(value > root_node.value):
		root_node.right_part= delete_node(root_node.right_part, value)
		return root_node
	    
	if root_node.left_part is None and root_node.right_part is None:
		return None
	    
	if root_node.left_part is None:
		temporary_node = root_node.right_part
		root_node = None
		return temporary_node
	elif root_node.right_part is None:
		temporary_node = root_node.left_part
		root_node = None
		return temporary_node

	    
	successorParent = root_node
	successor = root_node.right_part
	while successor.left_part!= None:
		successorParent = successor
		successor = successor.left_part
	if successorParent != root_node:
		successorParent.left_part = successor.right_part
	else:
		successorParent.right_part= successor.right_part
	root_node.value = successor.value

	return root_node

def search(root_node,search_element):
    if root_node == None:
        print("\n Element Not Present: ",search_element)
    elif root_node.value == search_element:
        print("\n Element Present: ",search_element)
    elif search_element<= root_node.value:
        return search(root_node.left_part,search_element)
    else:
        return search(root_node.right_part,search_element)

root_node = None
root_node = data_insert(root_node, 10)
root_node = data_insert(root_node, 5)
root_node = data_insert(root_node, 20)
root_node = data_insert(root_node, 35)
root_node = data_insert(root_node, 7)
root_node = data_insert(root_node, 61)
root_node = data_insert(root_node, 8)

search(root_node,10)

print("inorder_traversal traversal:")
inorder_traversal(root_node)

print("\nDelete 7")
root = delete_node(root_node, 7)
print("inorder_traversal traversal:")
inorder_traversal(root_node)

print("\nDelete 10")
root = delete_node(root_node, 10)
print("inorder_traversal traversal:")
inorder_traversal(root_node)

search(root_node,10)

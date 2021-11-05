import math
r = None
def search(root,key):
     
    # Base Cases: root is null or key is present at root
    if root is None or root.val == key:
        return root
 
    # Key is greater than root's key
    if root.val < key:
        return search(root.right,key)
   
    # Key is smaller than root's key
    return search(root.left,key)
 
# This code is contributed by Bhavya Jain


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
 
# A utility function to insert
# a new node with the given key
 
 
def streamerOnline(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = streamerOnline(root.right, key)
        else:
            root.left = streamerOnline(root.left, key)
    return root
 
# A utility function to do inorder tree traversal
 
 
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)
 
 
# Driver program to test the above functions
# Let us create the following BST
#    50
#  /     \
# 30     70
#  / \ / \
# 20 40 60 80
 
# r = Node(50)
# r = insert(r, 30)
# r = insert(r, 20)
# r = insert(r, 40)
# r = insert(r, 70)
# r = insert(r, 60)
# r = insert(r, 80)
 
# # Print inoder traversal of the BST
# inorder(r)




def solution(streamerInformation):
    # Please write your code here.
    i = 0
    splitedSize = 3
    a_splited = [streamerInformation[x:x+splitedSize] for x in range(0, len(streamerInformation), splitedSize)]   
    for element in a_splited:
        if i == 0:
            r = Node(element)
            i += 1
        else:
            r = insert(r,element)    
 
    
    inorder(r)


    return ["a", "b"]

streamerInformation = ["Ninja",100000,"Fortnite","Pokimane",40000,"Valorant"]
solution(streamerInformation)


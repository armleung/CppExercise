# Searching Notes

## Type of Tree Traversals
```
Example Input : 
                50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
```
- Level Order Output : 50 -> 30 -> 70 -> 20 -> 40 -> 60 -> 80 
- InOrder Output (Left, Root, Right) (^): 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80
- PreOrder Output (Root, Left, Right) (/_): 50 -> 30 -> 20 -> 40 -> 70 -> 60 -> 80
- PostOrder Output (Left, Right, Root) (_\): 20 -> 40 -> 30 -> 60 -> 80 -> 70 -> 50

### InOrder
#### Algorithm 
1. Traverse the left subtree, i.e., call Inorder(left-subtree)
2. Visit the root.
3. Traverse the right subtree, i.e., call Inorder(right-subtree)
#### Usage
- Gives in non-decreasing order.

### PreOrder
#### Algorithm 
1. Visit the root.
2. Traverse the left subtree, i.e., call Preorder(left-subtree)
3. Traverse the right subtree, i.e., call Preorder(right-subtree)
#### Usage
- Used to create a copy of the tree
- Get prefix expression on of an expression tree

### PostOrder
#### Algorithm 
1. Traverse the left subtree, i.e., call Postorder(left-subtree)
2. Traverse the right subtree, i.e., call Postorder(right-subtree)
3. Visit the root.
#### Usage
- Used to delete the tree
- Get the postfix expression of an expression tree
BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	else {
		if (X < BST->Data)
			BST->Left=Insert(BST->Left, X);
		else
			BST->Right=Insert(BST->Right, X);
	}
	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	BinTree A, B;
	if (BST == NULL)
		printf("Not Found\n");
	else if (BST->Data > X)
		BST->Left = Delete(BST->Left, X);
	else if (BST->Data < X)
		BST->Right = Delete(BST->Right, X);
	else if (BST->Left == NULL&&BST->Right == NULL) {
		free(BST);
		return NULL;
	}
	else if (BST->Left == NULL&&BST->Right != NULL) {
		A = BST->Right;
		free(BST);
		return A;
	}
	else if (BST->Left != NULL&&BST->Right == NULL) {
		A = BST->Left;
		free(BST);
		return A;
	}
	else {
		A = BST->Right->Left;
		B = BST->Right;
		B->Left = BST->Left;
		free(BST);
		BST = B->Left;
		while (BST->Right)
			BST = BST->Right;
		BST->Right = A;
		return B;
	}
	return BST;
}
Position Find(BinTree BST, ElementType X)
{
	while (BST&&BST->Data != X) {
		if (BST->Data > X)
			BST = BST->Left;
		else
			BST = BST->Right;
	}
	if (BST)
		return BST;
	else
		return NULL;
}

Position FindMin(BinTree BST)
{
	while (BST&&BST->Left)
		BST = BST->Left;
	return BST;
}

Position FindMax(BinTree BST)
{
	while (BST&&BST->Right)
		BST = BST->Right;
	return BST;
}
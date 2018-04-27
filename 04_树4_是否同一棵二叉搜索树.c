#include<stdio.h>
#include<stdlib.h>

struct BinNode {
	int Data;
	struct BinNode* Left;
	struct BinNode* Right;
};
typedef struct BinNode* BinTree;

BinTree BinInsert(BinTree T, int n);
int Is(BinTree T1, BinTree T2);

int main(void)
{
	int i, j, k, N, L, m;
	BinTree T1, T2;

	scanf("%d", &N);
	while (N != 0) {
		T1 = NULL;
		scanf("%d", &L);
		for (i = 0; i < N; i++) {
			scanf("%d", &m);
			T1 = BinInsert(T1, m);
		}
		for (i = 0; i < L; i++) {
			T2 = NULL;
			for (j = 0; j < N; j++) {
				scanf("%d", &m);
				T2 = BinInsert(T2, m);
			}
			if (Is(T1, T2))
				printf("Yes\n");
			else
				printf("No\n");
		}
		scanf("%d", &N);
	}
}

BinTree BinInsert(BinTree BST, int n)
{
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct BinNode));
		BST->Data = n;
		BST->Left = BST->Right = NULL;
	}
	else { 
		if (n < BST->Data)
			BST->Left = BinInsert(BST->Left, n);   
		else  if (n > BST->Data)
			BST->Right = BinInsert(BST->Right, n); 
											
	}
	return BST;
}

int Is(BinTree T1, BinTree T2) {
	if (T1 == NULL&&T2 == NULL)
		return 1;
	else if ((T1 == NULL&&T2 != NULL) || (T1 != NULL&&T2 == NULL))
		return 0;
	else if (T1->Data != T2->Data)
		return 0;
	else
		return Is(T1->Left, T2->Left) && Is(T1->Right, T2->Right);
}
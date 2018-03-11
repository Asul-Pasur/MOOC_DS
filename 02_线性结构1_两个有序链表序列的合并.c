List Merge(List L1, List L2)
{
	List L, p;
	L = (List)malloc(sizeof(struct Node));
	p = L;
	while (L1->Next && L2->Next) {
		if (L1->Next->Data < L2->Next->Data) {
			p->Next = L1->Next;
			L1->Next = L1->Next->Next;
			p = p->Next;
		}
		else {
			p->Next = L2->Next;
			L2->Next = L2->Next->Next;
			p = p->Next;
		}
	}
	if (L1->Next) {
		p->Next = L1->Next;
		L1->Next = NULL;
	}
	else {
		p->Next = L2->Next;
		L2->Next = NULL;
	}
	return L;
}
Position BinarySearch(List L, ElementType X)
{
	int f, l;
	int i, p;
	f = 1;
	l = L->Last;
	i = (f + l) / 2;
	while (X != L->Data[i]) {
		if (f >= l) {
			p = 0;
			break;
		}
		else if (X > L->Data[i]) {
			f = i + 1;
			i = (f + l) / 2;
		}
		else if (X < L->Data[i]) {
			l = i - 1;
			i = (f + l) / 2;
		}
	}
	if (X == L->Data[i])
		p = i;
	if (p == 0)
		return NotFound;
	else
		return p;
}
template <typename T>
void insertionSort(T*a, int size)
{
	for (int ind = 1; ind < size; ind++)
			for (int tmpInd = ind; (tmpInd != 0) && (a[tmpInd] < a[tmpInd - 1]); tmpInd--)
				swap(a[tmpInd], a[tmpInd - 1]);
}
template <typename T>
void bubbleSort(T*a,int size)
{
	int limit = 0;
	bool fl = true;
	while(fl)
	{
		fl = false;
		for(int i = 0; i < size - 1 - limit; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				fl = true;
			}
		limit++;
	}
}
template <typename T>
void selectionSort(T*a, int size)
{
	int minInd;
	for(int i = 0; i < size; i++)
	{
		minInd = i;
		for(int j = i + 1; j<size; j++)
			if(a[j] < a[minInd])
				minInd = j;
		swap (a[i], a[minInd]);
	}
}
template <typename T>
void quickSort(T*arr, int first, int last)
{
	int left, right;
	T mid;
	left = first, right = last, mid = arr[(first + last) / 2];
	do
	{
		while (arr[left] < mid) left++;
		while (arr[right] > mid) right--;
		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++; right--;
		}
	} while (left <= right);
	if (left < last)
		quickSort(arr, left, last);
	if (right > first)
		quickSort(arr, first, right);
}
template <typename T>
void quickSort_stack(T* a, int size)
{
	struct gran
	{
		int m_left, m_right;
	};
	int tmpL, tmpR;
	int left, right, midInd, k = 1;
	T mid;
	gran* stack = new gran[size];
	stack[k].m_left = 0;
	stack[k].m_right = size - 1;
	do
	{
		left = stack[k].m_left;
		right = stack[k].m_right;
		k--;
		do
		{
			midInd = (left + right) / 2;
			mid = a[midInd];
			tmpL = left;
			tmpR = right;
			do
			{
				while (a[tmpL] < mid) tmpL++;
				while (a[tmpR] > mid) tmpR--;
				if (tmpL <= tmpR)
				{
					swap(a[tmpL], a[tmpR]);
					tmpL++;
					tmpR--;
				}
			} while (tmpL <= tmpR);


				if (tmpL < midInd)
				{
					if (tmpL < right)
					{
						k++;
						stack[k].m_left = tmpL;
						stack[k].m_right = right;
					}
					right = tmpR;
				}
				else
				{
					if (tmpR > left)
					{
						k++;
						stack[k].m_left = left;
						stack[k].m_right = tmpR;
					}
					left = tmpL;
				}

		} while (tmpL < tmpR);
	} while (k != 0);
	
	delete[] stack;
}
template <typename T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}
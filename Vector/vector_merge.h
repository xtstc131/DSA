#pragma once
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
	T * A = _elem + lo;
	auto lb = mi - lo; T * B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	auto lc = hi - mi; T*C = _elem + mi;
	for(Rank  i =0 ,j =	0,k	= 0; j<lb ;)
	{
		if ((k < lc) && (C[k] < B[j]))A[i++] = C[k++];
		if ((lc <= k) || (B[j] <= C[k])) A[i++] = B[j++];
	}
	delete[]B;
}
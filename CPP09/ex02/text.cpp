template< typename T >
void    PmergeMe::sort(T& to_sort)
{
	T main;
	T temp;
	for (size_t i = 0; i < to_sort.size() - 1; i += 2)
	{
		if (to_sort[i] > to_sort[i + 1])
		{
			std::swap(to_sort[i], to_sort[i + 1]);
		}
	}
	if (to_sort.size() > 2)
	{
		for (size_t i = 0; i < to_sort.size(); i+= 2)
		{
			main.push_back(to_sort[i]);
			if (i < to_sort.size() - 1)
				temp.push_back(to_sort[i + 1]);
		}
		sort(temp);
		size_t pendSize = main.size();
		for (size_t i = 0; i < pendSize; i++)
		{
			size_t j = 0;
			size_t sortIndex = 0;
			for (; _jacobsthal(j) < i; j++) {}
			if (j)
			{
				if (_jacobsthal(j) >= pendSize - 1)
					sortIndex = pendSize - (i - _jacobsthal(j - 1));
				else
					sortIndex = _jacobsthal(j) + 1 - (i- _jacobsthal(j - 1));
			}
			_binarySearchInsert(temp, main[sortIndex]);
		}
		to_sort = temp;
	}
}

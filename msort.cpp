#include <string>
using std::string;

#include <vector>
using std::vector;

template<class T>
inline void merge(T low, T mid, T high) {
	
	T i = low;
	T j = mid;


	std::vector<Person*> sorted(std::distance(low, high));
	auto it = sorted.begin();

	//while neither subarrays reached the end
	while (i < mid && j < high) {
		if ((**j) < (*i))
			(*it++) = std::move(*j++);

		else
			(*it++) = std::move(*i++);

	}
	
	//Move leftover subarray.
	if (j == high)
		std::move(i, mid, it);
	else
		std::move(j, high, it);
	
	//move the sorted array back
	std::move(std::begin(sorted), std::end(sorted), low);
}


template<class T>
void merge_sort(T low, T high) {

	int size = std::distance(low, high);

	if (size <= 1)
		return;

	T mid(low);
	std::advance(mid, size / 2);

	merge_sort(low, mid);
	merge_sort(mid, high);
	merge(low, mid, high);

}

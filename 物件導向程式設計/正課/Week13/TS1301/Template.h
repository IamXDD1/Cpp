#pragma once
template<typename Type>
void ItrBinarySearch(const Type a[], int first, int last, Type key, bool& found, int& location) {
	for (; first <= last;) {
		int mid = (last + first) / 2;
		if (key > a[mid]) {
			first = mid+1;
		}
		else if (key < a[mid]) {
			last = mid-1;
		}
		else if (key == a[mid]) { // ==
			found = true;
			location = mid;
			return;
		}
	}
	found = false;
}

template<typename Type>
void RecBinarySearch(const Type a[], int first, int last, Type key, bool& found, int& location) {
	if (first <= last) {
		int mid = (last + first) / 2;
		if (key > a[mid]) {
			RecBinarySearch(a, mid + 1, last, key, found, location);
		}
		else if (key < a[mid]) {
			RecBinarySearch(a, first, mid - 1, key, found, location);
		}
		else if (key == a[mid]) { // ==
			found = true;
			location = mid;
			return;
		}
	}
	else found = false;
	return;
}
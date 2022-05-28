#include "Counter.h"


template<class T>
vector<T> Counter<T>::most_common()
{
	sort(obj_count.begin(), obj_count.end(), cmp);

	vector<T> ans;
	for (int i = 0; i < obj_count.size(); i++) {
		ans.push_back(obj_count[i].first);
	}

	return ans;
}

template<class T>
vector<T> Counter<T>::most_common(int n)
{
	sort(obj_count.begin(), obj_count.end(), cmp);

	vector<T> ans;
	if (n > obj_count.size()) n = obj_count.size();
	for (int i = 0; i < n; i++) {
		ans.push_back(obj_count[i].first);
	}
	return ans;
}

template<class T>
int Counter<T>::total()
{
	int ans = 0;
	for (int i = 0; i < obj_count.size(); i++) {
		ans += obj_count[i].second;
	}
	return ans;
}

template<class T>
void Counter<T>::subtract()
{
	for (int i = 0; i < obj_count.size(); i++) {
		obj_count[i].second--;
	}

	for (map<T, int> it = this->_Unchecked_begin; it != this->_Unchecked_end; it++) {
		it->second--;
	}
}

template<class T>
void Counter<T>::subtract(T key)
{
	for (int i = 0; i < obj_count.size(); i++) {
		if (obj_count[i].first == key) obj_count[i].second--;
	}

	this->at(key)--;
}

template<class T>
void Counter<T>::subtract(vector<T> keys)
{
	for (int i = 0; i < obj_count.size(); i++) {
		if (obj_count[i].first == keys[i]) obj_count[i].second--;
	}

	for (int i = 0; i < keys.size(); i++) {
		this->at(keys[i])--;
	}
}

template<class T>
Counter<T> Counter<T>::operator+(Counter<T> a)
{
	Counter<T> temp;
	for (auto& it : this->obj_count) {
		if (temp.try_emplace(it.first, it.second).second == false) temp.at(it.first) += it.second;

		bool find = false;
		for (auto& tmp_obj : temp.obj_count)
			if (it->first == tmp_obj.first) {
				tmp_obj.second += it.second;
				find = true;
				break;
			}

		if (!find) obj_count.push_back({ it.first, it.second });
	}

	for (auto& it : a.obj_count) {
		if (temp.try_emplace(it.first, it.second).second == false) temp.at(it.first) += it.second;

		bool find = false;
		for (auto& tmp_obj : temp.obj_count)
			if (it->first == tmp_obj.first) {
				tmp_obj.second += it.second;
				find = true;
				break;
			}

		if (!find) obj_count.push_back({ it.first, it.second });
	}

	return temp;
}

template<class T>
Counter<T> Counter<T>::operator-(Counter<T> a)
{
	Counter<T> temp;
	for (auto& it : this->obj_count) {
		if (temp.try_emplace(it.first, it.second).second == false) temp.at(it.first) += it.second;

		bool find = false;
		for (auto& tmp_obj : temp.obj_count)
			if (it->first == tmp_obj.first) {
				tmp_obj.second += it.second;
				find = true;
				break;
			}

		if (!find) obj_count.push_back({ it.first, it.second });
	}

	for (auto& it : a.obj_count) {
		if (temp.try_emplace(it.first, it.second).second == false) temp.at(it.first) -= it.second;

		bool find = false;
		for (auto& tmp_obj : temp.obj_count)
			if (it->first == tmp_obj.first) {
				tmp_obj.second -= it.second;
				find = true;
				break;
			}

		if (!find) obj_count.push_back({ it.first, it.second });
	}

	return temp;
}

template<class T>
Counter<T> operator-(Counter<T> a)
{
	vector<T> ans;
	for (int i = 0; i < a.obj_count.size(); i++) {
		for (int j = 0; j < a.obj_count.second; j++) {
			ans.push_back(-a.obj_count.first);
		}
	}
	return Counter<T>(ans);
}

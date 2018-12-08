// set, map, multiset, multimap, unordered_set, unordered_map, unordered_multiset, unordered_multimap

#include <iostream> 
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
//#include <iterator>
using namespace std; 

int main() 
{ 
	/* set example */
	set<int> s1; 
	s1.insert(2); 
	s1.insert(5); 
	s1.insert(3);
	s1.insert(2); 
	s1.insert(6); 

	cout << "Elements in set:\n"; 
	for (auto it : s1) 
		cout << it << " "; // Sorted 
	cout << endl;


	/* map example */
    map<int, int> m; 
  
    m[1] = 2; // Insertion by indexing 
  
    // Direct pair insertion 
    m.insert({ 4, 5 }); 
  
    // Insertion of pair by make_pair 
    m.insert(make_pair(8, 5)); 
	m.insert(make_pair(8, 7)); 
	m.insert({ 4, 10 });
  
    cout << "Elements in map:\n"; 
    for (auto it : m) 
        cout << "[" << it.first << ", " 
             << it.second << "]\n"; // Sorted 


	/* multimap example */
    multimap<int, int> mm; 
  
    mm.insert({ 1, 2 }); 
    mm.insert({ 2, 3 }); 
    mm.insert({ 4, 5 }); 
    mm.insert({ 2, 7 }); 
    mm.insert({ 1, 2 }); 
  
    cout << "Elements in multimap:\n"; 
    for (auto it : mm) 
        cout << "[" << it.first << ", " 
             << it.second << "]\n"; // Sorted 


	/* multiset example */
    multiset<int> ms; 
  
    ms.insert(1); 
    ms.insert(3); 
    ms.insert(4); 
    ms.insert(2); 
    ms.insert(2); 
	ms.insert(3);
    cout << "Elements in multiset:\n"; 
    for (auto it : ms) 
        cout << it << " "; // Sorted
	cout << endl;


	/* unordered_set example */
    unordered_set<int> us; 
  
    us.insert(1); 
    us.insert(3); 
    us.insert(4); 
    us.insert(2); 
    us.insert(2); 
  
    cout << "Elements in unordered_set:\n"; 
    for (auto it : us) 
        cout << it << " ";
	cout << endl; 


	/* unordered_map example */
    unordered_map<int, int> um; 
  
    um[1] = 2; 
    um[4] = 5; 
    um[1] = 3; 
    um[8] = 5; 
    um[3] = 6; 
  
    cout << "Elements in unordered_map:\n"; 
    for (auto it : um) 
        cout << "[" << it.first << ", " << it.second << "]\n"; 


	/* unordered_multimap example */
    unordered_multimap<int, int> umm; 
  
    umm.insert({1,2}); 
    umm.insert(make_pair(4,5)); 
	umm.insert(pair <int, int> (1,3)); 
	umm.insert({8,5});
	umm.insert({3,6});
  
    cout << "Elements in unordered_multimap:\n"; 
    for (auto itr : umm) 
        cout << "[" << itr.first << ", " << itr.second << "]\n"; 


	/* unordered_multiset example */
    unordered_multiset<int> ums; 
  
    ums.insert(1); 
    ums.insert(3); 
    ums.insert(4); 
    ums.insert(2); 
    ums.insert(2); 
  
    cout << "Elements in unordered_multiset:\n"; 
    for (auto it : ums) 
        cout << it << " ";
	cout << endl; 

	return 0; 
} 


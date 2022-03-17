## queue

### 双端队列——deque
`deque`可以用来实现单调队列。

### 优先级队列——priority_queue
```cpp
// Defined in header <queue>
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

A user-provided Compare can be supplied to change the ordering, e.g. using `std::greater<T>` would cause the smallest element to appear as the `top()`.

```cpp
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
 
template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
 
int main() {
    std::priority_queue<int> q;
 
    const auto data = {1,8,5,6,3,4,0,9,7,2};
 
    for(int n : data)
        q.push(n);
 
    print_queue(q);
 
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        q2(data.begin(), data.end());
 
    print_queue(q2);
 
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
 
    for(int n : data)
        q3.push(n);
 
    print_queue(q3);
}
```
output:
```
9 8 7 6 5 4 3 2 1 0 
0 1 2 3 4 5 6 7 8 9 
8 9 6 7 4 5 2 3 0 1
```

### Lamda 表达式
```cpp
auto f = [c](int &a, int &b)->bool {
	a += c;
	return a > b;
};
``` 
### decltype

`decltype(f);`
- 如果实参是没有括号的标识表达式或没有括号的类成员访问表达式，那么`decltype`产生以该表达式命名的实体的类型。
- 在难以或不可能以标准写法进行声明的类型时，`decltype`很有用，例如 lambda 相关类型或依赖于模板形参的类型。


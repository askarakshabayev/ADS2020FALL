1. Syllabus, topics to be covered doring the semester

Week 1
GCD, Prime numbers, binpow ( = Euclid, = Eroatosphen)
Stack ( problems: brackets, feelgood?)
Queue 
Deque 

Week 2
Linked list
Doubly-linked list

Week 3
Linear Search
Binary Search
Complexity and memory

Week 4
Binary search tree
Applications

Week 5
Priority queue
Heapsort
Applications

Week 6
Merge sort
Quicksort

Week 7
Rabin-Karp
KMP

Week 8
Representation of graphs in computer: adjacency list and matrix, edge list. 		
Trie

Week 9
BFS.
DFS.
Topological Sort.


Week 10
Dijkstra
Ford Bellman
Floyd
Spanning tree algorithms (Kruskal, Prima)

3. Euclid

4. count of points problem

5. prime numbers - Eroatosphen

6. STL Stack

7. Example of Node 

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


8. Stack (push, pop, back, size, empty)
    * Bracket problem
    * Advanced bracket problem
9. Queue (push, pop, front, size, empty)
    * Queue problems 
        - from a to b (operations a + c, a - c1, a * c2)
        - chess problem



Link to problems https://informatics.mccme.ru/enrol/index.php?id=3782
ADS2020FALL

Lecture #2 Notes:
Queue
Simple problem on queue
How to find distance 
More complex problems (chess, labirint)
How to find path on chess and labirint problems
Bonus problem
LinkedList

Lecture #3
Linkedlist
linear search
Binary search
mid = (left + right) / 2; 
if (a[mid] < k) 
    left = mid + 1; 
else 
    right = mid;

Кубический корень из числа x (y^3 = x) Найти кубический корень с точностью не менее 5 знаков после точки
r = x;
l = 1;
while (fabs(l-r)>eps) {
  m=(l+r)/2;
  if (m*m*m<x) l=m;
  else r=m;
}

Задача про ксерокс. 
int x = min(i, j);
int y = max(i, j);

int l = 0;
int r = (n - 1) * y;
while (l != r) {
    m = (l + r) / 2;
    int j = m / x + m / y;
    if (j < n - 1)
        l = m + 1;
    else
        r = m;
}
cout << r + x;

Хорошие и плохие числа. 
Дается N прямоугольников размеров a*b, найти минимальный X, в который все это поместиться

minmax

week 4
quiz

week 5
BST

week 6
1. Heap (MaxHeap, MinHeap)
    * complete tree
    * min head or max heap
    * 0 - root
    * 2i + 1 - left child
    * 2i + 2 - right child
    * (i - 1) / 2 - parent
2. parent and child nodes
3. Heap sort, priority queue, shortest path algorithms (Deijkstra, spanning tree)
4. insert()
5. extractMin()
6. decreaseKey()
7. getMin()
8. delete()
9. MinHeap
    parent(int i)
    left(int i), right(int i)
    extractMin()
    decreaseKey(int i, int new_val)
    delete(int i)
    insert(int key)

week 7:
1. quicksort
2. mergesort

week 10
week 11 - Trie
1. Что такое графы
2. Ориентированные и неориентированные графы
3. Пути и циклы
4. Кратные рёбра и петли
5. Связные графы
6. Дерево - это связный граф без циклов, петель и кратных рёбер
    Количество рёбер связано с количеством вершин формулой E=V−1.
    Между любой парой вершин существует ровно один путь.
7. матрица смежности
    В качестве примера решим простую задачу: для каждой вершины графа выведем количество рёбер, смежных с ней.
    
    Преимущества матрицы смежности:
    Сложность проверки наличия ребра между двумя вершинами: O(1)
    
    Недостатки матрицы смежности:
    Занимает N^2 памяти, что неприемлемо для достаточно больших графов.
    Сложность перебора всех вершин, смежных с данной: O(N)
8. Список смежности
    Преимущества списка смежности:

    Использует O(M) памяти, что оптимально.
    Позволяет быстро перебирать соседей вершины.
    Позволяет за O(logN) проверять наличие ребра и удалять его (при использовании std::set).

9. BFS
    * минимальное расстояние
10. DFS
    * 


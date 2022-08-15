#include <iostream>
#include <vector>
#include <forward_list>
#include <utility>
#include <initializer_list>

template <typename K, typename V>
class Hash_table {
public:
    Hash_table();
    Hash_table(int);
    Hash_table(const Hash_table<K, V>&);
    Hash_table(Hash_table<K, V>&&);
    Hash_table(std::initializer_list<std::pair<K, V>>);
    ~Hash_table();
    V& operator[](K&&);
    friend std::ostream& operator<<(std::ostream& os, Hash_table<K, V>& obj) {
        for (int i = 0; i < obj.m_vec.size(); ++i) {
            if (obj.m_vec[i]) {
                auto it = obj.m_vec[i]->m_list.begin();
                for (it; it != obj.m_vec[i]->m_list.end(); ++it) {
                    os << it-> first << " " << it -> second << '\n';
                }
            }
        }
        return os;
    }
public:
    int H1_index(int, int);
    int simple(int size);
    void insert(K, V);
    void my_clear();
    void print();
private:
    struct List {
        std::forward_list<std::pair<K, V>> m_list;
    };
private:
    void rehash();
    int node_count;
    std::vector<List*> m_vec;
};
int main()
{
    Hash_table<int, std::string> s {{7,"ffff"},
                                    {99,"pppp"}
                                    };
    s.insert(8, "tttt");
    std::cout << s[7];
    std::cout << s;
}

template<typename K, typename V>
V& Hash_table<K, V>::operator[](K&& val)
{
    auto tmp = m_vec[0]->m_list.begin();
    for (int i = 0; i < m_vec.size(); ++i) {
        if (m_vec[i]) {
            auto it = m_vec[i]->m_list.begin();
            for (it; it != m_vec[i]->m_list.end(); ++it) {
                if (val == it->first) {
                    return it->second;
                }
            }
        }
    }
    return tmp->second;
}

template<typename K, typename V>
Hash_table<K, V>::Hash_table(std::initializer_list<std::pair<K, V>> init) :
    m_vec(7)
{
    for(auto it = init.begin(); it != init.end(); ++it) {
         insert(it->first, it->second);
    }
}

template<typename K, typename V>
void Hash_table<K,V>::print()
{
    for (int i = 0; i < m_vec.size(); ++i) {
        if (m_vec[i]) {
            auto it = m_vec[i]->m_list.begin();
            for (it; it != m_vec[i]->m_list.end(); ++it) {
                std::cout << it->first << " ";
                std::cout << it->second;
                std::cout << std::endl;
            }
        }
    }
}

template<typename K, typename V>
int Hash_table<K, V>::simple(int size)
{
    bool b = true;
    do {
    for (int i = 2; i <= size/2; ++i) {
    if (size % i == 0) {
        b = false;
    }
  }
    if (b) {
        return size;
    } else {
        ++size;
    }
    b = true;
    } while (b);
    return size;
}

template<typename K, typename V>
void Hash_table<K, V>::my_clear()
{
    for (int i = 0; i < m_vec.size(); ++i) {
        if (m_vec[i]) {
          m_vec[i]->m_list.clear();
        }
    }
}

template<typename K, typename V>
void Hash_table<K, V>::rehash()
{
    int size = simple(2 * m_vec.size());
    Hash_table<K, V> tmp(size);
    for (int i = 0; i < m_vec.size(); ++i) {
        if (m_vec[i]) {
            auto it = m_vec[i]->m_list.begin();
            for (it; it != m_vec[i]->m_list.end(); ++it) {
                 tmp.insert(it->first, it->second);
            }
        }
    }
    my_clear();
    m_vec = std::move(tmp.m_vec);
}

template<typename K, typename V>
void Hash_table<K, V>::insert(K key, V val)
{
    ++node_count;
    if (node_count == m_vec.size()) {
        node_count = 0;
        rehash();
    }
    int index = H1_index(key, m_vec.size());
    if (m_vec[index] == nullptr) {
        m_vec[index] = new List();
        m_vec[index]->m_list.push_front({key, val});
    } else {
        m_vec[index]->m_list.push_front({key, val});
    }
}

template<typename K, typename V>
Hash_table<K,V>::Hash_table(int size) :
    m_vec(size)
{
    for (int i = 0; i < m_vec.size(); ++i) {
        m_vec[i] = nullptr;
    }
    node_count = 0;
}
template<typename K, typename V>
int Hash_table<K, V>::H1_index(int key, int size)
{
    return (key % size);
}

template<typename K, typename V>
Hash_table<K, V>::Hash_table(const Hash_table<K, V>& obj)
{
    m_vec = obj.m_vec;
}

template<typename K, typename V>
Hash_table<K, V>::Hash_table(Hash_table<K, V>&& obj)
{
    m_vec = std::move(obj, m_vec);
}

template<typename K, typename V>
Hash_table<K, V>::Hash_table() :
    m_vec(7)
{
    for (int i = 0; i < m_vec.size(); ++i) {
        m_vec[i] = nullptr;
    }
    node_count = 0;
}
template<typename K, typename V>
Hash_table<K, V>::~Hash_table()
{
    my_clear();
}

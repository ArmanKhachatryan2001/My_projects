#include <iostream>
#include <initializer_list>

enum {bit_count = 8 * sizeof(size_t)};

class vector_b
{
public:
     vector_b();
     vector_b(const vector_b&);
     vector_b(vector_b&&);
     vector_b(std::initializer_list<bool>);
     vector_b(size_t);
     vector_b(size_t, bool);
     ~vector_b();
     void insert(size_t, bool);
     void push_back(bool);
     void pop_back();
     size_t empty();
     void print();
public:
    class referance {
    public:
        referance(size_t*, size_t);
        referance(const referance&);
        referance(referance&&);
        referance& operator=(const referance&);
        referance& operator=(referance&&);
        referance& operator=(bool);
        operator bool() const;
        void flip();
    private:
        size_t* ptr;
        size_t index;
        bool val;
    };
public:
     referance operator[](size_t);
private:
    size_t m_cap;
    size_t m_size;
    size_t* m_buf;
};

int main()
{
    vector_b b;
    b.insert(0,1);
    b.insert(1,1);
    b.insert(2,0);
    b.insert(3,1);
    b.push_back(1);
    b.push_back(1);
    b.pop_back();
    b.print();
}

void vector_b::pop_back()
{
    (*this)[m_size--] = false;
}

void vector_b::push_back(bool val)
{
    if (this->empty()) {
        m_cap = bit_count;
        m_buf = new size_t[1];
        m_buf[m_size++] = val;
        return;
    }
    if (m_size == m_cap) {
        m_cap += bit_count;
        size_t* pt = new size_t[m_cap / bit_count];
        for (int i = 0; i < (m_size / bit_count); ++i) {
            pt[i] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = pt;
        pt = nullptr;
    }
    (*this)[m_size++] = val;
}

void vector_b::print()
{
  for (int i = 0; i < m_size; ++i) {
        std::cout << (*this)[i] << " ";
  }
}

vector_b::referance vector_b::operator[](size_t pos)
{
    return vector_b::referance(m_buf,pos);
}

size_t vector_b::empty()
{
    if (m_size == 0) {
        return true;
    }
    return false;
}

void vector_b::insert(size_t pos, bool val)
{
    if (this->empty()) {
        m_cap = bit_count;
        m_buf =new size_t[1];
        m_buf[m_size++] = val;
        return;
    }
    if (m_size == m_cap) {
        m_cap += bit_count;
        size_t* pt = new size_t[m_cap / bit_count];
        for (int i = 0; i < (m_size / bit_count); ++i) {
            pt[i] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = nullptr;
        m_buf = pt;
        pt = nullptr;
    }
    for (int i = m_size; i > pos; --i) {
        (*this)[i] = (*this)[i - 1];
    }
    (*this)[pos] = val;
    ++m_size;
}

vector_b::~vector_b()
{
    delete[] m_buf;
    m_size = 0;
    m_cap = 0;
}

vector_b::vector_b(size_t count, bool val)
    :
        m_cap(0),
        m_size(count),
        m_buf(nullptr)
{
    if (count) {
        while (count > m_cap) {
            m_cap += count;
        }
        m_buf = new size_t[m_cap / bit_count];
        if (val) {
            size_t bit = 1;
            for (int i = 0; i < m_size; ++i) {
                m_buf[i / bit_count] |= bit;
                bit <<= 1;
            }
        }
    }
}


vector_b::vector_b(size_t count) :
    m_cap(0),
    m_size(count),
    m_buf(nullptr)
{
    if (count) {
        while (m_cap < count) {
        m_cap += bit_count;
        }
        m_buf = new size_t[m_cap / bit_count];
    }

}


vector_b::vector_b(std::initializer_list<bool> init)
    :
        m_cap(0),
        m_size(init.size()),
        m_buf(nullptr)
{
    if (init.size()) {
        while (m_cap < init.size()) {
            m_cap += bit_count;
        }
        size_t bit = 1;
        int i = 0;
        m_buf = new size_t[m_cap / bit_count];
        for (auto it = init.begin(); it != init.end(); ++it, ++i) {
            if (*it) {
                m_buf[i / bit_count] |= (1 <<(i % bit_count));
            }
            bit <<= 1;
        }
    }
}

vector_b::vector_b(vector_b&& oth)
    :
        m_buf(oth.m_buf),
        m_size(oth.m_size),
        m_cap(oth.m_cap)
{
    oth.m_buf = nullptr;
    m_size = 0;
    m_cap = 0;
}

vector_b::vector_b(const vector_b& oth)
    :
        m_size(oth.m_size),
        m_cap(oth.m_cap)
{
    m_buf = new size_t[m_cap / bit_count];
    for (int i = 0; i < (m_cap / bit_count); ++i) {
        m_buf[i] = oth.m_buf[i];
    }
}

vector_b::vector_b()
    :
        m_buf(nullptr),
        m_size(0),
        m_cap(0)
{}

vector_b::referance::operator bool() const
{
    return val;
}

vector_b::referance& vector_b::referance::operator=(bool val)
{
    if (this->val != val) {
        this->flip();
    }
    return *this;
}

vector_b::referance& vector_b::referance::operator=(vector_b::referance&& oth) {
    ptr = oth.ptr;
    index = oth.index;
    val = oth.val;

    oth.ptr = nullptr;
    oth.index = 0;
    oth.val = false;
    return *this;
}

vector_b::referance& vector_b::referance::operator=(const vector_b::referance& oth) {
    if (val != oth.val) {
        this->flip();
    }
    return *this;
}

vector_b::referance::referance(vector_b::referance&& oth)
    :
        ptr(oth.ptr),
        index(oth.index),
        val(oth.val)
{
    oth.ptr = nullptr;
    oth.index = 0;
    oth.val = false;
}

vector_b::referance::referance(size_t* pt, size_t ind)
    :
        ptr(pt),
        index(ind),
        val(0)
{
    val = ptr[index / bit_count] & (1 << (index % bit_count));
}

vector_b::referance::referance(const vector_b::referance& oth)
    :
        ptr(oth.ptr),
        index(oth.index),
        val(oth.val)
{}

void vector_b::referance::flip()
{
        ptr[index/bit_count] ^= (1 << (index % bit_count));
        val = (!val);
}

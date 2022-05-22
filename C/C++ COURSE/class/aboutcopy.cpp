/*
参考源码转载来源:https://blog.csdn.net/wuqindeyunque/article/details/81488113?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165323277116781432964055%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165323277116781432964055&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-81488113-null-null.142^v10^control,157^v4^control&utm_term=%E8%BE%93%E5%87%BA%E6%B5%81%E8%BF%AD%E4%BB%A3%E5%99%A8&spm=1018.2226.3001.4187
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
/*
c++中的流迭代器是迭代器中一种特殊的迭代器，其中包含两种迭代器：
输入流迭代器(istream_iterator)，输出流迭代器(ostream_iterator)。
使用这两种迭代器可以把输入输出流当作*容器*来操作。（头文件iterator)
*/
int main()
{
    //鉴于本人当前学习水平，普通用法:
    vector<int> num;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_insert_iterator<vector<int>>(num));
    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " niconico~ ")); //最后一个输出流迭代器的括号内第二个参数可以改变，表示输出元素用什么间隔
    return 0;
    //其他均可照搬
}
/*
back_insert_iterator 等价于 num.push_back()
*/

/*
copy原型:

template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last,
              OutputIt d_first)
{
    while (first != last) {
        *d_first++ = *first++;
    }
    return d_first;
}
*/

/*
istream_iterator原型:

template <class _Tp,
          class _CharT = char, class _Traits = char_traits<_CharT>,
          class _Dist = ptrdiff_t>
class istream_iterator {
public:
  typedef _CharT                         char_type;
  typedef _Traits                        traits_type;
  typedef basic_istream<_CharT, _Traits> istream_type;

  typedef input_iterator_tag             iterator_category;
  typedef _Tp                            value_type;
  typedef _Dist                          difference_type;
  typedef const _Tp*                     pointer;
  typedef const _Tp&                     reference;

  istream_iterator() : _M_stream(0), _M_ok(false) {}
  istream_iterator(istream_type& __s) : _M_stream(&__s) { _M_read(); }//有参构造函数，以构造就会执行_M_read()函数

  reference operator*() const { return _M_value; }
  pointer operator->() const { return &(operator*()); }

  istream_iterator& operator++() { //每次前置++会执行一次_M_read函数一次
    _M_read();
    return *this;
  }
  istream_iterator operator++(int)  {//和前置++差不多
    istream_iterator __tmp = *this;
    _M_read();
    return __tmp;
  }

  bool _M_equal(const istream_iterator& __x) const//判断终止条件的关键
    { return (_M_ok == __x._M_ok) && (!_M_ok || _M_stream == __x._M_stream); }

private:
  istream_type* _M_stream;///数据成员
  _Tp _M_value;
  bool _M_ok;

  void _M_read() {
    _M_ok = (_M_stream && *_M_stream) ? true : false;//流不为空，且流状态ok时_M_ok为true
    if (_M_ok) {
      *_M_stream >> _M_value;
      _M_ok = *_M_stream ? true : false;
    }
  }
};

template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool
operator==(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return __x._M_equal(__y);
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool
operator!=(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return !__x._M_equal(__y);
}
*/

/*
ostream_iterator原型:
template <class _Tp,
          class _CharT = char, class _Traits = char_traits<_CharT> >
class ostream_iterator {
public:
  typedef _CharT                         char_type;
  typedef _Traits                        traits_type;
  typedef basic_ostream<_CharT, _Traits> ostream_type;

  typedef output_iterator_tag            iterator_category;
  typedef void                           value_type;
  typedef void                           difference_type;
  typedef void                           pointer;
  typedef void                           reference;

  ostream_iterator(ostream_type& __s) : _M_stream(&__s), _M_string(0) {}
  ostream_iterator(ostream_type& __s, const _CharT* __c)
    : _M_stream(&__s), _M_string(__c)  {}
  ostream_iterator<_Tp>& operator=(const _Tp& __value) {
    *_M_stream << __value;
    if (_M_string) *_M_stream << _M_string;
    return *this;
  }
  ostream_iterator<_Tp>& operator*() { return *this; }
  ostream_iterator<_Tp>& operator++() { return *this; }
  ostream_iterator<_Tp>& operator++(int) { return *this; }
private:
  ostream_type* _M_stream;
  const _CharT* _M_string;
};

template<class _CharT, class _Traits>
class istreambuf_iterator
  : public iterator<input_iterator_tag, _CharT,
                    typename _Traits::off_type, _CharT*, _CharT&>
{
public:
  typedef _CharT                           char_type;
  typedef _Traits                          traits_type;
  typedef typename _Traits::int_type       int_type;
  typedef basic_streambuf<_CharT, _Traits> streambuf_type;
  typedef basic_istream<_CharT, _Traits>   istream_type;

public:
  istreambuf_iterator(streambuf_type* __p = 0) { this->_M_init(__p); }
  istreambuf_iterator(istream_type& __is) { this->_M_init(__is.rdbuf()); }

  char_type operator*() const
    { return _M_is_initialized ? _M_c : _M_dereference_aux(); }

  istreambuf_iterator& operator++() { this->_M_nextc(); return *this; }
  istreambuf_iterator  operator++(int) {
    if (!_M_is_initialized)
      _M_postincr_aux();
    istreambuf_iterator __tmp = *this;
    this->_M_nextc();
    return __tmp;
  }

  bool equal(const istreambuf_iterator& __i) const {
    return this->_M_is_initialized && __i._M_is_initialized
      ? this->_M_eof == __i._M_eof
      : this->_M_equal_aux(__i);
  }

private:
  void _M_init(streambuf_type* __p) {
    _M_buf = __p;
    _M_eof = !__p;
    _M_is_initialized = _M_eof;
  }

  char_type _M_dereference_aux() const;
  bool _M_equal_aux(const istreambuf_iterator&) const;
  void _M_postincr_aux();

  void _M_nextc() {
    int_type __c = _M_buf->snextc();
    _M_c = traits_type::to_char_type(__c);
    _M_eof = traits_type::eq_int_type(__c, traits_type::eof());
    _M_is_initialized = true;
  }

  void _M_getc() const {
    int_type __c = _M_buf->sgetc();
    _M_c = traits_type::to_char_type(__c);
    _M_eof = traits_type::eq_int_type(__c, traits_type::eof());
    _M_is_initialized = true;
  }

private:
  streambuf_type* _M_buf;
  mutable _CharT _M_c;
  mutable bool _M_eof : 1;
  mutable bool _M_is_initialized : 1;
};

template<class _CharT, class _Traits>
_CharT istreambuf_iterator<_CharT, _Traits>::_M_dereference_aux() const
{
  this->_M_getc();
  return _M_c;
}

template<class _CharT, class _Traits>
bool istreambuf_iterator<_CharT, _Traits>
  ::_M_equal_aux(const istreambuf_iterator& __i) const
{
  if (!this->_M_is_initialized)
    this->_M_getc();
  if (!__i._M_is_initialized)
    __i._M_getc();

  return this->_M_eof == __i._M_eof;
}

template<class _CharT, class _Traits>
void istreambuf_iterator<_CharT, _Traits>::_M_postincr_aux()
{
  this->_M_getc();
}

template<class _CharT, class _Traits>
inline bool operator==(const istreambuf_iterator<_CharT, _Traits>& __x,
                       const istreambuf_iterator<_CharT, _Traits>& __y) {
  return __x.equal(__y);
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER

template<class _CharT, class _Traits>
inline bool operator!=(const istreambuf_iterator<_CharT, _Traits>& __x,
                       const istreambuf_iterator<_CharT, _Traits>& __y) {
  return !__x.equal(__y);
}
template<class _CharT, class _Traits>
class ostreambuf_iterator
  : public iterator<output_iterator_tag, void, void, void, void>
{
public:
  typedef _CharT                           char_type;
  typedef _Traits                          traits_type;
  typedef typename _Traits::int_type       int_type;
  typedef basic_streambuf<_CharT, _Traits> streambuf_type;
  typedef basic_ostream<_CharT, _Traits>   ostream_type;

public:
  ostreambuf_iterator(streambuf_type* __buf) : _M_buf(__buf), _M_ok(__buf) {}
  ostreambuf_iterator(ostream_type& __o)
    : _M_buf(__o.rdbuf()), _M_ok(__o.rdbuf() != 0) {}

  ostreambuf_iterator& operator=(char_type __c) {
    _M_ok = _M_ok && !traits_type::eq_int_type(_M_buf->sputc(__c),
                                               traits_type::eof());
    return *this;
  }

  ostreambuf_iterator& operator*()     { return *this; }
  ostreambuf_iterator& operator++()    { return *this; }
  ostreambuf_iterator& operator++(int) { return *this; }

  bool failed() const { return !_M_ok; }

private:
  streambuf_type* _M_buf;
  bool _M_ok;
};
*/
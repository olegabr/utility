//
//    Copyright 2003 � The Trustees of Indiana University.
//
//    See the file enable_if_LICENSE for licensing conditions.
//
//    Authors: Jaakko J�rvi (jajarvi at osl.iu.edu)
//             Jeremiah Willcock (jewillco at osl.iu.edu)
//             Andrew Lumsdaine (lums at osl.iu.edu)
//

#include <boost/test/minimal.hpp>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>

using boost::enable_if;
using boost::disable_if;
using boost::is_arithmetic;

template <int N> struct dummy {
  dummy(int) {};
};

template<class T>
typename enable_if<is_arithmetic<T>, bool>::type
arithmetic_object(T t, dummy<0> = 0) { return true; }

template<class T>
typename disable_if<is_arithmetic<T>, bool>::type
arithmetic_object(T t, dummy<1> = 0) { return false; }


int test_main(int, char*[])
{
 
  BOOST_TEST(arithmetic_object(1));
  BOOST_TEST(arithmetic_object(1.0));

  BOOST_TEST(!arithmetic_object("1"));  
  BOOST_TEST(!arithmetic_object(static_cast<void*>(0)));  

  return 0;
}

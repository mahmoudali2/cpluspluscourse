#include <iostream>
#include <cmath>
#include <compare>

/*

We are not fully happy with the default implementation of `<=>`for our `Complex` class below.
1. Modify it so that the ordering is based on the norm of the complexes.
2. Because you do not use any more the default implementation of `<=>` you had to provide also an implementation for `==`. What happens if you deduce it from `<=>` (using `(((*this)<=>other)==0)`) ?
3. Try to restore the default implementation for `==` only.

*/

struct Complex
 {
  double r, i ;
  double norm() const { return std::sqrt(r*r+i*i) ; }
  auto operator<=>( Complex const & other ) const = default ;
 } ;

std::ostream & operator<<( std::ostream & os, std::partial_ordering cmp )
 { return (os<<'<'<<(cmp<0)<<'|'<<(cmp==0)<<'|'<<(cmp>0)<<'>') ; }

std::ostream & operator<<( std::ostream & os, Complex const & c )
 { return (os<<c.r<<'+'<<c.i<<'i') ; }

template <typename T>
void compare( T lhs, T rhs )
 {
  std::cout<<std::endl ;
  std::cout<<lhs<<" ==  "<<rhs<<" : "<<(lhs==rhs)<<std::endl ;
  std::cout<<lhs<<" <=> "<<rhs<<" : "<<(lhs<=>rhs)<<std::endl ;
 }

int main()
 {
  compare<Complex>({ 1., 2. },{ 1.5, 1.5 }) ;
  compare<Complex>({ 1., 0. },{ 0., 1. }) ;
  std::cout<<std::endl ;
 }

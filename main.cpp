#include <iostream>
#include <Math.h>
double variant1( double res, int temp, int n, double sum )
{
	res = cos( (double)res ) * sqrt( (double)temp ) / 5;
	sum += res;
	return ( temp==n ? sum : variant1( res, temp+1, n, sum) );
}
double variant2( int n, double res, double &sum )
{
	if( n>1 ) res = cos( variant2(n-1,res, sum) ) * sqrt( (double)n ) / 5;
	sum += res;
	return res;
}
double variant3( int temp, int n, double res )
{
	res = cos( (double)res ) * sqrt( (double)temp ) / 5;
	return ( temp==n ? 1+res : res+variant3( temp+1, n, res) );
}
int main()
{
	int n;
	double result = 0;
	std::cout<<"Enter number: ";
	std::cin>>n;
	std::cout<<"Sum(first variant): "<<( n==1 ? 1 : variant1( 1, 2, n, 1) )<<std::endl;
	variant2( n, 1, result );
	std::cout<<"Sum(second variant): "<<result<<std::endl;
	std::cout<<"Sum(third variant): "<<( n==1 ? 1 : variant3( 2, n, 1 ) )<<std::endl;
	return 0;
}
#include <iostream>
#include <Math.h>
using namespace std;
double variant1( double rez, int temp, int n, double sum )
{
	rez = cos( (double)rez ) * sqrt( (double)temp ) / 5;
	sum += rez;
	return ( temp==n ? sum : variant1( rez, temp+1, n, sum) );
}
double variant2( int n, double rez, double &sum )
{
	if( n>1 ) rez = cos( variant2(n-1,rez, sum) ) * sqrt( (double)n ) / 5;
	sum += rez;
	return rez;
}
double variant3( int temp, int n, double rez )
{
	rez = cos( (double)rez ) * sqrt( (double)temp ) / 5;
	return ( temp==n ? 1+rez : rez+variant3( temp+1, n, rez) );
}
int main()
{
	int n;
	double rezult = 0;
	setlocale(LC_ALL,"Russian");
	cout<<"¬ведiть число: ";
	cin>>n;
	cout<<"—ума(варiант перший): "<<( n==1 ? 1 : variant1( 1, 2, n, 1) )<<endl;
	variant2( n, 1, rezult );
	cout<<"—ума(варiант другий): "<<rezult<<endl;
	cout<<"—ума(варiант третiй): "<<( n==1 ? 1 : variant3( 2, n, 1 ) )<<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <map>
 
using namespace std;
 
int const N = 8;
int const pow_10[N] = { 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
 
class card
{
    static int const Offset = 1;
 
public:
    template<typename T>
    card( T const& t )
    {
        for( int y=0; y<2; ++y ) {
            for( int x=0; x<N/2; ++x ) {
                num_[y][x] = t[y*N/2+x] + Offset;
                if ( num_[y][x] == Offset ) {
                    x0_ = x;
                    y0_ = y;
                }
            }
        }
    }
 
public:
    card make_moved( int const dir ) const
    {
        card ret( *this );
 
        switch( dir )
        {
        case 0:
            ret.to_up();
            break;
        case 1:
            ret.to_right();
            break;
        case 2:
            ret.to_down();
            break;
        case 3:
            ret.to_left();
            break;
        }
 
        return ret;
    }
 
public:
    operator long long int() const
    {
        long long int  p = 0;
 
        for( int y=0; y<2; ++y ) {
            for( int x=0; x<N/2; ++x ) {
                p += num_[y][x] * pow_10[y*N/2+x];
            }
        }
 
        return p;
    }
     
    bool operator==( card const& rhs ) const
    {
        return static_cast<long long int>( *this ) == static_cast<long long int>( rhs );
    }
 
    bool operator<( card const& rhs ) const
    {
        return static_cast<long long int>( *this ) < static_cast<long long int>( rhs );
    }
 
private:
    void to_down()
    {
        if ( y0_ == 0 ) {
            swap( num_[y0_][x0_], num_[y0_+1][x0_] );
            ++y0_;
        }
    }
 
    void to_up()
    {
        if ( y0_ == 1 ) {
            swap( num_[y0_][x0_], num_[y0_-1][x0_] );
            --y0_;
        }
    }
 
    void to_right()
    {
        if ( x0_ != N/2-1 ) {
            swap( num_[y0_][x0_], num_[y0_][x0_+1] );
            ++x0_;
        }
    }
 
    void to_left()
    {
        if ( x0_ != 0 ) {
            swap( num_[y0_][x0_], num_[y0_][x0_-1] );
            --x0_;
        }
    }
 
private:
    int num_[2][4];
    int x0_, y0_;
};
 
 
int main()
{
    int const start[N] = {0, 1, 2, 3, 4, 5, 6, 7 };
 
    map<card, int> costs;
    queue<pair<int, card> > q;
    q.push( make_pair( 0, card( start ) ) );
 
    // loop
    while( !q.empty() ) {
        int const cost = q.front().first;
        card const c = q.front().second;
        q.pop();
 
        if ( costs.find(c) != costs.end() ) continue;
        costs[c] = cost;
 
        for( int i=0; i<4; ++i ) {
            card const nc = c.make_moved( i );
            if ( nc == c ) continue;
 
            q.push( make_pair( cost + 1, nc ) );
        }
    }
 
 
    for(int r=0; r<1000; ++r ) {
        if ( cin.eof() )
            break;
 
        int nn[N];
        for( int i=0; i<N; ++i ) {
            cin >> nn[i];
	    if ( cin.eof() ) return 0;
        }
        card const f( nn );
 
        cout << costs.at( f ) << endl;
    }
}

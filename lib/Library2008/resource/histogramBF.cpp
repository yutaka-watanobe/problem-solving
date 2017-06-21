int getRectangleAreaBF( int size, int buffer[] ){
    int maxv = 0;
    for ( int i = 0; i < size; i++ ){
	for ( int j = i; j < size; j++ ){
	    int minh = INT_MAX;
	    for ( int k = i; k <= j; k++ ){
		minh = min( minh, buffer[k] );
	    }
	    maxv = max( maxv, minh*(j-i+1));
	}
    }
    return maxv;
}

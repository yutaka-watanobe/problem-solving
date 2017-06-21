int Q[ LIMIT + 1];
  int head, tail;

bool empty(){
    return head == tail;
  }

  void init(){
    head = tail = 1;
  }

  void push( int x ){
    Q[ tail ] = x;
    if ( tail == LIMIT ){
      tail = 0;
    } else {
      tail++;
    }
  }

  int front(){
    int x = Q[ head ];
    if ( head == LIMIT ){
      head = 1;
    } else {
      head++;
    }
    return x;
  }

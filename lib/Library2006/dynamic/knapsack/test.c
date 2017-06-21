#include<stdio.h>
#define MAX_SIZE 5
typedef struct {			
  int    price;	
  int    size;	
  int    count;
} ITEM;

int knap_size;
int item_number;

ITEM item_list[MAX_SIZE];

void read_data( void )
{
  int    i;
  scanf("%d", &knap_size );
  for( i = 0; i < MAX_SIZE; i++ ){
    int    price, size;
    if( scanf("%d %d", &price, &size ) < 2 ) break;
    item_list[i].price = price;
    item_list[i].size  = size;
    item_list[i].count = 0;
  }
  item_number = i;
} 


void knap( void )
{
  int    i, *gain, *choice;
  if( (gain = calloc( knap_size + 1, sizeof( int ) )) == NULL ||
      (choice = calloc( knap_size + 1, sizeof( int ) )) == NULL ){
    fprintf( stderr, "メモリが足りません\n" );
    exit( 1 );
  }
  for( i = 0; i < item_number; i++ ){
    int    size  = item_list[i].size;
    int    price = item_list[i].price;
    int    j;
    for( j = size; j <= knap_size; j++ ){
      int    space = j - size;
      int    new_value = price + *(gain + space);
      if( *(gain + j) < new_value ){
	*(gain + j) = new_value;
	*(choice + j) = i;
      }
    }
  }
  /* ナップザックの中を表示する */
  
  for( i = knap_size; i > 0; ){
    int    k = *(choice + i);
    item_list[k].count++;
    i -= item_list[k].size;
  }
  for( i = 0; i < item_number; i++ ){
    printf("No %d: price %d, size %d, 個数 %d\n", i,
	   item_list[i].price, item_list[i].size, item_list[i].count);
  }
}

main(){
  read_data();
  knap();
  return 0;
}

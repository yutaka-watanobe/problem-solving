/*******************
 * Hafman encoding *
 *******************/
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#define SIZE 999999
#define uchar unsigned char
#define LEFT 0
#define RIGHT 1
void downheap(int k,int n);

static int heap[256], w[512], index[256], left[512], right[512];

void dfs(int v, vector<int> path){
  int i;
  vector<int> tmp;

  tmp = path;
  if(left[v]>=256){
    tmp.push_back(LEFT);
    dfs(left[v], tmp);
  }else{
    tmp.push_back(LEFT);
    cout <<( (isalpha( (char)left[v] ) ) ? (char)left[v] : '*' )<< " = "; 
    for(i=0; i<tmp.size(); i++) cout << tmp[i];
    cout << endl;
  }
  
  tmp = path;
  if(right[v]>=256){
    tmp.push_back(RIGHT);
    dfs(right[v], tmp);
  }else{
    tmp.push_back(RIGHT);
    cout <<( (isalpha((char)right[v])) ? (char)right[v] : '*' )<< " = "; 
    for(i=0; i<tmp.size(); i++) cout << tmp[i];
    cout << endl;
  }

}

main(){
  int i,j,k,h,m,n,nw, cnt;
  uchar S[SIZE];
  uchar ch;
  /* Input the string to be encoded */
  i = 0;
  while(1){
    if(scanf("%c", &ch) == EOF) break;
    S[i++] = ch;
  }

  /* Compute the weight of each character */
  for (int i=0; i<256; i++) {w[i]=0; index[i]=0;}
  i=0;
  while (S[i]!='\0') w[S[i++]]++; 
  /* Construct the indirect heap */
  h=0;
  for (i=0; i<256; i++)
    if (w[i]>0) {h++; heap[h]=w[i]; index[h]=i;} 
  for (i=h/2; i>=1; i--) downheap(i,h); 

  /* Construct the binary tree */
  nw=256;
  while (h>1){
    i = index[1];
    heap[1] = heap[h]; index[1] = index[h--];
    downheap(1,h);
    j = index[1];
    k = nw++;
    w[k] = w[i] + w[j];
    heap[1] = w[k]; index[1] = k;
    left[k] = i; right[k] = j;
    downheap(1,h);
  }
 
  /* Outp ut the binary tree constructed */
  /*
  for (i=nw-1;i>=256;i--) {
    if (left[i]>=256) printf("left son of %4d is %4d ",i,left[i]);
    else printf("left son of %4d is %4c ",i,left[i]);
    if (right[i]>=256) printf("right son of %4d is %4d \n",i,right[i]);
    else printf("right son of %4d is %4c \n",i,right[i]);
  }
  */
  vector<int> path;
  dfs(nw-1, path);

}

void downheap(int k,int n){
  int j,u,v;
  u = heap[k]; v = index[k];
  while (k<=n/2){
    j= k + k;
    if (j<n && heap[j]>heap[j+1]) j++;
    if (u<=heap[j]) break;
    heap[k] = heap[j]; index[k] = index[j]; k = j;
  }
  heap[k] = u; index[k] = v;
}
  
